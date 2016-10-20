#include "SDL.h" 
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


  /*  *************************** Mes ajouts commencent d'ici  : Mise en place de la MAP " manuellement " *************** */

  // Draw two columns of sand              
  for ( i=0 ; i < MAPheight-2 ; i++)
    {
      MAP[1][i] = MAP[2][i] = 2;
    }
  for(i = 0 ; i < MAPlength ; i++)
    {
      MAP[i][MAPheight-4] = 2;
      MAP[i][MAPheight-3] = 2;
    }


  // Draw three columns of trees
  for ( j=5 ; j<10 ; j++ )
    {
      for(i=0 ; i<5 ; i++)
	{
	  MAP[j][i] = 3;
	}
    }
  for ( j = 0 ; j < 11 ; j++){
    MAP[3][j] = MAP[4][j] = 3;
  }







 
 
  // Drawing the trees 

  MAP[8][6] = 0;
  MAP[9][6] = 0; 
  MAP[8][7] = 0;
  MAP[9][7] = 0;


  for(i=9;i<=19;i++){
    MAP[i][6] = 3;
  }
  for(i=0;i<6;i++){
    MAP[20][i] = 3;
    MAP[19][i] = 3;
  }
  // Drawing the cave 

  MAP[10][5] = 6;
  MAP[10][0] = 13;
  MAP[18][0] = 14;
  MAP[17][0] = 12;
  MAP[11][0] = 11;



  for( i = 1 ; i < 5 ; i++)
    {
      MAP[10][i] = 8;
      MAP[18][i] = 9;
    }
  


  // Drawing the cave fields 
  for(i=11;i<18;i++){
    for(j=1;j<5;j++){
       MAP[i][j] = 10;
    }
    MAP[i][5] = 5 ;
  }

  for(i = 11 ; i < 18 ; i++)
    {
      MAP[i][0] = 10;
    }

 
}


/***************************** ET finissent ici ****************************************************/






void set_position()
{
  //a faire
  printf("\na faire\n");
}
