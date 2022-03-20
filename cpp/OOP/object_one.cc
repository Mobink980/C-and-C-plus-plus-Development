#include <string>
#include <iostream>
#include "Creature.hh"
#include "Point2D.hh"

//**********************************************************************************************************
//When it comes to programming objects, the same patterns that govern real-life objects are applicable 
//to the programming objects we create ourselves. By examining these in more detail, we can better 
//understand how to improve code reusability and write classes that are more extensible.

//There are many different kinds of relationships two objects may have in real-life, and we use specific 
//“relation type” words to describe these relationships. For example: a square “is-a” shape. A car 
//“has-a” steering wheel. A computer programmer “uses-a” keyboard. A flower “depends-on” a bee for 
//pollination. A student is a “member-of” a class. And your brain exists as “part-of” you (at least, 
//we can reasonably assume so if you’ve gotten this far).
//**********************************************************************************************************

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  Object composition  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//In real-life, complex objects are often built from smaller, simpler objects. For example, a car is built 
//using a metal frame, an engine, some tires, a transmission, a steering wheel, and a large number of other 
//parts. A personal computer is built from a CPU, a motherboard, some memory, etc… Even you are built from 
//smaller parts: you have a head, a body, some legs, arms, and so on. This process of building complex 
//objects from simpler ones is called object composition.
//Broadly speaking, object composition models a “has-a” relationship between two objects. A car “has-a” 
//transmission. Your computer “has-a” CPU. You “have-a” heart. The complex object is sometimes called 
//the whole, or the parent. The simpler object is often called the part, child, or component.
//When we build classes with data members, we’re essentially constructing a complex object from simpler 
//parts, which is object composition. For this reason, structs and classes are sometimes referred to as 
//composite types.
//There are two basic subtypes of object composition: composition and aggregation. 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  Composition  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//To qualify as a composition, an object and a part must have the following relationship:
//  The part (member) is part of the object (class)
//  The part (member) can only belong to one object (class) at a time
//  The part (member) has its existence managed by the object (class) ==> “death relationship”
//  The part (member) does not know about the existence of the object (class) ==> unidirectional relationship
//A good real-life example of a composition is the relationship between a person’s body and a heart. 
//While object composition models has-a type relationships (a body has-a heart, a fraction has-a denominator), 
//we can be more precise and say that composition models “part-of” relationships (a heart is part-of a body, a 
//numerator is part of a fraction). Composition is often used to model physical relationships, where one object 
//is physically contained inside another.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//**********************************************************************************************************
//Compositions are one of the easiest relationship types to implement in C++. They are typically created 
//as structs or classes with normal data members. Because these data members exist directly as part of the 
//struct/class, their lifetimes are bound to that of the class instance itself.

//In general, if you can design a class using composition, you should design a class using composition. 
//Classes designed using composition are straightforward, flexible, and robust (in that they clean up 
//after themselves nicely).
//**********************************************************************************************************

int main()
{
    std::cout << "Enter a name for your creature: ";
    std::string name;
    std::cin >> name;
    Creature creature{ name, { 4, 7 } };

    while (true)
    {
        // print the creature's name and location
        std::cout << creature << '\n';

        std::cout << "Enter new X location for creature (-1 to quit): ";
        int x{ 0 };
        std::cin >> x;
        if (x == -1)
            break;

        std::cout << "Enter new Y location for creature (-1 to quit): ";
        int y{ 0 };
        std::cin >> y;
        if (y == -1)
            break;

        creature.moveTo(x, y);
    }

    return 0;
}

//**********************************************************************************************************************
//Although most compositions directly create their parts when the composition is created and directly 
//destroy their parts when the composition is destroyed, there are some variations of composition that 
//bend these rules a bit.
// A composition may defer creation of some parts until they are needed. For example, a string class may not 
// create a dynamic array of characters until the user assigns the string some data to hold.
// A composition may opt to use a part that has been given to it as input rather than create the part itself.
// A composition may delegate destruction of its parts to some other object (e.g. to a garbage collection routine).
//The key point here is that the composition should manage its parts without the user of the composition 
//needing to manage anything.
//**********************************************************************************************************************

//**********************************************************************************************************************
//One question that new programmers often ask when it comes to object composition is, “When should I use a subclass 
//instead of direct implementation of a feature?”. Some benefits of using subclasses:

// 1. Each individual class can be kept relatively simple and straightforward, focused on performing one task well. 
//This makes those classes easier to write and much easier to understand, as they are more focused. For example, 
//Point2D only worries about point-related stuff, which helps keep it simple.

// 2. Each subclass can be self-contained, which makes them reusable. For example, we could reuse our Point2D class 
//in a completely different application. Or if our creature ever needed another point (for example, a destination it 
//was trying to get to), we can simply add another Point2D member variable.

// 3. The parent class can have the subclasses do most of the hard work, and instead focus on coordinating the data 
//flow between the subclasses. This helps lower the overall complexity of the parent object, because it can delegate 
//tasks to its children, who already know how to do those tasks. For example, when we move our Creature, it delegates 
//that task to the Point class, which already understands how to set a point. Thus, the Creature class does not have 
//to worry about how such things would be implemented.

//In this case of our example, it makes sense that Creature shouldn’t have to worry about how Points are implemented, 
//or how the name is being stored. Creature’s job isn’t to know those intimate details. Creature’s job is to worry 
//about how to coordinate the data flow and ensure that each of the subclasses knows what it is supposed to do. It’s 
//up to the individual subclasses to worry about how they will do it.
//**********************************************************************************************************************

//=====================================================================================================
//=========================================== BEST PRACTICE ===========================================
//=====================================================================================================
//A good rule of thumb is that each class should be built to accomplish a single task. That task 
//should either be the storage and manipulation of some kind of data (e.g. Point2D, std::string), 
//OR the coordination of subclasses (e.g. Creature). Ideally not both.
//=====================================================================================================






































