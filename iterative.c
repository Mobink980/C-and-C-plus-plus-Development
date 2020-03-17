#include <stdio.h>
#include <conio.h>
#include <math.h>

//This method will calculate sum of numbers iteratively
int Sum(int n)
{
    if (n == 1)
        return 1;
    else
        return (Sum(n - 1) + n);
}
int main()
{
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% sum of 1 to 100 iterative
    int number;
    printf("Enter a number to calculate sum:");
    scanf("%d", &number);
    printf("The sum is: %d", Sum(number));

    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% The average score of some students
    printf("\n");
    int studentsCount = 5;
    printf("How many students:");
    scanf("%d", &studentsCount);
    int i = 0;
    float sumMark = 0;
    float SMark[studentsCount];
    for (i = 0; i < studentsCount; i++)
    {
        printf("Enter Student%d's Mark:\n", i + 1);
        scanf("%f", &SMark[i]);
    }

    //calculate the average
    for (i = 0; i < studentsCount; i++)
    {
        printf("Student %d's Mark : %5.2f\n", i, SMark[i]);
        sumMark += SMark[i];
    }

    printf("Average: %5.2f", sumMark / studentsCount);

    getch(); //For keeping the command line open
    return 0;
}
