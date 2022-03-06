#include <iostream>

//As programs become larger, the number of identifiers increases linearly, 
//which in turn causes the probability of a naming collision occurring to increase exponentially.
//A way (when function names are the same) to avoid collisions is to put your functions into 
//your own namespaces. For this reason the standard library was moved into the std namespace.

void print() // this print lives in the global namespace
{
	std::cout << " there\n";
}


namespace foo // define a namespace named foo
{
    // This doSomething() belongs to namespace foo
    int doSomething(int x, int y)
    {
        return x + y;
    }

    void print() // this print lives in the foo namespace
	{
		std::cout << "Hello";
	}

	void printHelloThere()
	{
		print(); // calls print() in foo namespace
		::print(); // calls print() in global namespace
	}
}

namespace goo // define a namespace named goo
{
    // This doSomething() belongs to namespace goo
    int doSomething(int x, int y)
    {
        return x - y;
    }
}

// This doSomething() belongs to the global namespace
    int doSomething(int x, int y)
    {
        return x * y;
    }

//Namespaces can be nested inside other namespaces. For example:
namespace loo
{
    namespace hoo // hoo is a namespace inside the loo namespace
    {
        int add(int x, int y)
        {
            return x + y;
        }
    }
}

//When you write a library or code that you want to distribute to others, 
//always place your code inside a namespace. The code your library is used 
//it may not follow best practices -- in such a case, if your library’s 
//declarations aren’t in a namespace, there’s an elevated chance for naming 
//conflicts to occur. As an additional advantage, placing library code inside 
//a namespace also allows the user to see the contents of your library by using 
//their editor’s auto-complete and suggestion feature.

int main()
{
    //Getting the correct functuin from namespace using scope resolution operator (::)
    std::cout << foo::doSomething(4, 3) << '\n'; // use the doSomething() that exists in namespace foo
    std::cout << goo::doSomething(4, 3) << '\n'; // use the doSomething() that exists in namespace goo

    //Without scope resolution operator, the function in the global namespace is used (if it exists), or else, gives an error.
    std::cout << ::doSomething(4, 3) << '\n'; // explicitly use the doSomething() that exists in the global namespace
    foo::printHelloThere();
    std::cout << loo::hoo::add(1, 2) << '\n';
    namespace active = loo::hoo; // active now refers to loo::hoo
    std::cout << active::add(12, 14) << '\n'; // This is really loo::hoo::add()


    return 0;
}