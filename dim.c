#include <stdio.h>
#include <conio.h>
#include <string.h>

void ReadNumbers(int A[], int);
void WriteNumbers(int A[], int);
int main()
{
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% TWO DIMENSIONAL ARRAYS
    //The average of 3 students in 2 courses
    int i = 0, j = 0, stdCount, courseCount;
    float sumMark = 0;
    printf("How many students?");
    scanf("%d", &stdCount);
    printf("How many courses?");
    scanf("%d", &courseCount);

    float SMark[stdCount][courseCount];

    for (i = 0; i < stdCount; i++)
    {
        for (j = 0; j < courseCount; j++)
        {
            printf("Enter student %d's mark in lesson %d :", i + 1, j + 1);
            scanf("%f", &SMark[i][j]);
            sumMark += SMark[i][j];
        }
    }

    printf("Average = %5.2f", sumMark / (stdCount * courseCount));

    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    printf("\n");
    //Sum of two matrices
    int a[2][2], b[2][2], c[2][2];
    printf("Enter the elements of the matrix a: \n");
    for (int p = 0; p < 2; p++)
    {
        for (int q = 0; q < 2; q++)
        {
            scanf("%d", &a[p][q]);
        }
    }

    printf("Enter the elements of the matrix b: \n");
    for (int p = 0; p < 2; p++)
    {
        for (int q = 0; q < 2; q++)
        {
            scanf("%d", &b[p][q]);
        }
    }

    //performing the computation
    for (int p = 0; p < 2; p++)
    {
        for (int q = 0; q < 2; q++)
        {
            c[p][q] = a[p][q] + b[p][q];
        }
    }
    printf("The sum of the two matrices is: \n");
    for (int p = 0; p < 2; p++)
    {
        for (int q = 0; q < 2; q++)
        {
            printf("%d   ", c[p][q]);
        }
        printf("\n");
    }

    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Strings
    printf("\n");
    //printing characters of a string in different lines
    int m = 0;
    char str[50];
    printf("Enter the string to separate characters: ");
    scanf("%s", &str);
    while (str[m] != '\0')
    {
        printf("%c \n", str[m++]);
    }

    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    printf("\n");
    //printing a list of fruits
    int k = 0;
    char FruitNames[100][30];
    while (1)
    {
        printf("Enter fruit name: (write q to quit)");
        scanf("%s", &FruitNames[k]);

        if (strcmp(FruitNames[k], "q") == 0)
            break;
        k++;
    }

    printf("======== Fruit List ========= \n");
    k = 0;
    while (1)
    {
        if (strcmp(FruitNames[k], "q") == 0)
            break;
        printf("%s ", FruitNames[k]);
        k++;
    }

    getch(); //For keeping the command line open
    return 0;
}

//This method will get the numbers from the user
void ReadNumbers(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter Number %d:", i + 1);
        scanf("%d", &A[i]);
    }
}

//This method will write the numbers in the console
void WriteNumbers(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}
