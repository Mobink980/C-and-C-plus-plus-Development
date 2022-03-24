#include <string>
#include <iostream>
#include <cassert>

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  CONSTRUCTORS  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//A constructor is a special kind of class member function that is automatically called when an object 
//of that class is created. Constructors are typically used to initialize member variables of the class 
//to appropriate user-provided values, or to do any setup steps necessary for the class to be used 
//(e.g. open a file or database).
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Unlike normal member functions, constructors have specific rules for how they must be named:

// 1. Constructors must have the same name as the class (with the same capitalization)
// 2. Constructors have no return type (not even void)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


//A constructor that takes no parameters (or has parameters that all have default values) 
//is called a default constructor. The default constructor is called if no user-provided 
//initialization values are provided.
class Fraction
{
private:
    int m_numerator {};
    int m_denominator {};

public:
    Fraction() // default constructor
    {
        m_numerator = 0;
        m_denominator = 1;
    }

    //Fortunately, constructors can also be declared with parameters. 
    // Constructor with two parameters, one parameter having a default value
    Fraction(int numerator, int denominator=1)
    {
        assert(denominator != 0);
        m_numerator = numerator;
        m_denominator = denominator;
    }

    //##################################################################################################
    //Note that we now have two constructors: a default constructor that will be called in the default 
    //case, and a second constructor that takes two parameters. These two constructors can coexist 
    //peacefully in the same class due to function overloading. In fact, you can define as many 
    //constructors as you want, so long as each has a unique signature (number and type of parameters).
    //##################################################################################################
    // When implementing your constructors, consider how you might keep the number of 
    //constructors down through smart defaulting of values. The following can replace the two above:

    // // Default constructor
    // Fraction(int numerator=0, int denominator=1)
    // {
    //     assert(denominator != 0);

    //     m_numerator = numerator;
    //     m_denominator = denominator;
    // } 
    //##################################################################################################
    //If your class has no constructors, C++ will automatically generate a public default 
    //constructor for you. This is sometimes called an implicit constructor (or implicitly 
    //generated constructor). Assuming you haven’t provided a default constructor yourself, 
    //(only provided parametrized constructor) your objects will not be instantiable without 
    //arguments.
    //##################################################################################################


    int getNumerator() { return m_numerator; }
    int getDenominator() { return m_denominator; }
    double getValue() { return static_cast<double>(m_numerator) / m_denominator; }
};


class Date
{
private:
    int m_year{ 1900 };
    int m_month{ 1 };
    int m_day{ 1 };

public:
    // Tell the compiler to create a default constructor, even if
    // there are other user-provided constructors.
    Date() = default;

    Date(int year, int month, int day) // normal non-default constructor
    {
        m_year = year;
        m_month = month;
        m_day = day;
    }

public:
    //Access functions typically come in two flavors: getters and setters. 
    int getMonth() { return m_month; } // getter for month

    int getDay() { return m_day; } // getter for day

    int getYear() { return m_year; } // getter for year

};


//A class may contain other classes as member variables. By default, when the outer 
//class is constructed, the member variables will have their default constructors 
//called. This happens before the body of the constructor executes.
class A
{
public:
    A() { std::cout << "A\n"; }
};

class B
{
private:
    A m_a {}; // B contains A as a member variable

public:
    B() { std::cout << "B\n"; }
};


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Constructors actually serve two purposes. 
//First, constructors determine who is allowed to create an object. 
//That is, an object of a class can only be created if a matching constructor can be found.

//Second, constructors can be used to initialize objects. 
//Whether the constructor actually does an initialization is up to the programmer. 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


//=====================================================================================================
//=========================================== BEST PRACTICE ===========================================
//=====================================================================================================
//Much like it is a best practice to initialize all local variables, it’s also a best practice to 
//initialize all member variables on creation of the object. This can be done via a constructor or 
//via non-static member initialization. Always initialize all member variables in your objects.

//Finally, constructors are only intended to be used for initialization when the object is created. 
//You should not try to call a constructor to re-initialize an existing object. While it may compile, 
//the results will not be what you intended (instead, the compiler will create a temporary object 
//and then discard it).
//=====================================================================================================



//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  RULE  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Use member initializer lists to initialize your class member variables instead of assignment.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Member initializer lists allow us to initialize our members rather than assign values to them. 
//This is the only way to initialize members that require values upon initialization, such as 
//const or reference members, and it can be more performant than assigning values in the body 
//of the constructor. Member initializer lists work both with fundamental types and members 
//that are classes themselves.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
class Something
{
private:
    int m_value1 {};
    double m_value2 {};
    char m_value3 {};
    const int m_array[5];

public:
    Something(int value1, double value2, char value3='c')
        : m_value1{ value1 }, m_value2{ value2 }, m_value3{ value3 }, m_array {} // directly initialize our member variables
    {
    // No need for assignment here
    // m_value1 = 1;
    // m_value2 = 2.2;
    // m_value3 = 'c';
    }

    void print()
    {
         std::cout << "Something(" << m_value1 << ", " << m_value2 << ", " << m_value3 << ", " << m_array[2] <<")\n";
    }

};


