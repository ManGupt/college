#include <stdlib.h>
#include<stdio.h>
#include<conio.h>

int globalVariable = 2;

int main()
{
   char* sIdentifier;

   pid_t pID = fork();
   if (pID == 0)                // child
   {  sIdentifier = "Child Process: ";
      globalVariable++;
    }
    else if (pID < 0)            // failed to fork
    {
        printf("Failed to fork\n");
        exit(1);
    }
    else                                   // parent
    {sIdentifier = "Parent Process:";
    }
    printf("%s",sIdentifier);
    printf("Global variable:%d \n",globalVariable);
    getch();
    return 0;
}
/*
OUTPUT:
Parent Process: Global variable: 2
Child Process:  Global variable: 3
*/
