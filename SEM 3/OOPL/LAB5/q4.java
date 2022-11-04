import java.util.*;
class q4
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter a number ");
        int num = sc.nextInt();
        String res = String.format("%,03d",num);
        System.out.println(res);
    }
}