#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 200

int main()
{
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% FILE COPY IN C
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


    //file pointer in is for reading the test.txt file
    //file pointer out is for writing in the test2.txt file
    FILE *in, *out; 
    char ch;


    //opening the existing file in reading and binary mode
    if ((in = fopen("test.txt", "rb")) == NULL)
    {
        printf("Cannot open source file. \n");
        exit(1);
    }

    //opening the new file in writing and binary mode
    if ((out = fopen("test2.txt", "wb")) == NULL)
    {
        printf("Cannot open destination file. \n");
        exit(1);
    }

    //copying the characters of the existing file in the new file one by one
    while (!feof(in))
    {
        ch = getc(in);
        if(!feof(in)) putc(ch, out); //if we didn't reach the EOF  
    }

    //If the copying operaton was without errors, then show success and vice versa
    if(!ferror(in) && !ferror(out))
        printf("\nThe file successfully copied.");
    else
        printf("\nThe file could not be copied.");


    //close the two files
    fclose(in);
    fclose(out);

    

    getch(); //For keeping the command line open
    return 0;
}
