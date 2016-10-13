#include "SDL.h" //ALL IS NEW

#define MAPlength      64
#define MAPheight      44
#define SPRITE_SIZE    32

extern int MAP[MAPlength][MAPheight];


/*---Prototypes---*/

void set_map();
void set_position();


/*-----function------*/

void set_map()
{
  int i,j;
  
     /* set grass everywhere */  
  for( i=0 ; i < MAPlength ; i++)
    {
      for( j=0 ; j < MAPheight  ; j++)
	{
	  MAP[i][j] = 0;
	}
    }

     /* set whater */
  for( j=1 ; j < 3 ; j++ )
    {
      for( i=0 ; i < MAPlength ; i++ )
	{
	  MAP[i][MAPheight-j] = 1;
	}
    }
  MAP[2][3] = 2 ;
  MAP[2][4] = 3 ;
  MAP[2][5] = 4 ;
}









void set_position()
{
  //a faire
  printf("\na faire\n");
}