// Topic:: Smart pointer in c++

// Smartpointer: Smart pointers are that automatically manage memory and they will deallocate the object when they are not in use 
// 				and when the pointer is going out of scope automatically it’ll deallocate the memory.
// Using Smart Pointers, we can make pointers to work in a way that we don’t need to explicitly call delete.
// A smart pointer is a wrapper class over a pointer with an operator like * and -> overloaded.

// Memory leak: Every time at the creation of  an object is made, but  deleting of that object is not done, 
//				then there will be memory leak in heap memory, ie memeory is allocated but not used.
// effects: As there is infinite creation of objects, then the heap will be unused for some time  and Because of a lack of heap memory, 
//					the program will crash.  		
// Prevention:  So at the last of the fun() we should use ‘delete p’.	
// Types:  unique, shared and weak pointers.

#include<iostream>
using namespace std;

class Myint{
	public: // proccess to wrap the pointer.
		explicit Myint(int *p=nullptr){data=p;}  // step-1	constructor 
		~Myint(){delete data;}					// step-2 :destructor.
		int & operator *() {return *data;}		// step-3: overloading pointer.
		private:
			int *data;
};

int main(){
	int *p=new int(10); // crating the pointer to wrap it.
	Myint myint=Myint(p);	// Sending to smart pointer class to wrap the raw pointerand returning deferencing of pointer.
	cout<<*myint<<endl;	// printing tthe wrapped pointer through object.
	return 0;
}
