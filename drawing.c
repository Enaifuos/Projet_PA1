#include "SDL.h"
#include "global_variable.c"

#define SPRITE_SIZE    32



 /*============ prototypes ==============*/

void draw_grassGM(int i, int j);
void draw_grassPM(int i, int j);

void draw_waterGM(int i, int j);
void draw_waterPM(int i, int j);

void draw_sandGM(int i, int j, int x, int y);
void draw_sandPM(int i, int j, int x, int y);

void draw_treeGM(int i, int j);
void draw_treePM(int i, int j);

void draw_dirtGM(int i, int j, int x, int y);
void draw_dirtPM(int i, int j, int x, int y);

void draw_rockwallGM(int i, int j);
void draw_rockwallPM(int i, int j);





SDL_Surface* kind_of_dirt(int x, int y);

//SDL_Surface kinf_of_rockwall(int i, int j);

SDL_Surface* kind_of_sand(int x, int y);





/*----- special rockwall -----*/

void draw_rockwall_dlGM(int i, int j);
void draw_rockwall_dlPM(int i, int j);

void draw_rockwall_drGM(int i, int j);
void draw_rockwall_drPM(int i, int j);

void draw_rockwall_lGM(int i, int j);
void draw_rockwall_lPM(int i, int j);

void draw_rockwall_rGM(int i, int j);
void draw_rockwall_rPM(int i, int j);

void draw_rockwall_topGM(int i, int j);
void draw_rockwall_topPM(int i, int j);

void draw_rockwall_uclGM(int i, int j);
void draw_rockwall_uclPM(int i, int j);

void draw_rockwall_ucrGM(int i, int j);
void draw_rockwall_ucrPM(int i, int j);

void draw_rockwall_ulGM(int i, int j);
void draw_rockwall_ulPM(int i, int j);

void draw_rockwall_urGM(int i, int j);
void draw_rockwall_urPM(int i, int j);


















/*================== function ==================*/

void draw_grassPM(int i, int j)
{
  rcGrass.x = i * SPRITE_SIZE;
  rcGrass.y = j * SPRITE_SIZE;
  SDL_BlitSurface(grass, NULL, screen, &rcGrass);
}

void draw_grassGM(int i, int j)
{  
  rcGrass.x = i * SPRITE_SIZE - (coordplayerx % SPRITE_SIZE);
  rcGrass.y = j * SPRITE_SIZE - (coordplayery % SPRITE_SIZE);
  SDL_BlitSurface(grass, NULL, screen, &rcGrass);
}


//-----------------------------------


void draw_waterPM(int i, int j)
{
  rcWater.x = i * SPRITE_SIZE;
  rcWater.y = j * SPRITE_SIZE;
  SDL_BlitSurface(water, NULL, screen, &rcWater);
}

void draw_waterGM(int i, int j)
{
  rcWater.x = i * SPRITE_SIZE - (coordplayerx % SPRITE_SIZE);
  rcWater.y = j * SPRITE_SIZE - (coordplayery % SPRITE_SIZE);
  SDL_BlitSurface(water, NULL, screen, &rcWater);
}


//-----------------------------------



void draw_sandPM(int i, int j, int x, int y)
{  
  rcSand.x = i * SPRITE_SIZE;
  rcSand.y = j * SPRITE_SIZE;
  temp = kind_of_sand(x,y);
  SDL_BlitSurface(temp, NULL, screen, &rcSand);
}

void draw_sandGM(int i, int j, int x, int y)
{
  rcSand.x = i * SPRITE_SIZE - (coordplayerx % SPRITE_SIZE); 
  rcSand.y = j * SPRITE_SIZE - (coordplayery % SPRITE_SIZE);
  temp =  kind_of_sand(x,y);
  SDL_BlitSurface(temp, NULL, screen, &rcSand);
}


//-----------------------------------


void draw_treePM(int i, int j)
{
  rcTree.x = i * SPRITE_SIZE;
  rcTree.y = j * SPRITE_SIZE;
  SDL_BlitSurface(tree, NULL, screen, &rcTree);
}

