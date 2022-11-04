package com.course.structure;

public class building
{
    private int sqfoot;
    private int floors;
    public void set(int sqfoot,int floors)
    {
        this.sqfoot=sqfoot;
        this.floors=floors;
    }
    public void get()
    {
        System.out.println("Square Foot : "+sqfoot+" Floors : "+floors);
    }
}