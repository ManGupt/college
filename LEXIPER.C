#include<stdio.h>
#include<conio.h>
#define N 4
void print(int p[])
{ int i;
  printf("\n");
  for(i=0;i<N;i++)
   printf(" %d ",p[i]);
}
void swap(int *i,int *j)
{ int temp;
  temp=*i;
  *i=*j;
  *j=temp;
}
void arrange(int p[],int start)
{ int k,i,end;
  end=N-1;
  for(k=start,i=0;i<(end-start)/2+1;k++,i++)
   swap(&p[k],&p[N-1-i]);
}
int check(int p[],int start)
{ int i;
  for(i=N-1;i>start;i--)
  { if(p[i]>p[i-1])
     return 0;
  }
  return 1;
}
int main()
{ 
  int i,j,k,r;
  int p[N]={2,4,3,1};
  for(i=N-2;i>=0;)
  { if(check(p,i))
     i--;
    else
    { for(j=N-1;p[i]>p[j];j--);
      swap(&p[i],&p[j]);
      arrange(p,i+1);
      print(p);
      for(k=N-2;k>i;)
      { if(check(p,k))
         k--;
        else
        { for(j=N-1;p[k]>p[j];j--);
          swap(&p[k],&p[j]);
          arrange(p,k+1);
          print(p);
          k++;
        }
      }
    }
  }
  getch();
  return 0;
}
/*
 3  1  2  4
 3  1  4  2
 3  2  1  4
 3  2  4  1
 3  4  1  2
 3  4  2  1
 4  1  2  3
 4  1  3  2
 4  2  1  3
 4  2  3  1
 4  3  1  2
 4  3  2  1
*/