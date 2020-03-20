#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 200

int main()
{
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% WORKING WITH FILES IN C
    // exit(0) usually indicates that all is well, 
    //whilst exit(1) indicates that something has gone amiss.
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

    //In fopen function ==>
    //the Null will be placed in the pointer to the file if file could not be opened
    //if a file does not exist and we use writing mode, the file will be created.
    //if we use reading mode, we will get an error

    FILE *fp; //creating a file pointer
    char ch;

    //opening the test.txt file in the writing mode and put it in the pointer fp
    if ((fp = fopen("test.txt", "w")) == NULL)
    {
        //if the file pointer is Null it means that the file could not be opened
        printf("Can not open the file. \n");
        exit(1);
    }

    printf("Enter File Texts: (use ctrl + z and press Enter when done!)\n");
    //In a do-while loop, each time one character is being read and will be put in ch
    //the read character will be written on the file with the help of puts function (EOF ==> ctrl + z) 
    do
    {
        ch = getchar(); //reading the character
        putc(ch, fp); //put it in the file

    } while (ch != EOF);

    fclose(fp); //closing the file
    
    if((fp = fopen("test.txt", "r")) == NULL)
    {
        printf("Cannot open file. \n");
        exit(1);
    }
    printf("\n============================= FILE TEXT CONTENTS ==================================== \n");
    ch = getc(fp); //read one character
    while (ch != EOF)
    {
        putchar(ch); //print on screen
        ch = getc(fp); //reading the next character
    }
    
    fclose(fp); //close the file


    getch(); //For keeping the command line open
    return 0;
}
