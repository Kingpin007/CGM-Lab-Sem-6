#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

#define BKCOLOR BLACK
#define FGCOLOR WHITE

void iloop() {
 while(1) {
 if(kbhit())
 break;
 }
}
void arcs(int sx,int sy,int addx,int addy,int subx,int suby,int step,int r,int a1,int a2,int a3,int a4,int flag=0) {
    int i;
    setcolor(WHITE);
    setbkcolor(BLACK);
    rectangle(sx-subx-7,sy+suby,sx-subx-2,sy+suby+360);
    setfillstyle(SOLID_FILL,BROWN);
    floodfill(sx-subx-7+2,sy+suby+2,WHITE);
    line(sx+addx+subx,sy+suby,sx+addx+subx,sy+suby+3*step);
    for(i=0;i<4;i++) {
	arc(sx,sy+i*step,a1,a2,r);
	arc(sx+addx,sy+addy+i*step,a3,a4,r);
    }
    int colors[]={RED,WHITE,GREEN};
    for(i=0;i<3;i++) {
	setfillstyle(SOLID_FILL,colors[i]);
	floodfill(sx,sy+(flag ? -r : r)+step*i+1,WHITE);
    }
    setcolor(BLUE);
    circle(sx+subx,sy+suby+75,23);
    setcolor(WHITE);
}

void rect(int sx,int sy,int addx,int addy,int subx,int suby,int step,int r,int a1,int a2,int a3,int a4,int flag=0) {
    rectangle(sx-subx-7,sy+suby,sx-subx-2,sy+suby+360);
    setfillstyle(SOLID_FILL,BROWN);
    floodfill(sx-subx-7+2,sy+suby+2,WHITE);
    for(int i=0;i<3;i++) {
      rectangle(sx-subx-2,sy+suby+i*step,sx+addx+suby,sy+suby+(i+1)*step);
    }
}

void main()
{
    int gd=DETECT,gm,i;
    clrscr();
    initgraph(&gd,&gm,"\\TC\\BGI");
    int sx=200,sy=-100,addx=136,addy=375,subx=68,suby=187,step=50,r=200,a1=70,a2=110,a3=250,a4=290;
    //rect(sx,sy,addx,addy,subx,suby,step,r,a3,a4,a1,a2);
    while(1) {
	arcs(sx,sy,addx,addy,subx,suby,step,r,a3,a4,a1,a2);
	delay(1000);
	clrscr();
	arcs(sx,sy+suby*2,addx,-addy,subx,-suby,step,r,a1,a2,a3,a4,1);
	delay(1000);
	clrscr();
	if(kbhit())
	     break;
    }
    getch();
    closegraph();
}
