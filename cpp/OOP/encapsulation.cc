#include <iostream>
#include <string>

//This separation of interface and implementation is extremely useful 
//because it allows us to use objects without understanding how they work. 
//This vastly reduces the complexity of using these objects, and increases 
//the number of objects we’re capable of interacting with.

//The primary benefit is that encapsulation allows us to use a class without 
//having to know how it was implemented. This makes it a lot easier to use 
//classes we’re not familiar with.



//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  ENCAPSULATION  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//In object-oriented programming, Encapsulation (also called information hiding) is the process of 
//keeping the details about how an object is implemented hidden away from users of the object. 
//Instead, users of the object access the object through a public interface. In this way, users are 
//able to use the object without having to understand how it is implemented.

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//In C++, we implement encapsulation via access specifiers. Typically, all member variables of the class 
//are made private (hiding the implementation details), and most member functions are made public (exposing 
//an interface for the user). Although requiring users of the class to use the public interface may seem 
//more burdensome than providing public access to the member variables directly, doing so actually provides 
//a large number of useful benefits that help encourage class re-usability and maintainability.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// class Something
// {
// private:
//     int m_value1;
//     int m_value2;
//     int m_value3;

// public:
//     void setValue1(int value) { m_value1 = value; }
//     int getValue1() { return m_value1; }
// };

class Something
{
private:
    int m_value[3]; // note: we changed the implementation of this class!

public:
    // We have to update any member functions to reflect the new implementation
    void setValue1(int value) { m_value[0] = value; }
    int getValue1() { return m_value[0]; }
};


//An access function is a short public function whose job is to retrieve 
//or change the value of a private member variable.
class MyString
{
private:
    char* m_string; // we'll dynamically allocate our string here
    int m_length; // we need to keep track of the string length

public:
    int getLength() { return m_length; } // access function to get value of m_length
};


class Date
{
private:
    int m_month;
    int m_day;
    int m_year;

public:
    //Access functions typically come in two flavors: getters and setters. 
    int getMonth() { return m_month; } // getter for month
    void setMonth(int month) { m_month = month; } // setter for month

    int getDay() { return m_day; } // getter for day
    void setDay(int day) { m_day = day; } // setter for day

    int getYear() { return m_year; } // getter for year
    void setYear(int year) { m_year = year; } // setter for year
};


//A getter that returns a non-const reference would allow the caller to modify the 
//actual object being referenced, which violates the read-only nature of the getter 
//(and violates encapsulation).

//=====================================================================================================
//=========================================== BEST PRACTICE ===========================================
//=====================================================================================================
//Some developers would argue that use of access functions violates good OOP class design.

//If nobody outside your class needs to access a member, don’t provide access functions for that member.

//If someone outside your class needs to access a member, think about whether you can expose a 
//behavior or action instead (e.g. rather than a setAlive(bool) setter, implement a kill() 
//function instead).

//If you can't, consider whether you can provide only a getter.
//=====================================================================================================

class Foo
{
private:
    int m_value{ 4 };

public:
    int& getValue() { return m_value; } // returns a non-const reference
};



int main()
{   // our program works fine with both class implementations (magic of encapsulation)!
    Something something;
    something.setValue1(5);
    std::cout << something.getValue1() << '\n';

    Date my_date;
    my_date.setMonth(2);
    my_date.setDay(19);
    my_date.setYear(1998);

    std::cout << "I was born in " << my_date.getYear() << '/' << my_date.getMonth() 
    << '/' << my_date.getDay() <<" in a rainy day.\n";

    

    Foo f;                     // f.m_value is initialized to 4
    f.getValue() = 200;          // use the non-const reference to assign value 5 to m_value
    std::cout << f.getValue() << '\n'; // prints 5

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  RULE  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //Getters should return by value or const reference.
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    

    return 0;
}