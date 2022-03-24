#include <iostream>
#include <string>

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  Dependencies  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//In casual conversation, we use the term dependency to indicate that an object is reliant upon another object for 
//a given task. For example, flowers are dependent upon bees to pollinate them, in order to grow fruit or propagate 
//(but not otherwise).
//A dependency occurs when one object invokes another object’s functionality in order to accomplish some specific 
//task. This is a weaker relationship than an association, but still, any change to object being depended upon may 
//break functionality in the (dependent) caller. A dependency is always a unidirectional relationship.

//A good example of a dependency that you’ve already seen many times is std::ostream. Our classes that use 
//std::ostream use it in order to accomplish the task of printing something to the console, but not otherwise.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


class Point
{
private:
    double m_x, m_y, m_z;

public:
    Point(double x=0.0, double y=0.0, double z=0.0): m_x(x), m_y(y), m_z(z)
    {
    }

    friend std::ostream& operator<< (std::ostream &out, const Point &point); // Point has a dependency on std::ostream here
};

std::ostream& operator<< (std::ostream &out, const Point &point)
{
    // Since operator << is a friend of the Point class, we can access Point's members directly.
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ")\n";

    return out;
}

//In the above code, Point isn’t directly related to std::ostream, but it has a 
//dependency on std::ostream since operator<< uses std::ostream to print the 
//Point to the console.


//******************************************************************************************************************
//*******************************  Dependencies vs Association in C++  *********************************************
//******************************************************************************************************************
//In C++, associations are a relationship between two classes at the class level. That is, one class keeps a direct 
//or indirect “link” to the associated class as a member. For example, a Doctor class has an array of pointers to 
//its Patients as a member. You can always ask the Doctor who its patients are. The Driver class holds the id of 
//the Car the driver object owns as an integer member. The Driver always knows what Car is associated with it.

//Dependencies typically are not represented at the class level -- that is, the object being depended on is not 
//linked as a member. Rather, the object being depended on is typically instantiated as needed (like opening a 
//file to write data to), or passed into a function as a parameter (like std::ostream in the overloaded 
//operator<< above).
//******************************************************************************************************************



//******************************************************************************************************************
//********************************************  Container classes  *************************************************
//******************************************************************************************************************
//In real life, we use containers all the time. Your breakfast cereal comes in a box, the pages in your book come 
//inside a cover and binding, and you might store any number of items in containers in your garage. The value the 
//container provides is largely in its ability to help organize and store items that are put inside it.

//Similarly, a container class is a class designed to hold and organize multiple instances of another type (either 
//another class, or a fundamental type). By far the most commonly used container in programming is the array, which 
//you have already seen many examples of. Although C++ has built-in array functionality, programmers will often use 
//an array container class (std::array or std::vector) instead because of the additional benefits they provide.

//Container classes typically implement a fairly standardized minimal set of functionality. 
//Most well-defined containers will include functions that:
//------------------------------------------------------------------------------------------
// Create an empty container (via a constructor)
// Insert a new object into the container
// Remove an object from the container
// Report the number of objects currently in the container
// Empty the container of all objects
// Provide access to the stored objects
// Sort the elements (optional)

//Container classes implement a member-of relationship. For example, elements of an array are members-of 
//(belong to) the array. Note that we’re using “member-of” in the conventional sense, not the C++ class 
//member sense.

//Container classes generally come in two different varieties. Value containers are compositions that store copies 
//of the objects that they are holding (and thus are responsible for creating and destroying those copies). 
//Reference containers are aggregations that store pointers or references to other objects (and thus are not 
//responsible for creation or destruction of those objects).
//Unlike in real life, where containers can hold whatever types of objects you put in them, in C++, containers 
//typically only hold one type of data.

//Despite the restrictions on their use, containers are immensely useful, and they make programming easier, 
//safer, and faster.
//******************************************************************************************************************


//=====================================================================================================
//=========================================== BEST PRACTICE ===========================================
//=====================================================================================================
//If a class in the standard library meets your needs, use that instead of creating your own. It’s 
//battle tested, efficient, and plays nicely with the other classes in the standard library. But 
//sometimes you need a specialized container class that doesn’t exist in the standard library, 
//so it’s good to know how to create your own when you need to.
//=====================================================================================================

int main()
{
    Point point1(2.0, 3.0, 4.0);

    std::cout << point1; // the program has a dependency on std::cout here

    return 0;
}


//Implementing a constructor that takes a std::initializer_list parameter allows us to use 
//list initialization with our custom classes. We can also use std::initializer_list to 
//implement other functions that need to use an initializer list, such as an assignment 
//operator.










