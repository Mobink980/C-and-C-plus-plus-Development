#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% working with pointers
    // & is used for giving address. * is used to get the content of an address.
    //Ex ==> p = &i; the address of the variable i will be saved in p
    //x = *p; the content of the memory cell with the address p will be saved in x
    //if p and q are pointers and we have p = q, then if we get *p = 5, then we have *q = 5 and vice versa
    int *p, *q;
    int i = 10, j = 20;
    p = &i; //putting the address of the variable i into p
    (*p)++; //targeting the content of the memory cell with address p and incrementing it
    printf("i = %d \n", i);
    q = &j; //putting the address of the variable j into q
    printf("q = %d \n", *q);
    //*p  is the content of variable i & *q is the content of variable j
    j = *p + *q; // j = 11 + 20 = 31
    printf("j = %d \n", j);

    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% POINTER TO POINTER
    int x, *r, **t;
    x = 10;
    r = &x; //putting the address of the variable x into r
    t = &r; //putting the address of the pointer r into t
    //Thus, t saves the address of the pointer r which has the address of the variable x
    printf("r = %d *r = %d \n", r, *r);
    printf("t = %d *t = %d **t = %d \n", t, *t, **t);

    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% ALLOCATING DYNAMIC MEMORY
    printf("\n");
    //three pointers for keeping two numbers and calculating their sum
    float *d1, *d2, *sum;

    //creating space for containing a float number
    d1 = (float *)malloc(sizeof(float)); //putting the address of the created space in the pointer d1
    printf("Enter number 1: ");
    scanf("%f", d1); //getting the number from the user and saving it in the created space

    //creating space for containing a float number
    d2 = (float *)malloc(sizeof(float)); //putting the address of the created space in the pointer d2
    printf("Enter number 2: ");
    scanf("%f", d2); //getting the number from the user and saving it in the created space

    //creating space for containing a float number for the sum of the numbers
    sum = (float *)malloc(sizeof(float));
    *sum = *d1 + *d2; //adding the contents of the two created spaces and putting it in the sum space created
    printf("sum = %5.2f", *sum);

    //freeing three spaces created
    free(d1);
    free(d2);
    free(sum);

    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% USING POINTERS IN ARRAYS
    printf("\n");

    float marks[5];  //creating an array of type float
    float *pointer;  //creating a float pointer
    pointer = marks; //putting the array into the pointer so pointer indicates to the first element of array marks
    for (int s = 0; s < 5; s++)
    {
        printf("Enter Mark %d:", s + 1);
        //putting the float numbers from the user into the array
        scanf("%f", pointer + s);
    }

    for (int s = 0; s < 5; s++)
    {
        printf("\n Mark %d = %5.2f", s + 1, marks[s]);
    }

    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% DYNAMIC ARRAYS
    printf("\n");
    int NumCourse;
    //the pointer *grades is used to store the grades
    float *grades, sumMarks;
    printf("Enter the number of courses:");
    scanf("%d", &NumCourse);
    //allocating space to  the pointer grades to the number of courses
    grades = (float *)malloc(sizeof(float) * NumCourse);
    sumMarks = 0; //sum of all the grades
    for(int s = 0; s < NumCourse; s++) {
        printf("Enter mark of course %d:", s + 1);
        scanf("%f", &grades[s]); //getting the grades
        sumMarks += grades[s];
    }
    printf("Average = %5.2f", sumMarks/NumCourse);

    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% POINTERS & STRINGS
    printf("\n\n");
    int w = 0;
    char *FruitNames[100]; //creating an array of pointers
    char cFruit[20]; //a string (length initialized 20)
    while (1)
    {
       printf("Enter Fruit Name: ");
       scanf("%s", cFruit);
       //allocating space to the bytes of the input string
       FruitNames[w] = (char *) malloc(sizeof(char) * strlen(cFruit));
       strcpy(FruitNames[w], cFruit); //putting the input string to the allocated space

        
        //strcmp = 0 ==> 2 strings are equal
        //strcmp = 1 ==> first string is greater
        //strcmp = -1 ==> second string is greater
        //if the input string was q, then break
       if(strcmp(FruitNames[w], "q") == 0) break;
       w++;
    }
    printf("============== Fruit List ================== \n");
    w = 0;
    while (1)
    {
        //if the input string was q, then break and stop printing
        if(strcmp(FruitNames[w], "q") == 0) break;
        printf("%s ", FruitNames[w]);
        w++;
    }
    
    
    getch(); //For keeping the command line open
    return 0;
}
