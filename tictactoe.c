#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#define toprow 10
#define topcol 10
#define botrow 410
#define botcol 410

int divide(int num);
int cross(int row,int col);
int circl(int row,int cross);
int row,col,xoffset,yoffset,i;
int main()
{
   int gd = DETECT, gm;
   int count = 1;

   initgraph(&gd,&gm,"C:\\TC\\BGI");

   divide(3);
   getch();

   cross(0,0);
   circl(0,1);
   cross(1,1);
   circl(2,2);
   cross(1,0);
   circl(0,2);
   cross(2,0);


   printf("CROSS WINS\n");
   getch();
   closegraph();
   return 0;
}

int divide(int num){
    rectangle(topcol,toprow,botcol,botrow);

    xoffset = (botcol - topcol)/num;
    yoffset = (botrow - toprow)/num;

    for(col=1;col<num;col++)
	    line(topcol + (col * xoffset), toprow, topcol + (col * xoffset),botrow);

    for(row=1;row<num;row++)
    line(topcol,toprow + (row * yoffset),botcol,toprow + (row * yoffset));
}

int cross(int row,int col){

    xoffset = (botcol - topcol)/3;
    yoffset = (botrow - toprow)/3;

    line(topcol + (col * xoffset),toprow + (row * yoffset),topcol + (col * xoffset)+xoffset,toprow + (row * yoffset)+yoffset);
    line(topcol + (col * xoffset) + xoffset,toprow + (row * yoffset),topcol + (col * xoffset),toprow + (row * yoffset)+yoffset);

    getch();
}

int circl(int row,int col){

    xoffset = (botcol - topcol)/3;
    yoffset = (botrow - toprow)/3;

    circle(topcol + (col * xoffset) + xoffset/2,toprow + (row * yoffset) + yoffset/2,yoffset/2);

    getch();
}
