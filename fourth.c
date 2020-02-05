#include <stdio.h>
#include <conio.h>
#include <math.h>
int main(){
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //A program to do some operations
    char operation; //the operation
    int num1, num2; //input integers
    float result = 0.0; //The result of the operation
    printf("Enter the first integer:");
    scanf("%d", &num1);
    printf("Enter the second integer:");
    scanf("%d", &num2);
    printf("Enter the operation:\n");
    printf("+:aggregation, -: minus, /: division, *: multiplication, ^: power, %%: reminder\n");
    operation = getch();
    switch(operation){
        case '+':
        result = num1 + num2;
        printf("The result is %f \n", result);
        break;

        case '-':
        result = num1 - num2;
        printf("The result is %f \n", result);
        break;

        case '*':
        result = num1 * num2;
        printf("The result is %f \n", result);
        break;

        case '/':
        result = num1 / num2;
        printf("The result is %f \n", result);
        break;

        case '%':
        result = num1 % num2;
        printf("The result is %f \n", result);
        break;

        case '^':
        result = pow(num1, num2); 
        printf("The result is %f \n", result);
        break;

        default:
        printf("Unknown type of operation. \n");
    }

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //A program to find out the maximum and minimum and their number of repetitions
    int x, n, max, min, minrep, maxrep;
    printf("How many numbers:");
    scanf("%d", &n);
    min = 1000;
    max = -1000;
    for(int i = 0; i < n; i++){
        printf("Enter Number %d:", i);
        scanf("%d", &x);
        if(x > max){
            max = x;
            maxrep = 0;
        }
        if(x < min){
            min= x;
            minrep = 0;
        }

        if(x == min){
            minrep++;
        }
        if(x == max){
            maxrep++;
        }
    }
    printf("\nMax=%d, max Repeats=%d", max, maxrep);
    printf("\nMin=%d, min Repeats=%d\n", min, minrep);

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //A program to draw a rectangle based on given dimensions
    int height, width;
    printf("Enter the height: ");
    scanf("%d", &height);
    printf("Enter the width: ");
    scanf("%d", &width);
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            printf("*");
        }
        printf("\n");
    }

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //A program to check whether a number is prime
    int num, k = 2, isPrime = 1;
    printf("Enter the number:");
    scanf("%d", &num);
    while (k <= (num/2))
    {
        if(num % k == 0){
            isPrime = 0;
            break;
        }
        k++;
    }
    if (isPrime == 1){
        printf("%d is a prime number. \n", num);
    }
    else{
        printf("%d is not prime. \n", num);
    }
    
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //A program to print * to the number of convenience
    int numStar;
    printf("Enter number of stars:");
    scanf("%d", &numStar);
    while(numStar < 1){ //watch out for negative integers
        printf("\nEnter an integer greater than 0:");
        scanf("%d", &numStar);
    }
    do{ //do it for once at least
        for(int i = 0; i < numStar; i++){
            printf("*");
        }
        printf("\nEnter the number of stars: press 0 to exit :-)");
        scanf("%d", &numStar);
    
    } while (numStar != 0);

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //A program to print the prime numbers between 2 integers 
    int m, i, j, first, second;  
    printf("Enter the first number: ");
    scanf("%d", &first);
    printf("Enter the second number: ");
    scanf("%d", &second);
    // if(first <= 2 && second > 2){
    //     printf("%d , ", 2);
    // }
    for(i = first; i <= second; i++){
        j = 2;
        while(j <= (i/2)){
            m = i % j;
            if (m == 0)
                break;
             j++;          
        }
        if(m != 0){
            printf("%d , ", i);
        }

    }

    getch(); //For keeping the command line open

}