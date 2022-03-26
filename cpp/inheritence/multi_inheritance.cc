#include <string>
#include <iostream>
#include <vector>
#include <functional> // reference_wrapper


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  Multiple inheritance  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//So far, all of the examples of inheritance we’ve presented have been single inheritance -- that is, each 
//inherited class has one and only one parent. However, C++ provides the ability to do multiple inheritance. 
//Multiple inheritance enables a derived class to inherit members from more than one parent.
//To use multiple inheritance, simply specify each base class (just like in single inheritance), separated 
//by a comma.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


//Multiple inheritance can be used to create a Teacher class 
//that inherits properties from both Person and Employee. 

class Person
{
private:
    std::string m_name;
    int m_age {};

public:
    Person(std::string name, int age)
        : m_name { name }, m_age { age }
    {
    }

    std::string getName() const { return m_name; }
    int getAge() const { return m_age; }
};


class Employee
{
private:
    std::string m_employer;
    double m_wage {};

public:
    Employee(std::string employer, double wage)
        : m_employer { employer }, m_wage { wage }
    {
    }

    std::string getEmployer() const { return m_employer; }
    double getWage() const { return m_wage; }
};


// Teacher publicly inherits Person and Employee
class Teacher: public Person, public Employee
{
private:
     int m_teachesGrade {};

public:
    Teacher(std::string name, int age, std::string employer, double wage, int teachesGrade)
        : Person { name, age }, Employee { employer, wage }, m_teachesGrade { teachesGrade }
    {
    }
};


//Problems with multiple inheritance:
//********************************************************************************
//While multiple inheritance seems like a simple extension of single inheritance, 
//multiple inheritance introduces a lot of issues that can markedly increase the 
//complexity of programs and make them a maintenance nightmare. Let’s take a look 
//at some of these situations.

//First, ambiguity can result when multiple base classes contain a function with the same name. For example:
class USBDevice
{
private:
    long m_id {};

public:
    USBDevice(long id)
        : m_id { id }
    {
    }

    long getID() const { return m_id; }
};


class NetworkDevice
{
private:
    long m_id {};

public:
    NetworkDevice(long id)
        : m_id { id }
    {
    }

    long getID() const { return m_id; }
};


class WirelessAdapter: public USBDevice, public NetworkDevice
{
public:
    WirelessAdapter(long usbId, long networkId)
        : USBDevice { usbId }, NetworkDevice { networkId }
    {
    }
};

//You can see how things can get complex when your class inherits from four or six base 
//classes, which inherit from other classes themselves.
//The potential for naming conflicts increases exponentially as you inherit 
//more classes, and each of these naming conflicts needs to be resolved explicitly.

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//Second, and more serious is the diamond problem, which your author likes to call 
//the “diamond of doom”. This occurs when a class multiply inherits from two classes 
//which each inherit from a single base class. This leads to a diamond shaped 
//inheritance pattern.

//For example, consider the following set of classes:
class PoweredDevice
{
};

class Scanner: public PoweredDevice
{
};

class Printer: public PoweredDevice
{
};

class Copier: public Scanner, public Printer
{
};


//There are many issues that arise in this context, including whether Copier 
//should have one or two copies of PoweredDevice, and how to resolve certain 
//types of ambiguous references. While most of these issues can be addressed 
//through explicit scoping, the maintenance overhead added to your classes in 
//order to deal with the added complexity can cause development time to skyrocket.


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//Many authors and experienced programmers believe multiple inheritance in C++ should 
//be avoided at all costs due to the many potential problems it brings. Your author 
//does not agree with this approach, because there are times and situations when 
//multiple inheritance is the best way to proceed. However, multiple inheritance 
//should be used extremely judiciously.

//As an interesting aside, you have already been using classes written using 
//multiple inheritance without knowing it: the iostream library objects std::cin 
//and std::cout are both implemented using multiple inheritance!

//=====================================================================================================
//=========================================== BEST PRACTICE ===========================================
//=====================================================================================================
// Avoid multiple inheritance unless alternatives lead to more complexity.
//=====================================================================================================

int main()
{
    std::cout << "\n============================================================================" << '\n';
    // Create a Teacher object
    Teacher teacher { "John", 30, "University of Texas", 100000, 100 };
    Teacher teacher2 { "Britney", 30, "University of Michigan", 100000, 100 };

    std::cout << teacher.getName() << " and " << teacher2.getName() 
    << " are working on a research project at ARPA (Advance Research Project Agency). \n";
    std::cout << "The project is funded by " << teacher.getEmployer() << " and " << teacher2.getEmployer() << ". \n";

    //********************************************************************************
    std::cout << "============================================================================" << '\n';

    WirelessAdapter c54G { 5442, 181742 };
    // std::cout << c54G.getID(); // Which getID() do we call?

    //You can explicitly specify which version you meant to call:
    std::cout << c54G.USBDevice::getID();

    std::cout << "\n============================================================================" << '\n';

    //********************************************************************************

    return 0;
}








