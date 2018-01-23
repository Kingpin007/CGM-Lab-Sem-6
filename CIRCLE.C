#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void makeCircle(int,int,int,int);
int main(void)
{
   
   int gdriver = DETECT, gmode, errorcode;   
   int R,x,y,cx,cy,d;   
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
   //MidPoint Circle algorithm:
   printf("enter co-ordinates for center");
   scanf("%d",&cx);
   scanf("%d",&cy);
   printf("enter the radius:");
   scanf("%d",&R);
   x=0,y=R;
   d=1-R;
   
   while(y>x)
   {

   makeCircle(cx,cy,x,y);
	x++;
   if(d<0)
   {
    d=d+(2*x)+6;
   }
   else
   {
    y--;
    d=d+(2*(x-y))+1;
    
   }
    makeCircle(cx,cy,x,y);
   }
   
   getch();
   closegraph();
   return 0;
}
void makeCircle(int cx,int cy,int x,int y)
{
    putpixel(cx+x,cy+y,2);
    putpixel(cx-x,cy+y,2);
    putpixel(cx+x,cy-y,2);
    putpixel(cx-x,cy-y,2);
    putpixel(cx+y,cy+x,2);
    putpixel(cx-y,cy+x,2);
    putpixel(cx+y,cy-x,2);
    putpixel(cx-y,cy-x,2);
}