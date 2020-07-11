
#include<iostream>
using namespace std;

template <class t>

t sum(t a, t b)
{
	return a+b;
}

template <class t>

t sum(t a, t b, t c)
{
	
	return a+b+c;
}


class max1{
	
   public:
   	
   int	maxx(int a,int b)
   	{
   		if(a>b)
   		return a;
   		else
   		return b;
	}
  int maxx(int a, int b, int c)
   {
   	if(a>b)
   	{
   		if(b>c)   		
   			return c;	    
	    else
	     return b;
	}
	else
	{
		if(a>c)
		return a;
		else
		return c;
	}
   }
};

class copying{
	
	public:
	int a1,b1,c1;
	copying(int a, int b)
	{
		a1=a;
		b1=b;
		cout<<"The first constructor overload is max of 2 variables: "<<a<<" "<<b<<endl;
	}
	copying(int a, int b,int c)
	{
		a1=a;
		b1=b;
		c1=c;
		cout<<"The Second constructor overload is max of 3 variables: "<<a<<" "<<b<<" "<<c<<endl;
	}
		
  
   
};
int main()
{
	cout<<"The first Template overload method is sum integer of 2 variables: "<< sum(5,6)<<endl;
	cout<<"The Second Template overload is sum integer of 3 variables: "<<sum(5,6,7)<<endl;
	cout<<"The first Template overload method is sum float of 2 variables: "<< sum(5.2,2.6)<<endl;
	cout<<"The Second Template overload is sum float of 3 variables: "<<sum(5.21,1.6,3.7)<<endl;
	max1 m1;
    cout<<"The first function overload is max of 2 variables: "<< m1.maxx(5,6)<<endl;
	cout<<"The Second function overload is max of 3 variables: "<<m1.maxx(5,6,7)<<endl;
    copying(51,61);
	copying(51,61,71);	
}
