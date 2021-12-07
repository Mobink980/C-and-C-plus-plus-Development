#ifndef CIRCLE_HH
#define CIRCLE_HH

//It’s legal to declare namespace blocks in multiple locations 
//(either across multiple files, or multiple places within the same file). 
//All declarations within the namespace are considered part of the namespace.
//The standard library makes extensive use of this feature, as each standard 
//library header file contains its declarations inside a namespace std block 
//contained within that header file. Otherwise the entire standard library 
//would have to be defined in a single header file!

namespace basicMath
{
    constexpr double pi{ 3.14 };
}

#endif