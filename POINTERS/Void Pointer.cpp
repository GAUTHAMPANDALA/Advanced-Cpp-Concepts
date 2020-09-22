
  											  //   Void pointers   //
  	
  // A void pointer in c is called a generic pointer, it has no associated data type. 
  // It can store the address of any type of object and it can be type-casted to any type. 
  // the pointer to void shall have the same representation and alignment requirements as a pointer to a character type.
  //  A void pointer declaration is similar to the normal pointer, but the difference is that instead of data types.
  //  we use the void keyword.  




#include <stdio.h>
int main(int argc, char *argv[])
{
    void *pvData;
    int iData = 10;
    char cData = 'A';
    float fData = 27.6;
    //Assigning address of character
    pvData = &cData;
    //dereferencing void pointer with character typecasting
    printf("cData = %c\n\n",*((char*)pvData));
    //Assigning address of integer
    pvData = &iData;
    //dereferencing void pointer with integer typecasting
    printf("iData = %d\n\n",*((int *)pvData));
    //Assigning address of float
    pvData = &fData;
    //dereferencing void pointer with float typecasting
    printf("fData = %f\n\n",*((float *)pvData));
    return 0;
}
