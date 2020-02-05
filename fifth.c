#include <stdio.h>
#include <conio.h>
#include <math.h>
int main(){
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //A program to print fibonacci numbers
    int i = 0, f1, f2, f3, count;
    printf("Enter the number of fibonacci numbers you want to see: ");
    scanf("%d", &count);
    printf("The fibonacci numbers are:\n");
    f1 = 0; f2 = 1; f3 = f1 + f2;
    while (i < count)
    {
        printf("%d, ", f1);
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
        i++;
    }

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //A program to convert an integer to the binary form (Needs fixing)
    unsigned long int number;
    int binary[10];
    for(int j = 0; j < 10; j++){
        binary[j] = 0;
    }
    for(int j = 0; j < 10; j++){
        printf("%d", binary[j]);
    }    
    
    printf("\nEnter the number in integer form to convert to binary:");
    scanf("%u", &number);  
    if(number % 2 == 0){ //if the decimal number is even
    int k = 9;
        while(number / 2 > 1){
            if(number%2 == 0){
                binary[k] = 0;
                
            }
            else{
                binary[k] = 1;
                
            }

            number = number/2;
            k--;
        }

    for(int j = 0; j < 10; j++){
        printf("%d", binary[j]);
    } 
    }
    else{ //if the decimal number is odd

    }

    printf("%s", binary);


    getch(); //For keeping the command line open

}