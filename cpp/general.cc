#include <iostream>
#include <string>
#include <iterator> // std::size



void countDown(int count)
{
    std::cout << "push " << count << '\n';
    if (count > 1) // termination condition
        countDown(count-1); // countDown() calls itself recursively
    
}

int fibo(int count)
{
    if (count == 0)
        return 0; // base case (termination condition)
    if (count == 1)
        return 1; // base case (termination condition)
    return fibo(count-1) + fibo(count-2);
}


int main()
{

    int prime[5]{ 2, 3, 5, 7, 11 }; // use initializer list to initialize the fixed array
    std::cout << "Length of array prime:" <<(sizeof(prime)/sizeof(*prime)) << '\n';

    char name[]{ "Mollie" };
    for (int i = 0; i < 6; i++)
    {
        std::cout << name[i];
    }
    std::cout << '\n';


    //################################# For each loops and the auto keyword ######################################
    //auto keyword lets C++ deduce the type of the array elements for us.
    constexpr int fibonacci[]{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
    for (auto number : fibonacci) // iterate over array fibonacci
    {
       std::cout << number << ' '; // we access the array element for this iteration through variable number
    }

    std::cout << '\n';
    //#############################################################################################################

    //############################################## RECURSION ###################################################
    //Best practice: Generally favor iteration over recursion, except when recursion really makes sense.
    countDown(5);

    for (int count { 0 }; count < 13; ++count)
        std::cout << fibo(count) << ' ';

    std::cout << '\n';

    //#############################################################################################################

    return 0;
}






