import java.util.*;
class person
{
    private String name;
    private GregorianCalendar dob;
    person(String name,GregorianCalendar dob)
    {
        this.name=name;
        this.dob=dob;
    }
    String get1()
    {
        return name;
    }
    GregorianCalendar get2()
    {
        return dob;
    }
}
class college_graduate extends person
{
    private double cgpa;
    private int year;
    college_graduate(String name1,GregorianCalendar cal1,double cgpa,int year)
    {
        super(name1,cal1);
        this.cgpa=cgpa;
        this.year=year;
    }
    void display()
    {
        String s1=get1();
        GregorianCalendar cal = get2();
        System.out.println("Name : "+s1+" DOB : "+cal.get(Calendar.DATE)+"/"+cal.get(Calendar.MONTH)+"/"+cal.get(Calendar.YEAR)+" CGPA : "+cgpa+" Year : "+year);
    }
}
class q1
{
    public static void main(String[] args)
    {
        college_graduate cg1 = new college_graduate("MIHIR",new GregorianCalendar(2003,9,25),9.5,4);
        cg1.display();
    }
}
