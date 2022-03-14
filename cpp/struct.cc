#include <iostream>
#include <string>

//A struct (short for structure) is a program-defined data type that allows 
//us to bundle multiple variables together into a single type. This makes 
//management of related sets of variables much simpler!

struct Employee
{
    int id {};
    std::string name{};
    int age {};
    double wage {};
};


//A function to create an Employee object
Employee createEmployee(int id, std::string name, int age, double wage)
{
    Employee e {};
    e.id = id;
    e.name = name;
    e.age = age;
    e.wage = wage;
    return e;
}


//A function to give an Employee a raise
void promoteEmployee(Employee& e)
{
    e.wage *= 1.4;
}


//A function to print an Employee
void printEmployee(Employee e)
{
    std::cout << "Employee ID: " << e.id << '\n';
    std::cout << "Employee Name: " << e.name << '\n';
    std::cout << "Employee Age: " << e.age << '\n';
    std::cout << "Employee Wage: " << e.wage << '\n';
}


int main()
{
    Employee meisam {};
    meisam.id = 1;
    meisam.name = "Meisam";
    meisam.age = 25;
    meisam.wage = 100.00;

    Employee frank { 15, "Frank" ,32, 60000.0 }; //preferred way of initializing a struct
    


    createEmployee(2, "Sonya" ,30, 200.00);
    createEmployee(3, "Sally" ,32, 300.00);
    createEmployee(4, "Sam" ,34, 400.00);

    std::cout << "Before promotion: " << '\n';
    std::cout << "===================================================" << '\n';

    printEmployee(meisam);

    //give Meisam a raise
    promoteEmployee(meisam);

    std::cout << "After promotion: " << '\n';
    std::cout << "===================================================" << '\n';

    printEmployee(meisam);

     std::cout << "===================================================" << '\n';

    Employee* ptr{ &frank }; //create a pointer to frank
    printEmployee(*ptr); //print frank using the pointer using the * operator

    //To make for a cleaner syntax, C++ offers a member selection from 
    //pointer operator (->) (also sometimes called the arrow operator) 
    //that can be used to select members from a pointer to an object:

    std::cout << "Frank's id: " << ptr->id << '\n'; // Better: use -> to select member from pointer to object


    return 0;
}