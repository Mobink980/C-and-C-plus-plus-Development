#include<iostream>
#include <string> // allows use of std::string

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

    return 0;
}
