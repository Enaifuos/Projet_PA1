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
  for( i=0 ; i<MAPheight-2 ; i++)
    {
      MAP[0][i] = 1;
    }
  // Draw two columns of sand 
  for ( i=0 ; i < MAPheight-2 ; i++)
    {
      MAP[1][i] = 2;
      MAP[2][i] = 2;
    }
  // Draw three columns of trees
  for( i=0 ; i < 7 ; i++)
    {
      MAP[3][i] = 3;
      MAP[4][i] = 3;
      MAP[5][i] = 3;
    }
  // Completting drawin trees columns with just two trees each line 
  for ( i=7 ; i < MAPheight-2 ; i++){
    MAP[3][i] = 3;
    MAP[4][i] = 3;
  }
}









void set_position()
{
  //a faire
  printf("\na faire\n");
}
