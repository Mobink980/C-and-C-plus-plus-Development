//In C++, it is a best practice for code files to #include their paired header file (if one exists). 
//In this example, add.cc includes add.hh. 
//This allows the compiler to catch certain kinds of errors at compile time instead 
//of link time (like return type mismatch between forward declaration and function itself). 

#include "add.hh" // Insert contents of add.hh at this point.  Note use of double quotes here.

// Best Practice:
// To maximize the chance that missing includes will be flagged by compiler, order your #includes as follows:
// 1. The paired header file
// 2. Other headers from your project
// 3. 3rd party library headers
// 4. Standard library headers
// The headers for each grouping should be sorted alphabetically. 
//That way, if one of your user-defined headers is missing an #include for a 3rd party 
//library or standard library header, it’s more likely to cause a compile error so you can fix it.
//Every header you write should compile on its own (it should #include every dependency it needs).
//Only #include what you need (don’t include everything just because you can).
//Do not #include .cpp files.

int add(int x, int y)
{
    return x + y;
}