#include <string>
#include <iostream>

//*********************************************************************************************
//In this lesson, we’ll take a closer look at public inheritance, as well as the two other 
//kinds of inheritance (private and protected). We’ll also explore how the different kinds 
//of inheritance interact with access specifiers to allow or restrict access to members.
//*********************************************************************************************


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  The protected access specifier  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//C++ has a third access specifier that we have yet to talk about because it’s only useful in an inheritance 
//context. The protected access specifier allows the class the member belongs to, friends, and derived classes 
//to access the member. However, protected members are not accessible from outside the class.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

class Base
{
public:
    int m_public {}; // can be accessed by anybody
protected:
    int m_protected {}; // can be accessed by Base members, friends, and derived classes
private:
    int m_private {}; // can only be accessed by Base members and friends (but not derived classes)
};

class Derived: public Base
{
public:
    Derived()
    {
        m_public = 1; // allowed: can access public base members from derived class
        m_protected = 2; // allowed: can access protected base members from derived class
        // m_private = 3; // not allowed: can not access private base members from derived class
    }
};


//=====================================================================================================
//=========================================== BEST PRACTICE ===========================================
//=====================================================================================================
//In general, it’s better to make your members private if you can, and only use protected when derived 
//classes are planned and the cost to build and maintain an interface to those private members is too 
//high. Favor private members over protected members.
//=====================================================================================================

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@  Different kinds of inheritance, and their impact on access  @@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//First, there are three different ways for classes to inherit from other classes: public, protected, and private.
//To do so, simply specify which type of access you want when choosing the class to inherit from:
// Inherit from Base publicly
class Pub: public Base
{
};

// Inherit from Base protectedly
class Pro: protected Base
{
};

// Inherit from Base privately
class Pri: private Base
{
};

class Def: Base // Defaults to private inheritance
{
};

//If you do not choose an inheritance type, C++ defaults to private inheritance (just like members 
//default to private access if you do not specify otherwise).
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//****************************************************************************************************************
//Keep in mind the following rules:
// 1. A class can always access its own (non-inherited) members.
// 2. The public accesses the members of a class based on the access specifiers of the class it is accessing.
// 3. A derived class accesses inherited members based on the access specifier inherited from the parent class. 
//    This varies depending on the access specifier and type of inheritance used.
//****************************************************************************************************************

//=============================================================================
// Public inheritance:
//=============================================================================
//Public inheritance is by far the most commonly used type of inheritance. 
//In fact, very rarely will you see or use the other types of inheritance.
//When you inherit a base class publicly, inherited public members stay public, 
//and inherited protected members stay protected. Inherited private members, 
//which were inaccessible because they were private in the base class, stay 
//inaccessible.
//-----------------------------------------------------------------------------------
//Access specifier in base class  ========> Access specifier when inherited publicly
//-----------------------------------------------------------------------------------
// Public    ========> Public
// Protected ========> Protected
// Private   ========> Inaccessible
//=============================================================================

class Pub1: public Base // note: public inheritance
{
    // Public inheritance means:
    // Public inherited members stay public (so m_public is treated as public)
    // Protected inherited members stay protected (so m_protected is treated as protected)
    // Private inherited members stay inaccessible (so m_private is inaccessible)
public:
    Pub1()
    {
        m_public = 1; // okay: m_public was inherited as public
        m_protected = 2; // okay: m_protected was inherited as protected
        // m_private = 3; // not okay: m_private is inaccessible from derived class
    }
};

//****************************************************************************************************************
//Best practice: Use public inheritance unless you have a specific reason to do otherwise.
//****************************************************************************************************************

//=============================================================================
// Protected inheritance:
//=============================================================================
//Protected inheritance is the least common method of inheritance. It is almost 
//never used, except in very particular cases. With protected inheritance, the 
//public and protected members become protected, and private members stay 
//inaccessible.
//-----------------------------------------------------------------------------------
//Access specifier in base class  ========> Access specifier when inherited protectedly
//-----------------------------------------------------------------------------------
// Public    ========> Protected
// Protected ========> Protected
// Private   ========> Inaccessible
//=============================================================================



