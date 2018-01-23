#include <math.h>
#include <stdio.h>
#include<conio.h>
#include<graphics.h>
#include<iostream.h>
#include<stdlib.h>
#include<dos.h>
#include<conio.h>

#define size 2

int main(void){
   int gd = DETECT,gm,x,y,i,j;
   char c;
   initgraph(&gd,&gm,"C:\\TC\\BGI");
   int a[100][100];
   for(i=0;i<100;i++)
	for(j=0;j<100;j++)
		a[i][j]=0;
   for(i=0;i<100;i++)
   {
	a[i][0]=1;
	a[0][i]=1;
	a[i][99]=1;
	a[99][i]=1;
   }
   for(i=0;i<50;i++)
  {
	a[25+i][0]=1;
	a[30+i][15]=1;
	a[15][i+5]=1;
   }

   for(i=0;i<80;i++)
	a[80][i]=1;
   for(i=90;i<99;i++)
	a[0][i]=0;
   for(i=0;i<10;i++)
	a[99][i]=0;
   for(i=0;i<100;i++)
   {
	for(j=0;j<100;j++)
	{
		if(a[i][j])
			putpixel(i+100,j+100,1);
	}
   }
   x=100;y=195;

   circle(x,y,2);
   while(1)
   {
	c=getch();
	switch(c)
	{
		case '2':
			if(!a[x-100][y+1-100])
			{
				setcolor(0);
				circle(x,y,2);
				setcolor(15);
				circle(x,y+1,2);
				y++;
			}
			break;
		case '8':
			if(!a[x-100][y-1-100])
			{
				setcolor(0);
				circle(x,y,2);
				setcolor(15);
				circle(x,y-1,2);
				y--;
			}
			break;
		case '6':
			if(!a[x+1-100][y-100])
			{
				setcolor(0);
				circle(x,y,2);
				setcolor(15);
				circle(x+1,y,2);
				x++;
			}
			break;
		case '4':
			if(!a[x-1-100][y-100])
			{
				setcolor(0);
				circle(x,y,2);
				setcolor(15);
				circle(x-1,y,2);
				x--;
			}
			break;

	}
	if(x>200 && y<110 && y>100)
		break;
   }
   getch();
   closegraph();
}