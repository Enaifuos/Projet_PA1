#include "SDL.h" 
#include "global_variable.c"
#define MAPlength      64
#define MAPheight      44
#define SPRITE_SIZE    32



/*---Prototypes---*/

void set_map();
void set_position();

//array function
SDL_Surface ** creerTable(int l , int c);
void freeTable(SDL_Surface **tableau);




/*-----function------*/
void set_position()
{
  coordplayerx = 10*SPRITE_SIZE;   
  coordplayery = 8*SPRITE_SIZE;  
}





SDL_Surface ** creerTable(int l , int c)
{
  printf("creation table");
  SDL_Surface ** t1 = (SDL_Surface **)malloc(sizeof(SDL_Surface)*l);
  SDL_Surface *t2 = (SDL_Surface *)malloc(sizeof(SDL_Surface)*c*l);
  int i ;
  for (i = 0 ; i < l ; i++)
    {
      t1[i] = &t2[i*c];
    }
  if( t1 == NULL ) // test if the malloc run
    {
      printf("missing dynamic memory to run the game");
    }
  else{
    printf("\n\nYAHOOOO\n\n");
  }
  return t1 ;
}




void freeTable(SDL_Surface **tableau)
{
  int i;
  for( i = 0 ; i < MAPheight -1 ; i++)
    {
      free(tableau[i]);
    }
  free(tableau);
}













/*------------------- SET THE MAP ---------------------*/


void set_map()
{
  int i,j;
  
     /* set grass everywhere */  
  for( i=0 ; i < MAPlength ; i++)
    {
      for( j=0 ; j < MAPheight  ; j++)
	{
	  MAP[i][j] = *grass;
	}
    }


  /* Draw two columns of sand */             
  for ( i=0 ; i < MAPheight-2 ; i++)
    {
      MAP[1][i] = *sandw_l;
      MAP[2][i] = *sandg_r;
    }
  for(i = 0 ; i < MAPlength ; i++)
    {
      MAP[i][MAPheight-4] = *sandg_u;
      MAP[i][MAPheight-3] = *sandw_d;
    }
  

     /* set water */
  for( j=1 ; j < 3 ; j++ )
    {
      for( i=0 ; i < MAPlength ; i++ )
	{
	  MAP[i][MAPheight-j] = *water;
	}
    }
  for( i=0 ; i<MAPheight-2 ; i++)
    {
      MAP[0][i] = *water;
    }

 

  /* Draw three columns of trees */
  for ( j=5 ; j<9 ; j++ )
    {
      for(i=0 ; i<5 ; i++)
	{
	  MAP[j][i] = *tree;
	}
    }
  for ( j = 0 ; j < 13 ; j++)
    {
      MAP[3][j] = *tree;
      MAP[4][j] = *tree;
    }
  for ( i = 5 ; i < 17 ; i++)
    {
      MAP[i][12] = *tree;
    }

  for(i=0;i<6;i++)
    {
      MAP[20][i] = *tree;
      MAP[19][i] = *tree;
    }
 
  for ( i = 25 ; i < 30 ; i ++ )
    {
      MAP[i][17] = *tree;
    }
  for ( i = 17 ; i < 34 ; i ++ )
    {
      for (j = 30 ; j < 34 ; j ++ )
	{
	  MAP[j][i] = *tree;
	}
    }



  for( i = 1 ; i < 5 ; i++)
    {
      MAP[10][i] = *rockwall_l;
      MAP[18][i] = *rockwall_r;
    }
  


  // Drawing the cave fields 
  for(i=11;i<18;i++)
    {
      for(j=1;j<5;j++)
	{
	  MAP[i][j] = *rockwall_top;
	}
      MAP[i][5] = *rockwall;
    }
  
  for(i = 11 ; i < 18 ; i++)
    {
      MAP[i][0] = *rockwall_top;
    }
  
  MAP[14][5] = *rockwall_door;
  
 // Drawing the cave 

  MAP[10][5] = *rockwall_dl;
  MAP[10][0] = *rockwall_ul;
  MAP[18][0] = *rockwall_ur;
  MAP[18][5] = *rockwall_dr;

   /* set water beside the cave */
  for( i = 0 ; i < 8 ; i ++ )
    {
      MAP[9][i] = *water ;
    }

  for ( i = 10 ; i < 19 ; i ++ )
    {
      MAP[i][6] = *water ;
      MAP[i][7] = *water ;
    }
  
  for ( i = 7 ; i < 15 ; i ++)
    {
      MAP[17][i] = *water ;
      MAP[18][i] = *water ;
    }

  for ( i = 0 ; i < 18 ; i ++)
    {
      MAP[i][13] = *water ;
      MAP[i][14] = *water ;
    }
  
  for ( i = 17 ; i < 33 ; i ++ )
    {
      MAP[i][15] = *water ;
      MAP[i][16] = *water ;
    }
  
  for ( i = 0 ; i < 17 ; i ++ )
    {
      MAP[32][i] = *water ;
      MAP[33][i] = *water ;
    }
  
  // right permutation of rockwall to draw a second one 
  for ( i = 10 ; i < 19; i ++ )
    {
      for ( j = 0 ; j < 6 ; j ++ )
	{
	  MAP[i+11][j] = MAP[i][j]; // first permutation ( second rockwall)
	  MAP[i-2][j+16] = MAP[i][j];// second permutation ( third rockwall )
	  
	}
    }
  MAP[25][5] = *rockwall_door;

 



  // Drawing the bridge 
  MAP[14][6] = *bridge1;
  MAP[14][7] = *bridge1;
  MAP[15][6] = *bridge2;
  MAP[15][7] = *bridge2;
  
  MAP[17][10] = *bridge1;
  MAP[17][11] = *bridge1;
  MAP[18][10] = *bridge2;
  MAP[18][11] = *bridge2;

  MAP[24][15] = *bridge1;
  MAP[25][15] = *bridge2;
  MAP[24][16] = *bridge1;
  MAP[25][16] = *bridge2;

  MAP[24][17] = *trap;
  for ( i = 19 ; i < 30 ; i++)
    {
      if ( i != 24 && i != 25 )
	{
	  for ( j = 6 ; j < 10 ; j ++ )
	    {
	      MAP[i][j] = *tree ;
	    }
	  for ( j = 12 ; j < 15 ; j ++ )
	    {
	      MAP[i][j] = *tree ;
	    }
	}
    }

   // Permutation of the bloc ( rockwall with trees and box )
  for ( i = 19 ; i < 30 ; i ++ )
    {
      for (j = 0 ; j < 15 ; j ++ )
	{
	  MAP[i][j+18] = MAP[i][j] ;
	}
    }
  // drawing the mystery box 
  MAP[25][10] = *box; // à voir la position ou les mettre ! 

  
  /* dessiner une échelle 
   *MAP[24][10] = 19;
   * MAP[24][11] = 20;*/

  //test

  MAP[30][10] = *dirt;
  MAP[31][10] = *dirt;
  MAP[31][11] = *dirt;
  MAP[30][11] = *dirt;
}
  