//=============================================================================
// Private inheritance:
//=============================================================================
//With private inheritance, all members from the base class are inherited as 
//private. This means private members are inaccessible, and protected and 
//public members become private. 
//Note that this does not affect the way that the derived class accesses 
//members inherited from its parent! It only affects the code trying to 
//access those members through the derived class.
//-----------------------------------------------------------------------------------
//Access specifier in base class  ========> Access specifier when inherited privately
//-----------------------------------------------------------------------------------
// Public    ========> Private
// Protected ========> Private
// Private   ========> Inaccessible
//=============================================================================

class Pri1: private Base // note: private inheritance
{
    // Private inheritance means:
    // Public inherited members become private (so m_public is treated as private)
    // Protected inherited members become private (so m_protected is treated as private)
    // Private inherited members stay inaccessible (so m_private is inaccessible)
public:
    Pri1()
    {
        m_public = 1; // okay: m_public is now private in Pri1
        m_protected = 2; // okay: m_protected is now private in Pri1
        // m_private = 3; // not okay: derived classes can't access private members in the base class
    }
};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// A final example:
class MyBaseClass
{
public:
	int m_public {};
protected:
	int m_protected {};
private:
	int m_private {};
};

//MyBaseClass can access its own members without restriction. 
//The public can only access m_public. Derived classes 
///can access m_public and m_protected.

class D2 : private MyBaseClass // note: private inheritance
{
	// Private inheritance means:
	// Public inherited members become private
	// Protected inherited members become private
	// Private inherited members stay inaccessible
public:
	int m_public2 {};
protected:
	int m_protected2 {};
private:
	int m_private2 {};
};

//D2 can access its own members without restriction. 
//D2 can access MyBaseClass’s m_public and m_protected members, 
//but not m_private. Because D2 inherited MyBaseClass privately, 
//m_public and m_protected are now considered private when 
//accessed through D2. This means the public can not access 
//these variables when using a D2 object, nor can any classes 
//derived from D2.

class D3 : public D2
{
	// Public inheritance means:
	// Public inherited members stay public
	// Protected inherited members stay protected
	// Private inherited members stay inaccessible
public:
	int m_public3 {};
protected:
	int m_protected3 {};
private:
	int m_private3 {};
};

//D3 can access its own members without restriction. 
//D3 can access D2’s m_public2 and m_protected2 members, 
//but not m_private2. Because D3 inherited D2 publicly, 
//m_public2 and m_protected2 keep their access specifiers 
//when accessed through D3. D3 has no access to MyBaseClass’s 
//m_private, which was already private in MyBaseClass. Nor does 
//it have access to MyBaseClass’s m_protected or m_public, both 
//of which became private when D2 inherited them.

//=============================================================================
//As a final note, although in the examples above, we’ve only shown examples 
//using member variables, these access rules hold true for all members (e.g. 
//member functions and types declared inside the class).
//=============================================================================

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

int main()
{
    Base base;
    base.m_public = 1; // allowed: can access public members from outside class
    // base.m_protected = 2; // not allowed: can not access protected members from outside class
    // base.m_private = 3; // not allowed: can not access private members from outside class

    //*******************************************************************************************

    // Outside access uses the access specifiers of the class being accessed.
    Base base1;
    base1.m_public = 1; // okay: m_public is public in Base
    // base1.m_protected = 2; // not okay: m_protected is protected in Base
    // base1.m_private = 3; // not okay: m_private is private in Base

    Pub1 pub1;
    pub1.m_public = 1; // okay: m_public is public in Pub
    // pub1.m_protected = 2; // not okay: m_protected is protected in Pub
    // pub1.m_private = 3; // not okay: m_private is inaccessible in Pub

    //*******************************************************************************************

    // Outside access uses the access specifiers of the class being accessed.
    // In this case, the access specifiers of base.
    Base base2;
    base2.m_public = 1; // okay: m_public is public in Base
    // base2.m_protected = 2; // not okay: m_protected is protected in Base
    // base2.m_private = 3; // not okay: m_private is private in Base

    Pri1 pri1;
    // pri1.m_public = 1; // not okay: m_public is now private in Pri
    // pri1.m_protected = 2; // not okay: m_protected is now private in Pri
    // pri1.m_private = 3; // not okay: m_private is inaccessible in Pri

    return 0;
}



























