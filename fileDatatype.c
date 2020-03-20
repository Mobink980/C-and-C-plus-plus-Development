#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 200

int main()
{
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% WORKING WITH FILES IN C
    //Reading and Writing variables that are not of type characters in file
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
    double d = 12.23;
    int i = 101;
    long int l = 123023L;

    //open the file test4.dat in the binary form for reading and writing and store it in pointer fp
    if ((fp = fopen("test4.dat", "wb+")) == NULL)
    {
        //if the file pointer is Null it means that the file could not be opened
        printf("Cannot open the file. \n");
        exit(1);
    }

    //if we want to pass an array as the argument of the fwrite, we just write its name
    //for determining the number of bytes needed we use sizeof() method (Ex: double ==> 8 bytes)
    //the third parameter means that only one value must be written within the file
    //the last parameter is the file pointer
    fwrite(&d, sizeof(double), 1, fp); //write a variable of type double in the file
    fwrite(&i, sizeof(int), 1, fp); //write a variable of type int in the file
    fwrite(&l, sizeof(long), 1, fp); //write a variable of type long in the file

    rewind(fp);//change the file position to the first of the file

    //reading the variables from the file using fread() method
    fread(&d, sizeof(double), 1, fp);
    fread(&i, sizeof(int), 1, fp);
    fread(&l, sizeof(long), 1, fp);

    printf("\n============================= FILE test4.dat CONTENTS ==================================== \n");
    //printing the values read from the file
    printf("double number: %f , int number: %d , long int number: %ld", d, i, l);

    fclose(fp); //close the file

    getch(); //For keeping the command line open
    return 0;
}
