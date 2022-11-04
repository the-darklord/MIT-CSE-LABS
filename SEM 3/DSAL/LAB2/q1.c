#include <stdio.h>

void Reverse(int a[100],int n)
{
    int *pt;
    pt=&a[0];
    int *pt2;
    pt2 = &a[n-1];
    int temp;
    for(int i=0;i<n/2;i++)
    {
        temp = *(pt2 - i);
        *(pt2-i) = *(pt+i);
        *(pt+i) = temp;
    }

}
int main()
{
    int a[100],n;
    printf("enter array size : \t");
    scanf("%d",&n);
    printf("Enter array elements : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    Reverse(a,n);
    for(int i=0;i<n;i++)
    {
        printf("%d \t",*(a+i));
    }
    printf("\n");
}