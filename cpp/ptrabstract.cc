#include <iostream>


int main()
{
    int x{ 5 };
    int& ref { x };  // get a reference to x
    int* ptr { &x }; // get a pointer to x

    std::cout << x;
    std::cout << ref;  // use the reference to print x's value (5)
    std::cout << *ptr; // use the pointer to print x's value (5)

    ref = 6; // use the reference to change the value of x
    std::cout << x;
    std::cout << ref;  // use the reference to print x's value (6)
    std::cout << *ptr; // use the pointer to print x's value (6)

    *ptr = 7; // use the pointer to change the value of x
    std::cout << x;
    std::cout << ref;  // use the reference to print x's value (7)
    std::cout << *ptr; // use the pointer to print x's value (7)


    //Thus, both pointers and references provide a way to indirectly access 
    //another object. The primary difference is that with pointers, we need 
    //to explicitly get the address to point at, and we have to explicitly 
    //dereference the pointer to get the value. With references, the 
    //address-of and dereference happens implicitly.

    //Difference: References are not objects, pointers are.
    //Pointers are variables that hold a memory address.

    std::cout << std::endl;

    return 0;
}