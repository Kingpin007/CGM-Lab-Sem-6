#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>

int main()
{
    int gdriver = DETECT,gmode;
    initgraph(&gdriver,&gmode,"");
    int x = getmaxx()/2;
    int y = getmaxy()/2;
    int i;
    for(i=30;i<200;i++)
    {
        delay(10);
        setcolor(i/10);
        arc(x,y,0,180,i-10);
    }
    getch();
}

