// Topic:: Shared_pointer in cpp.

// Syntax; shared_ptr<class_name> ptr_name(new class_name);
// Assingnig shared pointer: shared_ptr<A> ptr2(ptr1); 


// 0. shared_ptr is a smart pointer which can share the ownership of object (managed object).
// 1. Several shared_ptr can point to the same object (managed object).
// 2. It keep a reference count to maintain how many shared_ptr are pointing to the same object.
//   and once last shared_ptr goes out of scope then the managed object gets deleted.
// 3. shared_ptr is threads safe and not thread safe. [what is this??]
//   a. control block is thread safe
//   b. managed object is not
// 4. There are three ways shared_ptr will destroyed managed object.
//   a. If the last shared_ptr goes out of scope.
//   b. If you initialize shared_ptr with some other shared_ptr.
//   c. If you reset shared_ptr.
// 5. Reference count doesn't work when we use reference or pointer of shared_ptr.



// when to use
//   Use shared_ptr if you want to share ownership of a resource. Many shared_ptr can point to a single resource.
//  shared_ptr maintains reference count for this propose. when all shared_ptr’s pointing to resource goes out of scope,
//   the resource is destroyed.


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
    shared_ptr<A> p1(new A); 
    cout << p1.get() << endl; 
    p1->show(); 
    shared_ptr<A> p2(p1);   // assigning the pointer p1 to p2.
    p2->show(); 
    cout << p1.get() << endl; 
    cout << p2.get() << endl; 
  
    // Returns the number of shared_ptr objects referring to the same managed object. 
    cout << p1.use_count() << endl; 
    cout << p2.use_count() << endl; 
  
    // Relinquishes ownership of p1 on the object  and pointer becomes NULL 
    p1.reset(); 
    cout << p1.get() << endl; 
    cout << p2.use_count() << endl; 
    cout << p2.get() << endl; 
  
    return 0; 
} 
