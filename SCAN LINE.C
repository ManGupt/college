#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#define R(a) (a+0.5)
#define N 6
int set(float x,float y,int c)
{ x=x+319;  y=239-y;
  x=R(x);  y=R(y);
  putpixel((int)x,(int)y,c);
  return 0;
}
int algo()
{ float dx,dy,x,y,max,min;
  float pt[N+1][2]={ {50, 20},{20, 40},{35, 60},{50, 40},{65,60},{80,40},{50, 20} };
  float edge[N][2],m[N]={0},ar[N]={0};//x,y  ymin,ymax
  int i,j,count;
  /*printf("\n Enter points(6): ");//enter points
  for(i=0;i<N;i++)
   scanf("%f%f",&pt[i][0],&pt[i][1]);
  pt[i][0]=pt[0][0]; pt[i][1]=pt[0][1];*/
  for(i=0;i<N;i++)//edge ymin,ymax
  { if((int)pt[i][1]>(int)pt[i+1][1])
    { edge[i][0]=pt[i+1][1];
      edge[i][1]=pt[i][1];
    }
    else
    { edge[i][0]=pt[i][1];
      edge[i][1]=pt[i+1][1];
    }
  }
  for(i=0;i<N;i++)//edge m
  { dx=(pt[i][0]-pt[i+1][0]);
    dy=(pt[i][1]-pt[i+1][1]);
    if(!dy&&!dx) m[i]=0;
    else m[i]=dx/dy;
  }
  min=240;//start y
  max=-240;//end y
  for(i=0;i<N;i++)
  { if((int)min>(int)edge[i][0])
     min=edge[i][0];
    if((int)max<(int)edge[i][1])
     max=edge[i][1];
  }
  for(y=min+1;y<max;y++)
  {
  for(i=0,count=0;i<N;i++)//intersect x
  { if((int)y>=(int)edge[i][0]&&(int)y<=(int)edge[i][1])
    { ar[count]=pt[i][0]+m[i]*(y-pt[i][1]);
      if(ar[count]==ar[count-1])
      { if((edge[i][0]==edge[i-1][1])&&(edge[i][1]>edge[i-1][1]))
         count--;
        if((edge[i-1][0]==edge[i][1])&&(edge[i][0]<edge[i-1][1]))
         count--;
      }
      count++;
    }
  }
  for(i=0;i<count;i+=2)
  { for(x=ar[i];x<ar[i+1];x++)
     set(x,y,10);
  }
}
  for(i=0;i<N;i++)
   line(319+(int)pt[i][0],239-(int)pt[i][1],319+(int)pt[i+1][0],239-(int)pt[i+1][1]);
  return 0;
}
int main()
{ int gdrv=DETECT,gmd,n;
  initgraph(&gdrv,&gmd,"");
  graphdefaults();
  rectangle(0,0,639,479);
  line(319,0,319,479);
  line(0,239,639,239);
  algo();
  getch();
  closegraph();
  return 0;
}
