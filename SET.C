#include<stdio.h>

enum SIZE { S1=5, S2=5 };

int main()
{ int a[S1],b[S2],i;
  long hash1=0,hash2=0;
  printf("\nEnter 5 elements of 1st set:(0-31) ");
  for(i=0;i<S1;i++)
   scanf("%d",&a[i]);
  printf("\nEnter 5 elements of 2nd set:(0-31) ");
  for(i=0;i<S2;i++)
   scanf("%d",&b[i]);
  for(i=0;i<S1;i++)
   if(hash1 & (1<<a[i]));
   else hash1=hash1 | (1<<a[i]);
  for(i=0;i<S2;i++)
   if(hash2 & (1<<b[i]));
   else hash2=hash2 | (1<<b[i]);
  
  printf("\nUnion or Addition ");
  for(i=0;i<S1;i++)
   printf("%d ",a[i]);
  for(i=0;i<S2;i++)
   if(hash1&(1<<b[i]));
   else printf("%d ",b[i]);
  
  printf("\nIntersection ");
  for(i=0;i<S1;i++)
   if(hash2&(1<<a[i]))
    printf("%d ",a[i]);
  
  printf("\nSubtraction ");
  for(i=0;i<S1;i++)
   if(hash2&(1<<a[i]));
   else printf("%d ",a[i]);
  return 0;
}
/*
Enter 5 elements of 1st set:(0-31) 2 13 10 23 18
Enter 5 elements of 2nd set:(0-31) 20 18 13 29 23
Union or Addition 2 13 10 23 18 20 29
Intersection 13 23 18
Subtraction 2 10
*/
