// Topic: Function_pointer in cpp

// The function pointer is a pointer hold the address of the function. 
// Since C is not OOP language , Consider the Function Pointer as the Father of virtual functionality in the modern languages. 
// In the oop language each driven class will  implements the virtual method depend on its need. 
//  In the C it is something similar, since we give the function pointer the address of the desired function implementation

//Function pointer is c technique which  enable the programmer to controlling the execution sequence within an application 
// by allowing alternate functions to be executed based on the application’s needs.


// Syntax:  define:   retrun_type (*functionpointer_name) (parameter datattype) = &function
//			calling:  (*functionpointer_name )(argument_values).

#include <stdio.h> 
// A normal function with an int parameter and void return type 
void fun(int a) 
{ 
    printf("Value of a is %d\n", a); 
} 
  
int main() 
{ 
    // fun_ptr is a pointer to function fun()  
    void (*fun_ptr)(int) = &fun; 
    
  
    /* The above line is equivalent of following two 
       void (*fun_ptr)(int); 
       fun_ptr = &fun;  
    */
  
    // Invoking fun() using fun_ptr 
    (*fun_ptr)(10); 
  
    return 0; 
} 
