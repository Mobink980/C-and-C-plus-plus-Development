#include <functional> // reference_wrapper
#include <iostream>
#include <string>
#include <vector>

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  Association  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Object composition is used to model relationships where a complex object is built from one or more simpler 
//objects (parts). In this lesson, we’ll take a look at a weaker type of relationship between two otherwise 
//unrelated objects, called an association. Unlike object composition relationships, in an association, there is 
//no implied whole/part relationship.

//To qualify as an association, an object and another object must have the following relationship:
//  The associated object (member) is otherwise unrelated to the object (class) ==> not part of the object
//  The associated object (member) can belong to more than one object (class) at a time
//  The associated object (member) does not have its existence managed by the object (class)
//  The associated object (member) may or may not know about the existence of the object (class)

//The relationship between doctors and patients is a great example of an association. The doctor clearly has a 
//relationship with his patients, but conceptually it’s not a part/whole (object composition) relationship. A 
//doctor can see many patients in a day, and a patient can see many doctors (perhaps they want a second opinion, 
//or they are visiting different types of doctors). Neither of the object’s lifespans are tied to the other.
//We can say that association models as “uses-a” relationship. The doctor “uses” the patient (to earn income). 
//The patient uses the doctor (for whatever health purposes they need).
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// Composition ==> part-of
// Aggregation ==> has-a
// Association ==> uses-a
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


//Because associations are a broad type of relationship, they can be implemented in 
//many different ways. However, most often, associations are implemented using pointers, 
//where the object points at the associated object.

//In this example, we’ll implement a bi-directional Doctor/Patient relationship, since it 
//makes sense for the Doctors to know who their Patients are, and vice-versa.


// Since Doctor and Patient have a circular dependency, we're going to forward declare Patient
class Patient;

class Doctor
{
private:
	std::string m_name{};
	std::vector<std::reference_wrapper<const Patient>> m_patient{};

public:
	Doctor(const std::string& name) :
		m_name{ name }
	{
	}

	void addPatient(Patient& patient);

	// We'll implement this function below Patient since we need Patient to be defined at that point
	friend std::ostream& operator<<(std::ostream& out, const Doctor& doctor);

	const std::string& getName() const { return m_name; }
};

class Patient
{
private:
	std::string m_name{};
	std::vector<std::reference_wrapper<const Doctor>> m_doctor{}; // so that we can use it here

	// We're going to make addDoctor private because we don't want the public to use it.
	// They should use Doctor::addPatient() instead, which is publicly exposed
	void addDoctor(const Doctor& doctor)
	{
		m_doctor.push_back(doctor);
	}

public:
	Patient(const std::string& name)
		: m_name{ name }
	{
	}

	// We'll implement this function below Doctor since we need Doctor to be defined at that point
	friend std::ostream& operator<<(std::ostream& out, const Patient& patient);

	const std::string& getName() const { return m_name; }

	// We'll friend Doctor::addPatient() so it can access the private function Patient::addDoctor()
	friend void Doctor::addPatient(Patient& patient);
};

void Doctor::addPatient(Patient& patient)
{
	// Our doctor will add this patient
	m_patient.push_back(patient);

	// and the patient will also add this doctor
	patient.addDoctor(*this);
}

std::ostream& operator<<(std::ostream& out, const Doctor& doctor)
{
	if (doctor.m_patient.empty())
	{
		out << doctor.m_name << " has no patients right now";
		return out;
	}

	out << doctor.m_name << " is seeing patients: ";
	for (const auto& patient : doctor.m_patient)
		out << patient.get().getName() << ' ';

	return out;
}

