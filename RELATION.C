#include<stdio.h>
#include<conio.h>
#define M 4
int main()
{ int a[M][M],i,j,k,flag=1;
  printf("\nEnter relational matrix(0-1 format)\n");
  for(i=0;i<M;i++)
   for(j=0;j<M;j++)
    scanf("%d",&a[i][j]);
  
  for(i=0;i<M&&flag;i++)
  { if(a[i][i]==1);
    else flag=0;        //reflextion
    for(j=i;j<M&&flag;j++)
    { if(a[i][j]==a[j][i]);
      else flag=0;      //symmetry
      for(k=0;k<M&&flag;k++)
       if(a[i][j]==1&&a[j][k]==1)
       { if(a[i][k]==1);
         else flag=0;    //transitive
         }
      }
    }
  if(flag)
   printf("\nEQUIVALENCE RELATION ");
  else
   printf("\n NOT EQUIVALENCE RELATION ");
  getch();
  return 0;
}
/*
Enter relational matrix(0-1 format)
1 0 0 1
0 1 0 0
0 1 1 0
1 0 0 1
 NOT EQUIVALENCE RELATION
*/