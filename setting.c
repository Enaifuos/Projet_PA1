#include "SDL.h" 
#include "global_variable.c"
#define MAPlength      64
#define MAPheight      44
#define SPRITE_SIZE    32



/*---Prototypes---*/

void set_position();


//array function
SDL_Surface ** CreateTable(int c , int l);
void FreeTableMAP(SDL_Surface **tableau, int c);


void set_map(int day);
void set_objectmap();







/*-----function------*/
void set_position()
{
  coordplayerx = 10*SPRITE_SIZE;   
  coordplayery = 8*SPRITE_SIZE;
  rcSprite.x = 9*SPRITE_SIZE;
  rcSprite.y = 7*SPRITE_SIZE;
}





SDL_Surface ** CreateTable(int c , int l)
{
  SDL_Surface ** t1 = (SDL_Surface **)malloc(sizeof(SDL_Surface*)*c);
  if ( t1 == NULL ) // test if the malloc run
    {
      printf("missing dynamic memory to run the game (error table)\n");
    }

  int i ;
  for (i = 0 ; i < c ; i++) {
      t1[i] = (SDL_Surface *)malloc(sizeof(SDL_Surface)*l);
  }

  return t1 ;
}






void FreeTableMAP(SDL_Surface **tableau, int c)
{
  int i;
  for( i = 0 ; i < c ; i++)
    {
      free(tableau[i]);
    }
  free(tableau);
}







/*------------------- SET THE MAP ---------------------*/


