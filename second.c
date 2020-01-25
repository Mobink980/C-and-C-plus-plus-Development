#include <stdio.h>
#include <conio.h>
#include <math.h>
int main(){
    //Program for calculating the tax bills
    float Price, TaxRate, Tax;
    int EmpCode;
    printf("Enter EmpCode:");
    scanf("%d", &EmpCode);
    printf("Enter Price: ");
    scanf("%f", &Price);
    printf("Enter TaxRate: ");
    scanf("%f", &TaxRate);

    Tax = TaxRate*Price;
    printf("\n----------------");
    printf("\n EmpCode: %d", EmpCode);
    printf("\n Price: %f", Price);
    printf("\n TaxRate: %f", TaxRate);
    printf("\n Tax: %f", Tax);

    //Program to show the usage of getche, getch
    char ch;
    printf("\n Test getch: Enter a character:");
    ch = getch();
    printf("\n ch=%c ,ASCII Code=%d",ch, ch);

    printf("\n Test getche: Enter a character:");
    ch = getche();
    printf("\n ch=%c ,ASCII Code=%d",ch, ch);


    //A program to print A in a star form
    ch = '*';
    printf("\n%5c\n", ch); //first line

    printf("%4c", ch); //second line
    printf("%2c\n", ch);

    printf("%3c", ch); //third line
    printf("%2c", ch);
    printf("%2c\n", ch);

    printf("%2c", ch); //fourth line
    printf("%6c\n", ch);

    //A program to convert inch to centimeter
    float inch, cent;
    printf("Enter the Length into inch:");
    scanf("%f", &inch);
    cent = inch*2.54; //1 inch is 2.54 centimeter
    printf("Length in centimeter is: %f centimeter\n\n", cent);

    //A program to calculate the perimeter and area of a triangle
    int a = 0, b = 0, c = 0;
    printf("Please enter the length of the three sides separated by a space: \n");   
    scanf("%ld%ld%1d", &a, &b, &c); 
    printf("The sides were: %d %d %d \n", a, b, c);
    if(a + b  <= c || a + c <= b || b + c <= a){ //the triangle inequality
        printf("The triangle is invalid.\n");
    }else{
        float area = 0;
        int perimeter = 0;
        perimeter = a + b + c;
        area = sqrt((perimeter/2) * ((perimeter/2)-a) * ((perimeter/2)-b) * ((perimeter/2)-c));
        printf("The perimeter of the triangle is %d and the area of the triangle is %e \n",perimeter, area);
    }
    

    //A program to rotate values
    int first, second, third;
    printf("Enter the three numbers to rotate left by a space: \n");   
    scanf("%ld%ld%1d", &first, &second, &third);    
    int rotate; //helper variable
    rotate = first;
    first = second;
    second = third;
    third = rotate; 

    printf("The rotated numbers are: %d %d %d \n", first, second, third);


    //Program to calculate the function f(x) = (x^2 + 2x - 1)/(x^3 - 2x^2 + 9)
    float x, y;
    printf("Enter the number to calculate: \n");   
    scanf("%lf", &x);
    y = (pow(x, 2) + 2*x - 1)/(pow(x, 3) - 2*pow(x, 2) + 9);
    printf("f(x) = %1f \n", y);


    getch(); //For keeping the command line open

}