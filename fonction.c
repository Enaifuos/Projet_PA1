#include "SDL.h"
#include "setting.c" // NEW

#define SCREEN_WIDTH  608
#define SCREEN_HEIGHT 480
#define SPRITE_SIZE    32
#define MAPlength      64
#define MAPheight      44


extern int MAP[MAPlength][MAPheight];
extern SDL_Surface *screen, *temp, *sprite, *grass, *water, *sand, *tree, *ground_land;
extern SDL_Rect rcSprite, rcGrass, rcWater, rcSand, rcTree, rcGround_land ;
extern SDL_Event event;
extern Uint8 *keystate;
extern int colorkey, gameover;
extern int coordplayerx, coordplayery;



/*---Prototypes---*/

//movement
int check_move_ground(int x, int y);
void move_down();
void move_up();
void move_right();
void move_left();



//drawing
void draw_grassGM(int i, int j);
void draw_grassPM(int i, int j);

void draw_waterGM(int i, int j);
void draw_waterPM(int i, int j);

void draw_sandGM(int i, int j);
void draw_sandPM(int i, int j);

void draw_treeGM(int i, int j);
void draw_treePM(int i, int j);

void draw_groundlandGM(int i, int j);
void draw_groundlandPM(int i, int j);



//action in the game
void you_loose(); //NEW



//screen printing
void screen_printing_Gmove(); //NEW
void screen_printing_Pmove(); //NEW










   /*-----function------*/


   /*-----movement-----*/
int check_move_ground(int x, int y)
{
  int res = 1;
  if(MAP[x][y])
    {
      res = 0;
    }
  return res;
}


void move_down()
{
  if(check_move_ground(coordplayerx/SPRITE_SIZE , (coordplayery/SPRITE_SIZE)+1))
    {
      if(coordplayery <= (MAPheight-1) *  SPRITE_SIZE)
	{
	  int i;
	  if( coordplayery/SPRITE_SIZE > MAPheight - 9 || coordplayery/SPRITE_SIZE <= 6 )
	    {
	      for( i=0 ; i<SPRITE_SIZE ; i++ )
		{
		  rcSprite.y += 1;
		  coordplayery += 1;
		  SDL_Delay(2);
		  screen_printing_Pmove();
		}
	    }
	  else
	    {
	      for( i=0 ; i < SPRITE_SIZE ; i++)
		{
		  coordplayery += 1;
		  SDL_Delay(2);
		  screen_printing_Gmove();
		}
	      //  SDL_Delay(150);
	    }
	}
    }
}



void move_up()
{
  if( check_move_ground(coordplayerx/SPRITE_SIZE , (coordplayery/SPRITE_SIZE)-1))
    {
      if(coordplayery >= SPRITE_SIZE)
	{
	  int i;
	  if( coordplayery/SPRITE_SIZE > MAPheight - 8 || coordplayery/SPRITE_SIZE <= 7 )
	    {
	      for( i=0 ; i<SPRITE_SIZE ; i++ )
		{
		  rcSprite.y -= 1;
		  coordplayery -= 1;
		  SDL_Delay(2);
		  screen_printing_Pmove();
		}
	    }
	  else
	    {
	      for( i=0 ; i<SPRITE_SIZE ; i++)
		{
		  coordplayery -= 1;
		  SDL_Delay(2);
		  screen_printing_Gmove();
		}
	      //	      SDL_Delay(150);
	    }
	}
    }
}

void move_right()
{
  if(check_move_ground((coordplayerx/SPRITE_SIZE)+1 , coordplayery/SPRITE_SIZE))
    {
      if( coordplayerx < (MAPlength-1) * SPRITE_SIZE)
	{
	  int i;
	  if( coordplayerx/SPRITE_SIZE >= MAPlength - 10 || coordplayerx/SPRITE_SIZE <= 8 )
	    {
	      SDL_Delay(20);
	      for( i=0 ; i < SPRITE_SIZE ; i++ )
		{
		  rcSprite.x += 1;
		  coordplayerx += 1;
		  SDL_Delay(2);
		  screen_printing_Pmove();
		}
	    }
	   else
	    {
	      for( i=0 ; i < SPRITE_SIZE ; i++ )
		{
		  coordplayerx += 1;
		  SDL_Delay(2);
		  screen_printing_Gmove(); 
		}
	      //     SDL_Delay(150);
	    }	  
	}
    }
}





void move_left()
{
  if( check_move_ground((coordplayerx/SPRITE_SIZE)-1 , coordplayery/SPRITE_SIZE) )
    {
      if( coordplayerx >= SPRITE_SIZE )
	{
	  int i;
	  if( coordplayerx/SPRITE_SIZE >= MAPlength - 9  || coordplayerx/SPRITE_SIZE <= 9 ) 
	    {
	      SDL_Delay(20);
	      for( i=0 ; i < SPRITE_SIZE ; i++ )
		{
		  rcSprite.x -= 1;
		  coordplayerx -= 1;
		  SDL_Delay(2);
		  screen_printing_Pmove();
		}
	    }
	  else
	    {
	      for( i=0 ; i < SPRITE_SIZE ; i++ )
		{
		  coordplayerx -= 1;
		  SDL_Delay(2);
		  screen_printing_Gmove(); 
		}
	      //	      SDL_Delay(150);
	    }
	}
    }
}