void draw_treeGM(int i, int j)
{
  rcTree.x = i * SPRITE_SIZE - (coordplayerx % SPRITE_SIZE);
  rcTree.y = j * SPRITE_SIZE - (coordplayery % SPRITE_SIZE);
  SDL_BlitSurface(tree, NULL, screen, &rcTree);
}


//-----------------------------------


void draw_dirtPM(int i, int j, int x, int y)
{
  rcDirt.x = i * SPRITE_SIZE;
  rcDirt.y = j * SPRITE_SIZE;
  temp = kind_of_dirt(x,y);
  SDL_BlitSurface(temp,NULL, screen, &rcDirt);
}

void draw_dirtGM(int i, int j, int x, int y)
{
  rcDirt.x = i * SPRITE_SIZE - (coordplayerx % SPRITE_SIZE);
  rcDirt.y = j * SPRITE_SIZE - (coordplayery % SPRITE_SIZE);
  temp =  kind_of_dirt(x,y);
  SDL_BlitSurface(temp, NULL, screen, &rcDirt);
}


//-----------------------------------


void draw_rockwallPM(int i, int j)
{
  rcRock.x = i * SPRITE_SIZE;
  rcRock.y = j * SPRITE_SIZE;
  SDL_BlitSurface(rockwall, NULL, screen, &rcRock);
}


void draw_rockwallGM(int i, int j)
{
  rcRock.x = i * SPRITE_SIZE - (coordplayerx % SPRITE_SIZE);
  rcRock.y = j * SPRITE_SIZE - (coordplayery % SPRITE_SIZE);
  SDL_BlitSurface(rockwall, NULL, screen, &rcRock);
}





/*=========== special rockwall ============*/

void draw_rockwall_dlPM(int i, int j)
{
  rcRock.x = i * SPRITE_SIZE;
  rcRock.y = j * SPRITE_SIZE;
  SDL_BlitSurface(rockwall_dl, NULL, screen, &rcRock);
}


void draw_rockwall_dlGM(int i, int j)
{
  rcRock.x = i * SPRITE_SIZE - (coordplayerx % SPRITE_SIZE);
  rcRock.y = j * SPRITE_SIZE - (coordplayery % SPRITE_SIZE);
  SDL_BlitSurface(rockwall_dl, NULL, screen, &rcRock);
}


//-----------------------------------


void draw_rockwall_drPM(int i, int j)
{
  rcRock.x = i * SPRITE_SIZE;
  rcRock.y = j * SPRITE_SIZE;
  SDL_BlitSurface(rockwall_dr, NULL, screen, &rcRock);
}

void draw_rockwall_drGM(int i, int j)
{
  rcRock.x = i * SPRITE_SIZE - (coordplayerx % SPRITE_SIZE);
  rcRock.y = j * SPRITE_SIZE - (coordplayery % SPRITE_SIZE);
  SDL_BlitSurface(rockwall_dr, NULL, screen, &rcRock);
}


//-----------------------------------


void draw_rockwall_lPM(int i, int j)
{
  rcRock.x = i * SPRITE_SIZE;
  rcRock.y = j * SPRITE_SIZE;
  SDL_BlitSurface(rockwall_l, NULL, screen, &rcRock);
}

void draw_rockwall_lGM(int i, int j)
{
  rcRock.x = i * SPRITE_SIZE - (coordplayerx % SPRITE_SIZE);
  rcRock.y = j * SPRITE_SIZE - (coordplayery % SPRITE_SIZE);
  SDL_BlitSurface(rockwall_l, NULL, screen, &rcRock);
}


//-----------------------------------


void draw_rockwall_rPM(int i, int j)
{
  rcRock.x = i * SPRITE_SIZE;
  rcRock.y = j * SPRITE_SIZE;
  SDL_BlitSurface(rockwall_r, NULL, screen, &rcRock);
}

void draw_rockwall_rGM(int i, int j)
{
  rcRock.x = i * SPRITE_SIZE - (coordplayerx % SPRITE_SIZE);
  rcRock.y = j * SPRITE_SIZE - (coordplayery % SPRITE_SIZE);
  SDL_BlitSurface(rockwall_r, NULL, screen, &rcRock);
}


