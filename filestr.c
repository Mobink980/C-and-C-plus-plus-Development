#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 200

int main()
{
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% WORKING WITH FILES IN C
    //Reading and Writing strings in file
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

    char str[80];
    FILE *fp; //creating the file pointer fp

    //open the file test3.txt in the writing/reading mode and store it in pointer fp
    if ((fp = fopen("test3.txt", "w+")) == NULL)
    {
        //if the file pointer is Null it means that the file could not be opened
        printf("Cannot open the file. \n");
        exit(1);
    }

    do
    {
        printf("Enter a string (Empty Line to Quit): \n");
        gets(str); //read the input string and put it in the str
        strcat(str, "\n"); //adding a newline
        fputs(str, fp); //write the input string in the test3.txt

    } while (*str != '\n'); //keep going until reaching an empty line

    rewind(fp);//change the file position to the first of the file

    printf("\n============================= FILE test3.txt CONTENTS ==================================== \n");
    // while the end of the file is not reached
    while (!feof(fp))
    {
        fgets(str, 79, fp); //read the input strings
        printf(str); //print it in the console
    }

    fclose(fp); //close the file

    getch(); //For keeping the command line open
    return 0;
}