std::ostream& operator<<(std::ostream& out, const Patient& patient)
{
	if (patient.m_doctor.empty())
	{
		out << patient.getName() << " has no doctors right now";
		return out;
	}

	out << patient.m_name << " is seeing doctors: ";
	for (const auto& doctor : patient.m_doctor)
		out << doctor.get().getName() << ' ';

	return out;
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//In general, you should avoid bidirectional associations if a unidirectional one will do, as they add complexity 
//and tend to be harder to write without making errors.
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//******************************************************************************************************************
//*************************************  Reflexive association  ****************************************************
//******************************************************************************************************************
//Sometimes objects may have a relationship with other objects of the same type. This is called a reflexive 
//association. A good example of a reflexive association is the relationship between a university course and 
//its prerequisites (which are also university courses).
//******************************************************************************************************************

//Consider the simplified case where a Course can only have one prerequisite. We can do something like this:
class Course
{
private:
    std::string m_name;
    const Course* m_prerequisite;

public:
    Course(const std::string& name, const Course* prerequisite = nullptr):
        m_name{ name }, m_prerequisite{ prerequisite }
    {
    }

    void printPrerequisites() const
    {
        if (m_prerequisite)
        {
            std::cout << m_name << " has a prerequisite of " << m_prerequisite->m_name << std::endl;
        }
        else
        {
            std::cout << m_name << " has no prerequisite" << std::endl;
        }
    }
    

};

//This can lead to a chain of associations (a course has a prerequisite, which has a prerequisite, etc…)


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Associations can be indirect
//In all of the previous cases, we’ve used either pointers or references to directly link objects together. 
//However, in an association, this is not strictly required. Any kind of data that allows you to link two 
//objects together suffices. In the following example, we show how a Driver class can have a unidirectional 
//association with a Car without actually including a Car pointer or reference member:

class Car
{
private:
	std::string m_name;
	int m_id;

public:
	Car(const std::string& name, int id)
		: m_name{ name }, m_id{ id }
	{
	}

	const std::string& getName() const { return m_name; }
	int getId() const { return m_id;  }
};

// Our CarLot is essentially just a static array of Cars and a lookup function to retrieve them.
// Because it's static, we don't need to allocate an object of type CarLot to use it
class CarLot
{
private:
	static Car s_carLot[4];

public:
	CarLot() = delete; // Ensure we don't try to create a CarLot

	static Car* getCar(int id)
	{
		for (int count{ 0 }; count < 4; ++count)
		{
			if (s_carLot[count].getId() == id)
			{
				return &(s_carLot[count]);
			}
		}

		return nullptr;
	}
};

Car CarLot::s_carLot[4]{ { "Prius", 4 }, { "Corolla", 17 }, { "Accord", 84 }, { "Matrix", 62 } };

class Driver
{
private:
	std::string m_name;
	int m_carId; // we're associated with the Car by ID rather than pointer

public:
	Driver(const std::string& name, int carId)
		: m_name{ name }, m_carId{ carId }
	{
	}

	const std::string& getName() const { return m_name; }
	int getCarId() const { return m_carId; }
};




int main()
{
	// Create a Patient outside the scope of the Doctor
	Patient dave{ "Dave" };
	Patient frank{ "Frank" };
	Patient betsy{ "Betsy" };
    Patient jane{ "Jane" };
    Patient john{ "John" };
    Patient joan{ "Joan" };
    Patient sally{ "Sally" };
    Patient raj{ "Raj" };


	Doctor james{ "James" };
	Doctor scott{ "Scott" };
    Doctor karim{ "Karim" };
    Doctor akram{ "Akram" };
    Doctor collete{ "Collete" };

	james.addPatient(dave);
	scott.addPatient(dave);
	scott.addPatient(betsy);
    karim.addPatient(jane);
    karim.addPatient(betsy);
    akram.addPatient(john);
    akram.addPatient(joan);
    collete.addPatient(joan);
    collete.addPatient(sally);
    collete.addPatient(raj);

    //doctors
    std::cout << "==========================================================" << '\n';
    std::cout << "======================== Doctors =========================" << '\n';
    std::cout << "==========================================================" << '\n';
	std::cout << james << '\n';
	std::cout << scott << '\n';
    std::cout << karim << '\n';
    std::cout << akram << '\n';
    std::cout << collete << '\n';

    //patients
    std::cout << "==========================================================" << '\n';
    std::cout << "======================== Patients ========================" << '\n';
    std::cout << "==========================================================" << '\n';
	std::cout << dave << '\n';
	std::cout << frank << '\n';
	std::cout << betsy << '\n';
    std::cout << jane << '\n';
    std::cout << john << '\n';
    std::cout << joan << '\n';
    std::cout << sally << '\n';
    std::cout << raj << '\n';

    std::cout << "==========================================================" << '\n';
    std::cout << "==========================================================" << '\n';

    //********************************************************************************
    Course computerArch { "Computer Architecture" };
    Course advancedComputerArch{ "Advanced Computer Architecture" , &computerArch };
    computerArch.printPrerequisites();
    advancedComputerArch.printPrerequisites();

    //********************************************************************************

    Driver d{ "Franz", 17 }; // Franz is driving the car with ID 17

	Car* car{ CarLot::getCar(d.getCarId()) }; // Get that car from the car lot

	if (car)
		std::cout << d.getName() << " is driving a " << car->getName() << '\n';
	else
		std::cout << d.getName() << " couldn't find his car\n";

	return 0;
}
