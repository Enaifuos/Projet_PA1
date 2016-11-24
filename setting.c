#include "SDL.h" 
#include "global_variable.c"


#define MAPlength      64
#define MAPheight      44
#define SPRITE_SIZE    32



/*---Prototypes---*/


void set_position();
void set_countletter();


//array function
void set_map(SDL_Surface * map, int day);
void set_objectmap(Objmap * map);
int check_ground_MAP(int x, int y);
void set_letter_pos(Objmap *objectmap );





/*-----function------*/
void set_position()
{
  coordplayerx = 10*SPRITE_SIZE;   
  coordplayery = 8*SPRITE_SIZE;
  rcSprite.x = 9*SPRITE_SIZE;
  rcSprite.y = 7*SPRITE_SIZE;
}


void set_countletter()
{
  int i;
  for( i = 0 ; i < 8 ; i++ )
    {
      SURVIVAL[i] = 0;
    }
}











/*------------------- SET THE MAP ---------------------*/


void set_map(SDL_Surface * map, int DAY) //
{
  int i,j;
  
  if(DAY)
    {
      /* set grass everywhere */  
      for( i=0 ; i < MAPlength ; i++)
	{
	  for( j=0 ; j < MAPheight  ; j++)
	    {
	      map[i+j*MAPlength] = *grass;       // it blocks the program 
	    }
	}
  

      /* Draw two columns of sand */             
     
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
  

      /* set water */
      for( j=1 ; j < 3 ; j++ )
	{
	  for( i=0 ; i < MAPlength ; i++ )
	    {	  
	      map[i+(MAPheight-j)*MAPlength] = *water;	    
	    }
	}
      for( i=0 ; i<MAPheight-2 ; i++)
	{     
	  map[i*MAPlength] = *water;
	}

 

      /* Draw three columns of trees */
      for ( j=5 ; j<9 ; j++ )
	{
	  for(i=0 ; i<5 ; i++)
	    {	  
	      map[j+i*MAPlength] = *tree;	    
	    }
	}
      for ( j = 0 ; j < 13 ; j++)
	{            
	  map[3+j*MAPlength] = *tree;
	  map[4+j*MAPlength] = *tree;
	}
      for ( i = 5 ; i < 17 ; i++)
	{      
	  map[i+12*MAPlength] = *tree;

	}
  
      for(i=0;i<6;i++)
	{
	  map[20+i*MAPlength] = *tree;
	  map[19+i*MAPlength] = *tree;
	}
  
      for ( i = 25 ; i < 30 ; i ++ )
	{
	  map[i+17*MAPlength] = *tree;
	}
      for ( i = 17 ; i < 34 ; i ++ )
	{
	  for (j = 30 ; j < 34 ; j ++ )
	    {
	      map[j+i*MAPlength] = *tree; 
	    }
	}



      for( i = 1 ; i < 5 ; i++)
	{
	  map[10+i*MAPlength] = *rockwall_l;
	  map[18+i*MAPlength] = *rockwall_r;	  
	}
  
  

      // Drawing the cave fields 
      for(i=11;i<18;i++)
	{
	  for(j=1;j<5;j++)
	    {
	      map[i+j*MAPlength] = *rockwall_top;
	    }
      
	  map[i+5*MAPlength] = *rockwall;
	}
  
      for(i = 11 ; i < 18 ; i++)
	{
	  map[i] = *rockwall_top;
	}
  
  
      map[14+5*MAPlength] = *rockwall_door; 
  
  

      // Drawing the cave 
  
      map[10+5*MAPlength] = *rockwall_dl;
      map[10] = *rockwall_ul;
      map[18] = *rockwall_ur;
      map[18+5*MAPlength] = *rockwall_dr;
  
  
      /* set water beside the cave */
      for( i = 0 ; i < 8 ; i ++ )
	{
	  map[9+i*MAPlength] = *water;
	}

      for ( i = 10 ; i < 19 ; i ++ )
	{
	  map[i+6*MAPlength] = *water;
	  map[i+7*MAPlength] = *water;
	}
  
      for ( i = 7 ; i < 15 ; i ++)
	{
	  map[17+i*MAPlength] = *water;
	  map[18+i*MAPlength] = *water;
	}
  
      for ( i = 0 ; i < 18 ; i ++)
	{
	  map[i+13*MAPlength] = *water;
	  map[i+14*MAPlength] = *water;
	}
  
      for ( i = 17 ; i < 33 ; i ++ )
	{
	  map[i+15*MAPlength] = *water;
	  map[i+16*MAPlength] = *water;
	}
  
      for ( i = 0 ; i < 17 ; i ++ )
	{
	  map[32+i*MAPlength] = *water;
	  map[33+i*MAPlength] = *water;
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
      map[25+5*MAPlength] = *rockwall_door;
  



      // Drawing the bridge 
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
   

      // map[24][17] = *trap;
      for ( i = 19 ; i < 30 ; i++)
	{
	  if ( i != 24 && i != 25 )
	    {
	      for ( j = 6 ; j < 10 ; j ++ )
		{
		  map[i+j*MAPlength] = *tree;
		}
	      for ( j = 12 ; j < 15 ; j ++ )
		{
		  map[i+j*MAPlength] = *tree;
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

  
      map[3+22*MAPlength] = *dirtg_ul;
      for (i = 4 ; i < 18 ; i ++)
	{
	  map[i+22*MAPlength] = *dirtg_u;
	  map[i+39*MAPlength] = *dirtg_d;
	}
      map[18+22*MAPlength] = *dirtg_ur;
      
      for ( i = 23 ; i < 39 ; i ++ )
	{
	  map[3+i*MAPlength] = *dirtg_l;
	  if ( i < 33 )
	    {
	      map[18+i*MAPlength] = *dirtg_r;
	    }
	}
      map[3+39*MAPlength] = *dirtg_dl;
    
  
      // remplissage 
      for ( i = 4 ; i < 18 ; i ++ )
	{
	  for ( j = 23 ; j < 39 ; j ++ )
	    {
	      map[i+j*MAPlength] = *dirt;
	    }
	}
  
      for ( i = 34 ; i < 39 ; i ++ )
	{
	  for (j = 18 ; j < 33 ; j ++ )
	    {
	      map[j+i*MAPlength] = *dirt;
	    }
	}
 
      map[18+33*MAPlength] = *dirt;
      for ( i = 19 ; i < 33 ; i ++ )
	{
	  map[i+33*MAPlength] = *dirtg_u;
	}
      map[33+33*MAPlength] = *dirtg_ur;
      for (i = 34 ; i < 39 ; i ++ )
	{
	  map[33+i*MAPlength] = *dirtg_r;
	}
      
      map[33+39*MAPlength] = *dirtg_dr;
      
      for ( i = 32 ; i > 17 ; i -- )
	{
	  map[i+39*MAPlength] = *dirtg_d;
	}
  
      // ======================
      // Drawing the escape zone 
      for( j=0 ; j < MAPheight  ; j++)
	{
	  for( i=50 ; i < MAPlength ; i++)
	    {
	      map[i+j*MAPlength] = *water;
	    }
	}
      if( j < MAPheight-2 )
	{
	  map[49+j*MAPlength] = *sandw_r;
	  if( j < MAPheight-4)
	    map[48+j*MAPlength] = *sandg_l;
	}

  
      map[49+(MAPheight-3)*MAPlength] = *sandw_dr;

  
      // ======================

      //test
  
      map[30+10*MAPlength] = *dirtg_ul;
      map[31+10*MAPlength] = *dirtg_ur;
      map[31+11*MAPlength] = *dirtg_dr;
      map[30+11*MAPlength] = *dirtg_dl;
    }



  /*----------- NIGHT -----------*/
  else
    {
      /* set grass everywhere */  
      for( i=0 ; i < MAPlength ; i++)
	{
	  for( j=0 ; j < MAPheight  ; j++)
	    {
	      map[i+j*MAPlength] = *grass_night;       // it blocks the program 
	    }
	}
  

      /* Draw two columns of sand */             
     
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
  

      /* set water */
      for( j=1 ; j < 3 ; j++ )
	{
	  for( i=0 ; i < MAPlength ; i++ )
	    {	  
	      map[i+(MAPheight-j)*MAPlength] = *water_night;	    
	    }
	}
      for( i=0 ; i<MAPheight-2 ; i++)
	{     
	  map[i*MAPlength] = *water_night;
	}

 

      /* Draw three columns of trees */
      for ( j=5 ; j<9 ; j++ )
	{
	  for(i=0 ; i<5 ; i++)
	    {	  
	      map[j+i*MAPlength] = *tree_night;	    
	    }
	}
      for ( j = 0 ; j < 13 ; j++)
	{            
	  map[3+j*MAPlength] = *tree_night;
	  map[4+j*MAPlength] = *tree_night;
	}
      for ( i = 5 ; i < 17 ; i++)
	{      
	  map[i+12*MAPlength] = *tree_night;

	}
  
      for(i=0;i<6;i++)
	{
	  map[20+i*MAPlength] = *tree_night;
	  map[19+i*MAPlength] = *tree_night;
	}
  
      for ( i = 25 ; i < 30 ; i ++ )
	{
	  map[i+17*MAPlength] = *tree_night;
	}
      for ( i = 17 ; i < 34 ; i ++ )
	{
	  for (j = 30 ; j < 34 ; j ++ )
	    {
	      map[j+i*MAPlength] = *tree_night; 
	    }
	}



      for( i = 1 ; i < 5 ; i++)
	{
	  map[10+i*MAPlength] = *rockwall_l_night;
	  map[18+i*MAPlength] = *rockwall_r_night;	  
	}
  
  

      // Drawing the cave fields 
      for(i=11;i<18;i++)
	{
	  for(j=1;j<5;j++)
	    {
	      map[i+j*MAPlength] = *rockwall_top_night;
	    }
      
	  map[i+5*MAPlength] = *rockwall_night;
	}
  
      for(i = 11 ; i < 18 ; i++)
	{
	  map[i] = *rockwall_top_night;
	}
  
  
      map[14+5*MAPlength] = *rockwall_door_night; 
  
  

      // Drawing the cave 
  
      map[10+5*MAPlength] = *rockwall_dl_night;
      map[10] = *rockwall_ul_night;
      map[18] = *rockwall_ur_night;
      map[18+5*MAPlength] = *rockwall_dr_night;
  
  
      /* set water beside the cave */
      for( i = 0 ; i < 8 ; i ++ )
	{
	  map[9+i*MAPlength] = *water_night;
	}

      for ( i = 10 ; i < 19 ; i ++ )
	{
	  map[i+6*MAPlength] = *water_night;
	  map[i+7*MAPlength] = *water_night;
	}
  
      for ( i = 7 ; i < 15 ; i ++)
	{
	  map[17+i*MAPlength] = *water_night;
	  map[18+i*MAPlength] = *water_night;
	}
  
      for ( i = 0 ; i < 18 ; i ++)
	{
	  map[i+13*MAPlength] = *water_night;
	  map[i+14*MAPlength] = *water_night;
	}
  
      for ( i = 17 ; i < 33 ; i ++ )
	{
	  map[i+15*MAPlength] = *water_night;
	  map[i+16*MAPlength] = *water_night;
	}
  
      for ( i = 0 ; i < 17 ; i ++ )
	{
	  map[32+i*MAPlength] = *water_night;
	  map[33+i*MAPlength] = *water_night;
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
      map[25+5*MAPlength] = *rockwall_door_night;
  



      // Drawing the bridge 
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
   

      // map[24][17] = *trap_night;
      for ( i = 19 ; i < 30 ; i++)
	{
	  if ( i != 24 && i != 25 )
	    {
	      for ( j = 6 ; j < 10 ; j ++ )
		{
		  map[i+j*MAPlength] = *tree_night;
		}
	      for ( j = 12 ; j < 15 ; j ++ )
		{
		  map[i+j*MAPlength] = *tree_night;
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

  
      map[3+22*MAPlength] = *dirtg_ul_night;
      for (i = 4 ; i < 18 ; i ++)
	{
	  map[i+22*MAPlength] = *dirtg_u_night;
	  map[i+39*MAPlength] = *dirtg_d_night;
	}
      map[18+22*MAPlength] = *dirtg_ur_night;
      
      for ( i = 23 ; i < 39 ; i ++ )
	{
	  map[3+i*MAPlength] = *dirtg_l_night;
	  if ( i < 33 )
	    {
	      map[18+i*MAPlength] = *dirtg_r_night;
	    }
	}
      map[3+39*MAPlength] = *dirtg_dl_night;
    
  
      // remplissage 
      for ( i = 4 ; i < 18 ; i ++ )
	{
	  for ( j = 23 ; j < 39 ; j ++ )
	    {
	      map[i+j*MAPlength] = *dirt_night;
	    }
	}
  
      for ( i = 34 ; i < 39 ; i ++ )
	{
	  for (j = 18 ; j < 33 ; j ++ )
	    {
	      map[j+i*MAPlength] = *dirt_night;
	    }
	}
 
      map[18+33*MAPlength] = *dirt_night;
      for ( i = 19 ; i < 33 ; i ++ )
	{
	  map[i+33*MAPlength] = *dirtg_u_night;
	}
      map[33+33*MAPlength] = *dirtg_ur_night;
      for (i = 34 ; i < 39 ; i ++ )
	{
	  map[33+i*MAPlength] = *dirtg_r_night;
	}
      
      map[33+39*MAPlength] = *dirtg_dr_night;
      
      for ( i = 32 ; i > 17 ; i -- )
	{
	  map[i+39*MAPlength] = *dirtg_d_night;
	}
  
      // ======================
      // Drawing the escape zone 
      for( j=0 ; j < MAPheight  ; j++)
	{
	  for( i=50 ; i < MAPlength ; i++)
	    {
	      map[i+j*MAPlength] = *water_night;
	    }
	}
      if( j < MAPheight-2 )
	{
	  map[49+j*MAPlength] = *sandw_r_night;
	  if( j < MAPheight-4)
	    map[48+j*MAPlength] = *sandg_l_night;
	}

  
      map[49+(MAPheight-3)*MAPlength] = *sandw_dr_night;

  
      // ======================

      //test
  
      map[30+10*MAPlength] = *dirtg_ul_night;
      map[31+10*MAPlength] = *dirtg_ur_night;
      map[31+11*MAPlength] = *dirtg_dr_night;
      map[30+11*MAPlength] = *dirtg_dl_night;
    }

}
  














void set_objectmap(Objmap *map)
{
  int i, j;
  /* initialization of the objects  map */
  for( i = 0 ; i < MAPheight ; i ++)
    {
      for( j = 0 ; j < MAPlength ; j ++)
	{
	  map[j+i*MAPlength].objvalue = 0;
	}
    }
  
  map[25+10*MAPlength].objsprite = *box;
  map[25+10*MAPlength].objvalue = 9;
  map[25+11*MAPlength].objsprite = *apple;
  map[25+11*MAPlength].objvalue = 10; 
  map[26+10*MAPlength].objsprite = *box;
  map[26+10*MAPlength].objvalue = 9;

  /* setting letters */
  set_letter_pos(map);
}




void set_letter_pos (Objmap *objectmap )
{
  int i = 0 ;
  int j = 0 ;
  int c = 0 ;
  for ( c = 1 ; c < 9 ; c ++  ){
    while ( !check_ground_MAP(i , j)  ) 
      {
	i = rand()%MAPlength;
	j = rand()%MAPheight;
      }
    objectmap[i+j*MAPlength].objvalue = c ;
    objectmap[i+j*MAPlength].objsprite = *letter ;
    i = rand()%MAPlength ;
    j = rand()%MAPheight ;
  }
}




int check_ground_MAP(int x, int y)
{
  int allow = 0;
  SDL_Surface pos = MAP[x+y*MAPlength];
  //DAY
  if( day )
    {
      /* check if the player can go*/
      if( pos.pixels == (*grass).pixels || pos.pixels == (*dirt).pixels || pos.pixels == (*sand).pixels || pos.pixels == (*bridge1).pixels || pos.pixels == (*bridge2).pixels)
	{
	  allow = 1;
	}
       
      //special sandg
      else if( pos.pixels == (*sandg_u).pixels || pos.pixels == (*sandg_d).pixels || pos.pixels == (*sandg_dl).pixels || pos.pixels == (*sandg_dr).pixels || pos.pixels == (*sandg_ul).pixels || pos.pixels == (*sandg_ur).pixels || pos.pixels == (*sandg_l).pixels || pos.pixels == (*sandg_r).pixels)
	{
	  allow = 1;
	}
      //special sandw
      else if( pos.pixels == (*sandw_u).pixels || pos.pixels == (*sandw_d).pixels || pos.pixels == (*sandw_dl).pixels || pos.pixels == (*sandw_dr).pixels || pos.pixels == (*sandw_ul).pixels || pos.pixels == (*sandw_ur).pixels || pos.pixels == (*sandw_l).pixels || pos.pixels == (*sandw_r).pixels )
	{
	  allow = 1;
	}
      //special dirt
      else if( pos.pixels == (*dirtg_u).pixels || pos.pixels == (*dirtg_d).pixels || pos.pixels == (*dirtg_ul).pixels || pos.pixels == (*dirtg_ur).pixels || pos.pixels == (*dirtg_dl).pixels || pos.pixels == (*dirtg_dr).pixels || pos.pixels == (*dirtg_l).pixels || pos.pixels == (*dirtg_r).pixels )
	{
	  allow = 1;
	}
    }


//------------NIGHT-----------
  else
    {
      if( pos.pixels == (*grass_night).pixels || pos.pixels == (*dirt_night).pixels || pos.pixels == (*sand_night).pixels || pos.pixels == (*bridge1_night).pixels || pos.pixels == (*bridge2_night).pixels)
	{
	  allow = 1;
	}
      else if( pos.pixels == (*sandg_u_night).pixels || pos.pixels == (*sandg_d_night).pixels || pos.pixels == (*sandg_dl_night).pixels || pos.pixels == (*sandg_dr_night).pixels || pos.pixels == (*sandg_ul_night).pixels || pos.pixels == (*sandg_ur_night).pixels || pos.pixels == (*sandg_l_night).pixels || pos.pixels == (*sandg_r_night).pixels)
	{
	  allow = 1;
	}
      //special sandw
      else if( pos.pixels == (*sandw_u_night).pixels || pos.pixels == (*sandw_d_night).pixels || pos.pixels == (*sandw_dl_night).pixels || pos.pixels == (*sandw_dr_night).pixels || pos.pixels == (*sandw_ul_night).pixels || pos.pixels == (*sandw_ur_night).pixels || pos.pixels == (*sandw_l_night).pixels || pos.pixels == (*sandw_r_night).pixels )
	{
	  allow = 1;
	}
      //special dirt
      else if( pos.pixels == (*dirtg_u_night).pixels || pos.pixels == (*dirtg_d_night).pixels || pos.pixels == (*dirtg_ul_night).pixels || pos.pixels == (*dirtg_ur_night).pixels || pos.pixels == (*dirtg_dl_night).pixels || pos.pixels == (*dirtg_dr_night).pixels || pos.pixels == (*dirtg_l_night).pixels || pos.pixels == (*dirtg_r_night).pixels )
	{
	  allow = 1;
	}
    }

  return allow;
}
