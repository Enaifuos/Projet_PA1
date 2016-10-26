#include "SDL.h"
#define SPRITE_SIZE    32

/* extern variable */
extern SDL_Surface *screen, *temp, *sprite, *grass, *water, *tree, *dirt, *sand, *pause;
extern SDL_Surface *dirtg_d, *dirtg_dl, *dirtg_dr, *dirtg_l, *dirtg_r, *dirtg_u, *dirtg_ul, *dirtg_ur;
extern SDL_Surface *sandg_dl, *sandg_dr, *sandg_l, *sandg_r, *sandg_top, *sandg_ucl, *sandg_ucr, *sandg_ul, *sandg_ur;
extern SDL_Surface *sandw_dl, *sandw_dr, *sandw_l, *sandw_r, *sandw_top, *sandw_ucl, *sandw_ucr, *sandw_ul, *sandw_ur;
extern SDL_Surface *rockwall, *rockwall_dl, *rockwall_dr, *rockwall_l, *rockwall_r, *rockwall_top, *rockwall_ucl, *rockwall_ucr, *rockwall_ul, *rockwall_ur;

extern SDL_Rect rcSprite, rcSrcSprite, rcGrass, rcWater, rcSand, rcTree, rcDirt, rcRock, rcPause;
extern int coordplayerx, coordplayery;




 /*============ prototypes ==============*/

void draw_grassGM(int i, int j);
void draw_grassPM(int i, int j);

void draw_waterGM(int i, int j);
void draw_waterPM(int i, int j);

void draw_sandGM(int i, int j);
void draw_sandPM(int i, int j);

void draw_treeGM(int i, int j);
void draw_treePM(int i, int j);

void draw_dirtGM(int i, int j);
void draw_dirtPM(int i, int j);

void draw_rockwallGM(int i, int j);
void draw_rockwallPM(int i, int j);





SDL_Surface kind_of_dirt(int i, int j);

//SDL_Surface kinf_of_rockwall(int i, int j);

//SDL_Surface kind_of_sand(int i, int j);





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



void draw_sandPM(int i, int j)
{  
  rcSand.x = i * SPRITE_SIZE;
  rcSand.y = j * SPRITE_SIZE;
  SDL_BlitSurface(sand, NULL, screen, &rcSand);
}

void draw_sandGM(int i, int j)
{
  rcSand.x = i * SPRITE_SIZE - (coordplayerx % SPRITE_SIZE); 
  rcSand.y = j * SPRITE_SIZE - (coordplayery % SPRITE_SIZE);
  SDL_BlitSurface(sand, NULL, screen, &rcSand);
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


void draw_dirtPM(int i, int j)
{
  rcDirt.x = i * SPRITE_SIZE;
  rcDirt.y = j * SPRITE_SIZE;
  *temp = kind_of_dirt(i,j);
  SDL_BlitSurface(temp, NULL, screen, &rcDirt);
}

void draw_dirtGM(int i, int j)
{
  rcDirt.x = i * SPRITE_SIZE - (coordplayerx % SPRITE_SIZE);
  rcDirt.y = j * SPRITE_SIZE - (coordplayery % SPRITE_SIZE);
  *temp = kind_of_dirt(i,j);
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
  rcRock.x == i * SPRITE_SIZE;
  rcRock.y == j * SPRITE_SIZE;
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








SDL_Surface kind_of_dirt(int i, int j)
{
  int type;
  type = MAP[i][j];
  if( MAP[i+1][j] == type && MAP[i-1][j] == type && MAP[i][j-1] == type && MAP[i][j+1] == type )
    {
      return *dirt;
    }
  if( MAP[i+1][j] == type)
    {
      if( MAP[i-1][j] == type )
	{
	  if( !MAP[i][j+1] )
	    {
	      return *dirtg_u;
	    }
	  else
	    {
	      return *dirtg_d;
	    }
	}
      if( MAP[i][j+1] == type )
	{
	  return *dirtg_ul;
	}
      if( MAP[i][j-1] == type )
	{
	  return *dirtg_dl;
	}
    }
  if( MAP[i-1][j] == type )
    {
      if( MAP[i][j+1] == type )
	{
	  return *dirtg_ur;
	}
      if( MAP[i][j-1] )
	{
	  return *dirtg_ul;
	}
    }
  else
    {
      if( !MAP[i+1][j] )
	{
	  return *dirtg_r;
	}
      else
	{
	  return *dirtg_l;
	}
    }
}






