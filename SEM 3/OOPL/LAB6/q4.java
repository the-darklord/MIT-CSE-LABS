import java.util.*;
// Code not completed
interface Student
{
    Scanner sc = new Scanner(System.in);
    String name = sc.next();
    int id = sc.nextInt();
}
interface Sports extends Student
{
    int s_grade = sc.nextInt();
}
interface Exam extends Student
{
    int e_grade = sc.nextInt();
}
class Results implements Sports,Exam
{
    String s = name + " " + Integer.toString(id) + " " + Integer.toString(s_grade) + " " + Integer.toString(e_grade);
    void display()
    {
        System.out.println(s);
    }
}
class q4
{
    public static void main(String[] args)
    {
        Results r1 = new Results();
        r1.display();
    }
}