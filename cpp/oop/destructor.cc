#include <iostream>
#include <cassert>
#include <cstddef>

//**********************************************************************************************************
//**************************************  Why C++  *********************************************************
//**********************************************************************************************************
//There are some characteristics of C++ like closeness to hardware, better object management, speed, 
//performance, etc. which makes it more powerful than Java and thus motivate the developers to use C++ 
//for low-level programming, high-speed gaming applications, system programming, etc.

//Java was mainly designed for application programming (platform-independent) and has a functionality of 
//an interpreter for printing systems which was later developed into network computing.

//C++ is close to hardware and has many libraries that can manipulate the hardware resources. 
//Because of its closeness to hardware, C++ is often used for system programming, gaming applications, 
//operating system, and compilers.
//Java is mostly an application development language and is not close to the hardware.
//**********************************************************************************************************
//**********************************************************************************************************

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  DESTRUCTORS  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//A destructor is another special kind of class member function that is executed when an object of that 
//class is destroyed. Whereas constructors are designed to initialize a class, destructors are designed 
//to help clean up.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//For simple classes (those that just initialize the values of normal member variables), a destructor 
//is not needed because C++ will automatically clean up the memory for you.

//However, if your class object is holding any resources (e.g. dynamic memory, or a file or database 
//handle), or if you need to do any kind of maintenance before the object is destroyed, the destructor 
//is the perfect place to do so, as it is typically the last thing to happen before the object is destroyed.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Like constructors, destructors have specific naming rules:

//1. The destructor must have the same name as the class, preceded by a tilde (~).
//2. The destructor can not take arguments.
//3. The destructor has no return type.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// A class can only have a single destructor.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


class IntArray
{

IntArray(const IntArray&) = delete;
IntArray& operator=(const IntArray&) = delete;

private:
	int* m_array{};
	int m_length{};

public:

	IntArray(int length) // constructor
	{
		assert(length > 0);

		m_array = new int[static_cast<std::size_t>(length)]{};
		m_length = length;
	}

	~IntArray() // destructor
	{
		// Dynamically delete the array we allocated earlier in constructor.
		delete[] m_array;
	}

	void setValue(int index, int value) { m_array[index] = value; }
	int getValue(int index) { return m_array[index]; }

	int getLength() { return m_length; }
};


class Simple
{
private:
    int m_nID{};

public:
    Simple(int nID)
        : m_nID{ nID }
    {
        std::cout << "Constructing Simple " << nID << '\n';
    }

    ~Simple()
    {
        std::cout << "Destructing Simple" << m_nID << '\n';
    }

    int getID() { return m_nID; }
};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Global variables are constructed before main() and destroyed after main().
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Note that if you use the exit() function, your program will terminate and no 
//destructors will be called. Be wary if you’re relying on your destructors to 
//do necessary cleanup work (e.g. write something to a log file or database 
//before exiting).
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//As you can see, when constructors and destructors are used together, your classes 
//can initialize and clean up after themselves without the programmer having to do 
//any special work! This reduces the probability of making an error, and makes 
//classes easier to use.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


int main()
{
    //parenthesis based initialization should be used 
    //when initializing an array/container/list class 
    //with a length (as opposed to a list of elements).
    //For this reason, we initialize IntArray using IntArray ar ( 10 );. 
	IntArray ar ( 10 ); // allocate 10 integers
	for (int count{ 0 }; count < ar.getLength(); ++count)
		ar.setValue(count, count+1);

	std::cout << "The value of element 5 is: " << ar.getValue(4) << '\n';

    //=======================================================================
    // Allocate a Simple on the stack
    Simple simple{ 1 };
    std::cout << simple.getID() << '\n';

    // Allocate a Simple dynamically
    Simple* pSimple{ new Simple{ 2 } };

    std::cout << pSimple->getID() << '\n';

    // We allocated pSimple dynamically, so we have to delete it.
    delete pSimple;

	return 0;

} // ar is destroyed here, so the ~IntArray() destructor function is called here
// simple goes out of scope here (after the main())



