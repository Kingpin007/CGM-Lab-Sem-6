#include<stdio.h>
#include<graphics.h>
#include<math.h>

void drawEndRectangle();
void drawTopRectangle();
void drawMiddleRectangle();
int gd,gm;
int r,i,a,b,x,y;
float PI=3.141596;
int main()
{
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"");
	drawTopRectangle();
	drawMiddleRectangle();
	drawEndRectangle();
	//drawCircle();
	//drawSpokes();
	setcolor(WHITE);
	outtextxy(250,260,"FRANCE");
	getch();
	closegraph();
	return 0;
}

void drawTopRectangle()
{
    setcolor(RED);
	rectangle(100,100,450,150);
	setfillstyle(SOLID_FILL,RED);
	floodfill(101,101,RED);
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
    setcolor(BLUE);
	rectangle(100,200,450,250);
	setfillstyle(SOLID_FILL,BLUE);
	floodfill(101,201,BLUE);
}


