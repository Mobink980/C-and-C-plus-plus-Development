#ifndef CREATURE_HH
#define CREATURE_HH

#include <iostream>
#include <string>
#include "Point2D.hh"


//Now let’s design our Creature. Our Creature is going to have a few properties: 
//a name, which will be a string, and a location, which will be our Point2D class.

class Creature
{
private:
    std::string m_name;
    Point2D m_location;

public:
    Creature(const std::string& name, const Point2D& location)
        : m_name{ name }, m_location{ location }
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const Creature& creature)
    {
        out << creature.m_name << " is at " << creature.m_location;
        return out;
    }

    void moveTo(int x, int y)
    {
        m_location.setPoint(x, y);
    }
};

//This Creature is also a composition of its parts. The creature’s name and location 
//have one parent, and their lifetime is tied to that of the Creature they are part of.


#endif