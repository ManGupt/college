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
int algo7(float x1,float y1,float r1)//BRESENHAM circle
{ float p,x,y;
  p=3-2*r1;
  y=r1; x=0;
  while(y>=x)
  { set(x1+x,y1+y);set(x1-x,y1+y);set(x1+x,y1-y);set(x1-x,y1-y);
    set(x1+y,y1+x);set(x1-y,y1+x);set(x1+y,y1-x);set(x1-y,y1-x);
    if(p>0)
    { y--; p=p+2*(3+2*x)+4*(1-y); }
    else
    { y=y; p=p+2*(3+2*x); }
    x++;
  }
}
int algo8(float x1,float y1,float a,float b)//BRESENHAM ellipse
{ float p,x,y,sa,sb;
  sa=a*a; sb=b*b;
  p=2*sb-sa-2*sa*b;
  x=0; y=b;
  while(sb*x<=sa*y)
  { set(x1+x,y1+y);set(x1-x,y1+y);set(x1+x,y1-y);set(x1-x,y1-y);
    if(p>0)
    { y--; p=p+4*sa*(1-y)+sb*2*(3+2*x); }
    else
    { y=y; p=p+2*sb*(3+2*x); }
    x++;
  }
  p=sb*(2*x*(x+1)+1)+2*sa*(1+y*(y-2))-2*sa*sb;
  while(y>=0)
  { set(x1+x,y1+y);set(x1-x,y1+y);set(x1+x,y1-y);set(x1-x,y1-y);
    if(p>0)
    { x=x; p=p-2*sa*(2*y+1); }
    else
    { x++; p=p-2*sa*(2*y+1)+sb*4*(x+1); }
    y--;
  }
}
int algo9(float x1,float y1,float a,float b)//BRESENHAM hyperbola
{ float p,x,y,sa,sb;
  sa=a*a; sb=b*b;
  p=-2*sa+sb+2*sb*a;
  x=a; y=0;
  while(x<=5*a)
  { set(x1+x,y1+y);set(x1-x,y1+y);set(x1+x,y1-y);set(x1-x,y1-y);
    if(p<0)
    { x++; p=p+4*sb*(x+1)-2*sa*(3+2*y); }
    else
    { x=x; p=p-2*sa*(3+2*y); }
    y++;
  }
}
int main()
{ int gdrv=DETECT,gmd;
  float x,y,r1,r2;
  initgraph(&gdrv,&gmd,"");
  graphdefaults();
  rectangle(0,0,639,479);
  line(319,0,319,479);
  line(0,239,639,239);
  printf("\n Enter (x,y,a,b): ");
  scanf("%f%f%f%f",&x,&y,&r1,&r2);
  algo(x,y,r1,r2);
  getch();
  closegraph();
  return 0;
}
