#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 200

struct StudentInfo
{
    char Name[30];
    char Major[25];
    char ArrivalYear[4];
    float Average;
} StudentList[MAX];

char GradeAverage(float avg);
void InitList();
void EnterStudent();
void DeleteStudent();
void ListStudent();
void SaveFile();
void LoadFile();
int MenuSelect();
int FindFree();
int main()
{
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% WORKING WITH FILES IN C
    //Reading and Writing by random access (going to a specific position)
    //The ways to open a file
    // r ==> opens a text file for reading
    // w ==> creates a text file for writing
    // a ==> appends data to the end of a text file
    //rb ==> opens a binary file for reading
    //wb ==> opens a binary file for writing
    //ab ==> appends data to the end of a binary file
    // r+ ==> opens a text file for reading/writing
    // w+ ==> creates a text file for reading/writing
    // a+ ==> appends data to the end of a text file or creates it for reading and writing
    //r+b ==> opens a binary file for reading/writing
    //w+b ==> creates a binary file reading/writing
    //a+b ==> appends data to the end of a binary file or creates it for reading and writing

    
    char choice;
    
    InitList(); //initialize the structure array
    while (1)
    {
        choice = MenuSelect();

        switch (choice)
        {
        //Entering a student
        case 1:
            EnterStudent();
            SaveFile();
            LoadFile();
            break;
        //Deleting a student
        case 2:
            DeleteStudent();
            SaveFile();
            LoadFile();
            break;
        //Listing the previous students
        case 3:
            LoadFile();
            ListStudent();
            break;
        //exiting the program
        case 4:
            exit(0);
        default:
            exit(0);
        }
    }

    getch(); //For keeping the command line open
    return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% HELPER METHODS

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
        //initializing the name part of the array of length 200 with zero character
        StudentList[t].Name[0] = '\0'; 
    }
}

//get a menu selection
int MenuSelect()
{
    char s[80];
    int c;
    //printing the menu in the console
    printf("1. Enter a name \n");
    printf("2. Delete a name \n");
    printf("3. List the file \n");
    printf("4. Quit \n");

    do
    {
        printf("Enter your choice: ");
        gets(s); //read the character from the user
        c = atoi(s); //convert the character to an integer

    } while (c < 0 || c > 4); //keep doing this until the read character is negative or more than 4

    return c;
}

//input addresses into the ListStudent
//This method adds a new student to the ListStudent array
void EnterStudent()
{
    FILE *fp; //define a file pointer
    int slot; //an integer storing the first empty slot in the StudentList array
    char s[80]; //defining a string with length 80
    slot = FindFree(); //find the first empty slot in the StudentList array
    //if slot == -1, it means all the 200 slots are full
    if (slot == -1)
    {
        printf("\nList Full");
        return;
    }
    
    //get the inputs from the user and put them in 
    //the first empty slot in StudentList
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
//This method starts searching from the beginning of the 
//StudentList array to find the first empty slot
int FindFree()
{
    register int t;
    for (t = 0; StudentList[t].Name[0] && t < MAX; ++t);
    
        if (t == MAX) return -1; //no free slots
        return t;
    
}

//delete an address
void DeleteStudent()
{
    register int slot; //the slot that we want to empty
    char s[80]; //defining a string with length 80
    printf("Enter student record #:");
    gets(s);
    slot = atoi(s); //convert the string to an integer

    if (slot >= 0 && slot < MAX)
    {
        //if the slot is between 0 and MAX, then initialize 
        //the name part of the StudentList[slot] with zero character
        StudentList[slot].Name[0] = '\0';
    }
}

//display the list student on the screen
void ListStudent()
{
    register int t;
    for (t = 0; t < MAX; t++)
    {
        if (StudentList[t].Name[0])
        {
            printf("\n");
            printf("Student Name is %s\n", StudentList[t].Name);
            printf("Student Major is %s\n", StudentList[t].Major);
            printf("Student Arrival Year is %s\n", StudentList[t].ArrivalYear);
            printf("Student Average is %5.2f\n", StudentList[t].Average);
            printf("GPA = %c \n", GradeAverage(StudentList[t].Average));
        }
    }
    printf("\n\n");
}

//Save the StudentList
void SaveFile(void)
{
    FILE *fp; //define a file pointer
    register int i;
    if ((fp = fopen("StudentList.dat", "wb")) == NULL)
    {
        printf("Cannot open the file");
        return;
    }

    for (i = 0; i < MAX; i++)
    {
        if (*StudentList[i].Name)
        {
            if (fwrite(&StudentList[i], sizeof(struct StudentInfo), 1, fp) != 1)
            {
                printf("File write error. \n");
            }
        }
    }

    fclose(fp); //closing the file
}

//Load the file
void LoadFile()
{
    FILE *fp; //define a file pointer
    register int i;
    //open the file StudentList.dat in the binary form for reading and writing and store it in pointer fp
    if ((fp = fopen("StudentList.dat", "rb")) == NULL)
    {
        printf("Cannot open the file");
        return;
    }

    InitList();
    for (i = 0; i < MAX; i++)
    {
        if (fread(&StudentList[i], sizeof(struct StudentInfo), 1, fp) != 1)
        {
            if (feof(fp)) break;            
            printf("File read error. \n");
        }
    }

    fclose(fp); //close the file
}