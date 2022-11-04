package myPackages.p1;

public class Maximum
{
    public static int max(int a,int b,int c)
    {
        int large = a>b?(a>c?a:c):(b>c?b:c);
        return large;
    }
    public static double max(double a,double b,double c)
    {
        double large = a>b?(a>c?a:c):(b>c?b:c);
        return large;
    }
    public static int max(int[] arr)
    {
        int large = arr[0];
        for(int i=1;i<arr.length;i++)
        {
            if(large<arr[i])
            {
                large=arr[i];
            }
        }
        return large;
    }
    public static int max(int[][] arr)
    {
        int large = arr[0][0];
        for(int i=0;i<arr.length;i++)
        {
            for(int j=0;j<arr[i].length;j++)
            {
                if(large<arr[i][j])
                {
                    large=arr[i][j];
                }
            }
        }
        return large;
    }
}