#include <stdio.h>
#include <string.h>
#include "mihir1.c"

void main()
{
    int n,Z,ele,j=0;
    char m[100];
    printf("Enter Array size : \t");
    scanf("%d",&n);
    STACK s1,*ps1=&s1;
    ps1->tos=-1;
    ps1->stack=(char *)calloc(n+1,sizeof(char));
    printf("Enter Elements of Array : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ele);
        push(n,ele,ps1);
    }
    printf("Enter Number of elements to delete : \t");
    scanf("%d",&Z);
    while(Z!=0)
    {
        for(int i=0;i<n;i++)
        {
            if(ps1->stack[i]<ps1->stack[i+1])
            {
                Z--;
                pop(ps1,i);
                break;
            }
        }
    }
    for(j=0;j<ps1->tos+1;j++)
    {
        printf("%d ",ps1->stack[j]);
    }
    printf("\n");
}