/*--------action in the game---------*/


void you_loose()
{
  printf("**********\n YOU LOSE\n**********\n");
  set_map();
  set_position();
}

















/*--------- draw ----------*/

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


void draw_groundlandPM(int i, int j)
{
  rcGround_land.x = i * SPRITE_SIZE;
  rcGround_land.y = j * SPRITE_SIZE;
  SDL_BlitSurface(ground_land, NULL, screen, &rcGround_land);
}

void draw_groundlandGM(int i, int j)
{
  rcGround_land.x = i * SPRITE_SIZE - (coordplayerx % SPRITE_SIZE);
  rcGround_land.y = j * SPRITE_SIZE - (coordplayery % SPRITE_SIZE);
  SDL_BlitSurface(ground_land, NULL, screen, &rcGround_land);
}



















/*--------- screen printing ----------*/


void screen_printing_Gmove() 
{
  int i, j, x, y;
  if( (coordplayerx % SPRITE_SIZE) == 0 &&  (coordplayery % SPRITE_SIZE) == 0 )
    {
      /* draw the grass, water, sand, and tree */
      for( i=0 ; i < SCREEN_WIDTH/SPRITE_SIZE ; i++ )
	{
	  for( j=0 ; j < SCREEN_HEIGHT/SPRITE_SIZE ; j++ )
	    {
	      x = (coordplayerx - rcSprite.x)/SPRITE_SIZE + i;
	      y = (coordplayery - rcSprite.y)/SPRITE_SIZE + j;
	      if( MAP[x][y] == 0 )
		{ 
		  draw_grassGM(i , j);
		}
	      if( MAP[x][y] == 1)
		{
		  draw_waterGM(i , j);
		}
	      if( MAP[x][y] == 2)
		{
		  draw_sandGM(i ,  j);
		}
	      if( MAP[x][y] == 3)
		{
		  draw_treeGM(i , j);
		}
	      if( MAP[x][y] == 4)
		{
		  draw_groundlandGM(i , j);
		}
	    }
	}
      
      /* draw the sprite */
      SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
      
      /* update the screen */
      SDL_UpdateRect(screen,0,0,0,0);
    }
  else
    {
      /* draw the grass or the water */
      for( i = 0 ; i < (SCREEN_WIDTH/SPRITE_SIZE)+1 ; i++ )
	{
	  for( j = 0 ; j < (SCREEN_HEIGHT/SPRITE_SIZE)+1 ; j++ )
	    {
	      x = (coordplayerx - rcSprite.x) / SPRITE_SIZE +i ;
	      y = (coordplayery - rcSprite.y) / SPRITE_SIZE +j;
	      if( MAP[x][y] == 0 )
		{ 
		  draw_grassGM(i , j);
		}
	      if( MAP[x][y] == 1)
		{
		  draw_waterGM(i , j);
		}
	      if( MAP[x][y] == 2 )
		{ 
		  draw_sandGM(i , j);
		}
	      if( MAP[x][y] == 3)
		{
		  draw_treeGM(i , j);
		}
	      if( MAP[x][y] == 4)
		{
		  draw_groundlandGM(i , j);
		}	      
	    }
	}
      
      /* draw the sprite */
      SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
      
      /* update the screen */
      SDL_UpdateRect(screen,0,0,0,0);
    }
}




void screen_printing_Pmove()
{
  int i, j, x, y;
  
  /* draw the grass or the water */
  for( i=0 ; i < SCREEN_WIDTH/SPRITE_SIZE ; i++ )
    {
      for( j=0 ; j < SCREEN_HEIGHT/SPRITE_SIZE ; j++ )
	{
	  x = (coordplayerx - rcSprite.x)/SPRITE_SIZE + i;
	  y = (coordplayery - rcSprite.y)/SPRITE_SIZE + j;
	  if( MAP[x][y] == 0 )
	    { 
	      draw_grassPM(i , j);
	    }
	  if( MAP[x][y] == 1)
	    {
	      draw_waterPM(i , j);
	    }
	  if( MAP[x][y] == 2)
	    {
	      draw_sandPM(i , j);
	    }
	  if( MAP[x][y] == 3)
	    {
	      draw_treePM(i , j);
	    }
	  if( MAP[x][y] == 4 )
	    { 
	      draw_groundlandPM(i , j);
	    }
	}
    }
  
  /* draw the sprite */
  SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
  
  /* update the screen */
  SDL_UpdateRect(screen,0,0,0,0);
}
