#include <stdio.h>
#include <conio.h>
int main(){
    int x1 = 5, y1 = 20, z1 = 15;
    printf("x is: %d, y is:%d,z is:%d \n",x1, y1, z1); 
    x1 = x1 << 1; //shift to the left
    y1 = ~ y1; //ones complement of y1, replaces y1
    z1 = x1 ^ y1; //XOR of x1 and y1 would go into z1 (z1 = x1 XOR y1)

    printf("x is: %d, y is:%d,z is:%d \n",x1, y1, z1);  
    int x = 5, y = 10, z = 15;
    z = (x + 1)/(2*x*y) + (x*x);
    printf("z is: %d \n", z);
    z = (y/x) + (x*y);
    printf("z is: %d \n", z);
    z = (x*x + y*y)/(1 - x);
    printf("z is: %d \n", z);

    int A = 5, B = 0, C = 10;
    int a,b,c,g,e;
    a = !(A||B) && C;
    b = !(((3-4 % 3) < 5) && ((6 % C) <= 3));
    c = 7.3 * C / 3;
    g = 3*13 % A + C;
    e = B - (990 - A) % A;
    printf("a is: %d, b is:%d, c is:%d, d is:%d, e is:%d \n",a, b, c, g, e);

    //showing the conversion to different data types
    char ch = '3'; int i = 1; float f = 1.50; double d = 2.995;
    double result;
    result = (ch/i) + (f*d) - (f+i);  //the final data type would be double
    printf("result is: %f \n", result);

    int ab = 1260;
    printf("ab=%10d\n", ab); //creates 10 spaces before writing 1260 (\a make the system create a noise)

    //A program to calculate the area of a rectangle
    int W, H, S;
    printf("Enter Width: ");
    scanf("%d", &W);
    printf("Enter Height: ");
    scanf("%d", &H);
    S = W*H; //surface area
    printf("The area is: %d \n", S);

    //Program converting Fahrenheit to Centgrade
    float far, cent;
    printf("Enter the degree into Fahrenheit:");
    scanf("%f", &far);
    cent = (far-32)/1.8;
    printf("Temperature in centigrade is: %f", cent);
    


    getch(); //For keeping the command line open

}