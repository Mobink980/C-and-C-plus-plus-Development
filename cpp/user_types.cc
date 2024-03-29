#include <iostream>
#include <string>

//There are hundreds of potentially useful types that C++ doesn’t include because 
//it’s just not possible to anticipate everything that someone might need 
//(let alone implement and test those things).

//To solve this problem, C++ provides a set of user-defined(also called 
//program-defined) types.

//C++ allows us to create entirely new, custom types for use in our programs! 
//C++ has two categories of compound types that allow for this: the enumerated 
//types (including unscoped and scoped enumerations), and the class types 
//(including structs, classes, and unions).


// Define a program-defined type named Fraction so the compiler understands what a Fraction is
// This only defines what a Fraction type looks like, it doesn't create one
struct Fraction
{
	int numerator {};
	int denominator {};
}; //Don’t forget to end your type definitions with a semicolon.

//BEST PRACTICE: Whenever you create a new program-defined type, name it starting with a capital letter.


//An enumeration (also called an enumerated type or an enum) is a compound 
//data type where every possible value is defined as a symbolic constant (called an enumerator).


enum Pet
{
    cat,
    dog,
    pig,
    whale,
};

namespace color
{
    // Define a new unscoped enumeration named Color
    enum Color
    {
        // Here are the enumerators
        // These symbolic constants define all the possible values this type can hold
        // Each enumerator is separated by a comma, not a semicolon
        red,
        green,
        blue, // trailing comma optional but recommended
    }; // the enum definition must end with a semicolon
}




//BEST PRACTICE: Name your enumerated types starting with a capital letter. 
//Name your enumerators starting with a lower case letter.

namespace feeling
{
    enum Feeling
    {
        happy,
        tired,
        blue, // feeling::blue doesn't collide with color::blue
    };
}

enum SortOrder
{
    alphabetical,
    alphabeticalReverse,
    numerical,
};

void sortData(SortOrder order)
{
    if (order == alphabetical)
        std::cout << "sort data in forwards alphabetical order" << '\n';

    else if (order == alphabeticalReverse)
        std::cout << "sort data in backwards alphabetical order" << '\n';

    else if (order == numerical)
        std::cout << "sort data numerically" << '\n';

}


//#####################################  BEST PRACTICE  ######################################################
//A program-defined type used in only one code file should be defined in that code file as close to the 
//first point of use as possible.
//A program-defined type used in multiple code files should be defined in a header file with the same 
//name as the program-defined type and then #included into each code file as needed (e.g., Fraction.hh).
//############################################################################################################

// Function to print the feeling
std::string getFeel(feeling::Feeling feel)
{
    switch (feel)
    {
    case feeling::Feeling::happy: return "Happy";
    case feeling::Feeling::tired:   return "Tired";
    case feeling::Feeling::blue:  return "Blue";
    default:    return "???";
    
    }
}

//Scoped enumerations work similarly to unscoped enumerations, but have two primary 
//differences: They are strongly typed (they won’t implicitly convert to integers) 
//and strongly scoped (the enumerators are only placed into the scope region of 
//the enumeration).


//Although scoped enumerations use the class keyword, they aren’t considered to 
//be a “class type” (which is reserved for structs, classes, and unions).
enum class PhoneOS // "enum class" defines this as a scoped enumeration rather than an unscoped enumeration
    {
        android, // android is considered part of PhoneOS's scope region
        ios,
    };

enum class PCOS
{
    windows, // windows is considered part of PCOS's scope region
    mac,
    linuxOS,
};





int main()
{
    Fraction f{ 3, 4 }; // this actually instantiates a Fraction object named f

    std::cout << f.numerator << '/' << f.denominator << '\n';
    //#####################################  BEST PRACTICE  ######################################################
    //Prefer putting your enumerations inside a named scope region (such as a namespace or class) 
    //so the enumerators don’t pollute the global namespace.
    //############################################################################################################

    // Define a few variables of enumerated type Color
    color::Color apple { color::red };   // my apple is red
    color::Color shirt { color::green }; // my shirt is green
    color::Color cup { color::blue };    // my cup is blue

    feeling::Feeling my_feel { feeling::blue };

    Pet myPet { whale }; // my pet is a whale (global namespace)

    sortData(alphabetical); // sort data in forwards alphabetical order

    if( apple== color::red || shirt == color::green || cup == color::blue )
        std::cout << "Parfait!" << '\n';

    
    if (myPet == whale)
        my_feel = feeling::happy; // now I'm happy!!

    std::cout << "I am " << getFeel(my_feel) << ".\n";


    PCOS    my_pc { PCOS::windows }; // note: windows is not directly accessible, we have to use COS::windows
    PhoneOS my_phone { PhoneOS::android }; // note: android is not directly accessible, we have to use PhoneOS::android

    //if (my_pc == my_phone) // compile error: the compiler doesn't know how to compare 
    //different types PCOS and PhoneOS (unscoped enumeration would've allowed this).

    //std::cout << PCOS::windows; // compile error: std::cout doesn't know how to print this (will not implicitly convert to int)

    //###################################################################################################################
    //Best practice: Favor scoped enumerations over unscoped enumerations unless there’s a compelling reason to do otherwise.
    //###################################################################################################################

    if (my_pc == PCOS::windows)
        std::cout << "I am running Windows.\n";

    if (my_phone == PhoneOS::android)
        std::cout << "I am running Android.\n";



    return 0;
}