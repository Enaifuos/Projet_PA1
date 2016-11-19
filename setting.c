#include "SDL.h" 
#include "global_variable.c"

#define MAPlength      64
#define MAPheight      44
#define SPRITE_SIZE    32



/*---Prototypes---*/

void set_position();


//array function
SDL_Surface * CreateTable(int c , int l);
Objmap ** CreateObjtable(int c , int l);
void FreeTableMAP(SDL_Surface *tableau);
void FreeTableOBJ(Objmap **tableau, int c);


void set_map(SDL_Surface * map, int day);
void set_objectmap(Objmap * map);







/*-----function------*/
void set_position()
{
  coordplayerx = 10*SPRITE_SIZE;   
  coordplayery = 8*SPRITE_SIZE;
  rcSprite.x = 9*SPRITE_SIZE;
  rcSprite.y = 7*SPRITE_SIZE;
}





SDL_Surface * CreateTable(int c , int l)
{
  SDL_Surface * t1;
  t1 = (SDL_Surface *)malloc(sizeof(SDL_Surface)*c*l);
  return t1 ;
}



Objmap ** CreateObjtable(int c , int l)
{
  Objmap ** t1 = (Objmap **)malloc(sizeof(Objmap*)*c);
  if ( t1 == NULL ) // test if the malloc run
    {
      printf("missing dynamic memory to run the game (error table)\n");
    }

  else
    {      
      int i ;
      for (i = 0 ; i < c ; i++) 
	{
	  t1[i] = (Objmap *)malloc(sizeof(Objmap)*l);
	}
    }
  return t1 ;
}








/*------------------- SET THE MAP ---------------------*/


