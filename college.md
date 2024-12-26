## MERGE & QUICK SORT
```
#include<stdio.h>
void m_sort(int a[10],int s)
{ int step,i=0,j=0,k,tmp[10],l1,l2,u1,u2;
 for(step=1;step<s;step*=2)
 { k=0;  l1=0; l2=step; u1=step; u2=u1+step;
  while(l1<s)
  { for(j=l1,i=l2;(j<u1)&&(i<u2);k++)
    { if(a[j]>a[i])
      { tmp[k]=a[i]; i++; }
      else
      { tmp[k]=a[j]; j++; }
    }
    while(i<u2)
    { tmp[k]=a[i]; i++; k++; }
    while(j<u1)
    { tmp[k]=a[j]; j++; k++; }
    l1=u2; l2=l1+step; u1=l1+step; u2=u1+step;
  }
  for(k=0;k<=s;k++)
    a[k]=tmp[k];
 }
}
void swp(int *a,int *b)
{ int tmp;
  tmp=*b;
  *b=*a;
  *a=tmp;
}
void quick(int c[],int s)
{ int p,l,r;
  l=1,r=s-1,p=0;
  if(r<=0&&l>=s)
   return;
  while(l<=r)
  { while(c[p]>c[l]&&l<s)
    { l++; }
    while(c[p]<c[r]&&r>=0)
    { r--; }
    if(l<=r)
     swp(&c[r],&c[l]);
  }
  swp(&c[p],&c[r]);
  quick(c,r);
  quick(&c[r+1],s-r-1);
}
int main()
{ int i[50],j=0,k;
  printf("Enter elements ");
  do
  { scanf("%d",&i[j]);
    if(i[j]==0)
     break;
    j++;
  }while(i[j-1]!=0);
  for(k=0;k<j;k++)
  printf("\nElements are: %d ",i[k]);
  printf("\n1.Merge\n2.Quick");
  printf("\n Enter choice for sorting: ");
  scanf("%d",&k);
  switch(k)
  { case 1:m_sort(i,j);break;
    case 2:quick(i,j);break;
  }
  for(k=0;k<j;k++)
  printf(" %d ",i[k]);
  return 0;
}
```
```
OUTPUT
/*
Enter elements 13 5 10 29 18 23 20 0
Elements are: 13
Elements are: 5
Elements are: 10
Elements are: 29
Elements are: 18
Elements are: 23
Elements are: 20
1.Merge
2.Quick
 Enter choice for sorting: 2
5 10 13 18 20 23 29
*/
/*
Enter elements 13 2 10 29 18 0
Elements are: 13
Elements are: 2
Elements are: 10
Elements are: 29
Elements are: 18
1.Merge
2.Quick
 Enter choice for sorting: 1
2 10 13 18 29
*/
```

## BINARY SEARCH
```
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
```
```
OUTPUT
/*
Enter elements (asscending order) 2 10 13 18 23 29 0
Enter element to be searched 20
Element not found
Enter elements (asscending order) 2 10 13 18 23 0
Enter element to be searched 18
Element found
*/
```

## SET OPERATIONS
```
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
```
```
OUTPUT
/*
Enter 5 elements of 1st set:(0-31) 2 13 10 23 18
Enter 5 elements of 2nd set:(0-31) 20 18 13 29 23
Union or Addition 2 13 10 23 18 20 29
Intersection 13 23 18
Subtraction 2 10
*/
```

## MULTISET OPERATION
 ```
#include<stdio.h>

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
  return 0;
}
```
```
OUTPUT
/*
Enter elements of 1st set(7) 1 1 1 2 2 5 6
Enter elements of 2nd set(7) 1 2 2 2 6 6 7
Union 1-3 2-3 5-1 6-2 7-1
Intersection 1-1 2-2 6-1
Addition 1-4 2-5 5-1 6-3 7-1
Subtraction 1-2 5-1
*/
 ```
 
## MAX-MIN ELEMENT FROM LIST
 ```
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
```
```
OUTPUT
/*
Enter elements(10) 2 13 23 29 28 27 5 6 9 10
Max element: 29
Min element: 2
*/ 

```

## PERMUTATIONS  IN LEXICOGRAPHIC ORDER
 ```
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
```
```
OUTPUT
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
 ```
 
## COMBINATIONS  IN LEXICOGRAPHIC ORDER
 ```
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
```
```
OUTPUT
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
```

## EQUIVALENCE RELATION
```
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
```
```
OUTPUT
/*
Enter relational matrix(0-1 format)
1 0 0 1
0 1 0 0
0 1 1 0
1 0 0 1
 NOT EQUIVALENCE RELATION
*/
 ```
 
## DIJKSTRA’S ALGORITHM
```
#include<stdio.h>
#include<conio.h>
int w[6][6]={  {0,7,9,0,0,14},
               {7,0,10,15,0,0},
               {9,10,0,11,0,2},
               {0,15,11,0,6,0},
               {0,0,0,6,0,9},
               {14,0,2,0,9,0}
               };
void dij(int s,int d)
{ int dis[6]={0},curr,done[6]={0},tmp=0,k,i,small;
  for(i=0;i<6;i++)
   dis[i]=100;
  dis[s]=0,curr=s;
  while(curr!=d)
  { small=100;
    for(i=0;i<6;i++)
    { if(done[i]==0&&w[curr][i]!=0)
      { tmp=dis[curr]+w[curr][i];
	    if(tmp<dis[i])
	     dis[i]=tmp;
	    if(dis[i]<small)
	    { small=dis[i];
	      k=i;
	    }
      }
    }
    curr=k;
    done[curr]=1;
  }
  printf("\nLeast distance is %d ",dis[d]);
}
int main()
{ int s,d;
  printf("\nEnter source and destinstion ");
  scanf("%d%d",&s,&d);
  dij(s-1,d-1);
  getch();
  return 0;
}
```
```
/*
Enter source and destinstion 1 6
Least distance is 11
Enter source and destinstion 1 5
Least distance is 20
*/
 ```
 
## MINIMUM SPANNING TREE
 ```
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
```
```
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
```