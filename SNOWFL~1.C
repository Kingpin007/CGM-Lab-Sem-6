#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>


double factor;

char inbuff[ 80 ];

void vonkoch( int level, int scale, int rot );
void graph_vonkoch( void );

main()
{
   for ( ; ; ) {
      printf( "\nDo another (y = yes, n = no)? " );
      gets( inbuff );
      if ( toupper( *inbuff ) != 'Y' )
	 return EXIT_SUCCESS;
      graph_vonkoch();
   }
}


void graph_vonkoch( void )
{
   int gdriver = DETECT, gmode, errorcode, level;

   printf( "Enter level: " );
   gets( inbuff );
   level = atoi( inbuff );


   initgraph( &gdriver, &gmode, "C:\\tc\\bgi" );

   errorcode = graphresult();
   if ( errorcode != grOk )
   {
      printf( "Graphics error: %s\n", grapherrormsg( errorcode ) );
      return;
   }

   factor = sqrt( 3 ) / 2;
   moveto( 0, 0 );

   vonkoch( level, getmaxx(), 0 );


   outtextxy( 0, getmaxy() / 2, "Press any key to continue" );
   getch(); 
   closegraph();
}

void vonkoch( int level, int scale, int rot )
{
   if ( level == 0 )
      switch ( rot ) {
      case 0:
         linerel( scale, 0 );
         return;
      case 1:
         linerel( scale / 2, scale * factor );
         return;
      case 2:
         linerel( -scale / 2, scale * factor );
         return;
      case 3:
         linerel( -scale, 0 );
         return;
      case 4:
         linerel( -scale / 2, -scale * factor );
         return;
      case 5:
         linerel( scale / 2, -scale * factor );
         return;
      }

   vonkoch( level - 1, scale / 3, rot );
   vonkoch( level - 1, scale / 3, ( rot + 1 ) % 6 );
   vonkoch( level - 1, scale / 3, ( rot + 5 ) % 6 );
   vonkoch( level - 1, scale / 3, rot );
}