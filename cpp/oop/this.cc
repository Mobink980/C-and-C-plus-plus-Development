#include <iostream>


//**********************************************************************************************************
//“When a member function is called, how does C++ keep track of which object it was called on?”. 
//The answer is that C++ utilizes a hidden pointer named “this”!
//The this pointer is a hidden const pointer that holds the address of the object the 
//member function was called on.
//It’s worth noting that “this” is a const pointer -- you can change the value of the underlying object 
//it points to, but you can not make it point to something else!
//**********************************************************************************************************

class Simple
{
private:
    int m_id;

public:
    Simple(int id)
        : m_id{ id }
    {
    }

    void setID(int id) { m_id = id; }
    int getID() { return m_id; }
};


//**********************************************************************************************************
//Most of the time, you never need to explicitly reference the “this” pointer. However, there are a few 
//occasions where doing so can be useful:
//First, if you have a constructor (or member function) that has a parameter with the same name as a 
//member variable, you can disambiguate them by using “this”.
//Although this is acceptable coding practice, we find using the “m_” prefix on all member variable 
//names provides a better solution by preventing duplicate names altogether!
//**********************************************************************************************************
//Some developers prefer to explicitly add this-> to all class members. We recommend that you avoid 
//doing so, as it tends to make your code less readable for little benefit. Using the m_ prefix is a 
//more readable way to differentiate member variables from non-member (local) variables.
//**********************************************************************************************************
class Something
{
private:
    int data;

public:

    // Something(int data)
    // {
    //     this->data = data; // this->data is the member, data is the local parameter
    // }

    // Better practice is to use the m_ prefix on all member variables 
    //and use member initialization list instead of assignment.
    Something(int data): data{ data } //initializing using member initialization list
    {
        
    }

    int getSome() { return this->data; }
};


//**********************************************************************************************************
//Second, it can sometimes be useful to have a class member function return the object it was working with 
//as a return value. The primary reason to do this is to allow a series of member functions to be “chained” 
//together, so several member functions can be called on the same object! 
// e.g., std::cout << "Hello, " << userName;
//In this case, std::cout is an object, and operator<< is a member function that operates on that object. 
//The compiler evaluates the above snippet like this:
//(std::cout << "Hello, ") << userName;
//**********************************************************************************************************

//Another example
class Calc
{
private:
    int m_value{};

public:
    // void add(int value) { m_value += value; }
    // void sub(int value) { m_value -= value; }
    // void mult(int value) { m_value *= value; }

    //========================= Making our functions chainable =========================
    //*this, is just a reference to calc, so calc will be the object used in the subsequent evaluation.  
    // this = &calc (address of object calc) ==> *this = calc (*this is like object calc itself, a reference to it) 
    // return type is Calc&, which means it returns a reference of a Calc object.
    Calc& add(int value) { m_value += value; return *this; }
    Calc& sub(int value) { m_value -= value; return *this; }
    Calc& mult(int value) { m_value *= value; return *this; }

    int getValue() { return m_value; }
};


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// As classes get longer and more complicated, having all the member function definitions inside the 
//class can make the class harder to manage and work with. Using an already-written class only requires 
//understanding its public interface (the public member functions), not how the class works underneath 
//the hood. The member function implementation details just get in the way.

//Fortunately, C++ provides a way to separate the “declaration” portion of the class from the 
//“implementation” portion. This is done by defining the class member functions outside of the 
//class definition. To do so, simply define the member functions of the class as if they were 
//normal functions, but prefix the class name to the function using the scope resolution operator 
//(::) (same as for a namespace).
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

class Date
{
private:
    int m_year;
    int m_month;
    int m_day;

public:
    Date(int year, int month, int day);

    void SetDate(int year, int month, int day);

    int getYear() { return m_year; }
    int getMonth() { return m_month; }
    int getDay()  { return m_day; }
};

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




int main()
{
    Simple simple{1};
    simple.setID(2);
    std::cout << simple.getID() << '\n';

    //Somehow, when we call simple.setID(2);, C++ knows that 
    //function setID() should operate on object simple, and 
    //that m_id actually refers to simple.m_id. 

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //This is what happens:

    //When the compiler compiles a normal member function, it implicitly adds a new parameter to the 
    //function named “this”. The this pointer is a hidden const pointer that holds the address of the 
    //object the member function was called on (in our case simple is the object and its address becomes
    // this = &simple).

    //simple.setID(2); ==> 
    //setID(&simple, 2); // note that simple has been changed from an object prefix to a function argument!


    //There’s just one more detail to take care of. Inside the member function, any class members 
    //(functions and variables) also need to be updated so they refer to the object the member 
    //function was called on. This is easily done by adding a “this->” prefix to each of them. Thus, 
    //in the body of function setID(), m_id (which is a class member variable) has been converted to 
    //this->m_id. Thus, when “this” points to the address of simple, this->m_id will resolve to simple.m_id.

    //void setID(int id) { m_id = id; } ==>
    //void setID(Simple* const this, int id) { this->m_id = id; }
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //All you need to remember is that all normal member functions have a “this” pointer that refers to the 
    //object the function was called on.
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    //“this” always points to the object being operated on
    Simple A{1}; // this = &A inside the Simple constructor
    Simple B{2}; // this = &B inside the Simple constructor
    A.setID(3); // this = &A inside member function setID
    B.setID(4); // this = &B inside member function setID
    std::cout << A.getID() << "!=" << B.getID() << '\n';

    Something some{40};
    std::cout << some.getSome() << '\n';

    Calc calc{};
    calc.add(5).sub(3).mult(4).mult(10);
    std::cout << calc.getValue() << '\n';

    Date my_date{2019, 1, 1};
    std::cout << my_date.getYear() << '/' << my_date.getMonth() << '/' << my_date.getDay() <<'\n';
    my_date.SetDate(2020, 2, 2);
    std::cout << my_date.getYear() << '/' << my_date.getMonth() << '/' << my_date.getDay() << '\n';
    

    return 0;
}