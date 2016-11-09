#include "SDL.h" 
#include "global_variable.c"
#define MAPlength      64
#define MAPheight      44
#define SPRITE_SIZE    32

extern int** MAP;


/*---Prototypes---*/

void set_map();
void set_position();

//array function
int ** creerTable(int l , int c);
void freeTable(int **tableau);




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


  /* Draw two columns of sand */             
  for ( i=0 ; i < MAPheight-2 ; i++)
    {
      MAP[1][i] = MAP[2][i] = 2;
    }
  for(i = 0 ; i < MAPlength ; i++)
    {
      MAP[i][MAPheight-4] = 2;
      MAP[i][MAPheight-3] = 2;
    }
  

     /* set water */
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

 

  /* Draw three columns of trees */
  for ( j=5 ; j<9 ; j++ )
    {
      for(i=0 ; i<5 ; i++)
	{
	  MAP[j][i] = 3;
	}
    }
  for ( j = 0 ; j < 13 ; j++)
    {
      MAP[3][j] = MAP[4][j] = 3;
    }
  for ( i = 5 ; i < 17 ; i++)
    {
      MAP[i][12] = 3 ;
    }

  for(i=0;i<6;i++)
    {
      MAP[20][i] = 3;
      MAP[19][i] = 3;
    }
 



  for( i = 1 ; i < 5 ; i++)
    {
      MAP[10][i] = 8;
      MAP[18][i] = 9;
    }
  


  // Drawing the cave fields 
  for(i=11;i<18;i++)
    {
      for(j=1;j<5;j++)
	{
	  MAP[i][j] = 10;
	}
      MAP[i][5] = 5 ;
    }
  
  for(i = 11 ; i < 18 ; i++)
    {
      MAP[i][0] = 10;
    }
  
  MAP[14][5] = 17;
  
 // Drawing the cave 

  MAP[10][5] = 6;
  MAP[10][0] = 13;
  MAP[18][0] = 14;
  MAP[18][5] = 7;

   /* set water beside the cave */
  for( i = 0 ; i < 8 ; i ++ )
    {
      MAP[9][i] = 1 ;
    }

  for ( i = 10 ; i < 19 ; i ++ )
    {
      MAP[i][6] = 1 ;
      MAP[i][7] = 1 ;
    }
  
  for ( i = 7 ; i < 15 ; i ++)
    {
      MAP[17][i] = 1 ;
      MAP[18][i] = 1 ;
    }

  for ( i = 0 ; i < 18 ; i ++)
    {
      MAP[i][13] = 1 ;
      MAP[i][14] = 1 ;
    }
  
  // right permutation of rockwall to draw a second one 
  for ( i = 10 ; i < 19; i ++ )
    {
      for ( j = 0 ; j < 6 ; j ++ )
	{
	  MAP[i+11][j] = MAP[i][j];
	}
    }
  MAP[25][5] = 17;


  // Drawing the bridge 
  MAP[14][6] = 15;
  MAP[14][7] = 15;
  MAP[15][6] = 16;
  MAP[15][7] = 16;
  
  MAP[17][10] = 15;
  MAP[17][11] = 15;
  MAP[18][10] = 16;
  MAP[18][11] = 16;

  for ( i = 19 ; i < 30 ; i++)
    {
      if ( i != 24 && i != 25 ){
	for ( j = 6 ; j < 10 ; j ++ )
	  {
	    MAP[i][j] = 3 ;
	  }
	for ( j = 12 ; j < 15 ; j ++ )
	  {
	    MAP[i][j] = 3 ;
	  }
      }
    }

  // drawing the mystery box 
  MAP[25][10] = 18; // à voir la position ou les mettre ! 
 

  /* dessiner une échelle 
   *MAP[24][10] = 19;
   * MAP[24][11] = 20;*/

  //test

  MAP[30][10] = 4;
  MAP[31][10] = 4;
  MAP[31][11] = 4;
  MAP[30][11] = 4;
  
  
}
  









void set_position()
{
  coordplayerx = 10*SPRITE_SIZE;   
  coordplayery = 8*SPRITE_SIZE;  
}



int ** creerTable(int l , int c)
{
  int ** t1 = (int **)malloc(sizeof(int*)*l);
  int *t2 = (int *)malloc(sizeof(int*)*c*l);
  int i ;
  for (i = 0 ; i < l ; i++)
    {
      t1[i] = &t2[i*c];
    }
  return t1 ;
}


void freeTable(int **tableau)
{
  free(tableau[0]);
  free(tableau);
}
