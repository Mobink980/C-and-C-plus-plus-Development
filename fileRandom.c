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
}Student4;

int main()
{
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% WORKING WITH FILES IN C
    //Reading and Writing by random access (going to a specific position)
    //The ways to open a file
    // r ==> opens a text file for reading
    // w ==> creates a text file for writing
    // a ==> appends data to the end of a text file
    //rb ==> opens a binary file foe reading
    //wb ==> opens a binary file for writing
    //ab ==> appends data to the end of a binary file
    // r+ ==> opens a text file for reading/writing
    // w+ ==> creates a text file for reading/writing
    // a+ ==> appends data to the end of a text file or creates it for reading and writing
    //r+b ==> opens a binary file for reading/writing
    //w+b ==> creates a binary file reading/writing
    //a+b ==> appends data to the end of a binary file or creates it for reading and writing

    FILE *fp; //creating the file pointer fp

    //open the file test4.dat in the binary form for reading and writing and store it in pointer fp
    if ((fp = fopen("StudentList.dat", "rb")) == NULL)
    {
        //if the file pointer is Null it means that the file could not be opened
        printf("Cannot open the file. \n");
        exit(1);
    }

    //fseek is used to change the position in the file
    //fseek(file pointer, number of bytes, start position);
    //number of bytes determines how many bytes we must go after the start position
    //the start position can be one of the following:
    // SEEK_SET ==> BEGINNING OF THE FILE
    // SEEK_CUR ==> THE PLACE OF THE FILE POSITION
    // SEEK_END ==> THE END OF THE FILE
    //If fseek works properly it will return some non_zero value. Otherwise it will return 0
    if(fseek(fp, sizeof(struct StudentInfo)*3, SEEK_SET) == 0)
    {
        printf("Seek error. \n");
        exit(1);
    }

    fread(&Student4, sizeof(struct StudentInfo), 1, fp);



    printf("\n============================= FILE StudentList.dat CONTENTS ==================================== \n");
    //printing the values read from the file
    printf("Name: %s\n", Student4.Name);
    printf("Major: %s\n", Student4.Major);
    printf("Arrival Year: %s\n", Student4.ArrivalYear);
    printf("Average: %f\n\n", Student4.Average);



    getch(); //For keeping the command line open
    fclose(fp); //close the file
    return 0;
}
