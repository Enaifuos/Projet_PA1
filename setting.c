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


    // Mes ajouts commencent d'ici  : Mise en place de la MAP " manuellement "

  // Draw two columns of sand              
  for ( i=0 ; i < MAPheight-2 ; i++)
    {
      MAP[1][i] = MAP[2][i] = 2;
    }
  for(i = 0 ; i < MAPlength ; i++)
    {
      MAP[i][MAPheight-4] = MAP[i][MAPheight-3] = 2;
    }


  // Draw three columns of trees
  for( i=0 ; i < 7 ; i++)
    {
      MAP[3][i] = MAP[4][i] = MAP[5][i] = 3 ;        
    }
  for ( j=5 ; j<10 ; j++ )
    {
      for(i=0 ; i<5 ; i++)
	{
	  MAP[j][i] = 3;
	}
    }
  for ( j = 5 ; j < MAPheight-4 ; j++){
    MAP[8][j] = MAP[9][j] = 3;
  }



  // Completting drawing trees columns with just two trees each line 
  for ( i=7 ; i < MAPheight-4 ; i++){
    MAP[3][i] = MAP[4][i] = 3;
  }



  // Drawing the ground_land 
  for ( i = 10 ; i < 18 ; i++ )
    {
      MAP[i][7] = MAP[i][6] = 4 ;
    }
  

  // Drawing the trees 
  MAP[5][39] = MAP[5][38] = MAP[6][38] = MAP[6][39] = MAP[7][38] = MAP[7][39] = MAP[6][37] = MAP[7][37] = MAP[7][36]  =  MAP[6][7] = MAP[5][7] = 3 ;
  MAP[8][6] =  MAP[9][6] =   MAP[8][7] =  MAP[9][7] = 0  ;


  // Drawing the cascade cavern
  MAP[10][0] = 11 ;
  for(i = 11 ; i < 20 ; i++)
    {
      MAP[i][0] = 12 ;
    }
  MAP[20][0] = 13 ;
  
  for (i = 10 ; i < 21 ; i++)
    {
      for (j = 1 ; j < 3 ; j++)
	{
	  if(i == 10 || i == 20 ){
	    if(i == 10)
	      {
		MAP[i][j] = 14 ;
	      }
	    else
	      {
		MAP[i][j] = 15 ;
	      }
	  }
	  else
	    {
	      MAP[i][j] = 12 ;
	    }
	}
    }
  MAP[15][1] = 22 ;
  MAP[14][1] = 22 ;
  MAP[16][1] = 22 ;
  
  for (i = 2 ; i < 5 ; i++ )
    {
      for (j = 14 ; j <= 16 ; j++ )
	{
	  MAP[j][i] = 18 ;
	}
    }
  MAP[10][3] = 16  ;
  MAP[20][3] = 17 ;

  MAP [9][8] = 0 ; // A supprimer , juste pour laisser passer le personnage afin de parcourir la map 
}









void set_position()
{
  //a faire
  printf("\na faire\n");
}
