

#include<iostream>

using namespace std;
	
// creating template class, this must have atleast 1 template variable and 1 template function.
template <class t>

class nametemplate{
	
	t a,b; // template class datamembers are in private.
   public:
   
   void getvalues()
   {
   	
   	cin>>a>>b;
   }
   
   t sum()  // templaate class method is declared and defined.
   {
   		return a+b;
   }
   t maxx(); // For 2 example this templaate class method is declared after  template class 
   
};


// defining template class function MAX.
template <class t>

t nametemplate<t>:: maxx()
{
	if(a>b)
	return a;
	else return b;
}


// Main, we need to specify the datatype of function template while creating object for template class.
// ie, synatx class_name <datatype> object_name.

int main()
{
	nametemplate<int> t;  
	nametemplate<float> t1;
	cout<<"Enter 2 int "<<endl;
	t.getvalues();
	cout<<"The sum of integers: "<<t.sum()<<endl;
	cout<<"The max of integers: "<<t.maxx()<<endl;
	cout<<"Enter 2 float "<<endl;
	t1.getvalues();
	cout<<"The sum of float: "<<t1.sum()<<endl;
	cout<<"The max of float: "<<t1.maxx()<<endl;
	
}
