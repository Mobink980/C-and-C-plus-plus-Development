#include<iostream>
#include <string> // allows use of std::string


//C++ contains capabilities that allow programmers to create their own data types.
//Perhaps the simplest user-defined data type is the enumerated type. An enumerated 
//type (also called an enumeration or enum) is a data type where every possible value 
//is defined as a symbolic constant (called an enumerator). Enumerations are defined 
//via the enum keyword.

//Naming enumerators (e.g. color_red) in ALL_CAPS is discouraged, 
//because it risks collisions with preprocessor macro names.

// Define a new enumeration named Color
enum Color //Enumeration (e.g. Color) names are often named starting with a capital letter.
    {
        // Here are the enumerators
        // These define all the possible values this type can hold
        // Each enumerator is separated by a comma, not a semicolon
        color_black,
        color_red,
        color_blue,
        color_green,
        color_white,
        color_cyan,
        color_yellow,
        color_magenta, // there can be a comma after the last enumerator, but there doesn't have to be a comma
    }; // however the enum itself must end with a semicolon


//forward declaration
void printColor(Color color);

int main()
{
    std::string myName{ "Alex" }; // initialize myName with string literal "Alex"
    myName = "John"; // assign variable myName the string literal "John" 
    std::cout << myName << std::endl; // print the value of myName

    std::cout << "Enter your full name: ";
    std::string name{};
    // std::cin >> name; // this won't work as expected since std::cin breaks on whitespace
    //To read a full line of input into a string, you’re better off using the std::getline() function instead.
    //The std::ws input manipulator tells std::cin to ignore any leading whitespace.
    std::getline(std::cin >> std::ws, name); // read a full line of text into name
    std::cout << "Hello, " << name << "! Your name has " << name.length() << " characters." << std::endl; // print "Hello, name!"

    // convert name.length() which is an unsigned int to an int
    int length = static_cast<int>(name.length()); 
    for(int i = 0; i < length; i++)
    {
        std::cout << name[i] << " *_* "; // print each character of name
    }
    std::cout << std::endl;

    //const variables must be initialized.
    const double gravity { 9.8 }; // preferred use of const before type
    const int name_length { length }; // runtime constant
    std::cout << "Your name has " << name_length * gravity << " gravity!!" << std::endl;
    // Best practice: 
    // Any variable that should not be modifiable after initialization and whose initializer 
    //is known at compile-time should be declared as constexpr.
    // Any variable that should not be modifiable after initialization and whose initializer 
    //is not known at compile-time should be declared as const.
    constexpr int sum { 4 + 5 }; // ok, the value of 4 + 5 can be resolved at compile-time
    
    
    // Define a few variables of enumerated type Color
    Color paint = color_white;
    Color house(color_blue);
    Color apple { color_red };
    std::cout << "Each enumerator is automatically assigned an integer value based " 
    "on its position in the enumeration list.\n";
    std::cout << "The color of the house is " << house << std::endl;
    std::cout << "The color of the apple is " << apple << std::endl;
    std::cout << "The color of the paint is " << paint << std::endl;
    printColor(paint);
    printColor(color_yellow);
    printColor(color_green);

    //Enum class example
    //Also, just in case you ever run into it, “enum struct” is equivalent to 
    //“enum class”. But this usage is not recommended and is not commonly used.
    enum class Fruit
    {
        banana, // banana is inside the scope of Fruit
        apple
    };

    // note: banana is not directly accessible any more, we have to use Fruit::banana
    // It's kind of like namespace, where we need to use the scope operator to access the variable.
    Fruit fruit{ Fruit::banana }; 
    if (fruit == Fruit::banana) // this is okay
        std::cout << "Banana is yellow!!\n";
    else if (fruit == Fruit::apple)
        std::cout << "Apple is green!!\n";
    

    return 0;
}

//for printing the enumerated type
void printColor(Color color)
{
    switch (color)
    {
    case color_black:
        std::cout << "Black\n";
        break;
    case color_red:
        std::cout << "Red\n";
        break;
    case color_blue:
        std::cout << "Blue\n";
        break;
    case color_green:
        std::cout << "Green\n";
        break;
    case color_white:
        std::cout << "White\n";
        break;
    case color_cyan:
        std::cout << "Cyan\n";
        break;
    case color_yellow:
        std::cout << "Yellow\n";
        break;
    case color_magenta:
        std::cout << "Magenta\n";
        break;
    default:
        std::cout << "Who knows!\n";
    }
}
