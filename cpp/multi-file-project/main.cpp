#include <iostream>

// needed so main.cpp knows that add() is a function declared elsewhere (some other file for example)
int add(int x, int y); 
int sub(int x, int y); 
int mult(int x, int y); 
int divide(int x, int y); 
int getInteger();


//when we say std::cout, we’re saying “the cout that lives in namespace std“.
//This is the safest way to use cout, because there’s no ambiguity about which 
//cout we’re referencing (the one in the std namespace).
//The best practice is to use explicit namespace prefixes to access identifiers 
//defined in a namespace, rather than using a using directive statement(using namespace std; for instance).



int main()
{
    //Use (g++ main.cpp func.cpp input.cpp -o main -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion) to compile.
    //Parameters after the -o main (the name of the executable) are for turning off compiler extentions and useful warnings.
    //Generally you should not #include .cpp files, as it's bad form, and likely to lead to violations of the one definition rule.

    int x{ getInteger() };
	int y{ getInteger() };

    std::cout << "This is a multi-file project!\n";
    std::cout << "The result of "<< x << " + " << y << " is: "  << add(x, y) << '\n';
    std::cout << "The result of "<< x << " - " << y << " is: "  << sub(x, y) << '\n';
    std::cout << "The result of "<< x << " * " << y << " is: "  << mult(x, y) << '\n';
    std::cout << "The result of "<< x << " / " << y << " is: "  << divide(x, y) << '\n';

    //It turns out that std::cout‘s name isn’t really std::cout. It’s actually just cout, 
    //and std is the name of the namespace that identifier cout is part of. Because cout 
    //is defined in the std (standard C++ library) namespace, the name cout won’t conflict 
    //with any objects or functions named cout that we create in the global namespace. Thus,
    //when you use an identifier that is defined inside a namespace (such as the std namespace), 
    //you have to tell the compiler that the identifier lives inside the namespace.

    

    return 0;
}