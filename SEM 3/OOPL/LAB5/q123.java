import java.util.*;
class Student
{
	public static final Scanner sc = new Scanner(System.in);
	int reg_no;
	String f_name;
	GregorianCalendar cal;
	int semester;
	double gpa,cgpa;
	static int count=0;
	Student()
	{
		count++;
		reg_no=1450;
		f_name="TDL";
		cal = new GregorianCalendar(2003,9,25);
		semester=3;
		gpa=9.4;
		cgpa=8.7;
	}
	Student(String name,GregorianCalendar cal,int sem,double gpaa,double cgpaa)
	{
		count++;
		f_name=name;
		this.cal = cal;
		semester=sem;
		gpa=gpaa;
		cgpa=cgpaa;
		reg_no=(cal.get(Calendar.YEAR)%100)*100 + Integer.valueOf(String.format("%02d",count));
	}
	void Display()
	{
		System.out.println("Name : "+f_name+" Reg Num : "+reg_no+" DOJ : "+cal.get(Calendar.DATE)+"/"+cal.get(Calendar.MONTH)+"/"+cal.get(Calendar.YEAR)+" "+"Semester : "+semester+" GPA : "+gpa+" CGPA : "+cgpa);	
	}
	static void sort(Student s[])
	{
		System.out.println("Enter your choice \n 1) Sort by name \t 2) Sort by Sem and CGPA");
		int choice = sc.nextInt();
		Student temp;
		switch(choice)
		{
			case 1:
			{
				for(int i=0;i<s.length;i++)
				{
					for(int j=0;j<s.length-i-1;j++)
					{
						if(s[j].f_name.compareTo(s[j+1].f_name)>0)
						{
							temp=s[j];
							s[j]=s[j+1];
							s[j+1]=temp;
						}
					}
				}
				break;
			}
			case 2:
			{
				for(int i=0;i<s.length;i++)
				{
					for(int j=0;j<s.length-i-1;j++)
					{
						if(s[j].semester>s[j+1].semester)
						{
							temp=s[j];
							s[j]=s[j+1];
							s[j+1]=temp;
						}
						else if(s[j].semester==s[j+1].semester)
						{
							if(s[j].cgpa>s[j+1].cgpa)
							{
								temp=s[j];
								s[j]=s[j+1];
								s[j+1]=temp;
							}
						}
					}
				}
				break;
			}
			default:
			{
				System.out.println("Invalid Case");
				break;
			}
		}

	}
	static void list1(Student s[])
	{
		System.out.println("Enter the starting letter");
		char character = sc.next().charAt(0);
		for(int i=0;i<s.length;i++)
		{
			if(s[i].f_name.charAt(0)==character)
			{
				System.out.println(s[i].f_name);
			}
		}
	}
	static void list2(Student s[])
	{
		System.out.println("Enter Substring to match ");
		String substring = sc.next();
		for(int i=0;i<s.length;i++)
		{
			if(s[i].f_name.contains(substring))
			{
				System.out.println(s[i].f_name);
			}
		}
	}
	static String manipulateName(String str)
	{
        int len = str.length();
        str = str.trim();
        String t = "";
        for (int i = 0; i < len; i++)
		{
            char ch = str.charAt(i);
            if (ch != ' ')
			{
                t = t + ch;
            }
            else
			{
                System.out.print(Character.toUpperCase(t.charAt(0))+ ". ");
                t = "";
            }
        }
        String temp = "";
        for (int j = 0; j < t.length(); j++)
		{
            if (j == 0)
			{
                temp = temp + Character.toUpperCase(t.charAt(0));
			}
            else
			{
                temp = temp + Character.toLowerCase(t.charAt(j));
			}
        }
        return temp;
    }
}
class q123
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
			s[i].Display();
		}
		Student.sort(s);
		for(int i=0;i<n;i++)
		{
			s[i].Display();
		}
		Student.list1(s);
		Student.list2(s);
		for(int i=0;i<n;i++)
		{
			s[i].f_name = Student.manipulateName(s[i].f_name);
			System.out.println(s[i].f_name);
		}
	}
}