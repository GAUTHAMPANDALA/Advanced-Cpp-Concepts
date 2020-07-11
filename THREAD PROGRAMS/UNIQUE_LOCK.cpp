//  TOPIC: unique_lock In C++


// 1. The class unique_lock is a mutex ownership wrapper.
// 2. It Allows:
//    a. Can Have Different Locking Strategies
//    b. time-constrained attempts at locking (try_lock_for, try_lock_until)
//    c. recursive locking
//   d. transfer of lock ownership (move not copy)
//   e. condition variables. (See this in coming videos)


// Locking Strategies
//   TYPE           EFFECTS(S)
//  1. defer_lock   own the mutex, but donot lock the mutex, locks will happen in later part of code.
//  2. try_to_lock  if not able to lock the mutex, it will not wait for locking.
//  3. adopt_lock  assume the calling thread already has ownership of the mutex

#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

std::mutex m1;
int buffer=0;

void task(const char* threadnumber, int loopfor)
{
	std::unique_lock<mutex> lock(m1); 
	for(int i=0;i<loopfor;++i)
	{
		buffer++; // critical section.
		cout<<threadnumber<<" "<<buffer<<endl;
	}

}

int main()
{
	thread t1(task,"T0",10);
	thread t2(task,"T1",10);
	t1.join();
	t2.join();
	return 0;
}





