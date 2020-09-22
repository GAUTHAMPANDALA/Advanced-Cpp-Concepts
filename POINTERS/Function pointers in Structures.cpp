						// Function pointers in Structures 	//
						
					//  Using the Function Pointer inside C struct   //
// Struct can contian varibles from simple data type to complex ones such as varible of function pointer   //
//Function pointer is c technique which  enable the programmer to controlling the execution sequence within an application by
// s allowing alternate functions to be executed based on the application’s needs.


#include <stdio.h> 

// This is function pointer called Operation which return an int value and accepts two integer parameters
typedef   int (*Operation)(int a , int b); 

	// This simple struct STR which contains pointer to the Operation function pointer //
	//   an integer variable to store  returned value  from the Operation variable  //
	
typedef  struct _str {

       int  result ; // to sotre the resut
       Operation  opt; // funtion pointer 

 } STR;
 

int Add ( int a , int b ){   // Add function to sum elements
     
      return a+b ;
}


int Multi ( int a , int b ){ // To muldiply elements 

       return a*b ;
}


int main (){

      STR str_obj;

      str_obj.opt = Add;//the function pointer variable point to Add function 

      str_obj. result = str_obj.opt(5,3);

      printf (" the result is %d\n", str_obj.result );

      str_obj.opt= Multi;//the function pointer variable point to Multi function 

      str_obj. result = str_obj.opt(5,3); 

      printf (" the result is %d\n", str_obj.result );

      return 0 ;

}