void set_map(SDL_Surface * map, int DAY) //
{
  int i,j;


     /* set grass everywhere */  
  for( i=0 ; i < MAPlength ; i++)
    {
      for( j=0 ; j < MAPheight  ; j++)
	{
	  if ( day )
	    {
	      map[i+j*MAPlength] = *grass;
	    }
	  else
	    {
	      map[i+j*MAPlength] = *grass_night;       // it blocks the program 
	    }
	}
    }
  

  /* Draw two columns of sand */             
  if( DAY )
    {
      for ( i=0 ; i < MAPheight-2 ; i++)
	{
	  map[1+i*MAPlength] = *sandw_l;
	  map[2+i*MAPlength] = *sandg_r;
	}
      for(i = 0 ; i < MAPlength ; i++)
	{
	  map[i+(MAPheight-4)*MAPlength] = *sandg_u;
	  map[i+(MAPheight-3)*MAPlength] = *sandw_d;
	}
      map[1+(MAPheight-4)*MAPlength] = *sandw_l;
      map[2+(MAPheight-4)*MAPlength] = *sand;
      map[1+(MAPheight-3)*MAPlength] = *sandw_dl;
    }
  else
    {
      for ( i=0 ; i < MAPheight-2 ; i++)
	{
	  map[1+i*MAPlength] = *sandw_l_night;
	  map[2+i*MAPlength] = *sandg_r_night;
	}
      for(i = 0 ; i < MAPlength ; i++)
	{
	  map[i+(MAPheight-4)*MAPlength] = *sandg_u_night;
	  map[i+(MAPheight-3)*MAPlength] = *sandw_d_night;
	}
      map[1+(MAPheight-4)*MAPlength] = *sandw_l_night;
      map[2+(MAPheight-4)*MAPlength] = *sand_night;
      map[1+(MAPheight-3)*MAPlength] = *sandw_dl_night;
    }
  

  /* set water */
  for( j=1 ; j < 3 ; j++ )
    {
      for( i=0 ; i < MAPlength ; i++ )
	{
	  if ( DAY )
	    {
	      map[i+(MAPheight-j)*MAPlength] = *water;
	    }
	  else
	    {
	      map[i+(MAPheight-j)*MAPlength] = *water_night ;
	    }
	}
    }
  for( i=0 ; i<MAPheight-2 ; i++)
    {
      if ( DAY )
	{
	  map[i*MAPlength] = *water;
	}
      else
	{
	  map[i*MAPlength] = *water_night ;
	}
    }

 

  /* Draw three columns of trees */
  for ( j=5 ; j<9 ; j++ )
    {
      for(i=0 ; i<5 ; i++)
	{
	  if ( DAY )
	    {
	      map[j+i*MAPlength] = *tree;
	    }
	  else
	    {
	      map[j+i*MAPlength] = *tree_night;
	    }
	}
    }
  for ( j = 0 ; j < 13 ; j++)
    {
      if ( DAY )
	{
	  map[3+j*MAPlength] = *tree;
	  map[4+j*MAPlength] = *tree;
	}
      else
	{
	  map[3+j*MAPlength] = *tree_night;
	  map[4+j*MAPlength] = *tree_night;
	}
    }
  for ( i = 5 ; i < 17 ; i++)
    {
      if ( DAY )
	{
	  map[i+12*MAPlength] = *tree;
	}
      else
	{
	  map[i+12*MAPlength] = *tree_night;
	} 
    }
  
  for(i=0;i<6;i++)
    {
      if ( DAY )
	{
	  map[20+i*MAPlength] = *tree;
	  map[19+i*MAPlength] = *tree;
	}
      else
	{
	  map[20+i*MAPlength] = *tree_night;
	  map[19+i*MAPlength] = *tree_night;
	}
    }
  
  for ( i = 25 ; i < 30 ; i ++ )
    {
      if ( DAY )
	{
	  map[i+17*MAPlength] = *tree;
	}
      else
	{
	  map[i+17*MAPlength] = *tree_night;
	}
    }
  for ( i = 17 ; i < 34 ; i ++ )
    {
      for (j = 30 ; j < 34 ; j ++ )
	{
	  if ( DAY )
	    {
	      map[j+i*MAPlength] = *tree;
	    }
	  else
	    {
	      map[j+i*MAPlength] = *tree_night; 
	    }
	}
    }



  for( i = 1 ; i < 5 ; i++)
    {
      if( DAY )
	{
	  map[10+i*MAPlength] = *rockwall_l;
	  map[18+i*MAPlength] = *rockwall_r;
	}
      else
	{
	  map[10+i*MAPlength] = *rockwall_l_night;
	  map[18+i*MAPlength] = *rockwall_r_night;	  
	}
    }
  
  

  // Drawing the cave fields 
  for(i=11;i<18;i++)
    {
      for(j=1;j<5;j++)
	{
	  if( DAY )
	    {
	      map[i+j*MAPlength] = *rockwall_top;
	    }
	  else
	    {
	      map[i+j*MAPlength] = *rockwall_top_night;
	    }
	}
      if( DAY )
	{
	  map[i+5*MAPlength] = *rockwall;
	}
      else
	{
	  map[i+5*MAPlength] = *rockwall_night;
	}
    }
  
  for(i = 11 ; i < 18 ; i++)
    {
      if( DAY )
	{
	  map[i] = *rockwall_top;
	}
      else
	{
	  map[i] = *rockwall_top_night;
	}
    }
  
  if( DAY )
    {
      map[14+5*MAPlength] = *rockwall_door;
    }
  else
    {
      map[14+5*MAPlength] = *rockwall_door_night; 
    }
  


  // Drawing the cave 
  if( DAY )
    {
      map[10+5*MAPlength] = *rockwall_dl;
      map[10] = *rockwall_ul;
      map[18] = *rockwall_ur;
      map[18+5*MAPlength] = *rockwall_dr;
    }
  else
    {
      map[10+5*MAPlength] = *rockwall_dl_night;
      map[10] = *rockwall_ul_night;
      map[18] = *rockwall_ur_night;
      map[18+5*MAPlength] = *rockwall_dr_night;
    }
  
  /* set water beside the cave */
  for( i = 0 ; i < 8 ; i ++ )
    {
      if ( DAY )
	{
	  map[9+i*MAPlength] = *water ;
	}
      else
	{
	  map[9+i*MAPlength] = *water_night ;
	}
    }

  for ( i = 10 ; i < 19 ; i ++ )
    {
      if ( DAY )
	{
	  map[i+6*MAPlength] = *water ;
	  map[i+7*MAPlength] = *water ;
	}
      else
	{
	  map[i+6*MAPlength] = *water_night ;
	  map[i+7*MAPlength] = *water_night ;
	}
    }
  
  for ( i = 7 ; i < 15 ; i ++)
    {
      if ( DAY )
	{
	  map[17+i*MAPlength] = *water ;
	  map[18+i*MAPlength] = *water ;
	}
      else
	{
	  map[17+i*MAPlength] = *water_night ;
	  map[18+i*MAPlength] = *water_night ;
	}
    }
  
  for ( i = 0 ; i < 18 ; i ++)
    {
      if ( DAY )
	{
	  map[i+13*MAPlength] = *water ;
	  map[i+14*MAPlength] = *water ;
	}
      else
	{
	  map[i+13*MAPlength] = *water_night ;
	  map[i+14*MAPlength] = *water_night ;
	}
    }
  
  for ( i = 17 ; i < 33 ; i ++ )
    {
      if ( DAY )
	{
	  map[i+15*MAPlength] = *water ;
	  map[i+16*MAPlength] = *water ;
	}
      else
	{
	  map[i+15*MAPlength] = *water_night ;
	  map[i+16*MAPlength] = *water_night ;
	}
    }
  
  for ( i = 0 ; i < 17 ; i ++ )
    {
      if ( DAY )
	{
	  map[32+i*MAPlength] = *water ;
	  map[33+i*MAPlength] = *water ;
	}
      else
	{
	  map[32+i*MAPlength] = *water_night ;
	  map[33+i*MAPlength] = *water_night ;
	}
    }
  
  // right permutation of rockwall to draw a second one 
  for ( i = 10 ; i < 19; i ++ )
    {
      for ( j = 0 ; j < 6 ; j ++ )
	{
	  map[i+11+j*MAPlength] = map[i+j*MAPlength]; // first copy ( second rockwall)
	  map[i-2+(j+16)*MAPlength] = map[i+j*MAPlength];// second copy ( third rockwall )
	}
    }
  if( DAY )
    {
      map[25+5*MAPlength] = *rockwall_door;
    }
  else
    {
      map[25+5*MAPlength] = *rockwall_door_night;
    }
 



  // Drawing the bridge 
  if( DAY )
    {
      map[14+6*MAPlength] = *bridge1;
      map[14+7*MAPlength] = *bridge1;
      map[15+6*MAPlength] = *bridge2;
      map[15+7*MAPlength] = *bridge2;
      
      map[17+10*MAPlength] = *bridge1;
      map[17+11*MAPlength] = *bridge1;
      map[18+10*MAPlength] = *bridge2;
      map[18+11*MAPlength] = *bridge2;
      
      map[24+15*MAPlength] = *bridge1;
      map[25+15*MAPlength] = *bridge2;
      map[24+16*MAPlength] = *bridge1;
      map[25+16*MAPlength] = *bridge2;
    }
  else
    {
      map[14+6*MAPlength] = *bridge1_night;
      map[14+7*MAPlength] = *bridge1_night;
      map[15+6*MAPlength] = *bridge2_night;
      map[15+7*MAPlength] = *bridge2_night;
    
      map[17+10*MAPlength] = *bridge1_night;
      map[17+11*MAPlength] = *bridge1_night;
      map[18+10*MAPlength] = *bridge2_night;
      map[18+11*MAPlength] = *bridge2_night;

      map[24+15*MAPlength] = *bridge1_night;
      map[25+15*MAPlength] = *bridge2_night;
      map[24+16*MAPlength] = *bridge1_night;
      map[25+16*MAPlength] = *bridge2_night;
    }

  // map[24][17] = *trap;
  for ( i = 19 ; i < 30 ; i++)
    {
      if ( i != 24 && i != 25 )
	{
	  for ( j = 6 ; j < 10 ; j ++ )
	    {
	      if ( DAY )
		{
		  map[i+j*MAPlength] = *tree ;
		}
	      else
		{
		  map[i+j*MAPlength] = *tree_night;
		}
	    }
	  for ( j = 12 ; j < 15 ; j ++ )
	    {
	      if ( DAY )
		{
		  map[i+j*MAPlength] = *tree ;
		}
	      else
		{
		  map[i+j*MAPlength] = *tree_night;
		}
	    }
	}
    }
  
  // Copy of the bloc ( rockwall with trees and box )
  for ( i = 19 ; i < 30 ; i ++ )
    {
      for (j = 0 ; j < 15 ; j ++ )
	{
	  map[i+(j+18)*MAPlength] = map[i+j*MAPlength] ;
	}
    }

  if( DAY )
    {
      map[3+22*MAPlength] = *dirtg_ul ;
      for (i = 4 ; i < 18 ; i ++)
	{
	  map[i+22*MAPlength] = *dirtg_u ;
	  map[i+39*MAPlength] = *dirtg_d ;
	}
      map[18+22*MAPlength] = *dirtg_ur ;
      
      for ( i = 23 ; i < 39 ; i ++ )
	{
	  map[3+i*MAPlength] = *dirtg_l ;
	  if ( i < 33 )
	    {
	      map[18+i*MAPlength] = *dirtg_r ;
	    }
	}
      map[3+39*MAPlength] = *dirtg_dl ;
    }
  else
    {
      map[3+22*MAPlength] = *dirtg_ul_night ;
      for (i = 4 ; i < 18 ; i ++)
	{
	  map[i+22*MAPlength] = *dirtg_u_night ;
	  map[i+39*MAPlength] = *dirtg_d_night ;
	}
      map[18+22*MAPlength] = *dirtg_ur_night ;
      
      for ( i = 23 ; i < 39 ; i ++ )
	{
	  map[3+i*MAPlength] = *dirtg_l_night ;
	  if ( i < 33 )
	    {
	      map[18+i*MAPlength] = *dirtg_r_night ;
	    }
	}
      map[3+39*MAPlength] = *dirtg_dl_night ;
    }
  
  // remplissage 
  for ( i = 4 ; i < 18 ; i ++ )
    {
      for ( j = 23 ; j < 39 ; j ++ )
	{
	  if( DAY )
	    {
	      map[i+j*MAPlength] = *dirt ;
	    }
	  else
	    {
	      map[i+j*MAPlength] = *dirt_night ;
	    }
	}
    }
  
  for ( i = 34 ; i < 39 ; i ++ )
    {
      for (j = 18 ; j < 33 ; j ++ )
	{
	  if( DAY )
	    {
	      map[j+i*MAPlength] = *dirt ;	   
	    }
	  else
	    {
	      map[j+i*MAPlength] = *dirt_night ;
	    }
	}
    }
  if( DAY )
    {
      map[18+33*MAPlength] = *dirt ;
      for ( i = 19 ; i < 33 ; i ++ )
	{
	  map[i+33*MAPlength] = *dirtg_u ;
	}
      map[33+33*MAPlength] = *dirtg_ur ;
      for (i = 34 ; i < 39 ; i ++ )
	{
	  map[33+i*MAPlength] = *dirtg_r ;
	}
      
      map[33+39*MAPlength] = *dirtg_dr ;
      
      for ( i = 32 ; i > 17 ; i -- )
	{
	  map[i+39*MAPlength] = *dirtg_d ;
	}
    }
  else
    {
      map[18+33*MAPlength] = *dirt_night ;
      for ( i = 19 ; i < 33 ; i ++ )
	{
	  map[i+33*MAPlength] = *dirtg_u_night ;
	}
      map[33+33*MAPlength] = *dirtg_ur_night ;
      for (i = 34 ; i < 39 ; i ++ )
	{
	  map[33+i*MAPlength] = *dirtg_r_night ;
	}
      
      map[33+39*MAPlength] = *dirtg_dr_night ;
      
      for ( i = 32 ; i > 17 ; i -- )
	{
	  map[i+39*MAPlength] = *dirtg_d_night ;
	}
    }
  // ======================
  // Drawing the escape zone 
  for( j=0 ; j < MAPheight  ; j++)
    {
      for( i=50 ; i < MAPlength ; i++){
	if ( DAY )
	  {
	    map[i+j*MAPlength] = *water ;
	  }
	else
	  {
	    map[i+j*MAPlength] = *water_night ;
	  }
      }
      if( j < MAPheight-2 )
	{
	  if( DAY )
	    {
	      map[49+j*MAPlength] = *sandw_r ;
	      if( j < MAPheight-4 )
		map[48+j*MAPlength] = *sandg_l ;
	    }
	  else
	    {
	      map[49+j*MAPlength] = *sandw_r_night ;
	      if(j<MAPheight-4)
		map[48+j*MAPlength] = *sandg_l_night ;
	    }
	}
    }
  if( DAY )
    {
      map[49+(MAPheight-3)*MAPlength] = *sandw_dr ;
    }
  else
    {
      map[49+(MAPheight-3)*MAPlength] = *sandw_dr_night ;
    }

  
  // ======================

  //test
  if( DAY )
    {
      map[30+10*MAPlength] = *dirtg_ul;
      map[31+10*MAPlength] = *dirtg_ur;
      map[31+11*MAPlength] = *dirtg_dr;
      map[30+11*MAPlength] = *dirtg_dl;
    }
  else
    {
      map[30+10*MAPlength] = *dirtg_ul_night;
      map[31+10*MAPlength] = *dirtg_ur_night;
      map[31+11*MAPlength] = *dirtg_dr_night;
      map[30+11*MAPlength] = *dirtg_dl_night;
    }
}
  














void set_objectmap(Objmap *map)
{
  int i, j;
  for( i = 0 ; i < MAPheight ; i ++)
    {
      for( j = 0 ; j < MAPlength ; j ++)
	{
	  map[j+i*MAPlength].objvalue = 0;
	}
    }
  map[25+10*MAPlength].objsprite = *box;
  map[25+10*MAPlength].objvalue = 1;
  map[25+11*MAPlength].objsprite = *apple;
  map[25+10*MAPlength].objvalue = 2; 
  map[24+10*MAPlength].objsprite = *talismant;
  map[25+10*MAPlength].objvalue = 3; 
}

/*
void set_rockwall_map(){
  int i , j ;
   for( i=0 ; i < 44 ; i++)
    {
      for( j=0 ; j <64 ; j++){
	MAP[j][i] = *rockwall_inside ;
      }
    }
}
*/
