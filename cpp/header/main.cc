//When we use angled brackets, we’re telling the preprocessor that this is a header file we didn’t write ourselves. 
//The compiler will search for the header only in the directories specified by the include directories. 

//When we use double-quotes, we’re telling the preprocessor that this is a header file that we wrote. 
//The compiler will first search for the header file in the current directory. If it can’t find a 
//matching header there, it will then search the include directories.

#include "add.hh" // Insert contents of add.hh at this point.  Note use of double quotes here (not angle brackets).

//iostream doesn't have .h extension, so older program with iostream.h will work(2 different files).
//When including a header file from the standard library, use the version without the .h extension if it exists.
#include <iostream> 

// ".cc" and ".cpp" are the same extention; also ".h" and ".hh" and ".hpp" are the same extention. 

int main()
{
    //This is an example of how to use the header files.
    //Use (g++ main.cc add.cc -o main -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion) to compile.
    //Parameters after the -o main (the name of the executable) are for turning off compiler extentions and useful warnings.
    std::cout << "The sum of 3 and 4 is " << add(3, 4) << '\n';
    return 0;
}