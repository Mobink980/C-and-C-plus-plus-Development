#include <iostream>
#include <string>

class Base
{
public:
    std::string getName() const { return "Base"; }
};

class Derived: public Base
{
public:
    std::string getName() const { return "Derived"; }
};

//Because rBase is a Base reference, it calls Base::getName(), even though 
//it’s actually referencing the Base portion of a Derived object. In this 
//lesson, we will show how to address this issue using virtual functions.
//When a function is virtual, the most derived matching function between 
//a set of derived classes will be called.  

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  Virtual functions and polymorphism  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//A virtual function is a special type of function that, when called, resolves to the most-derived version 
//of the function that exists between the base and derived class. This capability is known as polymorphism. 
//A derived function is considered a match if it has the same signature (name, parameter types, and whether 
//it is const) and return type as the base version of the function. Such functions are called overrides.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//To make a function virtual, simply place the “virtual” keyword before the function declaration.
class BaseNew
{
public:
    virtual std::string getName() const { return "BaseNew"; } // note addition of virtual keyword
};

class DerivedNew: public BaseNew
{
public:
    virtual std::string getName() const { return "DerivedNew"; }
};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//Another example
class Animal
{
protected:
    std::string m_name;

    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal(const std::string& name)
        : m_name{ name }
    {
    }

public:
    const std::string& getName() const { return m_name; }
    virtual std::string speak() const { return "???"; }
};

class Cat: public Animal
{
public:
    Cat(const std::string& name)
        : Animal{ name }
    {
    }

    std::string speak() const override { return "Meow"; }
};

class Dog: public Animal
{
public:
    Dog(const std::string& name)
        : Animal{ name }
    {
    }

    std::string speak() const override { return "Woof"; }
};

void report(const Animal& animal)
{
    std::cout << animal.getName() << " says " << animal.speak() << '\n';
}


//************************************************************************************
//A word of warning: the signature of the derived class function must exactly match 
//the signature of the base class virtual function in order for the derived class 
//function to be used. If the derived class function has different parameter types, 
//the program will likely still compile fine, but the virtual function will not 
//resolve as intended.
//Also note that if a function is marked as virtual, all matching overrides are also 
//considered virtual, even if they are not explicitly marked as such.
//************************************************************************************


//=====================================================================================================
//=========================================== BEST PRACTICE ===========================================
//=====================================================================================================
//Never call virtual functions from constructors or destructors.
//If you were to call a virtual function from the Base constructor, and Derived portion of the class 
//hadn’t even been created yet, it would be unable to call the Derived version of the function because 
//there’s no Derived object for the Derived function to work on. In C++, it will call the Base version 
//instead.
//A similar issue exists for destructors. If you call a virtual function in a Base class destructor, 
//it will always resolve to the Base class version of the function, because the Derived portion of the 
//class will already have been destroyed.
//=====================================================================================================

//The downside of virtual functions
//-----------------------------------------------------------------------------------------------------
//Since most of the time you’ll want your functions to be virtual, why not just make all functions 
//virtual? The answer is because it’s inefficient -- resolving a virtual function call takes longer 
//than resolving a regular one. Furthermore, the compiler also has to allocate an extra pointer for 
//each class object that has one or more virtual functions. We’ll talk about this more in future 
//lessons in this chapter.


////////////////////////////////////////////////////////////////////////////////////////////////////
//As we mentioned in the previous lesson, a derived class virtual function is only 
//considered an override if its signature and return types match exactly. That can 
//lead to inadvertent issues, where a function that was intended to be an override 
//actually isn’t.
//To help address the issue of functions that are meant to be overrides but aren’t, the 
//override specifier can be applied to any virtual function by placing the specifier in 
//the same place const would go. If the function does not override a base class function 
//(or is applied to a non-virtual function), the compiler will flag the function as an error.
////////////////////////////////////////////////////////////////////////////////////////////////////

//=====================================================================================================
//=========================================== BEST PRACTICE ===========================================
//=====================================================================================================
//Use the virtual keyword on virtual functions in a base class. Use the override specifier (but not 
//the virtual keyword) on override functions in derived classes.
//=====================================================================================================


class A
{
public:
	virtual std::string getName1(int x) { return "A"; }
	virtual std::string getName2(int x) { return "A"; }
	virtual std::string getName3(int x) { return "A"; }
};

class B : public A
{
public:
	// std::string getName1(short int x) override { return "B"; } // compile error, function is not an override
	// std::string getName2(int x) const override { return "B"; } // compile error, function is not an override
	std::string getName3(int x) override { return "B"; } // okay, function is an override of A::getName3(int)

};


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@  Pure virtual (abstract) functions and abstract base classes  @@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//So far, all of the virtual functions we have written have a body (a definition). However, C++ allows you 
//to create a special kind of virtual function called a pure virtual function (or abstract function) that 
//has no body at all! A pure virtual function simply acts as a placeholder that is meant to be redefined 
//by derived classes.
//To create a pure virtual function, rather than define a body for the function, we simply assign the 
//function the value 0.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