//-----------------------------------


void draw_rockwall_topPM(int i, int j)
{
  rcRock.x = i * SPRITE_SIZE;
  rcRock.y = j * SPRITE_SIZE;
  SDL_BlitSurface(rockwall_top, NULL, screen, &rcRock);
}

void draw_rockwall_topGM(int i, int j)
{
  rcRock.x = i * SPRITE_SIZE - (coordplayerx % SPRITE_SIZE);
  rcRock.y = j * SPRITE_SIZE - (coordplayery % SPRITE_SIZE);
  SDL_BlitSurface(rockwall_top, NULL, screen, &rcRock);
}


//-----------------------------------


void draw_rockwall_uclPM(int i, int j)
{
  rcRock.x = i * SPRITE_SIZE;
  rcRock.y = j * SPRITE_SIZE;
  SDL_BlitSurface(rockwall_ucl, NULL, screen, &rcRock);
}

void draw_rockwall_uclGM(int i, int j)
{
  rcRock.x = i * SPRITE_SIZE - (coordplayerx % SPRITE_SIZE);
  rcRock.y = j * SPRITE_SIZE - (coordplayery % SPRITE_SIZE);
  SDL_BlitSurface(rockwall_ucl, NULL, screen, &rcRock);
}


//-----------------------------------


void draw_rockwall_ucrPM(int i, int j)
{
   rcRock.x = i * SPRITE_SIZE;
   rcRock.y = j * SPRITE_SIZE;
   SDL_BlitSurface(rockwall_ucr, NULL, screen, &rcRock);
}

void draw_rockwall_ucrGM(int i, int j)
{
  rcRock.x = i * SPRITE_SIZE - (coordplayerx % SPRITE_SIZE);
  rcRock.y = j * SPRITE_SIZE - (coordplayery % SPRITE_SIZE);
  SDL_BlitSurface(rockwall_ucr, NULL, screen, &rcRock);
}


//-----------------------------------


void draw_rockwall_ulPM(int i, int j)
{
  rcRock.x = i * SPRITE_SIZE;
  rcRock.y = j * SPRITE_SIZE;
  SDL_BlitSurface(rockwall_ul, NULL, screen, &rcRock);
}

void draw_rockwall_ulGM(int i, int j)
{
  rcRock.x = i * SPRITE_SIZE - (coordplayerx % SPRITE_SIZE);
  rcRock.y = j * SPRITE_SIZE - (coordplayery % SPRITE_SIZE);
  SDL_BlitSurface(rockwall_ul, NULL, screen, &rcRock);
}


//-----------------------------------


void draw_rockwall_urPM(int i, int j)
{
  rcRock.x = i * SPRITE_SIZE;
  rcRock.y = j * SPRITE_SIZE;
  SDL_BlitSurface(rockwall_ur, NULL, screen, &rcRock);
}

void draw_rockwall_urGM(int i, int j)
{
  rcRock.x = i * SPRITE_SIZE - (coordplayerx % SPRITE_SIZE);
  rcRock.y = j * SPRITE_SIZE - (coordplayery % SPRITE_SIZE);
  SDL_BlitSurface(rockwall_ur, NULL, screen, &rcRock);
}








