#include<stdio.h>
#include<conio.h>
int main()
{ 
  int a[10],max1,min1,i;

  printf("Enter elements(10) ");
  for(i=0;i<10;i++)
   scanf("%d",&a[i]);
  for(i=1,min1=max1=a[0];i<10;i++)
  { if(a[i]<min1)
     min1=a[i];
    else if(a[i]>max1)
     max1=a[i];
  }
  printf("\nMax element: %d\nMin element: %d",max1,min1);
  getch();
  return 0;
}
/*
Enter elements(10) 2 13 23 29 28 27 5 6 9 10
Max element: 29
Min element: 2
*/
