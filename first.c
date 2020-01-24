#include <stdio.h>
#include <conio.h>
  int main(){
    int age = 0;
    unsigned char name;
    unsigned char nationality;

    printf("Enter your name:\n");
    scanf("%s", &name);

    printf("Your name is %s \n", &name);

    	//Declares the variables and their data types first
    int int1, int2;
    double double1, double2;
    char char1, char2, char3;
    
    	// Print clear instructions
    printf("Please enter two integers separated by a space: ");   
    
    	// Takes in two inputs, using whitespace as separation
    scanf("%d%d",&int1,&int2);              

    	// Print back the two integers separately
    printf("The first integer was %d. \nThe second integer was %d. \n\n",int1,int2);        
    

    	// Same as above but with two doubles
    printf("Please enter two doubles (decimal numbers) separated by a space: ");   
    scanf("%lf%lf",&double1,&double2);              
    printf("The first double was %lf. \nThe second double was %lf. \n\n",double1,double2);  
    
    
      // Same as above but with three characters
    printf("Please enter two doubles (decimal numbers) separated by a space: ");   
    scanf("%lf%lf",&double1,&double2);              
    printf("The first double was %lf. \nThe second double was %lf. \n\n",double1,double2);    
    


    return 0;
}