class BaseClass
{
public:
    const char* sayHi() const { return "Hi"; } // a normal non-virtual function

    virtual const char* getName() const { return "Base"; } // a normal virtual function

    virtual int getValue() const = 0; // a pure virtual function

    // int doSomething() = 0; // Compile error: can not set non-virtual functions to 0
};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Using a pure virtual function has two main consequences: First, any class with one or more pure virtual 
//functions becomes an abstract base class, which means that it can not be instantiated! Consider what would 
//happen if we could create an instance of Base: what would base.getValue() resolve to?!
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//A pure virtual function is useful when we have a function that we want to put in the base class, but only 
//the derived classes know what it should return. A pure virtual function makes it so the base class can 
//not be instantiated, and the derived classes are forced to define these functions before they can be 
//instantiated. This helps ensure the derived classes do not forget to redefine functions that the base 
//class was expecting them to.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//It is possible to define a pure virtual function that has a body (the body must be provided separately (not inline)).
//This paradigm can be useful when you want your base class to provide a default implementation for a function, but 
//still force any derived classes to provide their own implementation. However, if the derived class is happy with 
//the default implementation provided by the base class, it can simply call the base class implementation directly. 

class Laptop // This Animal is an abstract base class
{
protected:
    std::string m_name;

public:
    Laptop(const std::string& name)
        : m_name(name)
    {
    }

    const std::string& getName() const { return m_name; }
    virtual const char* speak() const = 0; // note that speak is a pure virtual function

    virtual ~Laptop() = default;
};

const char* Laptop::speak() const
{
    return "Je suis un portable!"; // some default implementation
}

class Lenovo: public Laptop
{

public:
    Lenovo(const std::string& name)
        : Laptop{name}
    {
    }

    const char* speak() const override// this class is no longer abstract because we defined this function
    {
        return Laptop::speak(); // use Animal's default implementation
    }
};


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  Interface classes  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//An interface class is a class that has no member variables, and where all of the functions are pure 
//virtual! In other words, the class is purely a definition, and has no actual implementation. Interfaces 
//are useful when you want to define the functionality that derived classes must implement, but leave the 
//details of how the derived class implements that functionality entirely up to the derived class.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//Interface classes are often named beginning with an I. Here’s a sample interface class:
class IErrorLog
{
public:
    virtual bool openLog(const char *filename) = 0;
    virtual bool closeLog() = 0;

    virtual bool writeError(const char *errorMessage) = 0;

    virtual ~IErrorLog() 
    {
        // make a virtual destructor in case we delete an IErrorLog 
        //pointer, so the proper derived destructor is called
    } 
};

//Don’t forget to include a virtual destructor for your interface classes, 
//so that the proper derived destructor will be called if a pointer to the 
//interface is deleted.

int main()
{
    Derived derived;
    Base& rBase{ derived };
    std::cout << "rBase is a " << rBase.getName() << '\n';


    //********************************************************************************
    std::cout << "============================================================================\n";

    DerivedNew derivedNew;
    BaseNew& rBaseNew{ derivedNew }; 
    std::cout << "rBaseNew is a " << rBaseNew.getName() << '\n';

    //********************************************************************************
    std::cout << "============================================================================\n";

    Cat cat{ "Fred" };
    Dog dog{ "Garbo" };

    report(cat);
    report(dog);

    Cat fred{ "Fred" };
    Cat misty{ "Misty" };
    Cat zeke{ "Zeke" };

    Dog garbo{ "Garbo" };
    Dog pooky{ "Pooky" };
    Dog truffle{ "Truffle" };

    // Set up an array of pointers to animals, and set those pointers to our Cat and Dog objects
    Animal* animals[]{ &fred, &garbo, &misty, &pooky, &truffle, &zeke };

    for (const auto *animal : animals)
        std::cout << animal->getName() << " says " << animal->speak() << '\n';


    //Even though these two examples only use Cat and Dog, any other classes we derive from Animal 
    //would also work with our report() function and animal array without further modification! 
    //This is perhaps the biggest benefit of virtual functions -- the ability to structure your 
    //code in such a way that newly derived classes will automatically work with the old code 
    //without modification!

    //********************************************************************************
    std::cout << "============================================================================\n";

    Lenovo ideapad350{"ideapad350"}; 
    std::cout << ideapad350.getName() << " wants to say: " << ideapad350.speak() << '\n';

    return 0;
}


//Interface classes have become extremely popular because they are easy to use, easy to extend, and easy to maintain. 
//In fact, some modern languages, such as Java and C#, have added an “interface” keyword that allows programmers to 
//directly define an interface class without having to explicitly mark all of the member functions as abstract.







