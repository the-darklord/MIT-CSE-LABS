#include <stdio.h>
#include <stdlib.h>
#include "LL.c"

void main()
{
    int m,n;
    printf("Enter No. of Elements : \t");
    scanf("%d",&n);
    printf("Enter No. of Cells : \t");
    scanf("%d",&m);
    double alpha=n/m;
    int key;
    Nodeptr HashTable[m];
    for(int i=0;i<m;i++)
    {
        HashTable[i]=NULL;
    }
    int mod;
    for(int i=0;i<n;i++)
    {
        printf("Enter Key %d : \t",i+1);
        scanf("%d",&key);
        mod=key%m;
        HashTable[mod]=InsL(HashTable[mod],key);
    }
    for(int i=0;i<m;i++)
    {
        printf("%d\t",i);
        Display(HashTable[i]);
    }
    printf("SUCCESSFUL SEARCH COMPARISIONS : %f\n",1+alpha/2);
    printf("UNSUCCESSFUL SEARCH COMPARISIONS : %f\n",alpha);
}
