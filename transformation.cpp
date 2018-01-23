/* Graphics program for the different types of transformations such as
1.Translation
2.Rotation
3.Scaling */

#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

double finmat[3][3];
double identity[3][3];
int origmat[3][3]={{320,190,1},
{370,290,1},
{270,290,1}};
int transform[3][3];
int drawmat[8];

void multiply();
void setfin();
void transmat();

void main()
{
int gd=DETECT,gm,ch,x,y,i,j,k,errorcode,refx=320,refy=240;
double thita;
double costhita,sinthita;
initgraph(&gd,&gm,"c:\\tc\\bgi");
setcolor(RED);
do
{
drawmat[0] = origmat[0][0];
drawmat[1] = origmat[0][1]; //drawing triangle
drawmat[2] = origmat[1][0];
drawmat[3] = origmat[1][1];
drawmat[4] = origmat[2][0];
drawmat[5] = origmat[2][1];
drawmat[6] = origmat[0][0]; // connecting
drawmat[7] = origmat[0][1]; // to first
transmat();

drawpoly(4,drawmat);
printf("\n");
printf("1.To Translate an Object\n");
printf("2.To Rotate an Object\n");
printf("3.To Scale an Object\n");
printf("4.To Terminate the Program\n");
printf("Enter Your Choice : ");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter Translation Value For x : ");
scanf("%d",&x);
printf("Enter Translation Value For y : ");
scanf("%d",&y);
identity[0][0] = 1;
identity[0][1] = 0;
identity[0][2] = x; // 1 0 x
identity[1][0] = 0; // 0 1 y
identity[1][1] = 1; // 0 0 1
identity[1][2] = y;

identity[2][0] = 0;
identity[2][1] = 0;
identity[2][2] = 1;
multiply();
setfin();
getch();
clrscr();
cleardevice();
break;
case 2:
printf("Enter The Rotation Parameter 0: ");
scanf("%lf",&thita);
costhita = cos(thita*3.1428/180);
sinthita = sin(thita*3.1428/180);
//refx=320 refy=240
identity[0][0] = costhita;
identity[0][1] = -sinthita;
identity[0][2] = refx * ( 1 - costhita ) + refy * sinthita;
identity[1][0] = sinthita;
identity[1][1] = costhita;

identity[1][2] = refy * ( 1 - costhita ) - refx * sinthita;
identity[2][0] = 0;
identity[2][1] = 0;
identity[2][2] = 1;
multiply();
setfin();
getch();
clrscr();
cleardevice();
break;
case 3:
printf("Enter Scaling Value For x : ");
scanf("%d",&x);
printf("Enter Scaling Value For y : ");
scanf("%d",&y);

identity[0][0] = x;
identity[0][0] = 1/x;
identity[0][1] = 0;
identity[0][2] = ( 1 - x ) * refx;

identity[1][0] = 0;
identity[1][1] = y;

identity[1][2] = ( 1 - y ) * refy;
identity[2][0] = 0;
identity[2][1] = 0;
identity[2][2] = 1;
multiply();
setfin();
getch();
clrscr();
cleardevice();
break;
case 4:
getch();
cleardevice();
closegraph();
restorecrtmode();
exit(0);
default:
printf("Select your choice!\n");
getch();
break;
}
}while(ch!=4);
}

void multiply()
{
int i,j,k;
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
finmat[i][j]=0;
for(k=0;k<3;k++)
{
finmat[i][j] += identity[i][k] * transform[k][j];
}
}
}
}
void setfin()
{
drawmat[0] = int(finmat[0][0]);
drawmat[1] = int(finmat[1][0]);
drawmat[2] = int(finmat[0][1]); // 2x3
drawmat[3] = int(finmat[1][1]); // 0,0 0,1 0,2
drawmat[4] = int(finmat[0][2]); // 1,0 1,1 1,2
drawmat[5] = int(finmat[1][2]);
drawmat[6] = int(finmat[0][0]);
drawmat[7] = int(finmat[1][0]);
drawpoly(4,drawmat);
}
void transmat()
{
int i,j;
for(i=0;i<3;i++)
for(j=0;j<3;j++)
transform[j][i] = origmat[i][j];
}