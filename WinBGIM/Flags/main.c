#include<stdio.h>
#include<graphics.h>
#include<math.h>

void drawChakra();
void drawEndRectangle();
void drawTopRectangle();
void drawMiddleRectangle();
void drawCircle();
void drawSpokes();
int gd,gm;
int r,i,a,b,x,y;
float PI=3.14;
int main()
{
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"");
	drawTopRectangle();
	drawMiddleRectangle();
	drawEndRectangle();
	drawCircle();
    drawSpokes();
	getch();
	closegraph();
	return 0;
}

void drawTopRectangle()
{
    setcolor(COLOR(255,128,0));
	rectangle(100,100,450,150);
	setfillstyle(SOLID_FILL,COLOR(255,128,0));
	floodfill(101,101,COLOR(255,128,0));
}

void drawMiddleRectangle()
{
    setcolor(WHITE);
	rectangle(100,150,450,200);
	setfillstyle(SOLID_FILL,WHITE);
	floodfill(101,151,WHITE);
}

void drawEndRectangle()
{
    setcolor(GREEN);
	rectangle(100,200,450,250);
	setfillstyle(SOLID_FILL,GREEN);
	floodfill(101,201,GREEN);
}

void drawCircle()
{
    a=275;
	b=175;
	r=25;
	setcolor(BLUE);
	circle(a,b,r);
}
void drawSpokes()
{
	for(i=0;i<=360;i=i+15)
	{
		x=r*cos(i*PI/180);
		y=r*sin(i*PI/180);
		line(a,b,a+x,b-y);
	}
}
