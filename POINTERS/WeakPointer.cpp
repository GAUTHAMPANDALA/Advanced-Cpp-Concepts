// Topic: Weak_pointer in cpp.

//// Syntax: weak_ptr<class_name> ptr_name(new class_name);

//  0. If we say unique_ptr is for unique ownership and shared_ptr is for shared ownership then
//     weak_ptr is for non-ownership smart pointer.
//	1. It actually reference to an object which is managed by shared_ptr.
//	2. A weak_ptr is created as a copy of shared_ptr.
//	3. We have to convert weak_ptr to shared_ptr in order to use the managed object.
//	4. It is used to remove cyclic dependency between shared_ptr.

// Cyclic Dependency (Problems with shared_ptr): Let’s consider a scenario where we have two classes A and B, 
//													both have pointers to other classes. 
//													So, it’s always like A is pointing to B and B is pointing to A. 
//													Hence, use_count will never reach zero and they never get deleted.

// When to use.
//  When you do want to refer to your object from multiple places – for those references for which it’s ok to ignore and deallocate 
//	(so they’ll just note the object is gone when you try to dereference).


#include <iostream>
#include <memory>
 
using namespace std;
 
class Dog
{
   weak_ptr<Dog> m_pFriend;
   public:
   	string m_name;
   	void bark(){cout<<"Dog "<<m_name<<"rules!"<<endl;}
   	Dog(string name){cout<<"Dog is created: "<<name<<endl;m_name=name;}
   	~Dog(){cout<<"Dog is Destroyed : "<<m_name<<endl;}
    void makeFriend(shared_ptr<Dog> f){m_pFriend=f;}
    void showFriend(){
    	if(!m_pFriend.expired()) cout<<"My Friend is: "<<m_pFriend.lock()->m_name<<endl;
    	cout<<"He is owned by "<<m_pFriend.use_count()<<"pointers: "<<endl;
	}
   	
};
 
int main()
{
     shared_ptr<Dog> pd(new Dog("Gunner"));
     shared_ptr<Dog> pd2(new Dog("Smoothy"));
     pd->makeFriend(pd2);
     pd2->makeFriend(pd);
     pd->showFriend();
}
