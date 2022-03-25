#include <string>
#include <iostream>
#include <vector>
#include <functional> // reference_wrapper

//In this file we investigate the order of construction when using inheritance.


class Base
{
public:
    int m_id {};

    Base(int id=0)
        : m_id(id)
    {
        std::cout << "Base\n";
    }

    int getId() const { return m_id; }
};


class Derived: public Base
{
public:
    double m_cost {};

    Derived(double cost=0.0)
        : m_cost(cost)
    {
        std::cout << "Derived\n";
    }

    double getCost() const { return m_cost; }
};



//Because Derived inherits functions and variables from Base, you may assume 
//that the members of Base are copied into Derived. However, this is not true. 
//Instead, we can consider Derived as a two part class: one part Derived, and 
//one part Base.


//Base is a non-derived class because it does not inherit from any other classes. 
//C++ allocates memory for Base, then calls Base’s default constructor to do the 
//initialization.

//Now let’s take a look at what happens when we instantiate a derived class:
//===========================================================================
//As mentioned above, Derived is really two parts: a Base part, 
//and a Derived part. When C++ constructs derived objects, it 
//does so in phases. First, the most-base class (at the top of 
//the inheritance tree) is constructed first. Then each child 
//class is constructed in order, until the most-child class 
//(at the bottom of the inheritance tree) is constructed last.


//Another example:
class A
{
public:
    A()
    {
        std::cout << "A\n";
    }
};

class B: public A
{
public:
    B()
    {
        std::cout << "B\n";
    }
};

class C: public B
{
public:
    C()
    {
        std::cout << "C\n";
    }
};

class D: public C
{
public:
    D()
    {
        std::cout << "D\n";
    }
};


int main()
{
    std::cout << "Instantiating Base\n";
    Base base;

    std::cout << "Instantiating Derived\n";
    Derived derived;

    //*************************************************
    std::cout << "Constructing A: \n";
    A a;

    std::cout << "Constructing B: \n";
    B b;

    std::cout << "Constructing C: \n";
    C c;

    std::cout << "Constructing D: \n";
    D d;

    return 0;
}