SDL_Surface* kind_of_dirt(int x, int y)
{
 
  //checking if it's the top and then left or right
  if( !y )
    {
      if( !x ) //left top corner
	{
	  if( !MAP[x+1][y] && !MAP[x][y+1])
	    {
	      return dirtg_dr;
	    }
	  if( !MAP[x][y+1] )
	    {
	      return dirtg_d;
	    }
	  if( !MAP[x+1][y] )
	    {
	      return dirtg_r;
	    }
	}
      if( x == MAPlength-1 ) //right top corner
	{
	  if( !MAP[x-1][y] && !MAP[x][y+1] )
	    {
	      return dirtg_dl;
	    } 
	  if( !MAP[x][y+1] )
	    {
	      return dirtg_d;
	    }
	  if( !MAP[x-1][y] )
	    {
	      return dirtg_l;
	    }
	}
      else //top
	{
	  if( !MAP[x][y+1] )
	    {
	      if( !MAP[x+1][y] )
		{
		  return dirtg_dr;
		}
	      if( !MAP[x-1][y] )
		{
		  return dirtg_dl;
		}
	      return dirtg_d;
	    }
	  if( !MAP[x+1][y] )
	    {
	      return dirtg_r;
	    }
	  if( !MAP[x-1][y] )
	    {
	      return dirtg_l;
	    }
	}
    }
  
  //checking if it's the bottom and then left or right
  else if( y == MAPheight-1 )
    {
      if( !x ) //left down corner 
	{
	  if(!MAP[x+1][y] && !MAP[x][y-1])
	    {
	      return dirtg_ur;
	    }
	  if(!MAP[x][y-1])
	    {
	      return dirtg_u;
	    }
	  if(!MAP[x+1][y])
	    {
	      return dirtg_r;
	    }
	}
      if( x == MAPlength-1 ) //right down corner
	{
	  if( !MAP[x-1][y] && !MAP[x][y-1] )
	    {
	      return dirtg_ul;
	    }
	  if( !MAP[x][y-1] )
	    {
	      return dirtg_u;
	    }
	  if( !MAP[x-1][y] )
	    {
	      return dirtg_l;
	    }
	}
      else //bottom
	{
	  if( !MAP[x][y-1] )
	    {
	      if( !MAP[x+1][y] )
		{
		  return dirtg_ur;
		}
	      if( !MAP[x-1][y] )
		{
		  return dirtg_ul;
		}
	      return dirtg_u;
	    }
	  if( !MAP[x+1][y] )
	    {
	      return dirtg_r;
	    }
	  if( !MAP[x-1][y] )
	    {
	      return dirtg_l;
	    }
	}
    }
  
  //check left
  else if( !x )
    {
      if( !MAP[x+1][y] )
	{
	  if( !MAP[x][y+1] ) 
	    {
	      return dirtg_ur;
	    }
	  if( !MAP[x][y-1] )
	    {
	      return dirtg_dr;
	    }
	  return dirtg_r;
	}
      if( !MAP[x][y+1] )
	{
	  return dirtg_u;
	}
      if( !MAP[x][y-1] )
	{
	  return dirtg_d;
	}
    }
  
  //check right
  else if( x == MAPlength-1 ) 
    {
      if( !MAP[x-1][y] )
	{
	  if( !MAP[x][y+1] ) 
	    {
	      return dirtg_ul;
	    }
	  if( !MAP[x][y-1] )
	    {
	      return dirtg_dl;
	    }
	  return dirtg_r;
	}
      if( !MAP[x][y+1] )
	{
	  return dirtg_u;
	}
      if( !MAP[x][y-1] )
	{
	  return dirtg_d;
	}
    }
  
  //center
  else
    {
      if( !MAP[x][y+1] )
	{
	  if( !MAP[x+1][y] )
	    {
	      return dirtg_dr;
	    }
	  if( !MAP[x-1][y] )
	    {
	      return dirtg_dl;
	    }
	  return dirtg_d;
	}
      if( !MAP[x][y-1] )
	{
	  if( !MAP[x+1][y] )
	    {
	      return dirtg_ur;
	    }
	  if( !MAP[x-1][y] )
	    {
	      return dirtg_ul;
	    }
	  return dirtg_u;
	}
      if( !MAP[x+1][y] )
	{
	  return dirtg_r;
	}
      if( !MAP[x-1][y] )
	{
	  return dirtg_l;
	}
    }
  return dirt;
}






