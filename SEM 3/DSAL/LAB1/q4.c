#include <stdio.h>

int SecondLarge(int a[],int n)
{
   int i,large1,large2;
   large1=a[0];
   large2=a[1];
   if(large2>large1)
   {
      large1=large1+large2;
      large2=large1-large2;
      large1=large1-large2;
   }
   for(i=2;i<n;i++)
   {
      if(a[i]>large1)
      {
         large2=large1;
         large1=a[i];
      }
      else if(a[i]<large1&&a[i]>large2)
      {
         large2=a[i];
      }
   }
   return large2;
}
int main()
{
   int a[100],n,i,num;
   printf("Enter No. of Elements : \t");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
      printf("Enter element %d : \t",i+1);
      scanf("%d",&a[i]);
   }
   num=SecondLarge(a,n);
   printf("The Second Largest element is %d \n",num);
   return 0;
}