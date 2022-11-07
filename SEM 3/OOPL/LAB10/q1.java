import java.util.*;

class q1
{
    static <T> void swap(T arr[],T el1,T el2)
    {
        T temp;
        int pos1=0,pos2=0;
        for(int i=0;i<arr.length;i++)
        {
            if(arr[i]==el1)
            {
                pos1=i;
            }
            if(arr[i]==el2)
            {
                pos2=i;
            }
        }
        temp=arr[pos1];
        arr[pos1]=arr[pos2];
        arr[pos2]=temp;
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n;
        System.out.println("Enter Number of Elements : ");
        n=sc.nextInt();
        Integer arr[] = new Integer[n];
        for(int i=0;i<n;i++)
        {
            System.out.println("Enter Element "+(i+1));
            arr[i]=sc.nextInt();
        }
        System.out.println("Enter Elements to Swap");
        int el1=sc.nextInt();
        int el2=sc.nextInt();
        swap(arr, el1, el2);
        System.out.println();
        for(int i=0;i<n;i++)
        {
            System.out.print(arr[i]+" ");
        }
    }
}