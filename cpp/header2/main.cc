#include "square.hh" // square.h is also included once here
#include <iostream>

int main()
{
    //This is an example of how to use the header files. Also, we have a multi-file project.
    //Use (g++ main.cc square.cc -o main -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion) to compile.
    //Parameters after the -o main (the name of the executable) are for turning off compiler extentions and useful warnings.
    std::cout << "a square has " << getSquareSides() << " sides.\n";
    std::cout << "a square of length 5 has perimeter length " << getSquarePerimeter(5) << ".\n";

    return 0;
}