#include <array>
#include <chrono> // for std::chrono functions
#include <cstddef> // for std::size_t
#include <numeric> // for std::iota
#include <iostream>
#include <algorithm> // for std::sort


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

bool isEqual(const int value1, const int value2)
{
    return (value1 == value2);
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  Multiple friends  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//A function can be a friend of more than one class at the same time.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ Class prototypes @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Class prototypes serve the same role as function prototypes -- they tell the compiler what something 
//looks like so it can be used now and defined later. However, unlike functions, classes have no return 
//types or parameters, so class prototypes are always simply class ClassName, where ClassName is the 
//name of the class.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//This is a class prototype that tells the compiler that 
//we are going to define a class called Humidity in the 
//future. Without this line, the compiler would tell us 
//it doesn’t know what a Humidity is when parsing the 
//prototype for printWeather() inside the Temperature class.
class Humidity;

class Temperature
{
private:
    int m_temp {};

public:
    Temperature(int temp=0)
        : m_temp { temp }
    {
    }

    friend void printWeather(const Temperature& temperature, const Humidity& humidity);
};


class Humidity
{
private:
    int m_humidity {};

public:
    Humidity(int humidity=0)
        : m_humidity { humidity }
    {
    }

    friend void printWeather(const Temperature& temperature, const Humidity& humidity);
};


//This function is a friend of both Temperature and Humidity.
void printWeather(const Temperature& temperature, const Humidity& humidity)
{
    std::cout << "The temperature is " << temperature.m_temp <<
       " and the humidity is " << humidity.m_humidity << ".\n";
}


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  Friend classes  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//It is also possible to make an entire class a friend of another class. This gives all of the members 
//of the friend class access to the private members of the other class.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

class Storage
{
private:
    int m_nValue {};
    double m_dValue {};
public:
    Storage(int nValue, double dValue)
       : m_nValue { nValue }, m_dValue { dValue }
    {
    }

    // Make the Display class a friend of Storage
    friend class Display;
};

class Display
{
private:
    bool m_displayIntFirst;

public:
    Display(bool displayIntFirst)
         : m_displayIntFirst { displayIntFirst }
    {
    }

    void displayItem(const Storage& storage)
    {
        if (m_displayIntFirst)
            std::cout << storage.m_nValue << ' ' << storage.m_dValue << '\n';
        else // display double first
            std::cout << storage.m_dValue << ' ' << storage.m_nValue << '\n';
    }
};

//**********************************************************************************************************
//A few additional notes on friend classes. First, even though Display is a friend of Storage, Display has 
//no direct access to the *this pointer of Storage objects. Second, just because Display is a friend of 
//Storage, that does not mean Storage is also a friend of Display. If you want two classes to be friends 
//of each other, both must declare the other as a friend. Finally, if class A is a friend of B, and B is 
//a friend of C, that does not mean A is a friend of C.
//**********************************************************************************************************

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! WARNING !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//Be careful when using friend functions and classes, because it allows the friend function or class to 
//violate encapsulation. If the details of the class change, the details of the friend will also be 
//forced to change. Consequently, limit your use of friend functions and classes to a minimum.
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//**********************************************************************************************************
//An anonymous object is essentially a value that has no name. Because they have no name, there’s no way to
// refer to them beyond the point where they are created. Consequently, they have “expression scope”, meaning 
//they are created, evaluated, and destroyed all within a single expression. Here is the add() function 
//written using an anonymous object:
//**********************************************************************************************************

//Note how much cleaner this keeps our code -- we don’t have to litter 
//the code with temporary variables that are only used once.
int add(int x, int y)
{
    return x + y; // an anonymous object is created to hold and return the result of x + y
}

//Another example 
class Cents
{
private:
    int m_cents{};

public:
    Cents(int cents)
        : m_cents { cents }
    {}

    int getCents() const { return m_cents; }
};

void print(const Cents& cents)
{
   std::cout << cents.getCents() << " cents\n";
}

Cents add(const Cents& c1, const Cents& c2)
{
    Cents sum{ c1.getCents() + c2.getCents() };
    return sum;
}

//**********************************************************************************************************
//Much like functions and data can be members of a class, in C++, types can also be defined (nested) 
//inside of a class. To do this, you simply define the type inside the class, under the appropriate 
//access specifier.
//**********************************************************************************************************

class Fruit
{
public:
	// Note: we've moved FruitType inside the class, under the public access specifier
    //so the type definition can be accessed from outside the class.
	enum FruitType
	{
		apple,
		banana,
		cherry
	};

private:
	FruitType m_type {};
	int m_percentageEaten { 0 };

public:


	Fruit(FruitType type, int percentageEaten) :
		m_type { type }, m_percentageEaten { percentageEaten }
	{
	}

	FruitType getType() const { return m_type;  }
	int getPercentageEaten() const { return m_percentageEaten;  }
};

//**********************************************************************************************************
//When writing your code, sometimes you’ll run across cases where you’re not sure whether one method or 
//another will be more performant. So how do you tell? The good news is that we can easily encapsulate 
//all the timing functionality we need into a class that we can then use in our own programs.
//**********************************************************************************************************
class Timer
{
private:
	// Type aliases to make accessing nested type easier
	using clock_type = std::chrono::steady_clock;
	using second_type = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_type> m_beg { clock_type::now() };

public:
	void reset()
	{
		m_beg = clock_type::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_type>(clock_type::now() - m_beg).count();
	}
};


const int g_arrayElements { 10000 };

//A sorting function (Selection Sort)
void sortArray(std::array<int, g_arrayElements>& array)
{

    // Step through each element of the array
    // (except the last one, which will already be sorted by the time we get there)
    for (std::size_t startIndex{ 0 }; startIndex < (g_arrayElements - 1); ++startIndex)
    {
        // smallestIndex is the index of the smallest element we’ve encountered this iteration
        // Start by assuming the smallest element is the first element of this iteration
        std::size_t smallestIndex{ startIndex };

        // Then look for a smaller element in the rest of the array
        for (std::size_t currentIndex{ startIndex + 1 }; currentIndex < g_arrayElements; ++currentIndex)
        {
            // If we've found an element that is smaller than our previously found smallest
            if (array[currentIndex] < array[smallestIndex])
            {
                // then keep track of it
                smallestIndex = currentIndex;
            }
        }

        // smallestIndex is now the smallest element in the remaining array
        // swap our start element with our smallest element (this sorts it into the correct place)
        std::swap(array[startIndex], array[smallestIndex]);
    }
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

    //Note that we have to pass an Accumulator object to change_value_one(). 
    //This is because change_value_one() is not a member function. It does 
    //not have a *this pointer, nor does it have an Accumulator object to 
    //work with, unless given one.

    std::cout << std::boolalpha << isEqual(45, 60) << '\n';

    //**************************************************************************************

    Humidity hum(10);
    Temperature temp(12);

    printWeather(temp, hum);

    //**************************************************************************************

    Storage storage(5, 6.7); // create a Storage object
    Display display(false); // create a Display object

    display.displayItem(storage);

    //**************************************************************************************
    //Anonymous objects work not only with return values, but also with function parameters. 
    //function call using two anonymous objects:
    std::cout << "The sum of 5 and 6 is " << add(2 + 3, 3 + 3) << '\n'; 

    //one way
    Cents cents{ 6 };
    print(cents);

    //better way
    print(Cents{ 10 }); // create a Cents object anonymously (no temporary object defined)

    //one way
    Cents cents1{ 6 };
    Cents cents2{ 8 };
    Cents sum{ add(cents1, cents2) };
    std::cout << "I have " << sum.getCents() << " cents.\n";

    //better way (if we're gonna use cents1 and cents2 only once)
    std::cout << "I have " << add(Cents{6}, Cents{8}).getCents() << " cents.\n";

    //**************************************************************************************

    // Note: we access the FruitType via Fruit now
	Fruit apple { Fruit::apple , 20 };

	if (apple.getType() == Fruit::apple)
		std::cout << "I am an apple and " << apple.getPercentageEaten() << " percent of me is eaten!\n";
	else
		std::cout << "I am not an apple" << '\n';


    //**************************************************************************************

    std::array<int, g_arrayElements> array;
    std::iota(array.rbegin(), array.rend(), 1); // fill the array with values 10000 to 1

    Timer t1;

    sortArray(array);

    std::cout << "Time taken for our Selection Sort: " << t1.elapsed() << " seconds\n";

    Timer t2;

    std::sort(array.begin(), array.end());

    std::cout << "Time taken for Standard Library Sort: " << t2.elapsed() << " seconds\n";


    return 0;
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  A few caveats about timing @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Timing is straightforward, but your results can be significantly impacted by a number of things, and it’s important to 
//be aware of what those things are.

//First, make sure you’re using a release build target, not a debug build target. Debug build targets typically turn 
//optimization off, and that optimization can have a significant impact on the results. For example, using a debug 
//build target, running the above std::sort example on the author’s machine took 0.0235 seconds -- 33 times as long!

//Second, your timing results will be influenced by other things your system may be doing in the background. For best 
//results, make sure your system isn’t doing anything CPU or memory intensive (e.g. playing a game) or hard drive 
//intensive (e.g. searching for a file or running an antivirus scan).

//Then measure at least 3 times. If the results are all similar, take the average. If one or two results are different, 
//run the program a few more times until you get a better sense of which ones are outliers. Note that seemingly innocent 
//things, like web browsers, can temporarily spike your CPU to 100% utilization when the site you have sitting in the 
//background rotates in a new ad banner and has to parse a bunch of javascript. Running multiple times helps identify 
//whether your initial run may have been impacted by such an event.

//Third, when doing comparisons between two sets of code, be wary of what may change between runs that could impact timing. 
//Your system may have kicked off an antivirus scan in the background, or maybe you’re streaming music now when you weren’t 
//previously. Randomization can also impact timing. If we’d sorted an array filled with random numbers, the results could 
//have been impacted by the randomization. Randomization can still be used, but ensure you use a fixed seed (e.g. don’t use 
//the system clock) so the randomization is identical each run. Also, make sure you’re not timing waiting for user input, 
//as how long the user takes to input something should not be part of your timing considerations.

// Finally, note that results are only valid for your machine’s architecture, OS, compiler, and system specs. You may get 
//different results on other systems that have different strengths and weaknesses.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


