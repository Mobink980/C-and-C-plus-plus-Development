#include<iostream>

//Once your program is working, your job really isn’t done (unless the program is a one-off/throwaway). 
//The next step is to cleanup your code. This involves things like: removing (or commenting out) 
//temporary/debugging code, adding comments, handling error cases, formatting your code, 
//and ensuring best practices are followed. Also, optimization and shortening of code could be beneficial.
//Perhaps there is redundant logic that can be consolidated, or multiple statements that can be combined, 
//or variables that aren’t needed, or a thousand other little things that could be simplified.
//Too often new programmers focus on optimizing for performance when they should be optimizing for maintainability.

int main()
{
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    std::cout << "Double of " << num << " is " << num * 2 << " and Triple of " << num << " is " << num*3 << ".\n";
    return 0;
}
