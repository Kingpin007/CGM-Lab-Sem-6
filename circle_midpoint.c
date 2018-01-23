mi#include <stdio.h>
#include <dos.h>
#include <graphics.h>
void circleMidpoint(int, int, int);
void drawCircle(int, int, int, int);
void main()
{
int xc, yc, r;
int gd = DETECT, gm;
initgraph(&gd, &gm, "");
printf("Enter center coordinates of circle: ");
scanf("%d %d", &xc, &yc);
printf("Enter radius of circle: ");
scanf("%d", &r);
circleMidpoint(xc, yc, r);
getch();
}
void circleMidpoint(int xc, int yc, int r)
{
int x = 0, y = r;
int p = 1 - r;
while (x < y)
{
drawCircle(xc, yc, x, y);
x++;
if (p < 0)
p = p + 2 * x + 1;
else
{
y--;
p = p + 2 * (x - y) + 1;
}
drawCircle(xc, yc, x, y);
delay(50);
}
}
void drawCircle(int xc, int yc, int x, int y)
{
putpixel(xc+x, yc+y, RED);
putpixel(xc-x, yc+y, RED);
putpixel(xc+x, yc-y, RED);
putpixel(xc-x, yc-y, RED);
putpixel(xc+y, yc+x, RED);
putpixel(xc-y, yc+x, RED);
putpixel(xc+y, yc-x, RED);
putpixel(xc-y, yc-x, RED);
}
