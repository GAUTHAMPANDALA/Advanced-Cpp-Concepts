#include<iostream>

using namespace std;
	

// pure virtual or abstract functions are written.
class  abstract_class{
	
protected:
	 int x; 
public: 
    virtual void fun() = 0;  // abstract function.
    abstract_class(int i) { x = i; }  // abstract function overloading, this will be called using the derived class.
};

// This class inherits from virtual_class and implements fun() 
class Derived_from_abstract_class: public   abstract_class
{ 
    int y; 
public:
    // The below is implementation of constructor in the abstract_class.
	// we have to create the derived construtor then by scope operator call parent class constructor. 
	
	// syntax is as  derviedconstr():baseconstr(){ code..}, as follows.
     Derived_from_abstract_class(int i, int j):abstract_class(i)  // abstract function overloading 
	 { 
	 y = j;
	 }   
     void fun2() { cout <<"The constructor fun() is called: " <<"x = " << x << ", y = " << y<<endl; } 
     void fun() { cout << "The normal fun() called"<<endl; } 
}; 

int main()
{
	
	Derived_from_abstract_class d1(4,5);  // calling the abstract constructor 
	d1.fun();      // calling the normal function.
	d1.fun2();
 
    return 0;  
}
