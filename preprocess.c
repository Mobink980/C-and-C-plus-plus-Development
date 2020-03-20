#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define TED 10
#define US 0
#define ENGLAND 1
#define FRANCE 2
#define ACTIVE_COUNTRY US


int main()
{
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% BEFORE COMPILE
    //the program will be preprocessed and source code is generated. After that the interpretation begins :-)
    int i = 2;
    if(i >= 5)
    {
        // #error enter a number less than 5
    }
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    #if ACTIVE_COUNTRY == US
        char currency[] = "dollar";

    #elif ACTIVE_COUNTRY == ENGLAND
        char currency[] = "pound";

    #else
        char currency[] = "franc";

    #endif

    printf("The selected currency is %s \n", currency);

    #ifdef TED
        printf("Hi TED!!\n");

    #else
        printf("Hi anyone!!!");

    #endif

    #ifndef RALPH
        printf("RALPH is not define mon frere!!\n");
    #endif

    getch(); //For keeping the command line open
    return 0;
}
