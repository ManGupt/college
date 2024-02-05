#include<stdio.h>
#include<conio.h>

void print(int c[],int s)
{ int i;
  printf("\n");
  for(i=0;i<s;i++)
   printf(" %d ",c[i]);
}

int main()
{ 
  int i,j,k,n,r;
  int s[6]={1,2,3,4,5,6};
  int c[4]={1,3,4,5};
  n=6;r=4;
  for(i=r-1;i>=0;)
  { if(c[i] <s[i+n-r] )
    { for(j=i,k=c[i];j<r;j++,k++)
       c[j]=s[k];
      print(c,r);
      for(k=j-1;k>i;k--)
      { while(c[k] <s[k+n-r])
        { c[k]++;
          print(c,r);
        }
      }
    }
    else i--;
  }
  getch();
  return 0;
}
/*
 1  3  4  6
 1  3  5  6
 1  4  5  6
 2  3  4  5
 2  3  4  6
 2  3  5  6
 2  4  5  6
 3  4  5  6
*/