void set_map(int DAY)
{
  int i,j;
  if( DAY )
    {
      
    }
     /* set grass everywhere */  
  for( i=0 ; i < MAPlength ; i++)
    {
      for( j=0 ; j < MAPheight  ; j++)
	{
	  if ( day ){
	    MAP[i][j] = *grass;
	  }
	  else{
	    //  MAP[i][j] = *grass_night;       // it blocks the program 
	  }
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
	  if ( day ){
	    MAP[i][MAPheight-j] = *water;
	  }
	  else{
	    MAP[i][MAPheight-j] = *water_night ;
	  }
	}
    }
  for( i=0 ; i<MAPheight-2 ; i++)
    {
       if ( day ){
	 MAP[0][i] = *water;
       }
       else{
	 MAP[0][i] = *water_night ;
       }
    }

 

  /* Draw three columns of trees */
  for ( j=5 ; j<9 ; j++ )
    {
      for(i=0 ; i<5 ; i++)
	{
	  if ( day){
	    MAP[j][i] = *tree;
	  }
	  else{
	    MAP[j][i] = *tree_night;
	  }
	}
    }
  for ( j = 0 ; j < 13 ; j++)
    {
      if ( day){
	MAP[3][j] = *tree;
	MAP[4][j] = *tree;
      }
      else{
	MAP[3][j] = *tree_night;
	MAP[4][j] = *tree_night;
      }
    }
  for ( i = 5 ; i < 17 ; i++)
    {
      if ( day){
	MAP[i][12] = *tree;
      }
      else{
	MAP[i][12] = *tree_night;
      } 
    }

  for(i=0;i<6;i++)
    {
      if ( day){
	MAP[20][i] = *tree;
	MAP[19][i] = *tree;
      }
      else{
	MAP[20][i] = *tree_night;
	MAP[19][i] = *tree_night;
      }
    }
 
  for ( i = 25 ; i < 30 ; i ++ )
    {
      if ( day){
	MAP[i][17] = *tree;
      }
      else{
	MAP[i][17] = *tree_night;
      }
    }
  for ( i = 17 ; i < 34 ; i ++ )
    {
      for (j = 30 ; j < 34 ; j ++ )
	{
	  if ( day){
	    MAP[j][i] = *tree;
	  }
	  else{
	    MAP[j][i] = *tree_night; 
	  }
	}
    }



  for( i = 1 ; i < 5 ; i++)
    {
      if( day){
	MAP[10][i] = *rockwall_l;
	MAP[18][i] = *rockwall_r;
      }
      else{
	MAP[10][i] = *rockwall_l_night;
	MAP[18][i] = *rockwall_r_night; 


      }
    }
  


  // Drawing the cave fields 
  for(i=11;i<18;i++)
    {
      for(j=1;j<5;j++)
	{
	  if( day){
	    MAP[i][j] = *rockwall_top;
	  }
	  else{
	    MAP[i][j] = *rockwall_top_night;

	 
	  }
	}
      if( day){
	MAP[i][5] = *rockwall;
      }
      else{
	MAP[i][5] = *rockwall_night;


      }
    }
  
  for(i = 11 ; i < 18 ; i++)
    {
      if( day){
	MAP[i][0] = *rockwall_top;
      }
      else{
	MAP[i][0] = *rockwall_top_night;
      

      }
    }
  
  if( day){
    MAP[14][5] = *rockwall_door;
  }
  else{
    MAP[14][5] = *rockwall_door_night; 
  }
  


 // Drawing the cave 
  if( day){
    MAP[10][5] = *rockwall_dl;
    MAP[10][0] = *rockwall_ul;
    MAP[18][0] = *rockwall_ur;
    MAP[18][5] = *rockwall_dr;
  }
  else{
    MAP[10][5] = *rockwall_dl_night;
    MAP[10][0] = *rockwall_ul_night;
    MAP[18][0] = *rockwall_ur_night;
    MAP[18][5] = *rockwall_dr_night;
  }

   /* set water beside the cave */
  for( i = 0 ; i < 8 ; i ++ )
    {
      if ( day){
	MAP[9][i] = *water ;
      }
      else{
	MAP[9][i] = *water_night ;
      }
    }

  for ( i = 10 ; i < 19 ; i ++ )
    {
      if ( day){
	MAP[i][6] = *water ;
	MAP[i][7] = *water ;
      }
      else{
	MAP[i][6] = *water_night ;
	MAP[i][7] = *water_night ;
      }
    }
  
  for ( i = 7 ; i < 15 ; i ++)
    {
      if ( day){
	MAP[17][i] = *water ;
	MAP[18][i] = *water ;
      }
      else{
	MAP[17][i] = *water_night ;
	MAP[18][i] = *water_night ;
      }
    }

  for ( i = 0 ; i < 18 ; i ++)
    {
      if ( day){
	MAP[i][13] = *water ;
	MAP[i][14] = *water ;
      }
      else{
	MAP[i][13] = *water_night ;
	MAP[i][14] = *water_night ;
      }
    }
  
  for ( i = 17 ; i < 33 ; i ++ )
    {
      if ( day){
	MAP[i][15] = *water ;
	MAP[i][16] = *water ;
      }
      else{
	MAP[i][15] = *water_night ;
	MAP[i][16] = *water_night ;
      }
    }
  
  for ( i = 0 ; i < 17 ; i ++ )
    {
      if ( day){
	MAP[32][i] = *water ;
	MAP[33][i] = *water ;
      }
      else{
	MAP[32][i] = *water_night ;
	MAP[33][i] = *water_night ;
      }
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
  if(day){
    MAP[25][5] = *rockwall_door;
  }
  else{
    MAP[25][5] = *rockwall_door_night;
  }
 



  // Drawing the bridge 
  if( day){
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
  }
  else{
    MAP[14][6] = *bridge1_night;
    MAP[14][7] = *bridge1_night;
    MAP[15][6] = *bridge2_night;
    MAP[15][7] = *bridge2_night;
    
    MAP[17][10] = *bridge1_night;
    MAP[17][11] = *bridge1_night;
    MAP[18][10] = *bridge2_night;
    MAP[18][11] = *bridge2_night;

    MAP[24][15] = *bridge1_night;
    MAP[25][15] = *bridge2_night;
    MAP[24][16] = *bridge1_night;
    MAP[25][16] = *bridge2_night;
  }

  // MAP[24][17] = *trap;
  for ( i = 19 ; i < 30 ; i++)
    {
      if ( i != 24 && i != 25 )
	{
	  for ( j = 6 ; j < 10 ; j ++ )
	    {
	      if ( day){
		MAP[i][j] = *tree ;
	      }
	      else{
		MAP[i][j] = *tree_night;
	      }
	    }
	  for ( j = 12 ; j < 15 ; j ++ )
	    {
	      if ( day){
		MAP[i][j] = *tree ;
	      }
	      else{
		MAP[i][j] = *tree_night;
	      }
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

  
  MAP[3][22] = *dirtg_ul ;
  for (i = 4 ; i < 18 ; i ++)
    {
      MAP[i][22] = *dirtg_u ;
      MAP[i][39] = *dirtg_d ;
    }
  MAP[18][22] = *dirtg_ur ;

  for ( i = 23 ; i < 39 ; i ++ )
    {
      MAP[3][i] = *dirtg_l ;
      if ( i < 33 ){
	MAP[18][i] = *dirtg_r ;
      }
    }
  MAP[3][39] = *dirtg_dl ;
 

  // remplissage 
  for ( i = 4 ; i < 18 ; i ++ )
    {
      for ( j = 23 ; j < 39 ; j ++ )
	{
	  if(day){
	    MAP[i][j] = *dirt ;
	  }
	  else{
	    MAP[i][j] = *dirt_night ;
	  }
	}
    }

  for ( i = 34 ; i < 39 ; i ++ )
    {
      for (j = 18 ; j < 33 ; j ++ )
	{
	  if(day){
	    MAP[j][i] = *dirt ;	   
	  }
	  else{
	    MAP[j][i] = *dirt_night ;
	  }
	}
    }
  MAP[18][33] = *dirt ;
  for ( i = 19 ; i < 33 ; i ++ )
    {
      MAP[i][33] = *dirtg_u ;
    }
  MAP[33][33] = *dirtg_ur ;
  for (i = 34 ; i < 39 ; i ++ )
    {
      MAP[33][i] = *dirtg_r ;
    }
  
  MAP[33][39] = *dirtg_dr ;

  for ( i = 32 ; i > 17 ; i -- )
    {
      MAP[i][39] = *dirtg_d ;
    }
  // ======================
  // Drawing the escape zone 
  for( i=50 ; i < MAPlength ; i++)
    {
      for( j=0 ; j < MAPheight  ; j++)
	{
	  if ( day){
	    MAP[i][j] = *water ;
	  }
	  else{
	    MAP[i][j] = *water_night ;
	  }
	}
    }
  
  // ======================

  //test

  MAP[30][10] = *dirtg_ul;
  MAP[31][10] = *dirtg_ur;
  MAP[31][11] = *dirtg_dr;
  MAP[30][11] = *dirtg_dl;
}
  














void set_objectmap()
{
  int i, j;
  for( i=0 ; i < MAPlength ; i++)
    {
      for( j=0 ; j < MAPheight  ; j++)
	{
	  OBJECTMAP[i][j].pitch = 0;
	}
    }
  OBJECTMAP[25][10] = *box;
  OBJECTMAP[24][10] = *talismant;
  OBJECTMAP[25][11] = *apple;
}
