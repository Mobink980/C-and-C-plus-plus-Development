#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <iostream>


struct DateStruct
{
    int year {};
    int month {};
    int day {};
};

void print(const DateStruct& date)
{
    std::cout << date.year << '/' << date.month << '/' << date.day << '\n';
}

//In the world of object-oriented programming, we often want our types to 
//not only hold data, but provide functions that work with the data as well. 
//In C++, this is typically done via the class keyword. The class keyword 
//defines a new user-defined type called a class.


//Best practice: Name your classes starting with a capital letter.
class DateClass
{
    //Just like a struct declaration, a class declaration does not allocate 
    //any memory. It only defines what the class looks like.
public: 
    int m_year {};
    int m_month {};
    int m_day {};

    void print() // defines a member function named print()
    {
        std::cout << m_year << '/' << m_month << '/' << m_day << '\n';
    }

}; // class ends with semicolon


class Employee
{
public: // note use of public keyword here, and the colon (else, the members couldn't be accessed from main())
    std::string m_name {};
    int m_id {};
    double m_wage {};

    // Print employee information to the screen
    void print()
    {
        std::cout << "Name: " << m_name <<
                "  Id: " << m_id <<
                "  Wage: $" << m_wage << '\n';
    }
};

//Note that since classes are types, it’s possible to nest 
//classes inside other classes -- this is uncommon and is 
//typically only done by advanced programmers.

//Best practice: Use the struct keyword for data-only structures. 
//Use the class keyword for objects that have both data and functions.

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  Access specifiers  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Public members are members of a struct or class that can be accessed directly by anyone, 
//including from code that exists outside the struct or class.

//By default, all members of a class are private. Private members are members of a class 
//that can only be accessed by other members of the class (not by the public).

//Protected, works much like private does. We will discuss the difference between the 
//private and protected access specifier when we cover inheritance.

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  RULE  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Make member variables private, and member functions public, unless you have a good reason not to.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

class FriendClass // members are private by default
{
    int m_id {}; // private by default, can only be accessed by other members
    std::string m_name {}; // private by default, can only be accessed by other members
    std::string m_phone {}; // private by default, can only be accessed by other members
    std::string m_email {}; // private by default, can only be accessed by other members

public:
    void setFriend(int id, std::string name, std::string phone, std::string email) // public, can be accessed by anyone
    {
        // setDate() can access the private members of the class because it is a member of the class itself
        m_id = id;
        m_name = name;
        m_phone = phone;
        m_email = email;
    }

    void print() // public, can be accessed by anyone
    {
        std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << '\n';
        std::cout << "ID: " << m_id << '\n';
        std::cout << "Name: " << m_name << '\n';
        std::cout << "Phone: " << m_phone << '\n';
        std::cout << "Email: " << m_email << '\n';
        std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << '\n';
    }
};


int main()
{
    DateStruct today { 2020, 10, 14 }; // use uniform initialization

    today.day = 16; // use member selection operator to select a member of the struct
    print(today);

    DateClass myday { 1998, 02, 17 };

    myday.m_day = 19; // use member selection operator to select a member variable of the class
    myday.print(); // use member selection operator to call a member function of the class


    // Declare two employees
    Employee jax { "Jaxon", 1, 250.00 };
    Employee jacqui { "jacqueline", 2, 225.25 };

    // Print out the employee information
    jax.print();
    jacqui.print();


    //It turns out that the C++ standard library is full of classes that have been 
    //created for your benefit. std::string, std::vector, and std::array are all 
    //class types! So when you create an object of any of these types, you’re 
    //instantiating a class object. And when you call a function using these objects, 
    //you’re calling a member function.

    std::string s { "Hello, world!" }; // instantiate a string class object
    std::array<int, 3> a { 1, 2, 3 }; // instantiate an array class object
    std::vector<double> v { 1.1, 2.2, 3.3 }; // instantiate a vector class object

    std::cout << "length: " << s.length() << '\n'; // call a member function
    std::cout << "capacity: " << a.size() << '\n'; // call a member function

    //#########################################################################
    FriendClass clara;
    clara.setFriend(10, "Clara Watson", "202040403030", "cwatson@industryfour.com"); // okay, because setDate() is public
    clara.print(); // okay, because print() is public

    FriendClass cassie;
    clara.setFriend(20, "Cassie Kobayashi", "20215231030", "koba98@industryfour.com"); // okay, because setDate() is public
    clara.print(); // okay, because print() is public

    return 0;
}