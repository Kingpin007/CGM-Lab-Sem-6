
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
#include <stdio.h>

int rear=-1,front=-1,size=1000;
int arr[1000][8];

/* Function to create Circular queue */
void enQueue(int *value)
{
    int i;
    if ((front == 0 && rear == size-1) ||
            (rear == front-1))
    {
        printf("\nQueue is Full");
        return;
    }

    else if (front == -1) /* Insert First Element */
    {
        front = rear = 0;
        for(i=0;i<8;i++)
        {
            arr[rear][i]=value[i];
        }
    }

    else if (rear == size-1 && front != 0)
    {
        rear = 0;
        for(i=0;i<8;i++)
        {
            arr[rear][i]=value[i];
        }
    }

    else
    {
        rear++;
        for(i=0;i<8;i++)
        {
            arr[rear][i]=value[i];
        }
    }
}

// Function to delete element from Circular Queue
int* deQueue()
{
    int* data = arr[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size-1)
        front = 0;
    else
        front++;

    return data;
}

int empty(){
    if(front==-1)
        return 0;
    return 1;
}

void recurDraw(int *p,int n,int color)
{
    int a[8],m[8],b[8],c[8],i,k;
    for(i=0;i<8;i+=2){
        m[i] = (int)(p[i]+p[i+2])/2;
        m[i+1] = (int)(p[i+1]+p[i+3])/2;
    }
    m[6]=m[0];
    m[7]=m[1];
    drawpoly(4,m);
    setfillstyle(SOLID_FILL,color);
    fillpoly(4,m);
    a[0] = p[0];a[1]=p[1];a[2]=m[0];a[3]=m[1];a[4]=m[4];a[5]=m[5];a[6]=p[0];a[7]=p[1];
    enQueue(a);
    b[0]=p[2];b[1]=p[3];b[2]=m[0];b[3]=m[1];b[4]=m[2];b[5]=m[3];b[6]=p[2];b[7]=p[3];
    enQueue(b);
    c[0]=p[4];c[1]=p[5];c[2]=m[2];c[3]=m[3];c[4]=m[4];c[5]=m[5];c[6]=p[4];c[7]=p[5];
    enQueue(c);
    enQueue(m);
    if(n==0)
        return;
    int sc;
    while(1){
        printf("Recure more? (y/n): ");
        char cd;
        scanf(" %c",&cd);
        if(cd=='y'||cd=='Y'){
            if(color == WHITE)
                sc = BLACK;
            else
                sc = WHITE;
            recurDraw(deQueue(),0,sc);
            recurDraw(deQueue(),0,sc);
            recurDraw(deQueue(),0,sc);
            recurDraw(deQueue(),0,sc);
        }
        else
            break;
    }
}

int main()
{
    int gd = DETECT, gm;
    int x, y, i;

    initgraph(&gd, &gm, "");

    x = getmaxx()/2;
    y = getmaxy()/2;
    int points[] = {x-100,y-86,x+100,y-86,x,y+87,x-100,y-86};
    drawpoly(4,points);
    printf("Recure more? (y/n): ");
    char cd;
    scanf("%c",&cd);
    if(cd=='y'||cd=='Y')
        recurDraw(points,1,WHITE);
    getch();
    /* deallocate memory allocated for graphics screen */
    closegraph();

    return 0;
}
