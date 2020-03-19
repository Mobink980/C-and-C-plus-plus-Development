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
    char ArrivalYear[5];
    char Major[20];
    float Average;
} StudentList[MAX];

int main()
{
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% STRUCTURES & UNIONS in C
    char choice;
    InitList(); //initialize the structure array

    for (  ;  ;  )
    {
        choice = MenuSelect();
        switch (choice)
        {
        case 1: EnterStudent();  break;
        case 2: DeleteStudent(); break;
        case 3: ListStudent(); break;
        case 4: exit(0);
        default: break;
            
        }
    }
    



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

//initializing the list of students
void InitList(void)
{
    register int t;
    for (t = 0; t < MAX; t++)
    {
        StudentList[t].Name[0] = '\0';
    }
}

//get a menu selection
int MenuSelect()
{
    char s[80];
    int c;
    printf("1. Enter a name \n");
    printf("2. Delete a name \n");
    printf("3. List the file \n");
    printf("4. Quit \n");

    do
    {
        printf("Enter your choice: ");
        gets(s);
        c = atoi(s);

    } while (c < 0 || c > 4);
    return c;
}

//input addresses into the ListStudent
void EnterStudent()
{
    int slot;
    char s[80];
    slot = FindFree();
    if(slot == -1) {
        printf("\nList Full");
        return;
    }

    printf("Enter name: ");
    gets(StudentList[slot].Name);
    printf("Enter major: ");
    gets(StudentList[slot].Major);
    printf("Enter Arrival Year: ");
    gets(StudentList[slot].ArrivalYear);
    printf("Enter Average: ");
    gets(s);
    StudentList[slot].Average = strtof(s, '\0');
}

// find an unused structure
int FindFree()
{
    register int t;
    for (t = 0; StudentList[t].Name[0] && t < MAX; ++t)
    {
        if(t == MAX){
            return -1; //no free slots
        }

        return t;
    }
    
}


//delete an address
void DeleteStudent()
{
    register int slot;
    char s[80];
    printf("Enter student record #:");
    gets(s);
    slot = atoi(s);

    if(slot >= 0 && slot < MAX) {
        StudentList[slot].Name[0] = '\0';
    }
}

//display the list student on the screen
void ListStudent()
{
    register int t;
    for(t = 0; t < MAX; t++){
        if(StudentList[t].Name[0]){
            printf("Student Name is %s\n", StudentList[t].Name);
            printf("Student Arrival Year is %s\n", StudentList[t].Major);
            printf("Student Major is %s\n", StudentList[t].ArrivalYear);
            printf("Student Average is %5.2f\n\n", StudentList[t].Average);
        }
    }
    printf("\n\n");
}

