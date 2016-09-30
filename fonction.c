#include "SDL.h"


#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
#define SPRITE_SIZE    32


extern int MAP[SCREEN_WIDTH/SPRITE_SIZE+1][SCREEN_HEIGHT/SPRITE_SIZE+1];
extern SDL_Surface *screen, *temp, *sprite, *grass, *water;
extern SDL_Rect rcSprite, rcGrass, rcWater;
extern SDL_Event event;
extern Uint8 *keystate;
extern int colorkey, gameover;

/*---Prototypes---*/

int check_move_ground(int x, int y);
void move_down();
void move_up();
void move_right();
void move_left();











/*-----function------*/

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
  if(check_move_ground(rcSprite.x/SPRITE_SIZE , (rcSprite.y/SPRITE_SIZE)+1))
    {
      int i,j;
      if(rcSprite.y < SCREEN_HEIGHT - SPRITE_SIZE -1)
	{
	  for( i=0 ; i<SPRITE_SIZE ; i++)
	    {
	      SDL_Delay(2);
	      rcSprite.y += 1;
	      if(MAP[rcSprite.x/SPRITE_SIZE][rcSprite.y/SPRITE_SIZE])
		{
		  rcWater.x = rcSprite.x - (rcSprite.x % SPRITE_SIZE);
		  rcWater.y = rcSprite.y - (rcSprite.y % SPRITE_SIZE);
		  SDL_BlitSurface(water, NULL, screen, &rcWater);
		}
	      else
		{
		  rcGrass.x = rcSprite.x - (rcSprite.x % SPRITE_SIZE);
		  rcGrass.y = rcSprite.y - (rcSprite.y % SPRITE_SIZE);
		  SDL_BlitSurface(grass, NULL, screen, &rcGrass);
		}
	      if(MAP[(rcSprite.x/SPRITE_SIZE)][rcSprite.y/SPRITE_SIZE+1])
		{
		  rcWater.x =  rcSprite.x - (rcSprite.x % SPRITE_SIZE);
		  rcWater.y = rcSprite.y - (rcSprite.y % SPRITE_SIZE) + SPRITE_SIZE;
		  SDL_BlitSurface(water, NULL, screen, &rcWater);
		}
	      else
		{
		  rcGrass.x = rcSprite.x - (rcSprite.x % SPRITE_SIZE);
		  rcGrass.y = rcSprite.y - (rcSprite.y % SPRITE_SIZE) + SPRITE_SIZE;
		  SDL_BlitSurface(grass, NULL, screen, &rcGrass);						    
		}
	      SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
	      SDL_UpdateRect(screen,0,0,0,0);
	    }
	  SDL_Delay(150);
	}
    }
}



void move_up()
{
  if(check_move_ground(rcSprite.x/SPRITE_SIZE , (rcSprite.y/SPRITE_SIZE)-1))
    {
      int i,j;
      if(rcSprite.y > SPRITE_SIZE -1)
	{
	  for( i=0 ; i<SPRITE_SIZE ; i++)
	    {
	      SDL_Delay(2);
	      rcSprite.y -= 1;
	      if(MAP[rcSprite.x/SPRITE_SIZE][rcSprite.y/SPRITE_SIZE])
		{
		  rcWater.x = rcSprite.x - (rcSprite.x % SPRITE_SIZE);
		  rcWater.y = rcSprite.y - (rcSprite.y % SPRITE_SIZE);
		  SDL_BlitSurface(water, NULL, screen, &rcWater);
		}
	      else
		{
		  rcGrass.x = rcSprite.x - (rcSprite.x % SPRITE_SIZE);
		  rcGrass.y = rcSprite.y - (rcSprite.y % SPRITE_SIZE);
		  SDL_BlitSurface(grass, NULL, screen, &rcGrass);
		}
	      if(MAP[(rcSprite.x/SPRITE_SIZE)][rcSprite.y/SPRITE_SIZE+1])
		{
		  rcWater.x =  rcSprite.x - (rcSprite.x % SPRITE_SIZE);
		  rcWater.y = rcSprite.y - (rcSprite.y % SPRITE_SIZE) + SPRITE_SIZE;
		  SDL_BlitSurface(water, NULL, screen, &rcWater);
		}
	      else
		{
		  rcGrass.x = rcSprite.x - (rcSprite.x % SPRITE_SIZE);
		  rcGrass.y = rcSprite.y - (rcSprite.y % SPRITE_SIZE) + SPRITE_SIZE;
				SDL_BlitSurface(grass, NULL, screen, &rcGrass);						    
		}
	      SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
	      SDL_UpdateRect(screen,0,0,0,0);
	    }
	  SDL_Delay(150);
	}
    }
}

