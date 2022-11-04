#include <stdio.h>
int* Pointer(int* a)
{
    return a;
}
int** DoublePointer(int** a)
{
    return a;
}
int main()
{
    int c=10;
    int *pt=&c;
    int **ptptr=&pt;
    printf("value of constant is %d \n",c);
    printf("Address of c passed to function is %p \n",pt);
    printf("Address of c returned from functon is %p \n",Pointer(pt));
    printf("Address of pt passed to function is %p \n",ptptr);
    printf("Address of pt returned from functon is %p \n",DoublePointer(ptptr));
    return 0;
}