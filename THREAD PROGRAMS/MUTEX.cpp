// TOPIC: Mutex In C++ Threading | Why Use Mutex | What Is Race Condition And How To Solve It? | What Is Critical Section

/// Mutex: Mutual Exclusion

// RACE CONDITION:
// 0. Race condition is a situation where two or more threads/process happens to change/ modify a common data at the same time.
// 1. If there is a race condition then we have to protect it and the protected section is  called critical section/region.
// 2. RaceCondition is not applicable to access data.

// MUTEX:
// 0. Mutex is used to avoid race condition.
// 1. We use lock() , unlock() on mutex to avoid race condition.
// 2.  the first/primary thread to cpu locks using lock() function.
// 3. after first/primary  thread unlock , then secondary thread will unlock() it.


// Drawback:
	// if the mutex is already locked, and we try to lock that mutex then we will get blocked  and only after unlock of thread t1
	// we can start execution process of t2.
	// here when we are unable to lock a thread t2, then this t2  thread lock function waits untill the the locked thread is unlocked. 

#include<iostream>
#include<mutex>
#include<thread>

using namespace std;

int myamount=0;
std::mutex m;  // Using mutex to prevent race around condition.

void addmoney()
{
	m.lock();   // locking the thread
	++myamount; // there are 3 internal steps whlle modifying 1.load, 2. increment 3. store. and this is critical section.
	m.unlock(); // unlocking the thread.
}

int main()
{
	std::thread t1(addmoney);
	std::thread t2(addmoney);
	
	/// accesing the same data through two threads, this is race condition, because t1,t2 start parlelly.
	// TO PREVENT THIS WE USE MUTEX. 
    t1.join();
	t2.join();
	cout<<myamoount<<endl;	
}
