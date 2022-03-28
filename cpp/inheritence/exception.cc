#include <iostream>
#include <string>
#include <cmath>
//<math.h> does not declare the functions (like std::sqrt) in namespace std. 
//It has been included into the C++ standard only for compatibility 
//reasons. The correct C++ include would be <cmath>.

//When writing reusable code, error handling is a necessity. One of the most 
//common ways to handle potential errors is via return codes. For example:


int findFirstChar(std::string string, char ch)
{
    // Step through each character in string
    for (std::size_t index{ 0 }; index < string.length(); ++index)
        // If the character matches ch, return its index
        if (string[index] == ch)
            return index;

    // If no match was found, return -1
    return -1;
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//The primary virtue of this approach is that it is extremely simple. However, using return codes has a 
//number of drawbacks which can quickly become apparent when used in non-trivial cases:
//First, return values can be cryptic -- if a function returns -1, is it trying to indicate an error, or is 
//that actually a valid return value? It’s often hard to tell without digging into the guts of the function.
//Second, functions can only return one value, so what happens when you need to return both a function 
//result and an error code?
//Third, in sequences of code where many things can go wrong, error codes have to be checked constantly (
//like when working with files).
//Fourth, return codes do not mix with constructors very well. What happens if you’re creating an object 
//and something inside the constructor goes catastrophically wrong? Constructors have no return type to 
//pass back a status indicator, and passing one back via a reference parameter is messy and must be 
//explicitly checked. Furthermore, even if you do this, the object will still be created and then has 
//to be dealt with or disposed of.
//Finally, when an error code is returned to the caller, the caller may not always be equipped to handle 
//the error. If the caller doesn’t want to handle the error, it either has to ignore it (in which case it 
//will be lost forever), or return the error up the stack to the function that called it. This can be messy 
//and lead to many of the same issues noted above.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


double divide(int x, int y, bool& outSuccess)
{
    if (y == 0)
    {
        outSuccess = false;
        return 0.0;
    }

    outSuccess = true;
    return static_cast<double>(x)/y;
}


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  Exceptions  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//To summarize, the primary issue with return codes is that the error handling code ends up intricately 
//linked to the normal control flow of the code. This in turn ends up constraining both how the code is 
//laid out, and how errors can be reasonably handled.
//Exception handling provides a mechanism to decouple handling of errors or other exceptional circumstances 
//from the typical control flow of your code. This allows more freedom to handle errors when and how ever 
//is most useful for a given situation, alleviating many (if not all) of the messiness that return codes 
//cause.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


//Exceptions in C++ are implemented using three keywords that work in conjunction with each other: 
//throw, try, and catch.

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  Throwing exceptions  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//We use signals all the time in real life to note that particular events have occurred. In C++, a throw 
//statement is used to signal that an exception or error case has occurred (think of throwing a penalty 
//flag). Signaling that an exception has occurred is also commonly called raising an exception.
//To use a throw statement, simply use the throw keyword, followed by a value of any data type you wish to 
//use to signal that an error has occurred. Typically, this value will be an error code, a description of 
//the problem, or a custom exception class.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// throw -1; // throw a literal integer value
// throw ENUM_INVALID_INDEX; // throw an enum value
// throw "Can not take square root of negative number"; // throw a literal C-style (const char*) string
// throw dX; // throw a double variable that was previously defined
// throw MyException("Fatal Error"); // Throw an object of class MyException

//Each of these statements acts as a signal that some kind of problem that needs to be handled has occurred.

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  Looking for exceptions  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//In C++, we use the try keyword to define a block of statements (called a try block). The try block acts 
//as an observer, looking for any exceptions that are thrown by any of the statements within the try block.
//Note that the try block doesn’t define HOW we’re going to handle the exception. It merely tells the 
//program, “Hey, if any of the statements inside this try block throws an exception, grab it!”.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  Handling exceptions  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Actually handling exceptions is the job of the catch block(s). The catch keyword is used to define a 
//block of code (called a catch block) that handles exceptions for a single data type.
//Try blocks and catch blocks work together -- A try block detects any exceptions that are thrown by 
//statements within the try block, and routes them to the appropriate catch block for handling. A try 
//block must have at least one catch block immediately following it, but may have multiple catch blocks 
//listed in sequence.
//Once an exception has been caught by the try block and routed to a catch block for handling, the exception 
//is considered handled, and execution will resume as normal after the catch block.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Catch parameters work just like function parameters, with the parameter being available within the 
//subsequent catch block. Exceptions of fundamental types can be caught by value, but exceptions of 
//non-fundamental types should be caught by const reference to avoid making an unnecessary copy.
//Just like with functions, if the parameter is not going to be used in the catch block, the variable 
//name can be omitted.
//Note that the compiler will not perform implicit conversions or promotions when matching exceptions with 
//catch blocks! For example, a char exception will not match with an int catch block. An int exception will 
//not match a float catch block. However, casts from a derived class to one of its parent classes will be 
//performed.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//What catch blocks typically do
//If an exception is routed to a catch block, it is considered “handled” even if the catch block is empty. 
//However, typically you’ll want your catch blocks to do something useful. There are three common things 
//that catch blocks do when they catch an exception:

// First, catch blocks may print an error (either to the console, or a log file).
// Second, catch blocks may return a value or error code back to the caller.
// Third, a catch block may throw another exception. Because the catch block is outside of the try block, 
// the newly thrown exception in this case is not handled by the preceding try block -- it’s handled by 
// the next enclosing try block.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  Uncaught exceptions  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//When main() terminates with an unhandled exception, the operating system will generally notify you that 
//an unhandled exception error has occurred. How it does this depends on the operating system, but 
//possibilities include printing an error message, popping up an error dialog, or simply crashing. 
//Some OSes are less graceful than others. Generally this is something you want to avoid altogether!
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Since it’s possible to call functions without knowing how they are even implemented (and thus, what type 
//of exceptions they may throw), how can we possibly prevent this from happening?
//Fortunately, C++ provides us with a mechanism to catch all types of exceptions. This is known as a 
//catch-all handler. A catch-all handler works just like a normal catch block, except that instead of 
//using a specific type to catch, it uses the ellipses operator (…) as the type to catch. For this 
//reason, the catch-all handler is also sometimes called an “ellipsis catch handler”
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void runGame(); // Function prototype
void saveState(); // Function prototype


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  Exception classes  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//One of the major problems with using basic data types (such as int) as exception types is that they are 
//inherently vague. An even bigger problem is disambiguation of what an exception means when there are 
//multiple statements or function calls within a try block. One way to solve this problem is to use 
//exception classes. An exception class is just a normal class that is designed specifically to be thrown 
//as an exception.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

class ArrayException
{
private:
	std::string m_error;

public:
	ArrayException(std::string error)
		: m_error{ error }
	{
	}

	std::string getError() const { return m_error; }
//	const char* getError() const { return m_error.c_str(); } // C++14 or earlier, use this instead
};

class IntArray
{
private:

	int m_data[3]{}; // assume array is length 3 for simplicity
public:
	IntArray() {}

	int getLength() const { return 3; }

	int& operator[](const int index)
	{
		if (index < 0 || index >= getLength())
			throw ArrayException{ "Invalid index" };

		return m_data[index];
	}

};


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Note that exception handlers should catch class exception objects by reference instead of by value. This 
//prevents the compiler from making a copy of the exception, which can be expensive when the exception is a 
//class object, and prevents object slicing when dealing with derived exception classes (which we’ll talk 
//about in a moment). Catching exceptions by pointer should generally be avoided unless you have a specific 
//reason to do so.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  Exceptions and inheritance  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Since it’s possible to throw classes as exceptions, and classes can be derived from other classes, we need 
//to consider what happens when we use inherited classes as exceptions. As it turns out, exception handlers 
//will not only match classes of a specific type, they’ll also match classes derived from that specific type 
//as well! Consider the following example:
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
class Base
{
public:
    Base() {}
};

class Derived: public Base
{
public:
    Derived() {}
};

//It’s up to you whether you want create your own standalone exception classes, 
//use the standard exception classes, or derive your own exception classes from 
//std::exception or std::runtime_error. All are valid approaches depending on 
//your aims.


//Using the catch-all handler to wrap main()
//One interesting use for the catch-all handler is to wrap the contents of main():
int main()
{
    try
    {
        //Here’s a full program that uses throw, try, and multiple catch blocks:
        try
        {
            // Statements that may throw exceptions you want to handle go here
            throw -1; // here's a trivial example
        }
        catch (int x)
        {
            // Any exceptions of type int thrown within the above try block get sent here
            std::cerr << "We caught an int exception with value: " << x << '\n';
        }
        catch (double) // no variable name since we don't use the exception itself in the catch block below
        {
            // Any exceptions of type double thrown within the above try block get sent here
            std::cerr << "We caught an exception of type double" << '\n';
        }
        catch (const std::string& str) // catch classes by const reference
        {
            // Any exceptions of type std::string thrown within the above try block get sent here
            std::cerr << "We caught an exception of type std::string" << '\n';
        }

        std::cout << "Continuing on our merry way\n";

        //Exceptions are handled immediately
        try
        {
            throw 4.5; // throw exception of type double
            std::cout << "This never prints\n";
            //Note that “This never prints” is never printed, 
            //because the exception caused the execution path 
            //to jump immediately to the exception handler 
            //for doubles.
        }
        catch(double x) // handle exception of type double
        {
            std::cerr << "We caught a double of value: " << x << '\n';
        }

        std::cout << "Continuing on our merry way\n";

        std::cout << "Enter a number: ";
        double x {};
        std::cin >> x;

        try // Look for exceptions that occur within try block and route to attached catch block(s)
        {
            // If the user entered a negative number, this is an error condition
            if (x < 0.0)
                throw "Can not take sqrt of negative number"; // throw exception of type const char*

            // Otherwise, print the answer
            std::cout << "The sqrt of " << x << " is " << std::sqrt(x) << '\n';
        }
        catch (const char* exception) // catch exceptions of type const char*
        {
            std::cerr << "Error: " << exception << '\n';
        }


        //catch-all handler example
        try
        {
            throw 5; // throw an int exception
        }
        catch (double x)
        {
            std::cout << "We caught an exception of type double: " << x << '\n';
        }
        catch (...) // catch-all handler
        {
            std::cout << "We caught an exception of an undetermined type\n";
        }

        //The catch-all handler must be placed last in the catch block chain. 
        //This is to ensure that exceptions can be caught by exception handlers 
        //tailored to specific data types if those handlers exist.

        //Often, the catch-all handler block is left empty:
        // catch(...) {} // ignore any unanticipated exceptions

        //This will catch any unanticipated exceptions and prevent them from 
        //stack unwinding to the top of your program, but does no specific 
        //error handling.

        runGame();
    }
    catch (...)
    {
        std::cerr << "Abnormal termination\n";
    }


    saveState(); // Save user's game

    // return 1; 

    //In this case, if runGame() or any of the functions it calls throws an exception 
    //that is not caught, that exception will unwind the stack and eventually get caught 
    //by this catch-all handler. This will prevent main() from terminating, and gives us 
    //a chance to print an error of our choosing and then save the user’s state before 
    //exiting. This can be useful to catch and handle problems that may be unanticipated.

    //**************************************************************************************

    IntArray array;

	try
	{
        int my_value = array[1];
        std::cout << "my_value = " << my_value << '\n'; 

		int value{ array[5] }; // out of range subscript
	}
	catch (const ArrayException& exception)
	{
		std::cerr << "An array exception occurred (" << exception.getError() << ")\n";
	}


    //This way, the Derived handler will get first shot at catching 
    //objects of type Derived (before the handler for Base can). 
    //Objects of type Base will not match the Derived handler 
    //(Derived is-a Base, but Base is not a Derived), and thus 
    //will “fall through” to the Base handler.
    try
    {
        throw Derived();
    }
    catch (const Derived& derived)
    {
        std::cerr << "caught Derived\n";
    }
    catch (const Base& base)
    {
        std::cerr << "caught Base\n";
    }

    //Rule: Handlers for derived exception classes should be listed before those for base classes.
    //Because the derived object is a base too, and then the derived handler will never be used!


    return 0;
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// Inside the main function:
//In this case, the return statement stops the execution of the program, and 0 or 1 will denote the 
//execution status.
//These status codes are just used as a convention for a long time in C language because the language does 
//not support the objects and classes, and exceptions.
//return 0: A return 0 means that the program will execute successfully and did what it was intended to do.
//return 1: A return 1 means that there is some error while executing the program and it is not performing 
//what it was intended to do.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

void runGame()
{
    // Initialize the game
    // ...

    // Play the game
    // ...

    // Clean up the game
    // ...
}

void saveState()
{
    // Save the game state
    // ...
}







