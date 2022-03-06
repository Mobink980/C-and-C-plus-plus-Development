#include<iostream>
#include <string> // allows use of std::string
#include <cstdlib> // for std::rand() and std::srand()
#include<time.h>

//There are many instances in programming where we need more than 
//one variable in order to represent an object. For example, to 
//represent yourself, you might want to store your name, your 
//birthday, your height, your weight, or any other number of 
//characteristics about yourself.

//Fortunately, C++ allows us to create our own user-defined aggregate 
//data types (instead of independent variables). An aggregate data type 
//is a data type that groups multiple individual variables together. 
//One of the simplest aggregate data types is the struct. A struct 
//(short for structure) allows us to group variables of mixed data 
//types together into a single unit.

//If you want to share a struct definition across multiple files 
//(so you can instantiate variables of that struct type in multiple files), 
//put the struct definition in a header file, and #include that header file 
//anywhere you need it.

//Structs are very important in C++, as another aggregate data type 
//called a class, is built on top of structs.

struct Employee
{
    int id{};
    std::string name{};
    int age{};
    double wage{};
};

//Structs can contain other structs.
struct Company
{
    Employee CEO{}; // Employee is a struct within the Company struct
    int numberOfEmployees{};
};

void printInformation(Employee employee)
{
    std::cout << "ID:   " << employee.id << '\n';
    std::cout << "Name: " << employee.name << '\n';
    std::cout << "Age:  " << employee.age << '\n';
    std::cout << "Wage: " << employee.wage << '\n';
}

double getRandomNumber(); //function prototype

int main()
{
    //As with normal variables, struct member variables are not initialized 
    //by default, and will typically contain junk. We must initialize or 
    //assign values to them manually.

    // create an Employee struct for Joe 
    Employee joe; //struct Employee is capitalized, variable joe is not
    joe.id = 14; // assign a value to member id within struct joe
    joe.name = "Joe"; // assign a value to member name within struct joe
    joe.age = 32; // assign a value to member age within struct joe
    joe.wage = 2400.15; // assign a value to member wage within struct joe

    double randomWage = getRandomNumber(); // get a random number

    Employee frank; // create an Employee struct for Frank
    frank.id = 15; // assign a value to member id within struct frank
    frank.name = "Frank"; // assign a value to member name within struct frank
    frank.age = 28; // assign a value to member age within struct frank
    frank.wage = randomWage; // assign a value to member wage within struct frank   

    // faster way to create an Employee struct (using an initializer list)
    Employee cassie{ 1, "Cassie" ,32, 60000.0 }; // cassie.id = 1, cassie.age = 32, cassie.wage = 60000.0
    Employee sonya{ 21, "Sonya" ,26, 3000.0 }; // sonya.id = 21, sonya.age = 26, sonya.wage = 3000.0
    Employee emma{ 2, "Emma" ,28 }; // emma.id = 2, emma.age = 28, emma.wage = 0.0 (default initialization)

    // It's also possible to copy all members from one variable to another
    Employee jackson{ joe };

    Company specialForces; // create a Company struct
    specialForces.numberOfEmployees = 10; // assign a value to member numberOfEmployees within struct specialForces
    specialForces.CEO = joe; // assign the value of joe to the CEO member of specialForces

    

    // Print Cassie's information
    printInformation(cassie);

    std::cout << "========================================================\n";

    // Print Emma's information
    printInformation(emma);

    std::cout << "========================================================\n";

    std::cout << "The wage of the CEO (" << specialForces.CEO.name << ") is " << specialForces.CEO.wage << ".\n";
    std::cout << "The wage of the General (" << sonya.name << ") is " << sonya.wage << ".\n";
    std::cout << "The wage of Liutenant " << frank.name << " is " << frank.wage << ".\n";

    return 0;
}


double getRandomNumber()
{
    // Use current time as seed for random generator
    srand(time(0));

    // get a random number between 0 and RAND_MAX
    int randomNumber = std::rand();

    // convert the random number to a double
    double randomDouble = (randomNumber / static_cast<double>(RAND_MAX)) * 10000;

    return randomDouble;
}


