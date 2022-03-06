#ifndef SQUARE_HH //header guard (line 1)
#define SQUARE_HH //header guard (line 2)

//If we write a function definition in the header file, and we call the header file
//in several .cc files, then when the project with mulltiple .cc files is compiled,
//the linker will complain about two definitions of the same function.
//Put the function definition in one of the .cc files so that the header just contains 
//a forward declaration (like this file). In this way, the header file can be included 
//in multiple files (without duplicate identifier problem). There won't be two definitions 
//for the same function, which can happen in multi-file projects, like this one.

/*
* Header guards are designed to ensure that the contents of a given header file are not 
* copied more than once into any single file, in order to prevent duplicate definitions.
*
* Note that duplicate declarations are fine, since a declaration can be declared multiple 
* times without incident -- but even if your header file is composed of all declarations 
* (no definitions) it’s still a best practice to include header guards.
*
* Note that header guards do not prevent the contents of a header file from being copied 
* (once) into separate project files. This is a good thing, because we often need to 
* reference the contents of a given header from different project files.
*/

int getSquareSides(); // forward declaration for getSquareSides
int getSquarePerimeter(int sideLength); // forward declaration for getSquarePerimeter

#endif //header guard (line 3)