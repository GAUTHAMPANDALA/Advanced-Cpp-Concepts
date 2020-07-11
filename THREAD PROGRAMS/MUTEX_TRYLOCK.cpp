// TOPIC: std::mutex::try_lock() On Mutex In C++11 Threading

// 0. try_lock() Tries to lock the mutex. Returns immediately. On successful lock acquisition returns true otherwise returns false.
// 1. If try_lock() is not able to lock mutex, then it doesn't get blocked that's why it is called non-blocking.
// 2. If try_lock is called again by the same thread which owns the mutex, the behavior is undefined.
//    double_trylock is not allowed on same mutex by same thread, It is a dead lock situation with undefined behavior. 
//   (if you want to be able to lock the same mutex by same thread more than one time the go for recursive_mutex)

#include<iostream>
#include<mutex>
#include<thread>

using namespace std;

int counter=0;
int counter1=0;
std::mutex m;  // Using mutex to prevent race around condition.


// mutex using trylock and unlock.
void Increasecounterfor100000()
{
	for(int i=0;i<100000;++i)
	{
		if(m.try_lock()){ // this return false if we cannot lock mutexprocess.
			++counter;
			m.unlock();
		}
	}
}

// mutex using lock,unlock.
void Increasecounter1for100000()
{
	for(int i=0;i<100000;++i)
	{
	    	m.lock() // this is to lock mutexprocess.
			++counter1;
			m.unlock(); // this is to unlock mutexprocess.
		
	}
}

int main()
{
	std::thread t1(Increasecounterfor100000);
	std::thread t2(Increasecounterfor100000);
	
	
	std::thread t3(Increasecounter1for100000);
	std::thread t4(Increasecounter1for100000);
	
	/// accesing the same data through two threads, this is race condition, because t1,t2 start parlelly.
	// TO PREVENT THIS WE USE MUTEX with trylock.. 	
	t1.join();
	t2.join();
	
	/// accesing the same data through two threads, this is race condition, because t1,t2 start parlelly.
	// TO PREVENT THIS WE USE MUTEX. 	
	t3.join();
	t4.join();
	

	// The output is not same beacause, it is dependent on the arrival time of threads to cpu. 
	//There will be simultaneous increment, locking and unlocking situation between threads that gives us random incremented value.
	
		cout<<"Using try lock Counter could increase upto: "<<counter<<endl;		
		
	// The output is same beacause, it is dependent on the arrival time of threads to cpu. 
	//There will be no  simultaneous increment, locking and unlocking situation between threads.
	// beacause when t1 locks, unless this t1 unlocks the thread, t2 will not be execute.
		cout<<"Using lock Counter could increase upto: "<<counter1<<endl;
	
	
}




// Other Functions for TRY_LOCK are:
// 1. std::try_lock
// 2. std::mutex::try_lock
// 3. std::shared_lock::try_lock
// 4. std::timed_mutex::try_lock
// 5. std::unique_lock::try_lock
// 6. std::shared_mutex::try_lock
// 7. std::recursive_mutex::try_lock
// 8. std::shared_timed_mutex::try_lock
// 9. std::recursive_timed_mutex::try_lock
