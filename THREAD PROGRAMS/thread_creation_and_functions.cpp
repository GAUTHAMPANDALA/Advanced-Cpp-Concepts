#include<iostream>
#include<thread>

using namespace std;

void sum1(int a)
{
	cout<<"First Thread "<<a+a<<endl;
}

void sum2(float a)
{
	cout<<"Second Thread "<<a+a<<endl;
}

int main()
{
	cout<<"print main thread  before thread t1,t2"<<endl;
    thread t1 (sum1,5);
	thread t2 (sum1,5.5);
	if(t1.joinable())    // Checks whether thread is joinable
	t1.join();			// Joins thread and make two thrads  inter dependent.
	t1.detach();        // Detach from parent thread.
	cout<<"print after thread t1,t2"<<endl;
	
}
