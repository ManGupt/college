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
int algo4(float x1,float y1,float r1)//MID POINT circle
{ float p,x,y;
  p=3/4-2*r1;
  x=r1; y=0;
  while(x>=y)
  { set(x1+x,y1+y);set(x1-x,y1+y);set(x1+x,y1-y);set(x1-x,y1-y);
    set(x1+y,y1+x);set(x1-y,y1+x);set(x1+y,y1-x);set(x1-y,y1-x);
    if(p>0)
    { x=x; p=p-2*y-1; }
    else
    { x--; p=p+2*(x-y)+1; }
    y++;
  }
}
int algo5(float x1,float y1,float a,float b)//MID POINT ellipse
{ float p,x,y,sa,sb;
  sa=a*a; sb=b*b;
  p=sa+sb/4-sb*a;
  x=a; y=0;
  while(sb*x>=sa*y)
  { set(x1+x,y1+y);set(x1-x,y1+y);set(x1+x,y1-y);set(x1-x,y1-y);
    if(p>0)
    { x--; p=p-2*sb*x+sa*(3+2*y); }
    else
    { x=x; p=p+sa*(3+2*y); }
    y++;
  }
  p=sa/4+sb-sa*sb+sb*x*(x-2)+sa*y*(y+1);
  while(x>=0)
  { set(x1+x,y1+y);set(x1-x,y1+y);set(x1+x,y1-y);set(x1-x,y1-y);
    if(p>0)
    { y=y; p=p-sb*(2*x+1); }
    else
    { y++; p=p+2*sa*(1+y)-sb*(2*x+1); }
    x--;
  }
}
int algo6(float x1,float y1,float a,float b)//MID POINT hyperbola
{ float p,x,y,sa,sb;
  sa=a*a; sb=b*b;
  p=-sa+sb/4-sb*a;
  x=a; y=0;
  while(x<=5*a)
  { set(x1+x,y1+y);set(x1-x,y1+y);set(x1+x,y1-y);set(x1-x,y1-y);
    if(p<0)
    { x++; p=p+2*sb*(x+1)-sa*(3+2*y); }
    else
    { x=x; p=p-sa*(3+2*y); }
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
  printf("\n Enter (x,y,a): ");
  scanf("%f%f%f%f",&x,&y,&r1);
  algo(x,y,r1);
  getch();
  closegraph();
  return 0;
}
