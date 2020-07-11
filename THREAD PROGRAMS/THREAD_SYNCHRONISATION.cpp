
//	TOPIC: Thread OR Process Synchronization

// Thread and process Syncronization are same.
//	1.0 Thread Or Process synchronize to access critical section.
//	2.0 Critical section is one or collection of program statements which should be executed by only one thread or process at a time.
// This is achieved using mutex.


#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

long long bankbalance=0;
std::mutex m;
void addmoney(long long val){
	m.lock();   // lociking 
	bankbalance+=val;
	m.unlock();	// unlocking 
}

int main()
{
	std::thread t1(addmoney,100);
	std::thread t2(addmoney,200);
	
	t1.join();
	t2.join();
	
	cout<<"FINAL ACCCOUNT BALANCE: "<<bankbalance<<endl;
	return 0;
	
}
