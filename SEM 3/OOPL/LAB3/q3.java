import java.util.Scanner;
class Mixer
{
    int arr[];
    void accept(int length)
    {
        int i,j,temp;
        arr=new int[length];
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter array elements ");
        for(i=0;i<length;i++)
        {
            arr[i]=sc.nextInt();
        }
    }
    void display(int length)
    {
        System.out.println("Array elements are ");
        for(int i=0;i<length;i++)
        {
            System.out.print(arr[i]+" ");
            System.out.println();
        }
    }
    Mixer mix(Mixer A)
    {
        Mixer res = new Mixer();
        int totlen = arr.length + A.arr.length;
        res.arr = new int[totlen];
        for(int i=0;i<totlen;i++)
        {
            if(i>=0&&i<arr.length)
            {
                res.arr[i]=arr[i];
            }
            else if(i>=arr.length&&i<totlen)
            {
                res.arr[i]=A.arr[i-arr.length];
            }
        }
        return res;
    }
}
class q3
{
    public static void main(String args[])
    {
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter array1 size : ");
        int n=sc.nextInt();
        Mixer a1 = new Mixer();
        System.out.println("Enter array2 size : ");
        int m=sc.nextInt();
        Mixer a2 = new Mixer();
        a1.accept(n);
        a2.accept(m);
        a1.display(n);
        a2.display(m);
        int l=m+n;
        Mixer res = new Mixer();
        res=a1.mix(a2);
        res.display(l);
    }
}