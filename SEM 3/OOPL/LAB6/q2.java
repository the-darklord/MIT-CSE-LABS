class building
{
    private int sqfoot;
    private int floors;
    void set(int sqfoot,int floors)
    {
        this.sqfoot=sqfoot;
        this.floors=floors;
    }
    void get()
    {
        System.out.println("Square Foot : "+sqfoot+" Floors : "+floors);
    }
}
class house extends building
{
    private int bedrooms;
    private int bathrooms;
    void set(int bedrooms,int bathrooms)
    {
        this.bedrooms=bedrooms;
        this.bathrooms=bathrooms;
    }
    void get()
    {
        System.out.println("Bed Rooms : "+bedrooms+" Bath Rooms : "+bathrooms);
    }
}
class school extends building
{
    private int classrooms;
    private String gradelevel;
    void set(int classrooms,String gradelevel)
    {
        this.classrooms=classrooms;
        this.gradelevel=gradelevel;
    }
    void get()
    {
        System.out.println("Class Rooms : "+classrooms+" Grade Level : "+gradelevel);
    }
}
class q2
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