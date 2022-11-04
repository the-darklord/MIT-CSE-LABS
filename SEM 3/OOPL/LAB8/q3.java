import java.util.*;
class SeatsFilledException extends Exception
{
    void Display()
    {
        System.out.println("Seats are filled");
    }
}
class Student
{
	public static final Scanner sc = new Scanner(System.in);
	int reg_no,finalregnum;
	String f_name;
	GregorianCalendar cal;
	int semester;
	double gpa,cgpa;
	static int count=0;
	Student(String name,GregorianCalendar cal,int sem,double gpaa,double cgpaa)
	{
		count+=10;
		f_name=name;
		this.cal = cal;
		semester=sem;
		gpa=gpaa;
		cgpa=cgpaa;
		reg_no=(cal.get(Calendar.YEAR)%100)*100 + Integer.valueOf(String.format("%02d",count));
        finalregnum=(cal.get(Calendar.YEAR)%100)*100 + Integer.valueOf(String.format("%02d",25));
	}
	void Display() throws SeatsFilledException
	{
        if(reg_no>finalregnum)
        {
            throw new SeatsFilledException();
        }
        else
        {
            System.out.println("Name : "+f_name+" Reg Num : "+reg_no+" DOJ : "+cal.get(Calendar.DATE)+"/"+cal.get(Calendar.MONTH)+"/"+cal.get(Calendar.YEAR)+" "+"Semester : "+semester+" GPA : "+gpa+" CGPA : "+cgpa);	
        }
	}
}
class q3
{
	public static void main(String args[])
	{
		System.out.println("Enter Number of Students : ");
		int n = Student.sc.nextInt();
		Student[] s=new Student[n];
		for(int i=0;i<n;i++)
		{
			int t=i+1;
			System.out.println("Enter Details of Student "+t);
			System.out.println("Enter Name");
			Student.sc.nextLine();
			String name=Student.sc.nextLine();
			System.out.println("Enter DOJ in YYYY MM DD");
			GregorianCalendar cal = new GregorianCalendar(Student.sc.nextInt(),Student.sc.nextInt(),Student.sc.nextInt());
			System.out.println("Enter Semester");
			int sem=Student.sc.nextInt();
			System.out.println("Enter GPA");
			double gpa=Student.sc.nextDouble();
			System.out.println("Enter CGPA");
			double cgpa=Student.sc.nextDouble();
			s[i] = new Student(name,cal,sem,gpa,cgpa);
		}
		for(int i=0;i<n;i++)
		{
            try
            {
                s[i].Display();
            }
            catch(SeatsFilledException s1)
            {
                s1.Display();
            }
	    }
    }
}