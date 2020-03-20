#include <stdio.h>
#include <conio.h>
#include <time.h>



int main()
{
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% SYSTEM TIME
    //printing the time of the system
    struct tm *local, *gm;
    time_t t;
    t = time(NULL);
    local = localtime(&t);
    printf("Local time and date: %s\n", asctime(local));
    gm = gmtime(&t);
    printf("Coordinated Universal Time and date is : %s", asctime(gm));

    getch(); //For keeping the command line open
    return 0;
}
