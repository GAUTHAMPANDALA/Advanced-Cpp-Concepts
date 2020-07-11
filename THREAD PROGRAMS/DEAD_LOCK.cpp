// Topic: Dead lock in CPP

// Deadlock: This is a situation in which two computer programs sharing the same resource are effectively preventing each other from accessing
//		 	   the resource, resulting in both programs ceasing to function.


// In this exampe both the threads are waiting to get the other thread unlock at same time
//	 and both threads are simulltaaniously waiting for 1 second, this reults in deadlock printing nothing in compiler.
#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

std::mutex m1;
std::mutex m2;
// here if we donot use the sleep, then we cannot see deadlock, beacause may the m1 will goto cpu first and later m2 will go,
//		as it is dependent on the cpu intialising time.

void thread1()
{
	m1.lock(); // thread1 locking mutex 1.
	std::this_thread::sleep_for(std::chrono::seconds(1)); // time delay used for finding the deadlock situation
	m2.lock(); // thread1 wants to lock mutex 2  which is alrady locked by thread 2 after waiking up,. Result deadlock.
	cout<<"Critical Section of Thread One"<<endl;
	m1.unlock();
	m2.unlock();
}

void thread2()
{
	m2.lock(); // thread2 locking mutex 2.
	std::this_thread::sleep_for(std::chrono::seconds(1)); // time delay used for finding the deadlock situation
	m1.lock(); // thread2 wants to lock mutex 1  which is alrady locked by thread 1 after waiking up,. Result deadlock.
	cout<<"Critical Section of Thread Two"<<endl;
	m2.unlock();
	m1.unlock();
}

int main()
{
	thread t1(thread1);
	thread t2(thread2);
	
	t1.join();
	t2.join();
	return 0;
	
}



