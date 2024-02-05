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
