#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include<time.h>

void main(){

	  int graphdriver, graphmode, errorcode, i;
	  graphdriver = DETECT;
	  initgraph(&graphdriver, &graphmode, "C:\\TC\\BGI");

	  setcolor(BLUE);
	  setfillstyle(4,BLUE);
	  rectangle(100,300,300,250);
	  //putpixel(105,295,15);
	  floodfill(105,295,BLUE);

	  setfillstyle(5,BLUE);
	  rectangle(400,200,350,350);
	  //putpixel(375,300,15);
	  floodfill(375,300,BLUE);

	  line(300,250,350,200);
	  line(300,300,350,350);

	  setcolor(YELLOW);
	  setfillstyle(7,YELLOW);
	  for(int j=200;j<=350;j+=10){
	  line(410,j,600,j-100);
	  line(410,j,600,j+100);
	  line(410,j,600,j);
	  delay(10);
	  }

	  getch();
	  closegraph();
	  }