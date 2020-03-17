#include <stdio.h>
#include <conio.h>
#include <math.h>

void PrintAnswers(int, int, int);
float Calc(int, float);
int main()
{
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Equation solver
    int A, B, C;
    printf("In Ax^2 + Bx + C = 0 , Enter A:");
    scanf("%d", &A);
    printf("In Ax^2 + Bx + C = 0 , Enter B:");
    scanf("%d", &B);
    printf("In Ax^2 + Bx + C = 0 , Enter C:");
    scanf("%d", &C);
    printf("\n");

    PrintAnswers(A, B, C);

    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Mathematic Functions
    printf("\n");
    float x;
    int fNumber;
    printf("Function 1 : sin(x) \n");
    printf("Function 2 : cos(x) \n");
    printf("Function 3 : tan(x) \n");
    printf("Function 4 : exp(x) \n");
    printf("Function 5 : sqrt(x) \n");
    printf("Function 6 : log10(x) \n");
    printf("Function 7 : log(x) \n");
    printf("Function 8 : ceil(x) \n");
    printf("Function 9 : floor(x) \n");

    printf("Enter function number and input number: (with a space between) \n");
    scanf("%d %f", &fNumber, &x);
    printf("result = %5.2f", Calc(fNumber, x));

    getch(); //For keeping the command line open
    return 0;
}

//This method will solve a quadratic equation
void PrintAnswers(int a, int b, int c)
{
    float delta, x1, x2;
    delta = b * b - (4 * a * c);
    if (delta > 0)
    {
        x1 = (-b + sqrt(delta)) / 2 * a;
        x2 = (-b - sqrt(delta)) / 2 * a;
        printf("2 roots: \n");
        printf("\n first root = %f2", x1);
        printf("\n second root = %f2", x2);
    }
    else if (delta == 0)
    {
        x1 = -b / (2 * a);
        printf("Just 1 root.\n");
        printf("The only root is: %f3", x1);
    }
    else
    {
        printf("No real roots!");
    }
}

//This method will offer some mathematic functions
float Calc(int fNumber, float x)
{
    float r;
    switch (fNumber)
    {
    case 1:
        r = sin(x);
        break;
    case 2:
        r = cos(x);
        break;
    case 3:
        r = tan(x);
        break;
    case 4:
        r = exp(x);
        break;
    case 5:
        r = sqrt(x);
        break;
    case 6:
        r = log10(x);
        break;
    case 7:
        r = log(x);
        break;
    case 8:
        r = ceil(x);
        break;
    case 9:
        r = floor(x);
        break;
    default:
        r = 0;
        break;
    }

    return (r);
}