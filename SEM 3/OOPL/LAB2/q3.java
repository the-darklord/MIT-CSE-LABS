import java.util.Scanner;

class q3
{
    public static void main(String args[])
    {
        int i,n,ele,pos=-1;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Number of Elements : ");
        n=sc.nextInt();
        int a[]=new int[n];
        for(i=0;i<n;i++)
        {
            a[i]=sc.nextInt();
        }
        System.out.println("Enter element to search : ");
        ele=sc.nextInt();
        for(i=0;i<n;i++)
        {
            if(a[i]==ele)
            {
                pos=i;
            }
        }
        if(pos==-1)
        {
            System.out.println("Element not found");
        }
        else
        {
            System.out.println("Element found at position "+(pos+1));
        }
    }
}