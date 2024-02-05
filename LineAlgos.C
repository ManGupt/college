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
int algo1(float x1,float y1,float x2,float y2)//DDA
{ float x,y,dx,dy,step,xinc,yinc;
  dx=x2-x1; dy=y2-y1;
  step=(abs((int)dx)>abs((int)dy)) ? dx : dy;
  step=abs((int)step);
  if(!dx&&!dy)
  { set(x1,y1); return 0;
  }
  xinc=dx/step; yinc=dy/step;
  x=x1; y=y1;
  while(x!=x2&&y!=y2)
  { set(x,y);
    x+=xinc; y+=yinc;
  }
  return 0;
}
int algo2(float x1,float y1,float x2,float y2)//MID-POINT
{ float m,dx,dy,x,y,d,step,xinc,yinc;
  dx=x2-x1; dy=y2-y1;
  m=(abs((int)dx)>abs((int)dy)) ? dy/dx : dx/dy;
  step=(abs((int)dx)>abs((int)dy)) ? dx : dy;
  step=abs((int)step);
  if(!dx&&!dy)
  { set(x1,y1); return 0;
  }
  xinc=dx/step; yinc=dy/step;
  x=x1; y=y1;
  if(abs((int)dx)>abs((int)dy))
  {while(x!=x2&&y!=y2)
   { set(x,y);
     x+=xinc;
     d=y1+m*(x-x1);
     if((y+0.5)>d) y=d;
     else y+=yinc;
   }
  }
  else
  {while(x!=x2&&y!=y2)
   { set(x,y);
     y+=yinc;
     d=x1+m*(y-y1);
     if((x+0.5)>d) x=d;
     else x+=xinc;
   }
  }
  return 0;
}
int algo3(float x1,float y1,float x2,float y2)//BRESENHAM
{ float p,dx,dy,x,y,step,xinc,yinc;
  dx=x2-x1; dy=y2-y1;
  p=(abs((int)dx)>abs((int)dy)) ? dx-2*dy : dy-2*dx;
  step=(abs((int)dx)>abs((int)dy)) ? dx : dy;
  step=abs((int)step);
  if(!dx&&!dy)
  { set(x1,y1); return 0;
  }
  xinc=dx/step; yinc=dy/step;
  x=x1; y=y1;
  if(abs((int)dx)>abs((int)dy))
  {while(x!=x2&&y!=y2)
   { set(x,y);
     if(p>0)
     { y=y; p=p-2*dy; }
     else
     { y+=yinc; p=p-2*dy+2*dx; }
     x+=xinc;
   }
  }
  else
  {while(x!=x2&&y!=y2)
   { set(x,y);
     if(p>0)
     { x=x; p=p-2*dx; }
     else
     { x+=xinc; p=p-2*dx+2*dy; }
     y+=yinc;
   }
  }
  return 0;
}
int main()
{ int gdrv=DETECT,gmd;
  float x1,x2,y1,y2;
  printf("\n Enter coordinates(x1,y1): ");
  scanf("%f%f",&x1,&y1);
  printf(" Enter coordinates(x2,y2): ");
  scanf("%f%f",&x2,&y2);
  initgraph(&gdrv,&gmd,"");
  graphdefaults();
  rectangle(0,0,639,479);
  line(319,0,319,479);
  line(0,239,639,239);
  algo3(x1,y1,x2,y2);
  getch();
  closegraph();
  return 0;
}
