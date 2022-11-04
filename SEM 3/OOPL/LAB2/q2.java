import java.util.Scanner;

class q2
{
    public static void main(String args[])
    {
        int i,n,pos1,pos2;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Number of Elements :");
        n=sc.nextInt();
        int a[]=new int[n];
        for(i=0;i<n;i++)
        {
            a[i]=sc.nextInt();
        }
        System.out.println("Enter Element to insert : ");
        int ele=sc.nextInt();
        System.out.println("Enter position to insert : ");
        pos1=sc.nextInt();
        int arr[]=new int[n+1];
        for(i=0;i<n+1;i++)
        {
            if(i<pos1-1)
            {
                arr[i]=a[i];
            }
            else if(i==pos1-1)
            {
                arr[i]=ele;
            }
            else
            {
                arr[i]=a[i-1];
            }
        }
        System.out.println("Enter position to delete : ");
        pos2=sc.nextInt();
        for(i=pos2-1;i<n;i++)
        {
            arr[i]=arr[i+1];
        }
        System.out.println("New Array is : ");
        for(i=0;i<n;i++)
        {
            System.out.println(arr[i]);
        }
    }
}