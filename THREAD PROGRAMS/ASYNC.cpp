// TOPIC: std::async

// 1. It runs a function asynchronusly (potemtially is a new thread) and returns a std::future that will hold result.
//  2. THere are three launch polices for creating tasks.
//    a. std::launch::async  // creates thread at current statement. this is eager evaluation
//    b. std::launch::deffered // donot create a thread, and thread is created at the std::future statement. this is lazy evaluation
//    c. std::launch --> computerr decides whether to launch async or deffered.
//  3. This is used to achieve the same functionality as promise and we only write future.
// deferred the two threads run with sameID, but async there will be two different thread ids.

// Working
//  1. It automatically creates a thread ( or picks from internal thread pool) and a promise object for that.
//  2. Then passes the std::promise object to thread function  and returns associated std:: future object.
// 3.  When our passed argument function exsists then its value will be set in this promise object
//     so eventually return value will be available in std::future object.
// 4.  we can send functor and lambda functions as callback to std::async . It will work same.

#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>
#include<future>

using namespace std;
using namespace std::chrono;

typedef long int ull;

ull findodd( ull start, ull end) // recieving promise obj and input parameters.
{
	cout<<"Oddsum Thread Thread ID is: "<<std::this_thread::get_id()<<endl;
	ull oddsum=0; // this is local variable 
	for(ull i=start ;i<=end;++i)
	{
		if(i&1){
			oddsum+=1;
		}
	}
	return oddsum;
}

int main()
{
	ull start=0, end=1900000000;
	cout<<"Main Thread Thread ID is: "<<std::this_thread::get_id()<<endl;
	cout<<"Thread created if policy is std::launch::async!!"<<endl;
	std::future<ull> oddsum=std::async(std::launch::deferred, findodd,start,end); //initially this will not create thread, 
																				// but will reserve the thread and ready to call thread.
	cout<<"Waiting for result! "<<endl;     
	cout<<"Oddsum: "<<oddsum.get()<<endl; 		// In this statement the thread is invoked and result is recieved.
													// untill the statemnt returns this step will wait.
	cout<<"Completed! !"<<endl;
	return 0;
	
}
