
// Templates or generics are used for function normalisation and memory optimisation.
// we use one function for multiple datatypes and this supports polymorphisam.

#include<iostream>

using namespace std;

// Passing different  datayypes and  Passing same datatypes
// Here we accepet two different or same   dataypes in t1,t2 data holders>
template <class t1, class t2>   // The return type is float here and dependent on the function return. 
t2  sum(t1 a, t2 b) 
{
	return (a+b); // in integer,float case t1,t2 are integers and floats, but in case 3 t1 is int and t2 is float.
}

template <class t3>

t3   sumarray(t3 a[],int n)  // array type may be float or int.
{
	t3 s=0;   // this datatype is dependent on the sum.
	for(int i=0;i<n;i++)
	{
		s=s+a[i];
	}
	return s;
}

int main()
{
	int a[5]={1,2,3,4,5};
	float  b[5]={1.1,2.2,3.13,4.2,5.5};
	cout<< "int sum "<<" "<<sum(2,3)<<endl;
	cout<<"float sum "<< " "<<sum(2.15,3.5)<<endl;
	cout<<"Int and float sum "<< " "<<sum(2,3.5)<<endl;
	cout<<"The Integer Array sum is: "<<" "<<sumarray(a,5)<<endl;
	cout<<"The Float Array sum is: "<<" "<<sumarray(b,5)<<endl;

}
