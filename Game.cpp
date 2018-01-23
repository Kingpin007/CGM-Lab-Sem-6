#include <cstdio>
#include <iostream>
#include <cmath>
#include <graphics.h>

using namespace std;

int plates[6]={0};

void drawPlate() {
     for(int i=0; i<6; i++) {
         if(plates[i]==1)
             rectangle(0+(i*100),200,80+(i*100),210);
     }
}

void drawArrow(int x) {
     rectangle(0+x,10, 50+x, 25);
     int arrow[8] = {50+x,5, 75+x,18, 50+x,30, 50+x,5};
     drawpoly(4, arrow);
}

void drawDrops(int x, int y) {
     if(((x%100)<90)&&y<=200){
          circle(x,y,5);
          if(y==200 && x<=80) plates[0]=0;
          else if(y==200 && x<=180) plates[1]=0;
          else if(y==200 && x<=280) plates[2]=0;
     }     
     if(x%100 >= 90) circle(x,y,5);
}

int main()
{ 
    int gd=DETECT,gm,left,top,right,bottom;
    initgraph(&gd,&gm,"");
    int n;
    printf("Enter the number of plates : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++) plates[i]=1;
    int xdisplacement = 0;
    int ydisplacement[1000] = {0};
    while(xdisplacement<400) {
             cleardevice();
             drawPlate();
             drawArrow(xdisplacement);
             for(int i=0; i<=xdisplacement; i++) {
                  if(i%45 == 0) {
                      drawDrops(i, ydisplacement[i]);
                      ydisplacement[i]++;
                  }
             }             
             xdisplacement++;
             delay(7);
    }
    system("pause");
    closegraph();
    return 0;
}
