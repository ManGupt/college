#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#define R(a) (a+0.5)
int set(float x,float y)
{ x=x+319;  y=239-y;
  x=R(x);  y=R(y);
  putpixel((int)x,(int)y,15);
  return 0;
}
int algo10(float x1,float y1,float r1)//first difference circle
{ float p,x,y;
  p=3/4-2*r1;
  x=r1; y=0;
  while(x>=y)
  { set(x1+x,y1+y);set(x1-x,y1+y);set(x1+x,y1-y);set(x1-x,y1-y);
    set(x1+y,y1+x);set(x1-y,y1+x);set(x1+y,y1-x);set(x1-y,y1-x);
    if(p<0)
    { x=x; p=p+2*y+3; }
    else
    { x--; p=p-2*(x-y)+3; }
    y++;
  }
}
int algo11(float x1,float y1,float r1)//second difference circle
{ float d,e,se,x,y;
  d=3/4-2*r1;
  e=3; se=3-2*r1;
  x=r1; y=0;
  while(x>=y)
  { set(x1+x,y1+y);set(x1-x,y1+y);set(x1+x,y1-y);set(x1-x,y1-y);
    set(x1+y,y1+x);set(x1-y,y1+x);set(x1+y,y1-x);set(x1-y,y1-x);
    if(d<0)
    { x=x; d+=e;e+=2;se+=2; }
    else
    { x--; d+=se;e+=2;se+=4; }
    y++;
  }
}
int main()
{ int gdrv=DETECT,gmd;
  initgraph(&gdrv,&gmd,"");
  graphdefaults();
  rectangle(0,0,639,479);
  line(319,0,319,479);
  line(0,239,639,239);
  //algo10(70,50,100);
  algo11(-50,50,50);
  getch();
  closegraph();
  return 0;
}
