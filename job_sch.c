#include<stdio.h>
#include<conio.h>
int name[10],time[10],prior[10];
#define swap(a,b) a=b-a+(b=a)

int main()
{
    int a,b,i,x,y,q,done;
    int wait[10],res[10],turn[10];
    printf("\nProgram for Job Scheduling Algorithms(all Jobs arrive at same time):-");
    printf("\nEnter no. of jobs(max:10) ");
    scanf("%d",&y);
    for(i=0;i<10;i++)
    { wait[i]=res[i]=turn[i]=0;
      name[i]=time[i]=prior[i]=0;
      }
    for(i=0;i<y;i++)
    { printf("\nEnter job name, burst time ");
      scanf("%d%d",&name[i],&time[i]);
      }
    printf("\nEnter your choice of algorithm ");
    printf("\n1.Shortest Job First ");
    printf("\n2.First Come First Serve ");
    printf("\n3.Priority Scheduling ");
    printf("\n4.Round Robin ");
    scanf("%d",&x);
    switch(x)
    { case 1:
           for(a=0;a<y-1;a++)
           for(b=a+1;b<y;b++)
           { if(time[a]>time[b])
             { swap(name[a],name[b]);
               swap(time[a],time[b]);
               }
             }
           turn[0]=time[0];
           for(a=1;a<y;a++)
           { wait[a]=0;
             for(b=0;b<a;b++)
              wait[a]+=time[b];
             res[a]=wait[a];
             turn[a]=wait[a]+time[a];
             }
           printf("\n\tName\tWaiting\tResponse\tTurn Around time");
           for(i=0;i<y;i++)
           { printf("\n\t%3d\t%4d\t%4d\t\t%8d",name[i],wait[i],res[i],turn[i]);}
           break;
      case 2:
           turn[0]=time[0];
           for(a=1;a<y;a++)
           { wait[a]=0;
             for(b=0;b<a;b++)
              wait[a]+=time[b];
             res[a]=wait[a];
             turn[a]=wait[a]+time[a];
             }
           printf("\n\tName\tWaiting\tResponse\tTurn Around time");
           for(i=0;i<y;i++)
           { printf("\n\t%3d\t%4d\t%4d\t\t%8d",name[i],wait[i],res[i],turn[i]);}
           break;
      case 3:
           for(i=0;i<y;i++)
           { printf("\nEnter job priority: ");
             scanf("%d",&prior[i]);
           }
           for(a=0;a<y-1;a++)
           for(b=a+1;b<y;b++)
           { if(prior[a]>prior[b])
             { swap(name[a],name[b]);
               swap(time[a],time[b]);
               swap(prior[a],prior[b]);
               }
             }
           turn[0]=time[0];
           for(a=1;a<y;a++)
           { wait[a]=0;
             for(b=0;b<a;b++)
              wait[a]+=time[b];
             res[a]=wait[a];
             turn[a]=wait[a]+time[a];
             }
           printf("\n\tName\tWaiting\tResponse\tTurn Around time");
           for(i=0;i<y;i++)
           { printf("\n\t%3d\t%4d\t%4d\t\t%8d",name[i],wait[i],res[i],turn[i]);}
           break;
      case 4:
           printf("\nEnter quantum size: ");
           scanf("%d",&q);
           turn[0]=time[0];
           done=time[0];
           for(a=1;a<y;a++)
           { res[a]=a*q-(time[a-1]>q?0:-time[a-1]+q);
             turn[a]=time[a];
             done+=time[a];
             }
           for(i=0,b=0;b<done;i++)
           { a=i%y;
             if(time[a]>0)
             { b+=(time[a]>q?q:time[a]);
               time[a]-=q;
               wait[a]=b-turn[a];
               }
             }
           for(a=0;a<y;a++)
           { turn[a]+=wait[a];
             }
           printf("\n\tName\tWaiting\tResponse\tTurn Around time");
           for(i=0;i<y;i++)
           { printf("\n\t%4d\t%4d\t%4d\t\t%8d",name[i],wait[i],res[i],turn[i]);}
           break;
      default:printf("\nWrong choice");
      }
    getch();
    return 0;
}
