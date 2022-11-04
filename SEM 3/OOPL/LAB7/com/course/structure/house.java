package com.course.structure;

public class house extends building
{
    private int bedrooms;
    private int bathrooms;
    public void set(int bedrooms,int bathrooms)
    {
        this.bedrooms=bedrooms;
        this.bathrooms=bathrooms;
    }
    public void get()
    {
        System.out.println("Bed Rooms : "+bedrooms+" Bath Rooms : "+bathrooms);
    }
}