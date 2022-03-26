#include <string>
#include <iostream>

//******************************************************************************
//One of the biggest benefits of using derived classes is the ability to reuse 
//already written code. You can inherit the base class functionality and then 
//add new functionality, modify existing functionality, or hide functionality 
//you don’t want.
//******************************************************************************


class Base
{
protected:
    int m_value {};

public:
    Base(int value)
        : m_value { value }
    {
    }

    void identify() const { std::cout << "I am a Base\n"; }

protected:
    void printValue() const { std::cout << m_value; }
};

//Now, let’s create a derived class that inherits from Base. 
//Because we want the derived class to be able to set the value 
//of m_value when derived objects are instantiated, we’ll make 
//the Derived constructor call the Base constructor in the 
//initialization list.

class Derived: public Base
{
public:
    Derived(int value)
        : Base { value }
    {
    }
    //Because m_value has been declared as protected in the Base class, 
    //Derived has direct access to it.
    int getValue() const { return m_value; }
};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//There may be times when we have access to a base class but do not want to modify it. Consider the 
//case where you have just purchased a library of code from a 3rd party vendor, but need some extra 
//functionality. You could add to the original code, but this isn’t the best solution. What if the 
//vendor sends you an update? Either your additions will be overwritten, or you’ll have to manually
//migrate them into the update, which is time-consuming and risky.
//Alternatively, there may be times when it’s not even possible to modify the base class. Consider the 
//code in the standard library. We aren’t able to modify the code that’s part of the standard library.
//The same goes for 3rd party libraries where you are provided with headers but the code comes precompiled.
//**********************************************************************************************************
//In either case, the best answer is to derive your own class, and add the functionality you want to the 
//derived class.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

class DerivedClass: public Base
{
public:
    DerivedClass(int value)
        : Base { value }
    {
    }

    int getValue() const { return m_value; }

    //To modify the way a function defined in a base class works 
    //in the derived class, simply redefine the function in the 
    //derived class.
    // Here's our modified function
    void identify() const { std::cout << "I am a Derived\n"; }
};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  Adding to existing functionality  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Sometimes we don’t want to completely replace a base class function, but instead want to add additional 
//functionality to it. In the above example, note that Derived::identify() completely hides Base::identify()! 
//This may not be what we want. It is possible to have our derived function call the base version of the 
//function of the same name (in order to reuse code) and then add additional functionality to it.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//To have a derived function call a base function of the same name, simply do a normal function call, but 
//prefix the function with the scope qualifier (the name of the base class and two colons). The following 
//example redefines Derived::identify() so it first calls Base::identify() and then does its own additional 
//stuff.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

class DerivedClassNew: public Base
{
public:
    DerivedClassNew(int value)
        : Base { value }
    {
    }

    int getValue() const  { return m_value; }

    void identify() const
    {
        Base::identify(); // call Base::identify() first
        std::cout << "I am a Derived\n"; // then identify ourselves
    }
};


//C++ gives us the ability to change an inherited member’s access specifier in the derived class.
//Let’s define a Derived class that changes the access specifier of printValue() to public:
class DerivedClassPublic: public Base
{
public:
    DerivedClassPublic(int value)
        : Base { value }
    {
    }

    // Base::printValue was inherited as protected, so the public has no access
    // But we're changing it to public via a using declaration
    using Base::printValue; // note: no parenthesis here
};

//You can never change the access specifier of a base member 
//from private to protected or public, because derived classes 
//do not have access to private members of the base class.

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  Hiding functionality  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//In C++, it is not possible to remove or restrict functionality from a base class other than by modifying 
//the source code. However, in a derived class, it is possible to hide functionality that exists in the base 
//class, so that it can not be accessed through the derived class. This can be done simply by changing the 
//relevant access specifier.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//For example, we can make a public member private:
class BasePrivate
{
public:
	int m_value {};
};

class DerivedClassMine : public BasePrivate
{
private:
	using BasePrivate::m_value;

public:
	DerivedClassMine(int value)
	// We can't initialize m_value, since it's a BasePrivate member (BasePrivate must initialize it)
	{
		// But we can assign it a value
		m_value = value;
        std::cout << "m_value has been redefined as private in the inherited class.";
        //Note that this allowed us to take a poorly designed base class 
        //and encapsulate its data in our derived class.
	}
};

//Alternatively, instead of inheriting Base’s members publicly and 
//making m_value private by overriding its access specifier, we 
//could have inherited Base privately, which would have caused all 
//of Base’s member to be inherited privately in the first place.


//You can also mark member functions as deleted in the derived 
//class, which ensures they can’t be called at all through a 
//derived object:
class MyBase
{
private:
	int m_value {};

public:
	MyBase(int value)
		: m_value { value }
	{
	}

	int getValue() const { return m_value; }
};

class DerivedDeleted : public MyBase
{
public:
	DerivedDeleted(int value)
		: MyBase { value }
	{
        std::cout << "function getValue() cannot be accessed using DerivedDeleted class.\n";
	}


	int getValue() = delete; // mark this function as inaccessible
};


int main()
{
    Derived derived { 5 };
    std::cout << "derived has value " << derived.getValue() << '\n';
    
    //Because Derived is a Base, Derived has access to stuff in Base. 
    //However, Base does not have access to anything in Derived.

    //******************************************************************************
    //When a member function is called with a derived class object, the compiler 
    //first looks to see if that member exists in the derived class. If not, it 
    //begins walking up the inheritance chain and checking whether the member has 
    //been defined in any of the parent classes. It uses the first one it finds.
    //******************************************************************************
    std::cout << "==========================================================" << '\n';

    Base base { 5 };
    base.identify();

    Derived derived_one { 7 };
    derived_one.identify(); //Base::identify() is used because Derived::identify() doesn’t exist.

    //This means that if the behavior provided by a base class is 
    //sufficient, we can simply use the base class behavior.

    std::cout << "==========================================================" << '\n';

    //******************************************************************************
    //Redefining behaviors:
    //If we had defined Derived::identify() in the Derived class, it would 
    //have been used instead. This means we can make functions work differently 
    //with our derived classes by redefining them in the derived class!
    DerivedClass derived_two { 7 };
    derived_two.identify();

    //A function that is defined as private in the base class can be 
    //redefined as public in the derived class, or vice-versa!

    std::cout << "==========================================================" << '\n';

    DerivedClassNew derived_three { 7 };
    derived_three.identify();

    std::cout << "==========================================================" << '\n';

    DerivedClassPublic derived_four { 7 };

    // printValue is public in DerivedClassPublic, so this is okay
    derived_four.printValue(); // prints 7

    std::cout << "\n==========================================================" << '\n';

    DerivedClassMine derived_mine { 7 };

	// The following won't work because m_value has been redefined as private
	// std::cout << derived_mine.m_value;

    std::cout << "\n==========================================================" << '\n';

    DerivedDeleted derived_five { 7 };

	// The following won't work because getValue() has been deleted!
	// std::cout << derived_five.getValue();

    std::cout << "==========================================================" << '\n';

    //Note that the Base version of getValue() is still accessible though. 
    //This means that a Derived object can still access getValue() by upcasting 
    //the Derived object to a Base first:

    // We can still access the function deleted in the Derived class through the Base class
	std::cout << static_cast<MyBase&>(derived_five).getValue();

    //We can cast a Derived object to a Base object (like casting a double into int). 

    std::cout << "\n==========================================================" << '\n';



    return 0;
}










