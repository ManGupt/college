#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#define R(a) (a+0.5)
int set(float x,float y,int c)
{ x=x+319;  y=239-y;
  x=R(x);  y=R(y);
  putpixel((int)x,(int)y,c);
  return 0;
}
int bfill(float x,float y,int bc,int fc)
{ int c=(int)getpixel(319+(int)x,239-(int)y);
  if(c!=bc&&c!=fc)
  { set(x,y,fc);
    bfill(x+1,y,bc,fc);
    bfill(x-1,y,bc,fc);
    bfill(x,y+1,bc,fc);
    bfill(x,y-1,bc,fc);
  }
  return 0;
}
int ffill(float x,float y,int pc,int fc)
{ int c=(int)getpixel(319+(int)x,239-(int)y);
  if(c==pc)
  { set(x,y,fc);
    ffill(x+1,y,pc,fc);
    ffill(x-1,y,pc,fc);
    ffill(x,y+1,pc,fc);
    ffill(x,y-1,pc,fc);
  }
  return 0;
}
int main()
{ int gdrv=DETECT,gmd;
  initgraph(&gdrv,&gmd,"");
  graphdefaults();
  rectangle(0,0,639,479);
  line(319,0,319,479);
  line(0,239,639,239);
  
  setcolor(4);line(319+20,239-30,319+120,239-30);setcolor(6);line(319+120,239-30,319+120,239-110);
  setcolor(11);line(319+20,239-30,319+20,239-110);setcolor(9);line(319+20,239-110,319+120,239-110);
  setcolor(15);
  rectangle(319-20,239-30,319-120,239-110);
  line(319+0,239-0,319-150,239-150);
  bfill(-110,100,15,10);
  ffill(100,100,0,15);
  getch();
  closegraph();
  return 0;
}
