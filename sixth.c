#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
int check_ascendency(int, int[]);
void bubbleSort(float[], int);
void swap(float *, float *);
float operate(float , float , char);
long expo(int, int);
char get_least(char []);
void swap_ch(char [], int , int );
void mirror(char []);
int main()
{
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //A program to get a bunch of numbers and to see if they are ascendent
    int count = 5, arr[count];
    printf("How many numbers: \n");
    scanf("%d", &count);
    printf("Enter the numbers respectively:\n");
    for (int i = 0; i < count; i++)
    {
        scanf("%d", &arr[i]);
    }
    if (check_ascendency(count, arr) == 1)
    { //checking for ascendency using the defined method
        printf("The numbers entered are ascendent!");
    }
    else
    {
        printf("The numbers were not ascendent!");
    }

    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //A program that gets the GPA and student number of n students and prints the results
    int std_count = 3, m = 0;
    char std_number[std_count][20];
    float std_gpa[std_count];

    printf("\nHow many students: \n");
    scanf("%d", &std_count);
    while (m < std_count)
    {
        printf("Enter the student number of student %d \n", m + 1);
        scanf("%s", &std_number[m]);
        printf("Enter the GPA of student %d out of 20 \n", m + 1);
        scanf("%f", &std_gpa[m]);
        m++;
    }

    for (int i = 0; i < std_count; i++)
    {
        printf("The student number is %s and  ", std_number[i]);
        printf(" The student GPA is %f \n", std_gpa[i]);
    }

    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //A program to do basic mathematical operations and return the result
    float sum, minus, mult, div;
    long exponent;
    sum = operate(12.3, 56.32, '+'); 
    minus = operate(12.3, 56.32, '-'); 
    mult = operate(12.3, 56.32, '*'); 
    div = operate(12.3, 56.32, '/'); 
    exponent = expo(2,3);

    printf("The sum is: %f , The minus is: %f \nThe multiplication is: %f, The division is: %f \nThe exponentiation is: %d\n", sum, minus, mult, div, exponent);
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //A program to get the ones part of a number
    char string[20];
    printf("Enter the number to get the ones part: \n");
    scanf("%s", &string);
    char ch = get_least(string);
    printf("The ones of the number is: %c \n", ch);

    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //A program to get the mirror of a number
    char str_num[20];
    printf("Enter the number to get the mirror: \n");
    scanf("%s", &str_num);
    mirror(str_num);
    printf("The mirror of the number is: %s", str_num);

    getch(); //For keeping the command line open
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% HELPER METHODS
// This method gets an array and checks whether its elements are ascendent
int check_ascendency(int count, int arr[])
{
    for (int i = 0; i < count - 1; i++)
    {
        if (arr[i] >= arr[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

// A function to implement bubble sort
void bubbleSort(float arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
}
//A method to swap two float numbers
void swap(float *xp, float *yp)
{
    float tmp = *xp;
    *xp = *yp;
    *yp = tmp;
}

//A method to do some operation on two numbers and return the result
float operate(float num1, float num2, char ch){
    if(ch == '+')
        return num1 + num2;
    
    else if (ch == '-')
        return num1 - num2;
           
    else if(ch == '*')
        return num1 * num2;
        
    else{
        if(num2 != 0.0){
            return num1/num2;       
        }       
    }      
    return 0.0;
}

//A method for exponentiation
long expo(int base, int power){
long sum = 1;
for(int i = 0; i < power; i++){
    sum *= base;
}
    return sum;
}

//A method for getting the least part of a number
char get_least(char str[]){
    int len = strlen(str);
    return str[len - 1];
}

//A method to swap two characters in a string
void swap_ch(char arr[], int b, int e)
{
    char c = arr[b];
    arr[b] = arr[e];
    arr[e] = c;
}

void mirror(char arr[]){
    int last = strlen(arr);
    int count = (int)(last/2);
    
    for(int i = 0; i < count; i++){
        swap_ch(arr,i, last - 1 - i);
    }
}