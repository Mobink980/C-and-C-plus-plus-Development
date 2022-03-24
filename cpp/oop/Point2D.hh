#ifndef POINT2D_HH
#define POINT2D_HH

#include <iostream>

//In this example, we are going to create a creature class 
//that uses a point class to hold the creature’s location.

//First, let’s design the point class. Our creature is going to 
//live in a 2d world, so our point class will have 2 dimensions, 
//X and Y. We will assume the world is made up of discrete squares, 
//so these dimensions will always be integers.


class Point2D
{
private:
    int m_x;
    int m_y;

public:
    // A default constructor
    Point2D()
        : m_x{ 0 }, m_y{ 0 }
    {
    }

    // A specific constructor
    Point2D(int x, int y)
        : m_x{ x }, m_y{ y }
    {
    }

    // An overloaded output operator
    friend std::ostream& operator<<(std::ostream& out, const Point2D& point)
    {
        out << '(' << point.m_x << ", " << point.m_y << ')';
        return out;
    }

    // Access functions
    void setPoint(int x, int y)
    {
        m_x = x;
        m_y = y;
    }

};

//This Point2d class is a composition of its parts: location values x and y are 
//part-of Point2D, and their lifespan is tied to that of a given Point2D instance.

#endif





