#include <algorithm>
#include <array>
#include <iostream>
#include <string>
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  Lambdas  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//A lambda expression (also called a lambda or closure) allows us to define an anonymous function inside 
//another function. The nesting is important, as it allows us both to avoid namespace naming pollution, 
//and to define the function as close to where it is used as possible (providing additional context).

//The syntax for lambdas is one of the weirder things in C++, and takes a bit of getting used to. 
//Lambdas take the form:

// [ captureClause ] ( parameters ) -> returnType
// {
//     statements;
// }

//The capture clause and parameters can both be empty if they are not needed.
//The return type is optional, and if omitted, auto will be assumed (thus using type inference used to 
//determine the return type). While we previously noted that type inference for function return types 
//should be avoided, in this context, it’s fine to use (because these functions are typically so trivial).
//Also note that lambdas have no name, so we don’t need to provide one.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



int main()
{
    //a trivial lambda definition
    []() {}; // defines a lambda with no captures, no parameters, and no return type

    //another example
    const std::array<std::string, 4> arr{ "apple", "banana", "walnut", "lemon" };

    // Define the function right where we use it.
    const auto found{ std::find_if(arr.begin(), arr.end(), [](std::string str) 
                            { // here's our lambda, no capture clause
                                return (str.find("nut") != std::string::npos);
                            }) 
                    };

    if (found == arr.end())
    {
    std::cout << "No nuts\n";
    }
    else
    {
    std::cout << "Found " << *found << '\n';
    }


    //****************************************************************************************
    //In the above example, we defined a lambda right where it was needed. This use of a 
    //lambda is sometimes called a function literal.
    //****************************************************************************************

    //auto will find the type of a variable by itself (type inference).Type inference for 
    //function return types should be avoided, as it's expensive. It's fine for lambda.

    //another example
    const std::array<int, 6> int_arr{ 2, 4, 6, 8, 10, 12};

    //In the following snippet, we’re using std::all_of to check if all elements of 
    //an array are even:



    // Bad: We have to read the lambda to understand what's happening.
    std::cout << std::boolalpha << std::all_of(int_arr.begin(), int_arr.end(), [](int i){ return ((i % 2) == 0); }) << "\n";

    //We can improve the readability of this as follows:

    // Good: Instead, we can store the lambda in a named variable and pass it to the function.
    auto isEven{ //A variable instantiated with a lambda function
    [](int i)
    {
    return ((i % 2) == 0); //returns True if number is even
    }
    };


    std::cout << std::boolalpha << std::all_of(int_arr.begin(), int_arr.end(), isEven) << "\n";




    //****************************************************************************************
    //In actuality, lambdas aren’t functions (which is part of how they avoid the limitation 
    //of C++ not supporting nested functions). They’re a special kind of object called a 
    //functor. Functors are objects that contain an overloaded operator() that make them 
    //callable like a function.
    //****************************************************************************************

    // Using auto. Stores the lambda with its real type.
    auto addNumbers3{
        [](double a, double b) {
            return (a + b);
        }
    };

    std::cout << addNumbers3(5.2, 6.3) << "\n";

    //The only way of using the lambda’s actual type is by means of auto. auto also has 
    //the benefit of having no overhead compared to std::function.

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //Rule: Use auto when initializing variables with lambdas, and std::function if you 
    //can’t initialize the variable with the lambda.
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    //****************************************************************************************
    //Because lambdas with one or more auto parameter can potentially work with a wide 
    //variety of types, they are called generic lambdas.
    //****************************************************************************************


    constexpr  std::array<const char*, 12> months{ // pre-C++17 use std::array<const char*, 12>
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
    };

    // Search for two consecutive months that start with the same letter.
    const auto sameLetter{ std::adjacent_find(months.begin(), months.end(),
                                        [](const auto& a, const auto& b) {
                                        return (a[0] == b[0]);
                                        }) };

    // Make sure that two months were found.
    if (sameLetter != months.end())
    {
        // std::next returns the next iterator after sameLetter
        std::cout << *sameLetter << " and " << *std::next(sameLetter)
                    << " start with the same letter\n";
    }

    //############################################################################################
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! The capture clause !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //############################################################################################
    //The capture clause is used to (indirectly) give a lambda access to variables available in 
    //the surrounding scope that it normally would not have access to. All we need to do is list 
    //the entities we want to access from within the lambda as part of the capture clause. In this 
    //case, we want to give our lambda access to the value of variable search, so we add it to the 
    //capture clause:
    //############################################################################################
    std::array<std::string, 4> fruit_arr{ "apple", "banana", "walnut", "lemon" };

    std::cout << "search for: ";

    std::string search{};
    std::cin >> search;

    // Capture @search                                vvvvvv
    auto found_fruit{ std::find_if(fruit_arr.begin(), fruit_arr.end(), [search](std::string str) {
        return (str.find(search) != std::string::npos);
    }) };

    if (found_fruit == fruit_arr.end())
    {
        std::cout << "Not found\n";
    }
    else
    {
        std::cout << "Found " << *found_fruit << '\n';
    }

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  Conclusion  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //Lambdas and the algorithm library may seem unnecessarily complicated when compared to a solution that 
    //uses a loop. However, this combination can allow some very powerful operations in just a few lines of 
    //code, and can be more readable than writing your own loops. On top of that, the algorithm library 
    //features powerful and easy-to-use parallelism, which you won’t get with loops. Upgrading source code 
    //that uses library functions is easier than upgrading code that uses loops.

    //Lambdas are great, but they don’t replace regular functions for all cases. Prefer regular functions 
    //for non-trivial and reusable cases.
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@




    return 0;
}










