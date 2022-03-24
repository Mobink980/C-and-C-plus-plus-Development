#include "Date.hh"
#include <iostream>

// Date constructor
Date::Date(int year, int month, int day) : m_year{ year }, m_month{ month }, m_day{ day }
{
    SetDate(year, month, day); //not needed (cause of member init list), but just to show that it is possible
}

// Date member function
void Date::SetDate(int year, int month, int day)
{
    m_month = month;
    m_day = day;
    m_year = year;
}

//**********************************************************************************************************************
//Now any other header or code file that wants to use the Date class can simply #include "Date.hh". Note that 
//Date.cc also needs to be compiled into any project that uses Date.hh so the linker knows how Date is implemented.
//**********************************************************************************************************************

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Defining a class in a header file shouldn't violate the one-definition rule. If your header file has proper 
//header guards, it shouldn’t be possible to include the class definition more than once into the same file.

//Member functions defined inside the class definition are considered implicitly inline. Inline functions are 
//exempt from the one definition per program part of the one-definition rule. This means there is no problem 
//defining trivial member functions (such as access functions) inside the class definition itself.

//We recommend the following:
//*For classes used in only one file that aren’t generally reusable, define them directly in the 
//  single .cpp file they’re used in.
//*For classes used in multiple files, or intended for general reuse, define them in a .h file that 
//  has the same name as the class.
//*Trivial member functions (trivial constructors or destructors, access functions, etc…) can be 
//  defined inside the class.
//*Non-trivial member functions should be defined in a .cpp file that has the same name as the class.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//In real projects, it is much more common for classes to be put in their own code and header files, and you 
//should get used to doing so.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

class Something
{
public:
    int m_value {};

    Something(): m_value{0} { }

    void resetValue() { m_value = 0; }
    void setValue(int value) { m_value = value; }

    int getValue() const; // note addition of const keyword here

    //void resetValue() const { m_value = 0; } // compile error, const functions can't change member variables.
};

int Something::getValue() const // and here
{
    return m_value;
}

int main()
{

    Date my_date{2019, 1, 1};
    std::cout << my_date.getYear() << '/' << my_date.getMonth() << '/' << my_date.getDay() <<'\n';
    my_date.SetDate(2020, 2, 2);
    std::cout << my_date.getYear() << '/' << my_date.getMonth() << '/' << my_date.getDay() << '\n';

    //Instantiated class objects can also be made const by 
    //using the const keyword. Initialization is done via 
    //class constructors.
    const Date date3 { 2020, 10, 16 }; // initialize using parameterized constructor (C++11)

    //**********************************************************************************************************************
    //Best Practice: Make any member function that does not modify the state of the class object const, so that 
    //it can be called by const objects.
    //**********************************************************************************************************************
    const Something something;
    std::cout << something.getValue() << '\n'; //can be called by const objects

    //Because passing objects by const reference is common, your classes should 
    //be const-friendly. That means making any member function that does not modify 
    //the state of the class object const!

    return 0;
}