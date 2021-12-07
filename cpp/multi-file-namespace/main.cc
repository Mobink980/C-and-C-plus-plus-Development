#include "circle.hh" // for basicMath::pi
#include "growth.hh" // for basicMath::e

#include <iostream>

int main()
{
    //This is an example of how to use the header files and namespace in a multi-file project.
    //Use (g++ main.cc add.cc -o main -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion) to compile.
    //Parameters after the -o main (the name of the executable) are for turning off compiler extentions and useful warnings.
    std::cout << basicMath::pi << '\n';
    std::cout << basicMath::e << '\n';
    std::cout << basicMath::add(4, 3) << '\n';

    return 0;
}