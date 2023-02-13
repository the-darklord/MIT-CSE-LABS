#include <stdio.h>

/*
Code Not Completed
*/


int are_disjoint(int a[],int b[])
{
    int m=sizeof(a)/sizeof(a[0]);
    int n=sizeof(b)/sizeof(b[0]);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i]==b[j])
            {
                return 0;
            }
        }
    }
    return 1;
}

int is_sum_equal(int a[],int b[])
{
    int m=sizeof(a)/sizeof(a[0]);
    int n=sizeof(b)/sizeof(b[0]);
    int sum1=0,sum2=0;
    for(int i=0;i<m;i++)
    {
        sum1+=a[i];
    }
    for(int i=0;i<n;i++)
    {
        sum2+=b[i];
    }
    if(sum1==sum2)
    {
        return 1;
    }
    return 0;
}

void main()
{
    int n;
    printf("Enter Number of Elements : \t");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Array Elements : \n");
    for(int i=0;i<n;i++)
    {
        printf("Enter Element %d : \t",i+1);
        scanf("%d",&arr[i]);
    }
    int j=0;
    int a1[n/2],a2[n/2];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            
        }
    }
}