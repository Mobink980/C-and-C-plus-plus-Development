#include <string>
#include <iostream>
#include <vector>
#include <functional> // reference_wrapper
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  Inheritance  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//In the last chapter, we discussed object composition, where complex classes are constructed from simpler classes 
//and types. Object composition is perfect for building new objects that have a “has-a” relationship with their 
//parts. However, object composition is just one of the two major ways that C++ lets you construct complex classes. 
//The second way is through inheritance, which models an “is-a” relationship between two objects.

//Unlike object composition, which involves creating new objects by combining and connecting other objects, 
//inheritance involves creating new objects by directly acquiring the attributes and behaviors of other objects 
//and then extending or specializing them. 

//example: When you were conceived, you inherited your parents genes, and acquired physical attributes from both 
//of them -- but then you added your own personality on top. Technological products (computers, cell phones, etc…) 
//inherit features from their predecessors (often used for backwards compatibility). For example, the Intel Pentium 
//processor inherited many of the features defined by the Intel 486 processor, which itself inherited features from 
//earlier processors. C++ inherited many features from C, the language upon which it is based.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


//******************************************************************************************************************
//********************************************  C++ Inheritance  ***************************************************
//******************************************************************************************************************
//Inheritance in C++ takes place between classes. In an inheritance (is-a) relationship, the class being inherited 
//from is called the parent class, base class, or superclass, and the class doing the inheriting is called the 
//child class, derived class, or subclass.
//A child class inherits both behaviors (member functions) and properties (member variables) from the parent 
//(subject to some access restrictions). These variables and functions become members of the derived class.
//Because child classes are full-fledged classes, they can (of course) have their own members that are specific 
//to that class.

//Inheritance not only saves work, but also means that if we ever update or modify the base class (e.g. add new 
//functions, or fix a bug), all of our derived classes will automatically inherit the changes!
//******************************************************************************************************************

//Here’s a simple class to represent a generic person:

class Person
{
// In this example, we're making our members public for simplicity
public:
    std::string m_name{};
    int m_age{};

    Person(const std::string& name = "", int age = 0)
        : m_name{ name }, m_age{ age }
    {
    }

    const std::string& getName() const { return m_name; }
    int getAge() const { return m_age; }

};


//To have BaseballPlayer inherit from our Person class, the syntax 
//is fairly simple. After the class BaseballPlayer declaration, we 
//use a colon, the word “public”, and the name of the class we wish 
//to inherit. This is called public inheritance.

// BaseballPlayer publicly inheriting Person
class BaseballPlayer : public Person
{
public:
    double m_battingAverage{};
    int m_homeRuns{};

    BaseballPlayer(double battingAverage = 0.0, int homeRuns = 0)
       : m_battingAverage{battingAverage}, m_homeRuns{homeRuns}
    {
    }
};


class Employee : public Person
{
public:
    std::string m_employeeNumber{};
    std::string m_jobTitle{};
    double m_hourlySalary{};
    long m_employeeID{};

    Employee(const std::string& employeeNumber = "", const std::string& jobTitle = "", 
    double hourlySalary = 0.0, long employeeID = 0)
        : m_employeeNumber{ employeeNumber }, m_jobTitle{ jobTitle }, 
        m_hourlySalary{hourlySalary}, m_employeeID{employeeID}
    {
    }

    //Note that printNameAndSalary() uses variables both from the class it 
    //belongs to (Employee::m_hourlySalary) and the parent class (Person::m_name).
    void printNameAndSalary() const
    {
        std::cout << m_name << " has a salary of $" << m_hourlySalary << " per hour.\n";
    }

    void printNameAndJobTitle() const
    {
        std::cout << m_name << " is a " << m_jobTitle << ".\n";
    }
};


//It’s possible to inherit from a class that is itself derived from another class.
class Supervisor: public Employee
{
public:
    // This Supervisor can oversee a bunch employees
    std::vector<std::reference_wrapper<const Employee>> m_overseesEmployees{};

    void addOverseesEmployee(const Employee& employee)
    {
        m_overseesEmployees.push_back(employee);
    }

    // We'll implement this function below Doctor since we need Doctor to be defined at that point
	friend std::ostream& operator<<(std::ostream& out, const Employee& employee);

};


std::ostream& operator<<(std::ostream& out, const Supervisor& supervisor)
{
	if (supervisor.m_overseesEmployees.empty())
	{
		out << supervisor.m_name << " is not supervising anyone right now.\n";
		return out;
	}

	out << supervisor.getName() << " is supervising: ";
	for (const auto& employee : supervisor.m_overseesEmployees)
		out << employee.get().getName() << ' ';

	return out;
}

//By constructing such inheritance chains, we can create a set of reusable classes 
//that are very general (at the top) and become progressively more specific at each 
//level of inheritance.



int main()
{
    // Create a new BaseballPlayer object
    BaseballPlayer joe{};
    // Assign it a name (we can do this directly because m_name is public)
    joe.m_name = "Joe";
    joe.m_age = 30;
    // use the getName() function we've acquired from the Person base class
    std::cout << joe.getName() << " has " << joe.getAge() <<" years old.\n"; 

    std::cout << "==========================================================" << '\n';

    // Create a new Employee object
    Employee jane{};
    // Assign it a name (we can do this directly because m_name is public)
    jane.m_name = "Jane";
    jane.m_age = 25;
    jane.m_hourlySalary = 400.0;
    jane.m_jobTitle = "Sales Representative";
    jane.printNameAndJobTitle();
    jane.printNameAndSalary();

    std::cout << "==========================================================" << '\n';

    Employee frank{"+1 234563", "Regional Manager", 200.25, 12345};
    frank.m_name = "Frank"; // we can do this because m_name is public
    frank.printNameAndJobTitle();
    frank.printNameAndSalary();

    std::cout << "==========================================================" << '\n';

    // Create a new Supervisor object
    Supervisor sam;
    sam.addOverseesEmployee(jane);
    sam.addOverseesEmployee(frank);
    sam.m_name = "Sam";
    sam.m_age = 35;
    sam.m_hourlySalary = 375.0;
    sam.m_jobTitle = "Supervisor";
    sam.m_employeeID = 123563;
    sam.printNameAndJobTitle();
    sam.printNameAndSalary();
    std::cout << sam << '\n';

    std::cout << "==========================================================" << '\n';

    Supervisor collette;
    // Sam is a supervisor, but he's also an employee, so he can be supervised (so can Collette).
    collette.addOverseesEmployee(sam);
    collette.m_name = "Collette";
    collette.m_age = 40;
    collette.m_hourlySalary = 500.0;
    collette.m_jobTitle = "Supervisor Supreme";
    collette.m_employeeID = 113564;
    collette.printNameAndJobTitle();
    collette.printNameAndSalary();
    std::cout << collette << '\n';

    return 0;
}








