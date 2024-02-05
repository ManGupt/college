#include<stdio.h>

void bin(int a[],int s,int k)
{ int f=0,l=s-1,m;
  for(m=(l+f)/2;l>=f;m=(l+f)/2)
  { if(a[m]==k)
    { printf("\nElement found");
      return;
    }
    else if(a[m]<k)
	  f=m+1;
	 else
	  l=m-1;
  }
  printf("\nElement not found");
}
int main()
{ int i[50],j=0,k;
  printf("Enter elements (asscending order) ");
  do
  { scanf("%d",&i[j]);
    if(i[j]==0)
     break;
    j++;
  }while(i[j-1]!=0);
  printf("\nEnter element to be searched ");
  scanf("%d",&k);
  bin(i,j,k);
  return 0;
}
/*
Enter elements (asscending order) 2 10 13 18 23 29 0
Enter element to be searched 20
Element not found
Enter elements (asscending order) 2 10 13 18 23 0
Enter element to be searched 18
Element found
*/
