#include <iostream>
#include <string>

//A reference is a variable that holds a pointer to another variable.
//A reference is essentially identical to the object being referenced.
//This means we can use a reference to read or modify the object being referenced.
//Modern C++ contains two types of references: lvalue references, and rvalue references. 


int return5()
{
    return 5;
}


void printValue(std::string y)
{
    std::cout << y << '\n';
} // y is destroyed here



void printMyValue(std::string& y) // type changed to std::string&
{
    std::cout << y << '\n';
} // y is destroyed here



void printMyConstValue(const int& y) // y is now a const reference
{
    // void printMyConstValue(int& y) only accepts modifiable lvalues
    std::cout << y << '\n'; // now we can accept non-modifiable lvalues
}



int main()
{
    //=======================================================================================================
    //                                   /**LVALUES & RVALUES**/
    //=======================================================================================================

    //An lvalue (pronounced “ell-value”, short for “left value” or “locator value”, and 
    //sometimes written as “l-value”) is an expression that evaluates to a function or 
    //object that has an identity. An object or function has an identity if it has an identifier 
    //(such as a variable or named function) or an identifiable memory address 
    //(one that can be retrieved using operator&). lvalues expressions are those that evaluate to 
    //variables or other identifiable objects that persist beyond the end of the expression.

    //Since the introduction of constants into the language, lvalues come in two subtypes: 
    //a modifiable lvalue is an lvalue whose value can be modified. A non-modifiable lvalue 
    //is an lvalue whose value can’t be modified (because the lvalue is const or constexpr).

    //An rvalue (pronounced “arr-value”, short for “right value”, and sometimes written as r-value) 
    //is an expression that is not an l-value. Commonly seen rvalues include literals (except string 
    //literals, which are lvalues) and the return value of functions or operators. Rvalues only exist 
    //within the scope of the expression in which they are used.

    int x{ 5 }; // 5 is an rvalue expression
    const double d{ 1.2 }; // 1.2 is an rvalue expression
    int y{ 2 };

    std::cout << x << '\n'; // x is a modifiable lvalue expression
    std::cout << d << '\n'; // d is a non-modifiable lvalue expression
    std::cout << return5(); // return5() is an rvalue expression (since the result is returned by value)
    std::cout << "\n";
    std::cout << x + 1 << '\n'; // x + 1 is a rvalue
    std::cout << static_cast<int>(d) << '\n'; // the result of static casting d to an int is an rvalue

    //return5() and x + 1 are rvalues because these expressions produce values that 
    //must be used immediately (within the scope of the expression) or they are discarded.

     x = y; //lvalues will implicitly convert to rvalues, so an lvalue can be used wherever an rvalue is required.

    //=======================================================================================================
    /**Now that we’ve covered lvalues, we can get to our first compound type: the lvalue reference.**/
    //=======================================================================================================
    //An lvalue reference (commonly just called a reference) acts as an alias for an existing lvalue (such as a variable).

    int z { 5 };    // z is a normal integer variable
    //The type int& defines ref as an lvalue reference to an int.
    int& ref { z }; // ref is an lvalue reference variable that can now be used as an alias for variable z

    std::cout <<"Normal print: "<< z << '\n';  // print the value of z (5)
    std::cout <<"Print variable by reference: "<< ref << '\n'; // print the value of z via ref (5)

    //Best practice: When defining a reference, place the ampersand next to the type, 
    //not the reference variable’s name (int& ref instead of int &ref).

    //We can also use a reference to modify the value of the object being referenced:
    std::cout << z << '\n'; // print the value of z (5)
    ref = 10; // change the value of z to 10
    std::cout << z << '\n'; // print the value of z (10)

    //Much like constants, all references must be initialized. (int& invalidRef; ==> int& invalidRef {x};)
    //Lvalue references must be bound to a modifiable lvalue.

    //When a reference is initialized with an object (or function), we say it is bound to that object (or function). 
    //The process by which such a reference is bound is called reference binding. The object (or function) being 
    //referenced is sometimes called the referent.

    ref = y; // assigns 2 (the value of y) to z (the object being referenced by ref); acts like z = y.
    // The above line does NOT change ref into a reference to variable y!

    std::cout << z << ref << '\n'; // prints 22

    // Accessing a dangling reference (a reference that its referent is destroyed) leads to undefined behavior.

    //references are not objects in C++ (not required to exist or occupy storage), so the term “reference variable” 
    //is a bit of a misnomer, as variables are objects with a name, and references aren’t objects. Therefore, you 
    //can’t have a reference to a reference, since an lvalue reference must reference an identifiable object).
    int var{20};
    int& ref1{ var };  // an lvalue reference bound to var
    int& ref2{ ref1 }; // an lvalue reference bound to var (not to ref1, ref1 evaluates to var)
    std::cout << ref1 << ref2 << '\n'; // prints 2020


    //lvalue reference to a const value (sometimes called a reference to const or a const reference)
    const int my_num { 5 };    // my_num is a non-modifiable lvalue (int& ref { my_num }; alone is illegal)
    const int& my_ref { my_num }; // okay: my_ref is a an lvalue reference to a const value (won't allow changing my_num)
    std::cout << my_num << my_ref << '\n'; // prints 55

    // BEST PRACTICE: Favor lvalue references to const over lvalue references to non-const 
    //unless you need to modify the object being referenced.


    //Most of the types provided by the standard library (such as std::string) are class types. 
    //Class types (unlike fundamental types) are usually expensive to copy. Whenever possible, 
    //we want to avoid making unnecessary copies of objects that are expensive to copy, especially 
    //when we will destroy those copies almost immediately.

    std::string str { "Hello, world!" }; // str is a std::string
    printValue(str); // str is passed by value (copied) into parameter y (expensive)
    // This expensive copy is made every time printValue() is called!

    //One way to avoid making an expensive copy of an argument when calling a function is to 
    //use pass by reference instead of pass by value. Because the reference acts as an alias 
    //for the argument, no copy of the argument is made.

    //Because a reference acts as an alias for the object being referenced, when printMyValue() uses reference y, 
    //it’s accessing the actual argument str (rather than a copy of str).
    printMyValue(str); // str is now passed by reference into reference parameter y (inexpensive)

    // WHEN TO USE PASS BY VALUE AND WHEN TO USE PASS BY REFERENCE:
    //Since a reference acts identically to the object being referenced, when using pass by reference, 
    //any changes made to the reference parameter will affect the argument (unlike pass by value where
    // only the copy is changed with no effect on the actual variable).

    const int zig { 5 };
    printMyConstValue(zig); // ok: zig is a non-modifiable lvalue
    printMyConstValue(var); // ok: var is a modifiable lvalue
    // This way we can avoid making an expensive copy while ensuring that the value we pass remains unchanged.

    // BEST PRACTICE: Favor passing by const reference over passing by non-const reference 
    // unless you have a specific reason to do otherwise (e.g. the function needs to change 
    // the value of an argument). 


    // BEST PRACTICE: Pass fundamental types by value, and class (or struct) types by const reference.


    // BEST PRACTICE: Prefer pass by value for objects that are cheap to copy, and pass by const reference 
    // for objects that are expensive to copy. If you’re not sure whether an object is cheap or expensive 
    // to copy, favor pass by const reference(cost: The size of the object, Any additional setup costs).

    // Common types that are cheap to copy include all of the fundamental types, enumerated types, and std::string_view.
    // Common types that are expensive to copy include std::array, std::string, std::vector, and std::ostream.


    


    //=======================================================================================================
    //                                   /** POINTERS **/
    //=======================================================================================================


    return 0;
}
