#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
int gd=DETECT, gm;
initgraph(&gd,&gm," ");
int xc,yc,r,tx,ty,xc1,yc1,xc2,yc2;
cout<<"Enter xc,yc,r";
cin>>xc>>yc>>r;
setcolor(3);
circle(xc,yc,r);
cout<<"Enter tx,ty";
cin>>tx>>ty;
xc1=xc+tx;
yc1=yc+ty;
// cleardevice();
setcolor(5);
circle(xc1,yc1,r);
cout<<"enter tx,ty for inverse translation";
cin>>tx>>ty;
xc2=xc-tx;
yc2=yc-ty;
setcolor(7);
circle(xc2,yc2,r);
getch();
closegraph();
}