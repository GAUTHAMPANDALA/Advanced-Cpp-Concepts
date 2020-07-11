#include<iostream>

using namespace std;
int main(){
	
	int choice;
	cout<<"enter the choice"<<endl;
    
	cout<<"Shutdowwn"<<endl;
	cout<<"Restart"<<endl;
	cout<<"Enter Choice"<<endl;
	cin>>choice;
	switch(choice){
		case 1: cout<<"Your System will be shutdown after 20 Seconds"<<endl;
				system("c:\\windows\\system32\\shutdown /s /t 20 \n\n");
				break; 
		case 2: cout<<"Your System will be restart after 20 Seconds"<<endl;
				system("c:\\windows\\system32\\shutdown /r /t 20 \n\n");
				break; 
		default: cout<<"Wrong Choice";
	}
	return 0;
}
