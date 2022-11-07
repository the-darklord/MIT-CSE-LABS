import java.util.*;
import java.lang.*;
// code not completed
class Stack<T>
{
    ArrayList<T> arr;
    int tos=-1;
    int size;
    Stack(int size)
    {
        this.size=size;
        this.arr = new ArrayList<T>(size);
    }
    void push(T ele)
    {
        arr.add(ele);
        tos++;
    }
    T pop()
    {
        return arr.get(tos--);
    }
    void Display()
    {
        for(int i=0;i<=tos;i++){
            System.out.println(arr.get(i).toString());
        }
        System.out.println();
    }
}

class Student
{
    String name;
    int rollnum,grade;
    Student(String name,int rollnum,int grade)
    {
        this.name=name;
        this.rollnum=rollnum;
        this.grade=grade;
    }
    @Override
    public String toString()
    {
        String t = "Name : "+name+"\tRoll Num : "+rollnum+"\tGrade : "+grade;
        return t;
    }
}

class Employee
{
    String name;
    int empid;
    Employee(String name,int empid)
    {
        this.name=name;
        this.empid=empid;
    }
    @Override
    public String toString()
    {
        String t = "Name : "+name+"\tEmployee ID : "+empid;
        return t;
    }
}
class q2
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Size of Stack");
        int size = sc.nextInt();
        Stack<Student> s1 = new Stack<>(size);
        Stack<Employee> s2 = new Stack<>(size);
        Student ss=new Student("Mihir", 368, 9);
        Employee ee = new Employee("TDL", 57);
        s1.push(ss);
        s2.push(ee);
        s1.Display();
        s2.Display();
    }
}