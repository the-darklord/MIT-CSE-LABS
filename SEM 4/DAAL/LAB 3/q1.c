#include <stdio.h>

void main()
{
    int n,temp,opcount=0;
    printf("Enter No. of Elements : \t");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Array Elements : \n");
    for(int i=0;i<n;i++)
    {
        printf("Enter Element %d : \t",i+1);
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i;j<n-1;j++)
        {
            opcount++;
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("Operation Count is %d\n",opcount);
}