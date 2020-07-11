
#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

std:: recursive_mutex m1; // recursive mutex allowd for loops.

int main ()
{
	int i;
	
	for(i=0;i<5;i++)
	{
		m1.lock();     // locks the thread
		cout<<"Locked By ThreadID: "<<i<<"Times"<<endl;  // critical section
	}
	
		for(i=0;i<5;i++)
	{ 
		m1.unlock(); // unlocks the thread.
		cout<<"Unlocked By ThreadID: "<<i<<"Times"<<endl;  // critical section


	}
}
