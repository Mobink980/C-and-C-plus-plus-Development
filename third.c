#include <stdio.h>
#include <conio.h>
#include <math.h>
int main(){
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //A program to calculate the absolute of a number
    int num;
    printf("Enter Number to get absolute:");
    scanf("%d", &num);
    if(num < 0){
        num = -num;
    }

    printf("The absolute value is %d \n", num);

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //A program to calculate f(x) = 1/x
    float x, y;
    printf("Enter Number to calculate f(x) = 1/x:");
    scanf("%f", &x);
    if (x != 0.0){
        y = 1/x;
        printf("The answer is %f \n", y);
    }  
    else{ //if x = 0
        printf("The answer is infinity.\n");
    }
 
    
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //A program to calculate whether a student failed or passed a test.
    //If the result is less than 10, the student failed the test
    float mark;
    printf("Enter your Mark: ");
    scanf("%f", &mark);
    while(mark > 20.0 || mark < 0.0){
        printf("You have entered an invalid score. Try a number between 0.0 to 20.0:\n");
        scanf("%f", &mark);
    }

    if(mark < 10.0){
        printf("You have failed the test. Try Again!\n");
    }
    else{
        printf("You successfully passed the test with the score %f out of 20.\n", mark);
    }


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //A program to find the maximum number from a bunch of numbers
    int count = 0, i = 0;
    printf("How many numbers?\n");
    scanf("%d", &count); 
    float max = -100.0, number;
    printf("Enter the numbers:\n");
    while (i < count)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%f", &number);
        if(number > max){
            max = number;
        }   

        i++;  
    }

    printf("The maximum number is %f \n", max);
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //A program to determine the alphabetic score based on the score scale from 0 to 20
    float score;
    printf("Enter your score on the scale 0 to 20: ");
    scanf("%f", &score);
    if(score >= 17.0){
        printf("You get an A\n");
    }
    else if(score >= 14.0 && score < 17.0){
        printf("You get a B\n");
    }
    else if(score >= 12.0 && score < 14.0){
        printf("You get a C\n");
    }
    else if(score >= 10.0 && score < 12.0){
        printf("You get a D\n");
    }
    else{ //the score is less than 10
        printf("You get an E\n");
    }

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //A program to check whether a student is late on the class
    int StartHour, ArrivalHour, IsLate = 0;
    printf("Enter the start hour of the class:");
    scanf("%d", &StartHour);

    while(StartHour > 24 || StartHour < 0){ //while StartHour is invalid take the input
        printf("You have entered an invalid start hour. Try a number between 0 to 24:\n");
        scanf("%d", &StartHour);
    }

    printf("Enter the arrival hour of the student:");
    scanf("%d", &ArrivalHour);

    while(ArrivalHour > 24 || ArrivalHour < 0){//while ArrivalHour is invalid take the input
        printf("You have entered an invalid arrival hour. Try a number between 0 to 24:\n");
        scanf("%d", &ArrivalHour);
    }
    IsLate = ArrivalHour > StartHour ? 1 : 0; //if true, IsLate = 1, else IsLate = 0
    if (IsLate == 1){
        printf("The student is late on the class.\n");
    }
    else{
        printf("The student is on-time or early.\n");
    }



    
    

    getch(); //For keeping the command line open

}