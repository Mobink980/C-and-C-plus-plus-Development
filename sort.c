#include <stdio.h>
#include <conio.h>
#include <math.h>

void ReadNumbers(int A[], int);
void BubbleSort(int A[], int);
void InsertionSort(int A[], int);
void WriteNumbers(int A[], int);
int main()
{
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% BUBBLE SORT
    int n;
    int A[100];
    printf("Enter Number of Numbers: ");
    scanf("%d", &n);
    ReadNumbers(A, n);
    BubbleSort(A, n);
    WriteNumbers(A, n);

    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% INSERTION SORT
    printf("\n");
    int len;
    int B[100];
    printf("Enter Number of Numbers: ");
    scanf("%d", &len);
    ReadNumbers(B, len);
    InsertionSort(B, len);
    WriteNumbers(B, len);

    getch(); //For keeping the command line open
    return 0;
}

//This method will get the numbers from the user
void ReadNumbers(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter Number %d:", i + 1);
        scanf("%d", &A[i]);
    }
}

//This method will write the numbers in the console
void WriteNumbers(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}

//This method will sort the numbers with bubble sort
//In each loop the position of the last undetermined element will be determined
//Maximum from the remaining element will bubble up
void BubbleSort(int A[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        //omitting the sorted elements by subtracting i
        for (j = 0; j < n - i - 1; j++) 
        {

            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}


//This method will sort the numbers with insertion sort
//When an item is taken, the goal is to try inserting it in the right position
//Given an array, we start from the second element to the last and each time we
// try finding its correct position in the previous elements of the array
void InsertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j--;  
        }  
        arr[j + 1] = key; //putting the key in the correct position 
    }  
} 