class C
{
public:
    C(int x = 0) { std::cout << "C " << x << '\n'; }
};

class D
{
private:
    C m_c {};
public:
    D(int y)
        : m_c{ y - 1 } // call A(int) constructor to initialize member m_a
    {
        std::cout << "D " << y << '\n';
    }
};



//=====================================================================================================
//=========================================== BEST PRACTICE ===========================================
//=====================================================================================================
//For best results, the following recommendations should be observed:

//1. Don’t initialize member variables in such a way that they are dependent upon other 
//member variables being initialized first (in other words, ensure your member variables 
//will properly initialize even if the initialization ordering is different).

//2. Initialize variables in the initializer list in the same order in which they are declared 
//in your class. This isn’t strictly required so long as the prior recommendation has been 
//followed, but your compiler may give you a warning if you don’t do so and you have all 
//warnings turned on.
//=====================================================================================================



//Non-static member initialization (also called in-class member initializers) 
//provides default values for your member variables that your constructors will 
//use if the constructors do not provide initialization values for the members 
//themselves (via the member initialization list).
#include <iostream>

class Rectangle
{
private:
    double m_length{ 1.2 }; // m_length has a default value of 1.2
    double m_width{ 1.3 }; // m_width has a default value of 1.3

public:
    void print()
    {
        std::cout << "length: " << m_length << ", width: " << m_width << '\n';
    }
};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  RULE  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Favor use of non-static member initialization to give default values for your member variables.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Calling one constructor from another!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//Make sure you’re calling the constructor from the member initializer list, not in the body of the 
//constructor. Else, it will not work as you expect. What’s happens is that Foo(); instantiates a new 
//Foo object, which is immediately discarded, because it’s not stored in a variable.

// class Foo
// {
// public:
//     Foo()
//     {
//         // code to do A
//     }

//     Foo(int value)
//     {
//         Foo(); // use the above constructor to do A (doesn't work)
//         // code to do B
//     }
// };
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
class Employee
{
private:
    int m_id{};
    std::string m_name{};

public:
    Employee(int id=0, const std::string &name=""):
        m_id{ id }, m_name{ name }
    {
        std::cout << "Employee " << m_name << " created.\n";
    }

    // Use a delegating constructor to minimize redundant code
    Employee(const std::string &name) : Employee{ 0, name }
    { } //your constructors can delegate or initialize, but not both.
};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  Best Practice @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//If you have multiple constructors that have the same functionality, use delegating constructors 
//to avoid duplicate code (But ensure all of your constructors resolve to a non-delegating constructor
//to avoid an infinit loop of delegating constructors.)
//Or we can use a void function in our class and call it in the needed constructors (avoiding 
//redundant code).
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



int main()
{   
    //In this case, the default constructor will be called immediately after 
    //memory has been allocated and cleared for the object. The default 
    //constructor runs just like a normal function (assigning the values 
    //0 to m_numerator and 1 to m_denominator).

    Fraction frac{}; // calls Fraction() default constructor
    std::cout << frac.getNumerator() << '/' << frac.getDenominator() << " = " << frac.getValue() <<'\n';

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    // In the above program, we initialized our class object using value-initialization:
    // Fraction frac {}; // Value initialization using empty set of braces

    // We can also initialize class objects using default-initialization:
    // Fraction frac; // Default-initialization, calls default constructor
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //While you might be able to initialize all members in the classes you write, it’s not feasible to read the 
    //definitions of all classes you use to make sure they do the same.
    // Best practice: Favor list(value)-initialization over default-initialization for class objects.
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    // Fraction fiveThirds{ 5, 3 }; // List initialization, calls Fraction(int, int)
    // Fraction threeQuarters(3, 4); // Direct initialization, also calls Fraction(int, int)
    // Fraction six = Fraction{ 6 }; // Copy initialize a Fraction, will call Fraction(6, 1)
    // Fraction seven = 7;          // Copy initialize a Fraction.  The compiler will try to find a way 
    //                           //to convert 7 to a Fraction, which will invoke the Fraction(7, 1) constructor.
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    // Best practice: Favor brace initialization to initialize class objects 
    //(unless we have to use direct initialization). Avoid copy initialization.
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    Fraction fiveThirds{ 5, 3 };
    std::cout << fiveThirds.getNumerator() << '/' << fiveThirds.getDenominator() << " = " << fiveThirds.getValue() <<'\n';

    Date date{}; // date is initialized to Jan 1st, 1900
    Date today{ 1990, 10, 14 }; // today is initialized to Oct 14th, 2020

    std::cout << "Alice was born in " << today.getYear() << '/' << today.getMonth() 
    << '/' << today.getDay() <<" in Paris.\n";

    std::cout << "Her grandfather was born in " << date.getYear() << '/' << date.getMonth() 
    << '/' << date.getDay() <<" in Berlin.\n";

    B b; // calls B() default constructor

    Something something{ 1, 2.2 }; // value1 = 1, value2=2.2, value3 gets default value 'c'
    something.print();
    
    D d{ 5 }; // calls D(int) constructor

    Rectangle x{}; // x.m_length = 1.2, x.m_width = 1.3
    x.print();

    Employee emp {10, "John"}; 
    

    return 0;
}