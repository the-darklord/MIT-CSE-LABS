#include <stdio.h>
#include <stdlib.h>

int Smallest(int *a,int n,int *small)
{
    *small=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]<*small)
        {
            *small=a[i];
        }
    }
    return *small;
}
int main()
{
    int i,n,*small;
    printf("Enter size of array : \t");
    scanf("%d",&n);
    int *a;
    a=(int*)malloc(n*(sizeof(int)));
    printf("Enter array elements \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",(a+i));
    }
    Smallest(a,n,small);
    printf("Smallest Element is %d",*small);
    return 0;
}