SDL_Surface* kind_of_sand(int x, int y)
{
  //checking if it's the top and then left or right
  if( !y )
    {
      if( !x ) //left top corner
	{
	  if( 1 == MAP[x+1][y] && 1 == MAP[x][y+1])
	    {
	      return sandw_dr;
	    }
	  if( 1 == MAP[x][y+1] )
	    {
	      return sandw_d;
	    }
	  if( 1 == MAP[x+1][y] )
	    {
	      return sandw_r;
	    }
	}
      if( x == MAPlength-1 ) //right top corner
	{
	  if( 1 == MAP[x-1][y] && 1 == MAP[x][y+1] )
	    {
	      return sandw_dl;
	    } 
	  if( 1 == MAP[x][y+1] )
	    {
	      return sandw_d;
	    }
	  if( 1 == MAP[x-1][y] )
	    {
	      return sandw_l;
	    }
	}
      else //top
	{
	  if( 1 == MAP[x][y+1] )
	    {
	      if( 1 == MAP[x+1][y] )
		{
		  return sandw_dr;
		}
	      if( 1 == MAP[x-1][y] )
		{
		  return sandw_dl;
		}
	      return sandw_d;
	    }
	  if( 1 == MAP[x+1][y] )
	    {
	      return sandw_r;
	    }
	  if( 1 == MAP[x-1][y] )
	    {
	      return sandw_l;
	    }
	}
    }
  
  //checking if it's the bottom and then left or right
  else if( y == MAPheight-1 )
    {
      if( !x ) //left down corner 
	{
	  if(1 == MAP[x+1][y] && 1 == MAP[x][y-1])
	    {
	      return sandw_ur;
	    }
	  if(1 == MAP[x][y-1])
	    {
	      return sandw_u;
	    }
	  if(1 == MAP[x+1][y])
	    {
	      return sandw_r;
	    }
	}
      if( x == MAPlength-1 ) //right down corner
	{
	  if( 1 == MAP[x-1][y] && 1 == MAP[x][y-1] )
	    {
	      return sandw_ul;
	    }
	  if( 1 == MAP[x][y-1] )
	    {
	      return sandw_u;
	    }
	  if( 1 == MAP[x-1][y] )
	    {
	      return sandw_l;
	    }
	}
      else //bottom
	{
	  if( 1 == MAP[x][y-1] )
	    {
	      if( 1 == MAP[x+1][y] )
		{
		  return sandw_ur;
		}
	      if( 1 == MAP[x-1][y] )
		{
		  return sandw_ul;
		}
	      return sandw_u;
	    }
	  if( 1 == MAP[x+1][y] )
	    {
	      return sandw_r;
	    }
	  if( 1 == MAP[x-1][y] )
	    {
	      return sandw_l;
	    }
	}
    }
  
  //check left
  else if( !x )
    {
      if( 1 == MAP[x+1][y] )
	{
	  if( 1 == MAP[x][y+1] ) 
	    {
	      return sandw_ur;
	    }
	  if( 1 == MAP[x][y-1] )
	    {
	      return sandw_dr;
	    }
	  return sandw_r;
	}
      if( 1 == MAP[x][y+1] )
	{
	  return sandw_u;
	}
      if( 1 == MAP[x][y-1] )
	{
	  return sandw_d;
	}
    }
  
  //check right
  else if( x == MAPlength-1 ) 
    {
      if( 1 == MAP[x-1][y] )
	{
	  if( 1 == MAP[x][y+1] ) 
	    {
	      return sandw_ul;
	    }
	  if( 1 == MAP[x][y-1] )
	    {
	      return sandw_dl;
	    }
	  return sandw_r;
	}
      if( 1 == MAP[x][y+1] )
	{
	  return sandw_u;
	}
      if( 1 == MAP[x][y-1] )
	{
	  return sandw_d;
	}
    }
  
  //center
  else
    {
      if( 1 == MAP[x][y+1] )
	{
	  if( 1 == MAP[x+1][y] )
	    {
	      return sandw_dr;
	    }
	  if( 1 == MAP[x-1][y] )
	    {
	      return sandw_dl;
	    }
	  return sandw_d;
	}
      if( 1 == MAP[x][y-1] )
	{
	  if( 1 == MAP[x+1][y] )
	    {
	      return sandw_ur;
	    }
	  if( 1 == MAP[x-1][y] )
	    {
	      return sandw_ul;
	    }
	  return sandw_u;
	}
      if( 1 == MAP[x+1][y] )
	{
	  return sandw_r;
	}
      if( 1 == MAP[x-1][y] )
	{
	  return sandw_l;
	}
    }
  return sand;
}
