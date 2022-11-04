import myPackages.p1.*;
class q2
{
    public static void main(String[] args)
    {
        int arr1[] = {5,9,2,10,6};
        int arr2[][] = {{1,2,3},{4,5,6}};
        int m = Maximum.max(5,9,2);
        double n = Maximum.max(55.23,999.123,22.2012);
        int p = Maximum.max(arr1);
        int q = Maximum.max(arr2);
        System.out.println(m+"\n"+n+"\n"+p+"\n"+q+"\n");
    }
}