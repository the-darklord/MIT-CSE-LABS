#include <stdio.h>

void tower(int n,char S,char A,char D,int *opc )
{
    (*opc)++;
    if(n==1)
    {
        printf("Moving from %c to %c\n",S,D);
    }
    else
    {
        tower(n-1,S,D,A,opc);
        printf("Moving from %c to %c\n",S,D);
        tower(n-1,A,S,D,opc);
    }
}

void main()
{
    int n,opc=0;
    printf("Enter Number of Disks : \t");
    scanf("%d",&n);
    char s,d,a;
    printf("Enter Source,Auxiliary,Destination : \n");
    scanf(" %c %c %c",&s,&a,&d);
    tower(n,s,a,d,&opc);
    printf("\nOPCOUNT is %d\n",opc);
}