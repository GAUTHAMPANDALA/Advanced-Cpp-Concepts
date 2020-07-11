// Topic: Smart pointer Template.
// As using template we have to overide  operators *,->.   


#include <iostream> 
using namespace std; 

// A generic smart pointer class 
template <class T> 
class SmartPtr { 
	T* ptr; // Actual pointer 
public: 
	// Constructor 
	explicit SmartPtr(T* p = NULL) { ptr = p; } 

	// Destructor 
	~SmartPtr() { delete (ptr); } 

	// Overloading dereferncing operator 
	T& operator*() { return *ptr; } 

	// Overloading arrow operator so that members of T can be accessed  like a pointer 
	T* operator->() { return ptr; } 
}; 

int main() 
{ 
	
	int *p=new int(10);
    SmartPtr<int> myint=SmartPtr<int>(p);	
	cout<<*myint<<endl;	
	return 0;
} 
