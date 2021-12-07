#include<iostream>

//Once your program is working, your job really isn’t done (unless the program is a one-off/throwaway). 
//The next step is to cleanup your code. This involves things like: removing (or commenting out) 
//temporary/debugging code, adding comments, handling error cases, formatting your code, 
//and ensuring best practices are followed. Also, optimization and shortening of code could be beneficial.
//Perhaps there is redundant logic that can be consolidated, or multiple statements that can be combined, 
//or variables that aren’t needed, or a thousand other little things that could be simplified.
//Too often new programmers focus on optimizing for performance when they should be optimizing for maintainability.

//In C++ the code is executed sequentially from top to bottom line by line.
//Therefore, we need to use forward declaration to avoid compile errors when the sequence of function calls is not known.
int add(int x, int y); // function prototype includes return type, name, parameters, and semicolon.  No function body!

// A function that returns the power of 2 of a number
int power_of_two(int x)
{
    return x * x;
}

// A function that returns the double of a number
int double_it(int x)
{
    return x * 2;
}


int main()
{
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    std::cout << "Double of " << num << " is " << num * 2 << " and Triple of " << num << " is " << num*3 << ".\n \n";

    //y1(x) = 2x^2 + 4  & y2(x) = 5x^2 - 3
    int x;
    std::cout << "y1(x) = 2x^2 + 4  &  y2(x) = 5x^2 - 3 , y3 = y2 - y1 = 3x^2 - 7 \n";
    std::cout << "Enter an input to compute function y3: ";
    std::cin >> x;
    int y1 = double_it(power_of_two(x)) + 4;
    int y2 = power_of_two(x)*5 - 3;
    std::cout << "The output of the function y1 is " << y1 << " and the output of the functtion y2 is " << y2 <<".\n";
    std::cout << "The output of the function y3 is " << y2 - y1 <<".\n";

    std::cout << add(10, 20) << std::endl;

    //explicit type conversion (the thing between the angled brackets in C++ is most likely a type)
    std::cout << static_cast<int>(3.14) << std::endl; // 3
    char ch{ 97 }; // 97 is ASCII code for 'a'
    std::cout << ch << " has value " << static_cast<int>(ch) << '\n'; // print value of variable ch as an int


    return 0;
}

//Now, I can write this function after the main function, where the function is called.
//Because I used forward declaration.
int add(int x, int y) // even though the body of add() isn't defined until here
{
    return x + y;
}