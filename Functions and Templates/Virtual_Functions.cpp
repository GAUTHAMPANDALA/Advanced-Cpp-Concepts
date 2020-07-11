#include <iostream> 
using namespace std; 
  
class Base { 
public: 

// Virtual functions allow us to create a list of base class pointers 
// and call methods of any of the derived classes without even knowing kind of derived class object.
    virtual void show() 
    { 
        cout << " In Base \n"; // this is virtual function written in parent class.
    } 
}; 
  
class Derived : public Base { 
public: 
    void show() 
    { 
        cout << "In Derived \n"<<endl; 
    } 
}; 

class Derived1 : public Base {
	public:
	void show()
	{
		cout<<"In Derived1 \n"<<endl;
	}
};
  
int main(void) 
{ 
// Creating object pointer
    Base* bp = new Derived; 
//the function will be called based on the derived class object. this is also called as RUN-TIME POLYMORPHISM.
    bp->show();   // Here it is derived object call.
// Creating object pointer
    Base* bp1 = new Derived1; 
    bp1->show();   // Here it is derived1 object call.
    /*Derived d; // creating normal object.
    d.show();*/
    return 0; 
} 
