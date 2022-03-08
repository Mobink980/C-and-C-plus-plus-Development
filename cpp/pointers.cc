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



bool isNullPointer(int* ptr); // function prototype



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

    //A reference to var z goes to the address of the variable z and retrieves the value of the variable.
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

    //The address-of operator (&) returns the memory address of its operand. 
    int var1{ 100 };
    std::cout << "The value of the variable var1 is: " << var1 << '\n';  
    std::cout << "The memory address of variable var1 is: " << &var1 << '\n';  


    /**
     * When following a type name, & denotes an lvalue reference: int& ref.
     * When used in a unary context in an expression, & is the address-of operator: std::cout << &x.
     * When used in a binary context in an expression, & is the Bitwise AND operator: std::cout << x & y.
     */


    //Getting the address of a variable isn’t very useful by itself.
    //The most useful thing we can do with an address is access the value stored at that address. 
    //The dereference operator (*) returns the value at a given memory address as an lvalue.

    int Bonjour{ 5 };
    std::cout << "The value of variable Bonjour: " << Bonjour << '\n';  
    std::cout << "The memory address of variable Bonjour: " << &Bonjour << '\n';
    //In the following, parentheses not required, but make it easier to read.
    std::cout << "The value at the memory address of variable Bonjour: " << *(&Bonjour) << '\n'; 

    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //The address-of operator (&) and dereference operator (*) work as opposites: 
    //address-of gets the address of an object, and dereference gets the object at an address.
    //The dereference operator is unary, whereas the multiplication operator is binary(*hi Vs hi*bye).
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


    //##############################################################################################################
    //A pointer is an object that holds a memory address (typically of another variable) as its value. 
    //This allows us to store the address of some other object to use later.
    //Much like reference types are declared using an ampersand (&) character, pointer types are declared using an asterisk (*).
    //##############################################################################################################

    //Note that this asterisk is part of the declaration syntax for pointers, not a use of the dereference operator.
    int* ptr { &x }; // a pointer to an integer (holds the address of an integer value)

    //BEST PRACTICE: When declaring a pointer type, place the asterisk next to the type name.

    //BEST PRACTICE: When declaring a pointer, always initialize it 
    //(wild pointers contain garbage addresses causing undefined behavior).

    // int* ptr1;        // an uninitialized pointer (holds a garbage address)
    int* ptr2{};     // a null pointer 
    int* ptr3{ &Bonjour }; // a pointer initialized with the address of variable Bonjour
    std::cout << "The value of variable Bonjour is: " << *ptr3 << '\n'; //get the value with the dereference operator

    //In int* ptr{ &x }; ptr is holding the address of x, so we say that ptr is “pointing to” x.

    //##############################################################################################################
    //When we say, “an integer pointer”, we really mean “a pointer to an integer”. 
    //int* ptr{ 0x0012FF7C }; is not okay, 0x0012FF7C is treated as an integer literal
    //##############################################################################################################

    int lin { 5 };
    int lucie { 10 };
    int* pointer1 { &lin };
    std::cout << "lin is " << *pointer1 << '\n'; // print the value at the address being pointed to (lin's address)
    pointer1 = &lucie; // change pointer1 to point at lucie
    std::cout << "lucie is " << *pointer1 << '\n'; // print the value at the address being pointed to (lucie's address)
    *pointer1 = 6; // The object at the address held by pointer1 (lucie) assigned value 6 (note that pointer1 is dereferenced here)
    std::cout << "Now lucie is " << *pointer1 << '\n'; //6 of course!

    //##############################################################################################################
    // *( &x ) is x, e.g., *( &*( &*( &*( &*( &x ) ) ) ) ) == x. Pretty Cool!
    //##############################################################################################################


    //The address-of operator (&) returns a pointer containing the address of the operand (not the address as a literal).
    std::cout << typeid(&lin).name() << '\n'; // print the type of &lin (prints “pi”, meaning pointer to int)

    //BEST PRACTICE: Value initialize your pointers (to be null pointers) if you are not 
    //initializing them with the address of a valid object. Because we can use assignment 
    //to change what a pointer is pointing at, a pointer that is initially set to null can 
    //later be changed to point at a valid object.

    ptr2 = &lin; // ptr2 now points to lin (no longer a null pointer)
    std::cout << "lin is " << *ptr2 << '\n';

    //int* myNull_ptr { nullptr }; // can use nullptr keyword to initialize a pointer to be a 
    //null pointer (like the keywords true and false)
    //someFunction(nullptr); // we can also pass nullptr to a function that has a pointer parameter
    //BEST PRACTICE: Use nullptr when you need a null pointer literal for initialization, 
    //assignment, or passing a null pointer to a function.



    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!    WARNING   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //Accidentally dereferencing null and dangling pointers is one of the most common mistakes C++ programmers make, 
    //and is probably the most common reason that C++ programs crash in practice. Whenever you are using pointers, 
    //you’ll need to be extra careful that your code isn’t dereferencing null or dangling pointers, as this will 
    //cause undefined behavior (probably an application crash).
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    if (isNullPointer(ptr)) {
        std::cout << "ptr is null.\n";
    }
    else {
        std::cout << "ptr is not null. It holds the address " 
        << ptr << " and the object in that address has the value:" << *ptr <<'\n';
    }

    // Assume ptr is some pointer that may or may not be a null pointer
    if (ptr) // if ptr is not a null pointer (non-null pointers are true, null pointers are false)
        std::cout << "x has the value:" << *ptr <<'\n'; // okay to dereference
    else
        // do something else that doesn't involve dereferencing ptr 
        //(print an error message, do nothing at all, etc...)
        std::cout << "Error message! HaHaHaHa!\n";


    //BEST PRACTICE: A pointer should either hold the address of a valid object, 
    //or be set to nullptr. That way we only need to test pointers for null, and 
    //can assume any non-null pointer is valid. 
    //It is the programmer’s responsibility to ensure that all pointers to an 
    //object that has just been destroyed are properly set to nullptr.


    //float* ptr { 0 };  // ptr is now a null pointer (for example only, don't do this, architecture-dependent)


    //##############################################################################################################
    //Best practice: Favor references over pointers unless the additional capabilities provided by pointers are needed.
    //##############################################################################################################


    //Pointer to const value: A pointer to a const value is a (non-const) pointer that points to a constant value.
    const int parfait{ 100 };
    const int* ptr5 { &parfait }; // okay: ptr5 is pointing to a "const int"
    const int bien{ 90 };
    ptr5 = &bien; // okay: ptr now points at const int bien
    std::cout << "bien is " << *ptr5 << '\n'; 


    //Const pointers: We can also make a pointer itself constant. A const pointer is a pointer whose address 
    //can not be changed after initialization.

    int* const const_ptr { &lin }; // const after the asterisk means this is a const pointer
    //const_ptr = &lucie; // error: once initialized, a const pointer can not be changed (fixed address).
    *const_ptr = 200; // okay: the value being pointed to is non-const
    std::cout << "Now lin is " << lin << '\n';




    return 0;
}


//Conditionals can only be used to differentiate null 
//pointers from non-null pointers. There is no convenient 
//way to determine whether a non-null pointer is pointing 
//to a valid object or dangling (pointing to an invalid object).
bool isNullPointer(int* ptr)
{
    if (ptr == nullptr)
    {
        return true;
    }
    
    return false;
}
