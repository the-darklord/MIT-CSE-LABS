package com.course.structure;

public class school extends building
{
    private int classrooms;
    private String gradelevel;
    public void set(int classrooms,String gradelevel)
    {
        this.classrooms=classrooms;
        this.gradelevel=gradelevel;
    }
    public void get()
    {
        System.out.println("Class Rooms : "+classrooms+" Grade Level : "+gradelevel);
    }
}