class Student
{
    int rollnum , mark1,mark2;
    void GetNumber(int rollnum)
    {
        this.rollnum = rollnum;
    }
    void PutNumber()
    {
        System.out.println("Roll Number : "+rollnum);
    }
    void GetMarks(int mark1,int mark2)
    {
        this.mark1 = mark1;
        this.mark2 = mark2;
    }
    void PutMarks()
    {
        System.out.println("Mark1 : "+mark1+"\nMark2 : "+mark2);
    }

}
interface Sports
{
    double sportgrade = 9.0;
    void PutGrade();
}
class Result extends Student implements Sports
{
    double finalgrade;
    public void PutGrade()
    {
        finalgrade = ((mark1/10) + (mark2/10) + sportgrade)/3;
        System.out.println("Grade is "+finalgrade); 
    }
}
class q4
{
    public static void main(String[] args)
    {
        Result r1 = new Result();
        r1.GetNumber(368);
        r1.PutNumber();
        r1.GetMarks(50, 70);
        r1.PutMarks();
        r1.PutGrade();
    }
}