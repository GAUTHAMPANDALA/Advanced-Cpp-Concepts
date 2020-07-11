// Topic: STD::future and std::promise in c++

// 1. std::promise
//		a. Used to set values or exceptions.

// 2. std::future
//   a. used to get values from promise.
//   b. ask promise if value is available.
//   c. wait for promise,

// The scenario is that when we start a thread, we pass input parameters to that process, and 
// we even reecieve the data from the thread created
// To perform the aove function we use promise and future.

// steps: 1. create promise obj.
//		  2. create future object from promise object            (future_obj=promis_obj.get_future();
//		  3. move the promise object to thread created as function/process parameter.
//		  4. In thread process, return  the local result variable to main process through promise object
//				as,	following syntax-->						    (promise_object.set_value(local variable).)
//		  5. Now in main function recieve the returned value through future object. (futureobj.get()).


#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>
#include<future>

using namespace std;
using namespace std::chrono;
typedef long int ull;
ull  findodd( ull start, ull end) // recieving promise obj and input parameters.
{
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
	cout<<"Thread created if policy is std::launch::async!!"<<endl;
	std::future<ull> oddsum=std::async(std::launch::deferred, findodd,start,end);
	cout<<"Waiting for result! "<<endl;     
	cout<<"Oddsum: "<<oddsum.get()<<endl; 
	cout<<"Completed! !"<<endl;
	return 0;
	
}

