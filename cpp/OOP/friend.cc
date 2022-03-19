#include <array>
#include <iostream>

//**********************************************************************************************************
//For much of this chapter, we’ve been preaching the virtues of keeping your data private. 
//However, you may occasionally find situations where you will find you have classes and 
//functions outside of those classes that need to work very closely together. For example, 
//you might have a class that stores data, and a function (or another class) that displays 
//the data on the screen. Although the storage class and display code have been separated 
//for easier maintenance, the display code is really intimately tied to the details of the 
//storage class. Consequently, there isn’t much to gain by hiding the storage classes details 
//from the display code.
//Using friend classes and friend functions, you can give your display code access to the 
//private details of the storage class. This lets the display code directly access all the 
//private members and functions of the storage class, while keeping everyone else out!
//**********************************************************************************************************

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  Friend functions  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//A friend function is a function that can access the private members of a class as though it were a 
//member of that class. In all other regards, the friend function is just like a normal function. A 
//friend function may be either a normal function, or a member function of another class. To declare 
//a friend function, simply use the friend keyword in front of the prototype of the function you wish 
//to be a friend of the class. It does not matter whether you declare the friend function in the private 
//or public section of the class.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

class Accumulator
{
private:
    int m_value { 0 };

public:
    void add(int value) { m_value += value; }

    int getValue() { return m_value; }

    // Make the reset() function a friend of this class (efficient)
    friend void change_value_one(Accumulator& accumulator, int val);

    // An inefficent way to change the value of the accumulator object
    friend Accumulator change_value_two(Accumulator accumulator, int val);
};

// reset() is now a friend of the Accumulator class
//By using Accumulator& instead of Accumulator, we access the 
//original object by reference rather than making a copy of it.
void change_value_one(Accumulator& accumulator, int val)
{
    // And can access the private data of Accumulator objects
    accumulator.m_value = val;
}


//An inefficent way to change the value of the object is the following function.
//It takes an accumulator object, makes a copy of it, changes the value of the copy,
//and in order to use it, we have to return the copy and assign it to the original object.
//We said before that this is okay for fundamental data types (e.g. int, double, etc.),
//but not for objects (e.g. Accumulator, std::string, etc.).
Accumulator change_value_two(Accumulator accumulator, int val)
{
    accumulator.m_value = val;
    return accumulator;
}


int main()
{
    Accumulator acc;
    acc.add(5); // add 5 to the accumulator
    std::cout << acc.getValue() << '\n'; 

    //This is efficient, because we directly access the object by reference 
    //rather than making a copy of it that we just gonna throw away in a second. 
    change_value_one(acc, 100); 
    std::cout << acc.getValue() << '\n'; 

    //This is very inefficient (we copy the whole object, while we can change the value of the object by reference)
    acc = change_value_two(acc, 200); 
    std::cout << acc.getValue() << '\n';

    return 0;
}

