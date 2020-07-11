// Topic: Unique Pointer.

// Syntax; unique_ptr<class_name> ptr_name(new class_name);
// Moving unique pointer: unique_ptr<A> ptr2 = move(ptr1); 

//  unique_ptr is a class template.
// 1. unique_ptr is one of the smart pointer provided by c++11 to prevent memory leaks.
// 2. unique_ptr wraps a raw pointer in it, and de-allocates the raw pointer,
//   when unique_ptr object goes out of scope.
// 3. similar to actual pointers we can use arrow and * on the object of unique_ptr,  because it is overloaded in unique_ptr class.
// 4. When exception comes then also it will de-allocate the memory hence no memory leak.
// 5. Not only object we can create array of objects of unique_ptr.

// When to use

// 1. Use unique_ptr when you want to have single ownership(Exclusive) of the resource. 
// 2. Only one unique_ptr can point to one resource. 
// 3. Since there can be one unique_ptr for single resource its not possible to copy one unique_ptr to another.


#include <iostream> 
#include <memory> 
using namespace std; 
  
class A { 
public: 
    void show() 
    { 
        cout << "A::show()" << endl; 
    } 
}; 
  
int main() 
{ 
    unique_ptr<A> p1(new A); 
    p1->show(); 
  
    // returns the memory address of p1 
    cout << p1.get() << endl; 
  
    // transfers ownership to p2 
    unique_ptr<A> p2 = move(p1); // *p2->get() ,*p1 ->get() are not equal.
    p2->show(); 
    cout << p1.get() << endl; 
    cout << p2.get() << endl; 
  
    // transfers ownership to p3 
    unique_ptr<A> p3 = move(p2); // *p2->get() ,*p3->get() are not  equal.
    p3->show(); 
    cout << p1.get() << endl; 
    cout << p2.get() << endl; 
    cout << p3.get() << endl; 
  
    return 0; 
} 
