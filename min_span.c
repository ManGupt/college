#include<stdio.h>
#include<conio.h>
#define MAX 6
#define EMAX 10
int main()
{ int e[EMAX][3]={ {0,1,16}, {0,4,19}, {0,5,21}, {1,2,5}, {1,3,6}, {1,5,11}, {2,3,10}, {3,4,18}, {3,5,14}, {4,5,33}    };
  int i,j,ti,tj,tc,all=0;
  int done[MAX];
  for(i=0;i<MAX;i++) done[i]=0;
  for(i=0;i<EMAX-1;i++)
  for(j=i+1;j<EMAX;j++)
   if(e[i][2]>e[j][2])
   { ti=e[i][0],tj=e[i][1],tc=e[i][2];
     e[i][0]=e[j][0],e[i][1]=e[j][1],e[i][2]=e[j][2];
     e[j][0]=ti,e[j][1]=tj,e[j][2]=tc;
     } 
   for(i=0;i<EMAX;i++)
    if( !done[(e[i][0])] || !done[(e[i][1])] )
    { printf("\n%d %d = %d",e[i][0],e[i][1],e[i][2]);
      if(!done[(e[i][0])])
      { done[(e[i][0])]=1;
        all++;
        }
      if(!done[(e[i][1])])
      { done[(e[i][1])]=1;
        all++;        }
      if(all==MAX)
       goto X;      }
    else 
     printf("\nREJECT %d %d = %d",e[i][0],e[i][1],e[i][2]);
      
   printf("\nNO SPANNING TREE EXIST");
   X:getch();   return 0;
}
OUTPUT
/*
1 2 = 5
1 3 = 6
REJECT 2 3 = 10
1 5 = 11
REJECT 3 5 = 14
0 1 = 16
3 4 = 18
*/
