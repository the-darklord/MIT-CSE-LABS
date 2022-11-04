import com.course.structure.*;
class q1
{
    public static void main(String[] args)
    {
        building b1 = new building();
        house h1 = new house();
        school s1 = new school();
        b1.set(5000,3);
        h1.set(5,6);
        s1.set(5, "elementary");
        b1.get();
        h1.get();
        s1.get();
    }
}