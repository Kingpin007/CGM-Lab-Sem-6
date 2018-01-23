
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<math.h>
int main()
{
    int gm;
    int gd=DETECT;
    int x1,x2,x3,y1,y2,y3,x4,y4,x5,y5,nx1,nx2,nx3,ny1,ny2,ny3,nx4,ny4,nx5,ny5,c;
    int sx,sy,xt,yt,r;
    float t;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    printf("Enter the points of triangle\n");
    setcolor(WHITE);
    scanf("%d%d%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4,&x5,&y5);
    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x4,y4);
    line(x4,y4,x5,y5);
    line(x5,y5,x1,y1);

    //getch();
    printf("\n 1.Translation\n 2.Rotation\n 3.Scaling\n 4.exit\n");
    while(1)
    {
	printf("Enter your choice:\n");
	scanf("%d",&c);

	switch(c)
	{
	    case 1:
	    printf("Enter the translation factor\n");
	    scanf("%d%d",&xt,&yt);
	    nx1=x1+xt;
	    ny1=y1+yt;
	    nx2=x2+xt;
	    ny2=y2+yt;
	    nx3=x3+xt;
	    ny3=y3+yt;
	    nx4=x4+xt;
	    ny4=y4+yt;
	    nx5=x5+xt;
	    ny5=y5+yt;
	    clearviewport();
	    line(x1,y1,x2,y2);
	    line(x2,y2,x3,y3);
	    line(x3,y3,x4,y4);
	    line(x4,y4,x5,y5);
	    line(x5,y5,x1,y1);
	    line(nx1,ny1,nx2,ny2);
	    line(nx2,ny2,nx3,ny3);
	    line(nx3,ny3,nx4,ny4);
	    line(nx4,ny4,nx5,ny5);
	    line(nx5,ny5,nx1,ny1);
	    break;

	    case 2:
	    printf("Enter the angle of rotation\n");
	    scanf("%d",&r);
	    t=3.14*r/180;
	    nx1=abs(x1*cos(t)-y1*sin(t));
	    ny1=abs(x1*sin(t)+y1*cos(t));
	    nx2=abs(x2*cos(t)-y2*sin(t));
	    ny2=abs(x2*sin(t)+y2*cos(t));
	    nx3=abs(x3*cos(t)-y3*sin(
	    t));
	    ny3=abs(x3*sin(t)+y3*cos(t));
	    nx4=abs(x4*cos(t)-y4*sin(t));
	    ny4=abs(x4*sin(t)+y4*cos(t));
	    nx5=abs(x5*cos(t)-y5*sin(t));
	    ny5=abs(x5*sin(t)+y5*cos(t));
	    clearviewport();
	    line(x1,y1,x2,y2);
	    line(x2,y2,x3,y3);
	    line(x3,y3,x4,y4);
	    line(x4,y4,x5,y5);
	    line(x5,y5,x1,y1);
	    line(nx1,ny1,nx2,ny2);
	    line(nx2,ny2,nx3,ny3);
	    line(nx3,ny3,nx4,ny4);
	    line(nx4,ny4,nx5,ny5);
	    line(nx5,ny5,nx1,ny1);
	    break;

	    case 3:
	    printf("Enter the scaling factor\n");
	    scanf("%d%d",&sx,&sy);
	    nx1=x1*sx;
	    ny1=y1*sy;
	    nx2=x2*sx;
	    ny2=y2*sy;
	    nx3=x3*sx;
	    ny3=y3*sy;
	    nx4=x4*sx;
	    ny4=y4*sy;
	    nx5=x5*sx;
	    ny5=y5*sy;
	    clearviewport();
	    line(x1,y1,x2,y2);
	    line(x2,y2,x3,y3);
	    line(x3,y3,x4,y4);
	    line(x4,y4,x5,y5);
	    line(x5,y5,x1,y1);
	    line(nx1,ny1,nx2,ny2);
	    line(nx2,ny2,nx3,ny3);
	    line(nx3,ny3,nx4,ny4);
	    line(nx4,ny4,nx5,ny5);
	    line(nx5,ny5,nx1,ny1);
	    break;

	    case 4:
	    break;
	    default:
	    printf("Enter the correct choice");
	}
	if(c==4)
	break;
    }
    getch();
    closegraph();
    return 0;
}

