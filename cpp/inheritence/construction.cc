#include <string>
#include <iostream>

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


// class Derived: public Base
// {
// public:
//     double m_cost {};
//     //Shortcoming: There is no way to initialize m_id when we create a Derived object.
//     Derived(double cost=0.0)
//         : m_cost(cost)
//     {
//         std::cout << "Derived\n";
//     }

//     double getCost() const { return m_cost; }
// };



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

//*********************************************************************************************
//C++ prevents classes from initializing inherited member variables in the member initializer 
//list of a constructor. In other words, the value of a member variable can only be set in a 
//member initializer list of a constructor belonging to the same class as the variable.
// (m_id cannot be set in the member initializer list of the Derived constructor.)
//By restricting the initialization of variables to the constructor of the class those 
//variables belong to, C++ ensures that all variables are initialized only once.
//*********************************************************************************************
//Fortunately, C++ gives us the ability to explicitly choose which Base class constructor 
//will be called! To do this, simply add a call to the base class Constructor in the member 
//initializer list of the derived class:
//*********************************************************************************************
class Derived: public Base
{
public:
    double m_cost {};

    Derived(double cost=0.0, int id=0)
        : Base{ id } // Call Base(int) constructor with value id!
        , m_cost{ cost }
    {
        std::cout << "Derived\n";
    }

    double getCost() const { return m_cost; }
};

//The base class constructor Base(int) will be used to initialize m_id to 5, and the 
//derived class constructor will be used to initialize m_cost to 1.3!
//All that’s happening is that the Derived constructor is calling a specific Base 
//constructor to initialize the Base portion of the object. Because m_id lives in the 
//Base portion of the object, the Base constructor is the only constructor that can 
//initialize that value.

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

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

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Now that you know how to initialize base class members, there’s no need to keep our member variables public. 
//We make our member variables private again, as they should be.
//As a quick refresher, public members can be accessed by anybody. Private members can only be accessed by 
//member functions of the same class. Note that this means derived classes can not access private members of 
//the base class directly! Derived classes will need to use access functions to access private members of the 
//base class.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//Because it makes sense to give our BaseballPlayer a name and age when we create them, 
//we should modify this constructor to add those parameters. Here’s our updated classes 
//that use private members, with the BaseballPlayer class calling the appropriate Person 
//constructor to initialize the inherited Person member variables:

class Person
{
private:
    std::string m_name;
    int m_age {};

public:
    Person(const std::string& name = "", int age = 0)
        : m_name{ name }, m_age{ age }
    {
    }

    const std::string& getName() const { return m_name; }
    int getAge() const { return m_age; }

};
// BaseballPlayer publicly inheriting Person
class BaseballPlayer : public Person
{
private:
    double m_battingAverage {};
    int m_homeRuns {};

public:
    BaseballPlayer(const std::string& name = "", int age = 0,
        double battingAverage = 0.0, int homeRuns = 0)
        : Person{ name, age } // call Person(const std::string&, int) to initialize these fields
        , m_battingAverage{ battingAverage }, m_homeRuns{ homeRuns }
    {
    }

    double getBattingAverage() const { return m_battingAverage; }
    int getHomeRuns() const { return m_homeRuns; }
};


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  NOTES  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//It is worth mentioning that constructors can only call constructors from their immediate parent/base class. 
//Consequently, the C constructor could not call or pass parameters to the A constructor directly. The C 
//constructor can only call the B constructor (which has the responsibility of calling the A constructor).

//Destructors: When a derived class is destroyed, each destructor is called in the reverse order of construction. 
//In the above example, when c is destroyed, the C destructor is called first, then the B destructor, then 
//the A destructor.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

int main()
{
    std::cout << "Instantiating Base\n";
    Base base;

    std::cout << "Instantiating Derived\n";
    Derived derived;

    //*************************************************
    std::cout << "==========================================================" << '\n';

    std::cout << "Constructing A: \n";
    A a;

    std::cout << "Constructing B: \n";
    B b;

    std::cout << "Constructing C: \n";
    C c;

    std::cout << "Constructing D: \n";
    D d;

    //*************************************************
    std::cout << "==========================================================" << '\n';

    Base base1{ 5 }; // use Base(int) constructor
    //Here’s what actually happens when base is instantiated:
    // 1. Memory for base is set aside
    // 2. The appropriate Base constructor is called
    // 3. The member initializer list initializes variables
    // 4. The body of the constructor executes
    // 5. Control is returned to the caller

    //This is pretty straightforward. With derived classes, things are slightly more complex:

    Derived derived1{ 1.3 }; // use Derived(double) constructor
    //Here’s what actually happens when derived is instantiated:
    // 1. Memory for derived is set aside (enough for both the Base and Derived portions)
    // 2. The appropriate Derived constructor is called
    // 3. The Base object is constructed first using the appropriate Base constructor. 
    //     If no base constructor is specified, the default constructor will be used.
    // 4. The member initializer list initializes variables
    // 5. The body of the constructor executes
    // 6. Control is returned to the caller

    //*************************************************
    std::cout << "==========================================================" << '\n';

    Derived derived2{ 1.3, 5 }; // use Derived(double, int) constructor
    std::cout << "Id: " << derived2.getId() << '\n';
    std::cout << "Cost: " << derived2.getCost() << '\n';


    //*************************************************
    std::cout << "==========================================================" << '\n';

    BaseballPlayer pedro{ "Pedro Cerrano", 32, 0.342, 42 };

    std::cout << "name: " << pedro.getName() << '\n';
    std::cout << "age: " << pedro.getAge() << '\n';
    std::cout << "homeruns: " << pedro.getHomeRuns() << '\n';

    return 0;
}

