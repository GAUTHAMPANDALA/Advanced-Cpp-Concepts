//   TOPIC: Condition Variable In C++ Threading


// syntax for predicate:
   // []{ pedicate_body};
// syntax for conditional_variable
   //  cv.wait(mutex_object, predicate);.


//	1. Condition variables allow us to synchronize threads via notifications.
//   	a. notify_one();
//   	b. notify_all();
//  2. You need mutex to use condition variable
// 	3. Condition variable is used to synchronize two or more threads.
//  4. Best use case of condition variable is Producer/Consumer problem.
//  5. Condition variables can be used for two purposes:
//    a. Notify other threads
//    b. Wait for some condition


#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;

std::condition_variable cv;
std::mutex m;
int balance=0;

void addmoney(int money){
	std::lock_guard<mutex> lg(m); // now this thread will lock the mutex, that is released by the withdrowmoney thread.
	balance+=money; // perfoems critical section.
	cout<<"Amount added Current Balance: "<<balance<<endl;
	cv.notify_one();  // this notifies the waiting threaad, tp continue locking and acces critical section.
}  // after the scope the thread is released, so that waiting thread can acces this.

void withdrowmoney(int money)
{
	std::unique_lock<mutex> ul(m); // this locks the mutex.
	cv.wait(ul,[]{return (balance!=0)?true:false;});
	// the above piece of code is conditional variable, with mutex object and predicate.
	// predicate: []{return (balance!=0)?true:false;} and mutexobject is ul.
	// This statement waits for the predicate to be true, while releasing/unlocking. the mutex.
	if(balance>=money){
		balance-=money;  // perfoems critical section.
		cout<<"Amount Deducted: "<<money<<endl;
	}
	else{
		cout<<"Amount can't be Deducted, Current Balance is less than "<<money<<endl;
	}
	cout<<"Current Balance is: "<<balance<<endl;
	
}

int main()
{
	std::thread t1(withdrowmoney,500);
	std::thread t2(addmoney,500);
	t1.join();
	t2.join();
	return 0;
}
