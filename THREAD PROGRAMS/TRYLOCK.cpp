// TOPIC: std::try_lock() On Mutex In C++11 Threading

//Syntax: std::try_lock(m1,m2,m3,m4,..)

// 0. std::try_lock() tries to lock all the mutexes passed in it one by one in given order.
// 1. On success this function returns -1 otherwise it will return 0-based mutex index number which it could not lock.
// 2. If it fails to lock any of the mutex then it will release all the mutex it locked before.
// 3. If a call to try_lock results in an exception, unlock is called for any locked objects before re-throwing.


// This is useful when we run n threads parlelly, and 
// we need to consume the variables of (n-1) threads into nth thread for each of the insatance of delay. 
// here the order of execution is T1,T2,T3. ie, 
    //  1. t1 intiated and delayed after some time, and control shifted to t2.
    //   2. t2 initiated and delayed after some time, and control shifted to t3.
    //   3.  t3 initiated and unlocked both threads,and control shifted to t1 again .
    // 4. The whole process is looped for 5 times.

#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>
using namespace std;

int X=0, Y=0;  // the x and y global variables  are updated using XorY variable in incrementXY by threads t1,t2.
std::mutex m1, m2;   

// Funtion for delaying.
void doSomeWorkForSeconds(int seconds) { std::this_thread::sleep_for(std::chrono::seconds(seconds)); }

void incrementXY(int& XorY, std::mutex& m, const char* desc) {
 for(int i=0; i<5; ++i){         // looping to use the single thread critical section for 5 times
  m.lock();						// blocks m1 mutex in case of t1 and m2 incase of t2.
   ++XorY;             			// this state ment increments x,y of two threads t1,t2  parllerlly.
  cout << desc << XorY << '\n';  // printing the thread variables of t1,t2 as x,y.
  m.unlock();					// unlocking
  doSomeWorkForSeconds(1); 		 // delaying to initate thread t3.
 }
}

void consumeXY () {
 int useCount = 5;
 int XplusY = 0;
 while(1){
  int lockResult = std::try_lock(m1,m2); // try to lock m1,m2 mutex to get xory variable.
  if(lockResult == -1){
   if(X!=0 && Y!=0){     // beacause the x and y values are updated using XorY variable.
    --useCount;
    XplusY+=X+Y;         // consuming x and y while the incrementXY function is delayed.
    X = 0;				// againg initiating back to normal state.
    Y = 0;	
    cout << "XplusY " << XplusY << '\n'; // printing the consumed x and y vlaue.
   }
   m1.unlock();  // unlock thread m1, to start m1 again
   m2.unlock();  // unlock thread m2, to start m2 again
   if(useCount == 0) break;   // breaking after usage of the threads t1,t2 critical section for 5 times.
  }
 }
}

int main() {
 std::thread t1(incrementXY, std::ref(X), std::ref(m1), "X "); // passing the x,mutex as reference
 std::thread t2(incrementXY, std::ref(Y), std::ref(m2), "Y "); // passing the x,mutex as reference
 std::thread t3(consumeXY);

 t1.join();
 t2.join();
 t3.join();
 return 0;
}
