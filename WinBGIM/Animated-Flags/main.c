
/*#include <graphics.h>

#include <stdlib.h>

#include <stdio.h>

#include <conio.h>



int main(void)

{
   int gdriver = DETECT, gmode, errorcode;
   int midx, midy, addx, addy;
   int stangle = 45, endangle = 135;
   int radius = 100;
   initgraph(&gdriver, &gmode, "");
   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   setcolor(COLOR(255,128,0));
   arc(midx, midy, stangle, endangle, radius);
   addx=140;
   addy=0;
   arc(midx+addx,midy+addy,45,stangle+90,radius);
   getch();

   closegraph();

   return 0;

}*/

#include <conio.h>
#include <math.h>
#include <graphics.h>
#include <dos.h>

int main()
{
    int gd = DETECT, gm;
    int angle = 0;
    double x, y;

    initgraph(&gd, &gm, "");
    /* generate a sine wave */
    int amp = 25,addenum=0;
    while(1)
    {
        for(amp=25;amp>=0;amp--)
        {
            for(x = 0; x < getmaxx()/4; x+=1)
            {
                y = amp*sin(angle*3.141/180);
                y = getmaxy()/4 - y;
                for(addenum=0;addenum<25;addenum++)
                {
                    putpixel(x+50, y+addenum, RED);
                    putpixel(x+50, y+addenum+25, WHITE);
                    putpixel(x+50, y+addenum+50, BLUE);
                }
                angle+=2;
            }
            delay(200);
            cleardevice();
        }
        for(amp=0;amp<=25;amp++)
        {
            for(x = 0; x < getmaxx()/4; x+=1)
            {
                y = amp*sin(angle*3.141/180);
                y = getmaxy()/4 - y;
                for(addenum=0;addenum<25;addenum++)
                {
                    putpixel(x+50, y+addenum, RED);
                    putpixel(x+50, y+addenum+25, WHITE);
                    putpixel(x+50, y+addenum+50, BLUE);
                }
                angle+=2;
            }
            delay(200);
            cleardevice();
        }
    }
    getch();
    /* deallocate memory allocated for graphics screen */
    closegraph();

    return 0;
}
