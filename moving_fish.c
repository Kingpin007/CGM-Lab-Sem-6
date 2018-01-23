#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
void main()
{
int gd=DETECT,gm;
int x,y,r,c,mx,my;
initgraph(&gd,&gm," ");
cout<<"enter x, y ,c";
cin>>x>>y>>c;
mx=getmaxx();
my=getmaxy();
while(!kbhit())
{
if((x>=mx)||(y>=my))
{
while((x>0)||(y>0))
{
cleardevice();
setcolor(c);
ellipse(x,y,0,360,50,20);
circle(x-40,y-5,2);
line(x+50,y,x+80,y-30);
line(x+80,y-30,x+80,y+30);
line(x+80,y+30,x+50,y);
setfillstyle(1,0);
floodfill(x,y,c);
x=x-rand()%10;
y=y-rand()%10;
}
}
else
{
while((x<=mx)||(y<=my))
{
cleardevice();
setcolor(c);
ellipse(x,y,0,360,50,20);
circle(x-40,y-5,2);
line(x+50,y,x+80,y-30);
line(x+80,y-30,x+80,y+30);
line(x+80,y+30,x+50,y);
setfillstyle(1,0);
floodfill(x,y,c);
x=x+rand()%10;
y=y+rand()%10;
}
}
delay(200);
}
getch();
closegraph();
}