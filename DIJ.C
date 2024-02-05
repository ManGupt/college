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
/*
Enter source and destinstion 1 6
Least distance is 11
Enter source and destinstion 1 5
Least distance is 20
*/