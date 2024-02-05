#include<stdio.h>
#include<conio.h>

enum SIZE { S1=7, S2=7 };

int main()
{ int a[S1],b[S2],i;
  int max1,min1,max2,min2;
  char *hash1,*hash2;

  printf("Enter elements of 1st set(7) ");
  for(i=0;i<S1;i++)
   scanf("%d",&a[i]);
  printf("Enter elements of 2nd set(7) ");
  for(i=0;i<S2;i++)
   scanf("%d",&b[i]);

  for(i=1,min1=max1=a[0];i<S1;i++)
  { if(a[i]<min1)
     min1=a[i];
    else if(a[i]>max1)
     max1=a[i];
  }
  hash1=(char*)malloc(32);
  for(i=0;i<32;i++)
   hash1[i]=0;
  for(i=0;i<S1;i++)
   hash1[(a[i])]++;

  for(i=1,min2=max2=b[0];i<S2;i++)
  { if(b[i]<min2)
     min2=b[i];
    else if(b[i]>max2)
     max2=b[i];
  }
  hash2=(char*)malloc(32);
  for(i=0;i<32;i++)
   hash2[i]=0;
  for(i=0;i<S1;i++)
   hash2[(b[i])]++;
  
  printf("Union ");
  for(i=min1;i<=max1;i++)
   if(hash1[i]>0)
    if((int)hash2[i]>0)
    { printf("%d-%d ",i, (int)hash1[i] > (int)hash2[i] ? (int)hash1[i]: (int)hash2[i]);
    }
    else printf("%d-%d ",i,(int)hash1[i]);
  for(i=min2;i<=max2;i++)
   if(hash2[i]>0)
    if((int)hash1[i]>0);
    else printf("%d-%d ",i,(int)hash2[i]);
  
  printf("Intersection ");
  for(i=min1;i<=max1;i++)
   if(hash1[i]>0)
    if((int)hash2[i]>0)
    { printf("%d-%d ",i, (int)hash1[i] < (int)hash2[i] ? (int)hash1[i]: (int)hash2[i]);
    }
  
  printf("Addition ");
  for(i=min1;i<=max1;i++)
   if(hash1[i]>0)
    if((int)hash2[i]>0)
    { printf("%d-%d ",i,((int)hash1[i]+(int)hash2[i]));
    }
    else printf("%d-%d ",i,(int)hash1[i]);
  for(i=min2;i<=max2;i++)
   if(hash2[i]>0)
    if((int)hash1[i]>0);
    else printf("%d-%d ",i,(int)hash2[i]);
  
  printf("Subtraction ");
  for(i=min1;i<=max1;i++)
   if(hash1[i]>0)
    if( ((int)hash1[i]-(int)hash2[i]) >0)
    { printf("%d-%d ",i,((int)hash1[i]-(int)hash2[i]));
    }
getch();
  return 0;
}
/*
Enter elements of 1st set(7) 1 1 1 2 2 5 6
Enter elements of 2nd set(7) 1 2 2 2 6 6 7
Union 1-3 2-3 5-1 6-2 7-1
Intersection 1-1 2-2 6-1
Addition 1-4 2-5 5-1 6-3 7-1
Subtraction 1-2 5-1
*/
