#include <array>
#include <iostream>

//We learned that static variables keep their values and are not destroyed 
//even after they go out of scope. For example:
int generateID()
{
    static int s_id{ 0 };
    return ++s_id;
}

//**********************************************************************************************************
//C++ introduces two more uses for the static keyword when applied to classes: 
//static member variables, and static member functions. 
//Member variables of a class can be made static by using the static keyword. Unlike normal member 
//variables, static member variables are shared by all objects of the class. 
//It turns out that static members exist even if no objects of the class have been instantiated! 
//Much like global variables, they are created when the program starts, and destroyed when the program ends.
//Because s_value exists independently of any class objects (belong to the class itself), it can be 
//accessed directly using the class name and the scope resolution operator 
//(in this case, Something::s_value).
//**********************************************************************************************************

class Something
{
public:
    static int s_value;
};

//This line serves two purposes: it instantiates the static member 
//variable (just like a global variable), and optionally initializes it. 
//In this case, we’re providing the initialization value 1. 
//If no initializer is provided, C++ initializes the value to 0.
int Something::s_value{ 1 };

//**********************************************************************************************************
//Do not put the static member definition in a header file (much like a global variable, 
//if that header file gets included more than once, you’ll end up with multiple definitions, 
//which will cause a linker error).
//**********************************************************************************************************


//when the static member is a const integral type (which includes char and bool) or a const enum, 
//the static member can be initialized inside the class definition. Moreover, static constexpr 
//members can be initialized inside the class definition.
class Whatever
{
public:
    static const int st_value{ 4 }; // a static const int can be declared and initialized directly
    static constexpr double s_value{ 2.2 }; // ok
    static constexpr std::array<int, 3> s_array{ 1, 2, 3 }; // this even works for classes that support constexpr initialization
};


//**********************************************************************************************************
//If the static member variables are public, we can access them directly using the class name and the 
//scope resolution operator. But what if the static member variables are private? 
//Normally we access private members through public member functions. While we could create a normal public 
//member function to access s_value, we’d then need to instantiate an object of the class type to use the 
//function! We can do better. It turns out that we can also make functions static.
//Like static member variables, static member functions are not attached to any particular object. 
//**********************************************************************************************************

class Value
{
private:
    static int s_value;
public:
    static int getValue() { return s_value; } // static member function
};

int Value::s_value{ 1 }; // initializer


//**********************************************************************************************************
//Note that because all the data and functions in the following class are static, we don’t need to 
//instantiate an object of the class to make use of its functionality! This class utilizes a static 
//member variable to hold the value of the next ID to be assigned, and provides a static member function 
//to return that ID and increment it.
//**********************************************************************************************************
class IDGenerator
{
private:
    static int s_nextID; // Here's the declaration for a static member

public:
     static int getNextID(); // Here's the declaration for a static function
};

// Here's the definition of the static member outside the class.  Note we don't use the static keyword here.
// We'll start generating IDs at 1
int IDGenerator::s_nextID{ 1 };

// Here's the definition of the static function outside of the class.  Note we don't use the static keyword here.
int IDGenerator::getNextID() { return s_nextID++; }

//**********************************************************************************************************
//C++ does not support static constructors. If your static variable can be directly initialized, 
//no constructor is needed: you can initialize the static member variable at the point of definition 
//(even if it is private). We do this in the IDGenerator example above. 
//**********************************************************************************************************


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Two warnings about classes with all static members:
//First, because all static members are instantiated only once, there is no way to have multiple copies of 
//a pure static class (without cloning the class and renaming it). For example, if you needed two independent 
//IDGenerator objects, this would not be possible with a single pure static class.
//Second, because all of the members belong to the class (instead of object of the class), and class 
//declarations usually have global scope, a pure static class is essentially the equivalent of declaring 
//functions and global variables in a globally accessible namespace, with all the requisite downsides that 
//global variables have (any piece of code can change the value of the global variable and end up breaking 
//another piece of seemingly unrelated code).
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Best Practice: Classes can be created with all static member variables and static functions. However, 
//such classes are essentially the equivalent of declaring functions and global variables in a globally 
//accessible namespace, and should generally be avoided unless you have a particularly good reason to 
//use them.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


int main()
{
    std::cout << generateID() << '\n';
    std::cout << generateID() << '\n';
    std::cout << generateID() << '\n';

    Something first;
    Something second;
    first.s_value = 4;
    std::cout << first.s_value << '\n';
    std::cout << second.s_value << '\n';

    //Because s_value is a static member variable, s_value 
    //is shared between all objects of the class. Consequently, 
    //first.s_value is the same variable as second.s_value. 
    //The above program shows that the value we set using first 
    //can be accessed using second!

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //Best Practice: Access static members by class name (using the scope resolution operator) rather than 
    //through an object of the class (using the member selection operator).
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    // note: we're not instantiating any objects of type Something
    Something::s_value = 10;
    std::cout << Something::s_value << '\n';

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //Because static member functions are not attached to a particular object, they can be called directly by 
    //using the class name and the scope resolution operator. Like static member variables, they can also be 
    //called through objects of the class type, though this is not recommended.
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    std::cout << Value::getValue() << '\n';

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  NOTES @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //Static member functions have two interesting quirks worth noting. First, because static member functions 
    //are not attached to an object, they have no this pointer! 
    //Second, static member functions can directly access other static members (variables or functions), but 
    //not non-static members. This is because non-static members must belong to a class object, and static 
    //member functions have no class object to work with!
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    for (int count{ 0 }; count < 5; ++count)
        std::cout << "The next ID is: " << IDGenerator::getNextID() << '\n';

    return 0;
}