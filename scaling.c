#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"");
int x1,y1,x2,y2,sx,sy,x3,y3,x4,y4,x5,y5,x6,y6;
cout<<"x1,y1,x2,y2";
cin>>x1>>y1>>x2>>y2;
rectangle(x1,y1,x2,y2);
cout<<"sx,sy";
cin>>sx>>sy;
x3=x1*sx;
y3=y1*sy;
x4=x2*sx;
y4=y2*sy;
rectangle(x3,y3,x4,y4);
cout<<"-sx,-sy";
cin>>sx>>sy;
x5=x1/sx;
y5=y1/sy;
x6=x2/sx;
y6=y2/sy;
rectangle(x5,y5,x6,y6);
getch();
closegraph();
}