void move_right()
{
  if(check_move_ground((rcSprite.x/SPRITE_SIZE)+1 , rcSprite.y/SPRITE_SIZE))
    {
      int i,j;
      if(rcSprite.x <= SCREEN_WIDTH - SPRITE_SIZE -1)
	{
	  for( i=0 ; i<SPRITE_SIZE ; i++)
	    {
	      SDL_Delay(2);
	      rcSprite.x += 1;
	      if(MAP[rcSprite.x/SPRITE_SIZE][rcSprite.y/SPRITE_SIZE])
		{
		  rcWater.x = rcSprite.x - (rcSprite.x % SPRITE_SIZE);
		  rcWater.y = rcSprite.y - (rcSprite.y % SPRITE_SIZE);
		  SDL_BlitSurface(water, NULL, screen, &rcWater);
		}
	      else
		{
		  rcGrass.x = rcSprite.x - (rcSprite.x % SPRITE_SIZE);
		  rcGrass.y = rcSprite.y - (rcSprite.y % SPRITE_SIZE);
		  SDL_BlitSurface(grass, NULL, screen, &rcGrass);
		}
	      if(MAP[(rcSprite.x/SPRITE_SIZE)+1][rcSprite.y/SPRITE_SIZE])
		{
		  rcWater.x =  rcSprite.x - (rcSprite.x % SPRITE_SIZE) + SPRITE_SIZE;
		  rcWater.y = rcSprite.y - (rcSprite.y % SPRITE_SIZE);
		  SDL_BlitSurface(water, NULL, screen, &rcWater);
		}
	      else
		{
		  rcGrass.x = rcSprite.x - (rcSprite.x % SPRITE_SIZE) + SPRITE_SIZE;
		  rcGrass.y = rcSprite.y - (rcSprite.y % SPRITE_SIZE);
		  SDL_BlitSurface(grass, NULL, screen, &rcGrass);						    
		}
	      SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
	      SDL_UpdateRect(screen,0,0,0,0);
	    }     
	  SDL_Delay(150);
	}
    }
}





void move_left()
{
  if(check_move_ground((rcSprite.x/SPRITE_SIZE)-1 , rcSprite.y/SPRITE_SIZE))
    {
      int i,j;
      for( i=0 ; i<SPRITE_SIZE ; i++)
	{
	  SDL_Delay(2);
	  rcSprite.x -= 1;
	  if(MAP[rcSprite.x/SPRITE_SIZE][rcSprite.y/SPRITE_SIZE])
	    {
	      rcWater.x = rcSprite.x - (rcSprite.x % SPRITE_SIZE);
	      rcWater.y = rcSprite.y - (rcSprite.y % SPRITE_SIZE);
	      SDL_BlitSurface(water, NULL, screen, &rcWater);
	    }
	  else
	    {
	      rcGrass.x = rcSprite.x - (rcSprite.x % SPRITE_SIZE);
	      rcGrass.y = rcSprite.y - (rcSprite.y % SPRITE_SIZE);
	      SDL_BlitSurface(grass, NULL, screen, &rcGrass);
	    }
	  if(MAP[(rcSprite.x/SPRITE_SIZE)+1][rcSprite.y/SPRITE_SIZE])
	    {
	      rcWater.x =  rcSprite.x - (rcSprite.x % SPRITE_SIZE) + SPRITE_SIZE;
	      rcWater.y = rcSprite.y - (rcSprite.y % SPRITE_SIZE);
	      SDL_BlitSurface(water, NULL, screen, &rcWater);
	    }
	  else
	    {
	      rcGrass.x = rcSprite.x - (rcSprite.x % SPRITE_SIZE) + SPRITE_SIZE;
	      rcGrass.y = rcSprite.y - (rcSprite.y % SPRITE_SIZE);
	      SDL_BlitSurface(grass, NULL, screen, &rcGrass);						    
	    }
	  SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
	  SDL_UpdateRect(screen,0,0,0,0);
	}
      SDL_Delay(150);
    }
}
