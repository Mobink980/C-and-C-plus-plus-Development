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
    //Reading and Writing data by format in the file
    //They work similarly to printf and scanf with the difference that fprintf and fscanf operate on files
    //fprintf(file pointer, control string, variables)
    //fscanf(file pointer, control string, variables)
    //The ways to open a file
    // r ==> opens a text file for reading
    // w ==> creates a text file for writing


    FILE *fp; //creating the file pointer fp
    char s[80];
    int t;

    //open the file test4.dat in the binary form for reading and writing and store it in pointer fp
    if ((fp = fopen("test6.txt", "w")) == NULL)
    {
        //if the file pointer is Null it means that the file could not be opened
        printf("Cannot open the file. \n");
        exit(1);
    }

    printf("Enter a string and a number: ");
    scanf("%s %d", s, &t); //read from keyboard
    fprintf(fp, "%s %d", s, t); //write into file
    fclose(fp);

    //open the file test4.dat in the binary form for reading and writing and store it in pointer fp
    if ((fp = fopen("test6.txt", "r")) == NULL)
    {
        //if the file pointer is Null it means that the file could not be opened
        printf("Cannot open the file. \n");
        exit(1);
    }

    fscanf(fp, "%s %d", s, &t); //read from the file



    printf("\n============================= FILE test6.txt CONTENTS ==================================== \n");
    //printing the values read from the file
    printf("The string was %s and the integer was %d", s, t); //print on screen



    getch(); //For keeping the command line open
    return 0;
}
