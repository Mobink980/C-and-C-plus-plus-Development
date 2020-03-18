#include <stdio.h>
#include <conio.h>
#include <math.h>

void ReadNumbers(int A[], int);
void LinearSearch(int A[], int, int);
void BinarySearch(int A[], int, int);
void WriteNumbers(int A[], int);
int IsSorted(int A[], int);
int main()
{
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% LINEAR SEARCH
    int n, x;
    int A[100];
    printf("How many numbers? ");
    scanf("%d", &n);
    ReadNumbers(A, n);
    WriteNumbers(A, n);
    printf("\n");
    printf("Enter number to search: ");
    scanf("%d", &x);
    //if the array is not sorted
    if (!IsSorted(A, n))
    {
        printf("The array is not sorted, thus we use linear search. \n");
        LinearSearch(A, n, x);
    }
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% BINARY SEARCH
    //if the array is sorted
    else
    {
        printf("The array is sorted, thus we use binary search. \n");
        BinarySearch(A, n, x);
    }
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

//This method will search the first position of an element linearly
void LinearSearch(int A[], int n, int x)
{
    int FindIndex, i;
    for (i = 0; i < n; i++)
    {
        if (A[i] == x)
        {
            printf("The item %d was found at the position %d (starting from 0)", x, i);
            return;
        }
    }
    printf("The item %d could not be found", x);
}


//This method will search the array with binary search
//more efficient when the array is sorted
void BinarySearch(int A[], int n, int x)
{
    int mid, low = 0, high = n, isFound = 0;
    while (isFound == 0 && low <= high) 
    {
        mid = (low + high)/2;
        if (A[mid] == x){
            isFound = 1;
        }
        else if(A[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if(isFound == 1) {
        printf("The item %d was found at the position %d (starting from 0)", x, mid);
    }
    else
    {
        printf("The item %d could not be found", x);
    }
      
}

//This method checks whether an array is sorted
int IsSorted(int A[], int n) {
    //If there is one element that is greater than its right element
    //it means that the array is not sorted
    for(int i = 0; i < n - 1; i++) {
        if (A[i] > A[i + 1]){
            return 0;
        }
    }
    return 1;
}