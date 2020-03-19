#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 200
char GradeAverage(float avg);
void InitList();
void EnterStudent();
void DeleteStudent();
void ListStudent();
int MenuSelect();
int FindFree();
//structs are used for creating composite datatype
//(containing several datatype in one)
struct StudentInfo
{
    char Name[30];
    int ArrivalYear;
    char Major[25];
    float Average;
};

//struct for the birthday of a student
struct DateInfo
{
    unsigned day : 5;
    unsigned month : 4;
    unsigned year : 7;
} myBirthDate;

//Enumerations are used for naming values with the help of integers
enum DayOfWeek
{
    Saturday,
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday
};

enum FrenchDays
{
    Samedi,
    dimanche,
    Lundi,
    Mardi,
    Mercredi,
    Jeudi,
    Vendredi
};
int main()
{
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% STRUCTURES & UNIONS in C
    int numStudent;
    struct StudentInfo classStudents[80];
    //getting student information
    printf("Enter the number of students: ");
    scanf("%d", &numStudent);

    for (int i = 0; i < numStudent; i++)
    {
        printf("Enter Student Name: ");
        scanf("%s", classStudents[i].Name);
        printf("Enter Arrival Year: ");
        scanf("%d", &classStudents[i].ArrivalYear);
        printf("Enter Student Major: ");
        scanf("%s", classStudents[i].Major);
        printf("Enter Student Average: ");
        scanf("%f", &classStudents[i].Average);
        printf("\n");
    }

    //print student info
    printf("====================== STUDENT INFORMATION ================================= \n");
    for (int i = 0; i < numStudent; i++)
    {
        printf("Student Name is %s \n", classStudents[i].Name);
        printf("Student Arrival Year is %d \n", classStudents[i].ArrivalYear);
        printf("Student Major is %s \n", classStudents[i].Major);
        printf("Student Average is %5.2f \n", classStudents[i].Average);
        printf("GPA = %c \n", GradeAverage(classStudents[i].Average));
        printf("=======================================================================\n");
    }

    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    printf("\n");
    //program to get and print the birthday of a student
    int yy, mm, dd;
    printf("Enter the student's birth date: (yy/mm/dd): ");
    scanf("%d/%d/%d", &yy, &mm, &dd);
    //filling the variables in the struct
    myBirthDate.year = yy;
    myBirthDate.month = mm;
    myBirthDate.day = dd;

    printf("\nYour Birth Date is %d/%d/%d", myBirthDate.year,
           myBirthDate.month, myBirthDate.day);

    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    printf("\n");
    //finding the weekday of birth using enum
    enum DayOfWeek myBirthDay;
    enum FrenchDays myFrenchBirthDay;
    printf("In which day did you born? \n");
    printf("0 for Saturday. \n");
    printf("1 for Sunday. \n");
    printf("2 for Monday. \n");
    printf("3 for Tuesday. \n");
    printf("4 for Wednesday. \n");
    printf("5 for Thursday. \n");
    printf("6 for Friday. \n");
    printf("day ==>");
    scanf("%d", &myBirthDay);

    myFrenchBirthDay = myBirthDay;

    switch (myBirthDay)
    {
    case Saturday:
        printf("You were born in Saturday \n");
        break;
    case Sunday:
        printf("You were born in Sunday \n");
        break;
    case Monday:
        printf("You were born in Monday \n");
        break;
    case Tuesday:
        printf("You were born in Tuesday \n");
        break;
    case Wednesday:
        printf("You were born in Wednesday \n");
        break;
    case Thursday:
        printf("You were born in Thursday \n");
        break;
    case Friday:
        printf("You were born in Friday \n");
        break;
    default:
        break;
    }

    switch (myFrenchBirthDay)
    {
    case Samedi:
        printf("You were born in Samedi \n");
        break;
    case dimanche:
        printf("You were born in dimanche \n");
        break;
    case Lundi:
        printf("You were born in Lundi \n");
        break;
    case Mardi:
        printf("You were born in Mardi \n");
        break;
    case Mercredi:
        printf("You were born in Mercredi \n");
        break;
    case Jeudi:
        printf("You were born in Jeudi \n");
        break;
    case Vendredi:
        printf("You were born in Vendredi \n");
        break;
    default:
        break;
    }

    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    printf("\n");
    //creating portable program by typedef (machine independent program)
    //for instance we can define the integer datatype by ==> typedef int integer;
    //Then we can use the word integer instead of int
    typedef struct StudentInfo SInfo;
    SInfo myInfo = {"Rasool", 98, "Computer Engineering", 19.43};

    //print student info
    printf("====================== STUDENT INFORMATION ================================= \n");
    printf("Student Name is %s \n", myInfo.Name);
    printf("Student Arrival Year is %d \n", myInfo.ArrivalYear);
    printf("Student Major is %s \n", myInfo.Major);
    printf("Student Average is %5.2f \n", myInfo.Average);
    printf("GPA = %c \n", GradeAverage(myInfo.Average));

    getch(); //For keeping the command line open
    return 0;
}

//This method will calculate the GPA of a student
char GradeAverage(float avg)
{

    if (avg >= 17)
        return ('A');
    else if (avg >= 15)
        return ('B');
    else if (avg >= 12)
        return ('C');
    else if (avg >= 10)
        return ('D');
    else
        return ('E');
}
