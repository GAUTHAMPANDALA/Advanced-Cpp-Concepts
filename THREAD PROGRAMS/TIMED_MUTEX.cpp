// TOPIC: Timed Mutex In C++

// std::timed_mutex is blocked till timeout_time or the lock is acquired and returns true if success otherwise false.

// Member Function:
   //  a. lock
  //  b. try_lock
  //  c. try_lock_for    ---\ These two functions makes it different from mutex.
  // d. try_lock_until  ---/
  // e. unlock
  
  
// EXAMPLE: try_lock_for();
	 //   Waits until specified timeout_duration has elapsed or the lock is acquired, whichever comes first.
	 // On successful lock acquisition returns true, otherwise returns false.
	 
	 
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

int myAmount = 0;
std::timed_mutex m;

void increment(int i) {
 if(m.try_lock_for(std::chrono::seconds(2))){  // this waits for particular momment of time for thread t2 to lock the procces.
  ++myAmount;
  std::this_thread::sleep_for (std::chrono::seconds(1)); // this thread sleeps forsome time, while other thread is waiting.
  cout << "Thread " << i << " Entered" << endl;
  m.unlock();									// unlocking th thread.
 }else{
  cout << "Thread " << i << " Couldn't Enter" << endl;
 }
}

int main() {
 std::thread t1(increment, 1);
 std::thread t2(increment, 2);

 t1.join();
 t2.join();

 cout << myAmount << endl;
 return 0;
}




