#include <stdio.h>
int tower(int n,char source,char dest,char inter)
{
    static int count = 0;
    count++;
    if(n==1)
    {
        printf("Moving from %c to %c \n",source,dest);
    }
    else if(n!=0)
    {
        tower(n-1,source,inter,dest);
        printf("Moving from %c to %c \n",source,dest);
        tower(n-1,inter,dest,source);
    }
    return count;
}
void main()
{
    int n,count;
    printf("Enter Number of Disks : \t");
    scanf("%d",&n);
    char source='A',dest='B',inter='C';
    count = tower(n,source,dest,inter);
    printf("No. of Moves : %d\n",count);
}