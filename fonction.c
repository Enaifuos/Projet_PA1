#include "SDL.h"


#define SCREEN_WIDTH  608
#define SCREEN_HEIGHT 480
#define SPRITE_SIZE    32
#define MAPlength      64
#define MAPheight      44


extern int MAP[MAPlength][MAPheight];
extern SDL_Surface *screen, *temp, *sprite, *grass, *water;
extern SDL_Rect rcSprite, rcGrass, rcWater;
extern SDL_Event event;
extern Uint8 *keystate;
extern int colorkey, gameover;
extern int coordplayerx, coordplayery;



/*---Prototypes---*/

//setting
void set_map();

//movement
int check_move_ground(int x, int y);
void move_down();
void move_up();
void move_right();
void move_left();

//screen printing
void screen_printing_Gmove();
void screen_printing_Pmove();










/*-----function------*/

void set_map()
{
  int i,j;
  for( i=0 ; i < MAPlength ; i++)
    {
      for( j=0 ; j < MAPheight  ; j++)
	{
	  MAP[i][j] = 0;
	}
    }
  MAP[0][0] = 1; 
  MAP[0][1] = 1;
  MAP[0][2] = 1;
  MAP[0][3] = 1;
  MAP[1][8] = 1;
  MAP[3][2] = 1;
  
}











//-----movement
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
	  if( coordplayery/SPRITE_SIZE > MAPheight - 7 || coordplayery/SPRITE_SIZE <= 6 )
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
	      SDL_Delay(150);
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
	  if( coordplayery/SPRITE_SIZE > MAPheight - 8 || coordplayery/SPRITE_SIZE <= 8 )
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
	      SDL_Delay(150);
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
	      SDL_Delay(150);
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
	      SDL_Delay(150);
	    }
	}
    }
}





void screen_printing_Gmove() 
{
  int i, j, x, y;
  if( (coordplayerx % SPRITE_SIZE) == 0 &&  (coordplayery % SPRITE_SIZE) == 0 )
    {
      /* draw the grass or the water */
      for( i=0 ; i < SCREEN_WIDTH/SPRITE_SIZE ; i++ )
	{
	  for( j=0 ; j < SCREEN_HEIGHT/SPRITE_SIZE ; j++ )
	    {
	      x = (coordplayerx - rcSprite.x)/SPRITE_SIZE + i;
	      y = (coordplayery - rcSprite.y)/SPRITE_SIZE + j;
	      if( MAP[x][y] == 0 )
		{ 
		  rcGrass.x = i * SPRITE_SIZE;
		  rcGrass.y = j * SPRITE_SIZE;
		  SDL_BlitSurface(grass, NULL, screen, &rcGrass);
		}
	      else
		{
		  rcWater.x = i * SPRITE_SIZE;
		  rcWater.y = j * SPRITE_SIZE;
		  SDL_BlitSurface(water, NULL, screen, &rcWater);
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
		  rcGrass.x = i * SPRITE_SIZE - (coordplayerx % SPRITE_SIZE);
		  rcGrass.y = j * SPRITE_SIZE - (coordplayery % SPRITE_SIZE);
		  SDL_BlitSurface(grass, NULL, screen, &rcGrass);
		}
	      else
		{
		  rcWater.x = i * SPRITE_SIZE - (coordplayerx % SPRITE_SIZE);
		  rcWater.y = j * SPRITE_SIZE - (coordplayery % SPRITE_SIZE);
		  SDL_BlitSurface(water, NULL, screen, &rcWater);
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
	      rcGrass.x = i * SPRITE_SIZE;
	      rcGrass.y = j * SPRITE_SIZE;
	      SDL_BlitSurface(grass, NULL, screen, &rcGrass);
	    }
	  else
	    {
	      rcWater.x = i * SPRITE_SIZE;
	      rcWater.y = j * SPRITE_SIZE;
	      SDL_BlitSurface(water, NULL, screen, &rcWater);
	    }
	}
    }
  
  /* draw the sprite */
  SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
  
  /* update the screen */
  SDL_UpdateRect(screen,0,0,0,0);
}
