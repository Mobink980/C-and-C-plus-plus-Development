#include <iostream>

// Initialization = The object is given a known value at the point of definition.
// Assignment = The object is given a known value beyond the point of definition.
// Uninitialized = The object has not been given a known value yet.

void doNothing(int &) // Don't worry about what & is for now, we're just using it to trick the compiler into thinking variable x is used
{
}
// A function that returns the power of 2 of a number
int power_of_two(int x)
{
    return x * x;
}

int main()
{
    std::cout << "Bonjour!" << std::endl;
    std::cout << "Je suis Eddy. C'est mon fils, Junior." << std::endl;
    // '\n' as newline character is more efficient than endl since it doese not need to flush the output buffer
    std::cout << "Je suis un programmeur." << '\n';
    std::cout << "J'adore C++.\n";
    // insertion operator is << , and extraction operator is >>
    int age_homme{}; // zero initialization
    int age_fille{};
    std::cout << "Quel est ton age? et ta fille?";
    std::cin >> age_homme >> age_fille; //getting multiple values at once
    std::cout << "Tu as " << age_homme << " ans, et ta fille as " << age_fille << " ans.\n";
    // uninitialized variables in C++ bring the content of the memory the variable is referring to
    int x;        //best practice is to always initialize variables before use
    doNothing(x); // make the compiler think we're assigning a value to this variable
    std::cout << "x = " << x << '\n';

    // When writing variaable or function names, avoid abbreviations. Although they reduce the time you
    // need to write your code, they make your code harder to read (code is written once, but is read multiple times).
    int ccount{7};                                      // Bad	What does the c before “count” stand for?
    int customerCount{10};                              // Good	Clear what we’re counting
    int totalNmberOfCustomers = ccount + customerCount; // Descriptive
    std::cout << "Total number of customers = " << totalNmberOfCustomers << '\n';

    //numberOfChars with comment is better than lengthy variable name 'numberOfCharsIncludingWhitespaceAndPunctuation' !
    // holds number of chars in a piece of text -- including whitespace and punctuation!
    int base_num{};
   
    std::cout << "Enter a number to calculate power of 2: ";
    std::cin >> base_num;
    std::cout << "The result is: " << power_of_two(base_num) << '\n';

    return 0;
}
