#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

void slow()
{
    if(kbhit())
    {
        delay(1000000);
    }
}

void ceiling()
{
    line(0,1,650,1);
}

void ground()
{
    line(0,150,650,150);
}

void manpos()
{
    circle(50,50,25);
    line(50,75,50,125);
    line(25,100,50,75);
    line(50,75,75,100);
    line(25,150,50,125);
    line(50,125,75,150);
}

void manpos2()
{
    circle(50,50,25);
    line(50,75,50,125);
    line(25,100,50,75);
    line(50,75,75,100);
    line(25,150,50,125);
    line(50,125,77,130);
}

void man2pos()
{
    circle(600,50,25);
    line(600,75,600,125);
    line(625,100,600,75);
    line(600,75,575,100);
    line(625,150,600,125);
    line(600,125,575,150);
}

void man2pos2()
{
    circle(600,50,25);
    line(600,75,600,125);
    line(625,100,600,75);
    line(600,75,575,100);
    line(625,150,600,125);
    line(600,125,560,140);
}

void ball(int x)
{
    int i;
    for(i=x; i>=100; i-=10)
    {
        slow();
        cleardevice();
        ceiling();
        ground();
        manpos();
        man2pos();
        circle(i,140,10);
        delay(20);
    }
    cleardevice();
    ceiling();
    ground();
    manpos2();
    man2pos();
    circle(i,140,10);
    slow();
    delay(20);
}

void ball2(int x)
{
    int i;
    for(i=x; i<=560; i+=10)
    {
        slow();
        cleardevice();
        ceiling();
        ground();
        manpos();
        man2pos();
        circle(i,140,10);
        delay(20);
    }
    cleardevice();
    ceiling();
    ground();
    manpos();
    man2pos2();
    circle(i,140,10);
    slow();
    delay(20);
}

int kick(int x,int y)
{
    int i,j;
    for(i=x, j=140; j>=y; i++,j-=3)
    {
        slow();
        cleardevice();
        ceiling();
        ground();
        manpos();
        man2pos();
        circle(i,j,10);
        delay(10);
    }
    for(; j<=140; i++,j+=3)
    {
        slow();
        cleardevice();
        ceiling();
        ground();
        manpos();
        man2pos();
        circle(i,j,10);
        delay(10);
    }
    return i;
}

int kick2(int x,int y)
{
    int i,j;
    for(i=x, j=140; j>=y; i--,j-=3)
    {
        slow();
        cleardevice();
        ceiling();
        ground();
        manpos();
        man2pos();
        circle(i,j,10);
        delay(10);
    }
    for(; j<=140; i--,j+=3)
    {
        slow();
        cleardevice();
        ceiling();
        ground();
        manpos();
        man2pos();
        circle(i,j,10);
        delay(10);
    }
    return i;
}

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd,&gm,"C:\\Program Files (x86)\\CodeBlocks-EP\\sdk\\winbgim\\include");
    int init=560, flag=0;
    while(1)
    {
        slow();
        int x,y;

        ball(init);
        slow();
        for(x=100,y=15; y<=150; y=y+20)
        {
           x=kick(x,y);
           slow();
        }
        slow();
        ball2(x);
        slow();
        for(x=560,y=15; y<=150; y=y+20)
        {
           x=kick2(x,y);
           slow();
        }
        slow();
        init=x;
    }
    getch();
    return 0;
}
