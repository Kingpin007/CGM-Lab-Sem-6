#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>

int pixels[2][4];
float xn1,xn2,yn1,yn2,x3,y3,m;


void show_quadrant()
	{
	cleardevice();
	rectangle(120,40,320,240);
	rectangle(320,40,520,240);
	rectangle(120,240,320,440);
	rectangle(320,240,520,440);
	for(int i=130;i<=510;i+=10)
		{
		if(i==320)
		continue;
		outtextxy(i,237,"+");
		}
	for(i=50;i<=430;i+=10)
		{
		if(i==240)
		continue;
		outtextxy(317,i,"-");
		}
	outtextxy(310,230,"O");
	outtextxy(530,240,"X");
	outtextxy(320,450,"-Y");
	outtextxy(100,240,"-X");
	outtextxy(320,30,"Y");
	}


void midpt(int x1,int y1,int x2,int y2,int xmin,int ymin,int xmax,int ymax)
   	{
      	int fl=1;
      	int pixels[2][4],i,j;
      	for(i=0;i<2;i++)
	 	for(j=0;j<4;j++)
	     		pixels[i][j]=0;
      	if(y1>ymax)
		pixels[0][0]=1;
      	if(y1<ymin)
		pixels[0][1]=1;
      	if(x1>xmax)
		pixels[0][2]=1;
      	if(x1<xmin)
		pixels[0][3]=1;
      	if(y2>ymax)
		pixels[1][0]=1;
      	if(y2<ymin)
		pixels[1][1]=1;
      	if(x2>xmax)
		pixels[1][2]=1;
      	if(x2<xmin)
		pixels[1][3]=1;

      	for(j=0;j<4;j++)
      		{
	 	if(pixels[0][j]==0&&pixels[1][j]==0)
	    	continue;

	 	if(pixels[0][j]==1&&pixels[1][j]==1)
	  		{
	    		fl=3;
	    		break;
	  		}
		fl=2;
      		}
        switch(fl)
		{
	   	case 1:
	     		line(320+x1,240-y1,320+x2,240-y2);
	     		break;

	   	case 3:
	     		cout<<"

a" Line Is Not Visible...:-(";
		     	break;

	   	case 2:
			int ox1=x1,ox2=x2,oy1=y1,oy2=y2;
	     		xn1=x1;
			yn1=y1;
	     		xn2=x2;
			yn2=y2;
	     		fl=0;
	     		x3=x1;
			y3=y1;
	     		while(1)
	       			{
 if(!(y1>ymax || y1<ymin || x1>xmax || x1<xmin) && (x3 || y3)!=0.1)
			    	break;
		 		x3=(x1+x2)/2.0;
		 		y3=(y1+y2)/2.0;

 if(!(y3>ymax || y3<ymin || x3>xmax || x3<xmin))
		   		fl=1;
		 		else
		   		fl=0;

		 		if(fl)
		   			{
		      			x2=x3;
		      			y2=y3;
		   			}
		 		else
		   			{
		      			x1=x3;
		      			y1=y3;
		   			}
	       			}
	     		xn1=x3;
	     		yn1=y3;
	     		fl=0;
	     		x1=ox1;
	     		x2=ox2;
	     		y1=oy1;
	     		y2=oy2;
	     		x3=x2;
			y3=y2;
	     		while(1)
	       			{
 if(!(y2>ymax || y2<ymin || x2>xmax || x2<xmin) && (x3 || y3)!=0.1)
		    		break;
		 		x3=(x1+x2)/2.0;
		 		y3=(y1+y2)/2.0;

 if(!(y3>ymax || y3<ymin || x3>xmax || x3<xmin))
		   		fl=1;
		 		else
		   		fl=0;

		 		if(fl)
		   			{
		      			x1=x3;
		      			y1=y3;
		   			}
		 		else
		   			{
		      			x2=x3;
		      			y2=y3;
		   			}
	       			}
	     		xn2=x3;
	     		yn2=y3;
	     		line(320+xn1,240-yn1,320+xn2,240-yn2);
	     		break;
		}
   	}

void show_message()
	{
	char *mess[]={"-","=","["," ","P","o","l","y","g","o","n"," ",
		      "C","l","i","p","p","i","n","g"," ","]","=","-"};
	int xx=28,xxx=52,i,j;
	_setcursortype(_NOCURSOR);
	for(i=0,j=24;i<16,j>=12;i++,j--)
		{
		gotoxy(xx,1);
		cout<<mess[i];
		xx++;
		gotoxy(xxx,1);
		cout<<mess[j];
		xxx--;
		delay(50);
		}
	_setcursortype(_NORMALCURSOR);
	}


void main()
	{
	clrscr();
        int gd=DETECT,gm,i,j;
        int xmin,ymin,xmax,ymax,x[10],y[10],ver;
        int choice,ed[20],num;
        show_message();
        cout<<"

		" Enter The Co-Ordinates Of The Clipping Window."";
	cout<<"

		" Enter X(min) & Y(min) ":=";
        cin>>xmin>>ymin;
	cout<<"
		" Enter X(max) & Y(max) ":=";
        cin>>xmax>>ymax;
        cout<<"

		" Enter The No Of Vertices Of Polygon ":=";
	cin>>ver;
	for(i=0;i<ver;i++)
	   	{
	      	cout<<"
		" Vertex X["<<i+1<<"] Y["<<i+1<<"] ":=";
	      	cin>>x[i]>>y[i];
	   	}
	x[ver]=x[0];
	y[ver]=y[0];
        clrscr();
	initgraph(&gd,&gm,"..\bgi");
	clearviewport();
        show_quadrant();
      	line(320+xmin,240-ymin,320+xmin,240-ymax);
      	line(320+xmin,240-ymax,320+xmax,240-ymax);
      	line(320+xmax,240-ymax,320+xmax,240-ymin);
      	line(320+xmax,240-ymin,320+xmin,240-ymin);
	for(i=0;i<ver;i++)
	     	line(320+x[i],240-y[i],320+x[i+1],240-y[i+1]);
	getch();
        cleardevice();
        show_quadrant();
      	line(320+xmin,240-ymin,320+xmin,240-ymax);
      	line(320+xmin,240-ymax,320+xmax,240-ymax);
      	line(320+xmax,240-ymax,320+xmax,240-ymin);
      	line(320+xmax,240-ymin,320+xmin,240-ymin);
	for(i=0;i<ver;i++)
		{
	   	midpt(x[i],y[i],x[i+1],y[i+1],xmin,ymin,xmax,ymax);
	   	}
	getch();
	closegraph();
        }