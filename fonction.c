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











/*--------action in the game---------*/


void you_loose()
{
  printf("**********\n YOU LOSE\n**********\n");
  set_map();
  set_position();
}



























/*---------screen printing ----------*/


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
	      if( MAP[x][y] == 1)
		{
		  rcWater.x = i * SPRITE_SIZE;
		  rcWater.y = j * SPRITE_SIZE;
		  SDL_BlitSurface(water, NULL, screen, &rcWater);
		}
	      if( MAP[x][y] == 2){
		rcSand.x = i * SPRITE_SIZE;
		rcSand.y = j * SPRITE_SIZE;
		SDL_BlitSurface(sand, NULL, screen, &rcSand);
	      }
	      if( MAP[x][y] == 3){
		rcTree.x = i * SPRITE_SIZE;
		rcTree.y = j * SPRITE_SIZE;
		SDL_BlitSurface(tree, NULL, screen, &rcTree);
	      }
	      if( MAP[x][y] == 4){
		rcGround_land.x = i * SPRITE_SIZE;
		rcGround_land.y = j * SPRITE_SIZE;
		SDL_BlitSurface(ground_land, NULL, screen, &rcGround_land);
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
	      if( MAP[x][y] == 2 )
		{ 
		  rcSand.x = i * SPRITE_SIZE - (coordplayerx % SPRITE_SIZE);
		  rcSand.y = j * SPRITE_SIZE - (coordplayery % SPRITE_SIZE);
		  SDL_BlitSurface(sand, NULL, screen, &rcSand);
		}
	      if( MAP[x][y] == 3)
		{
		  rcTree.x = i * SPRITE_SIZE - (coordplayerx % SPRITE_SIZE);
		  rcTree.y = j * SPRITE_SIZE - (coordplayery % SPRITE_SIZE);
		  SDL_BlitSurface(tree, NULL, screen, &rcTree);
		}
	      if( MAP[x][y] == 4)
		{
		  rcGround_land.x = i * SPRITE_SIZE - (coordplayerx % SPRITE_SIZE);
		  rcGround_land.y = j * SPRITE_SIZE - (coordplayery % SPRITE_SIZE);
		  SDL_BlitSurface(ground_land, NULL, screen, &rcGround_land);
		}
	      if( MAP[x][y] == 1)
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
	  if( MAP[x][y] == 1)
	    {
	      rcWater.x = i * SPRITE_SIZE;
	      rcWater.y = j * SPRITE_SIZE;
	      SDL_BlitSurface(water, NULL, screen, &rcWater);
	    }
	  if( MAP[x][y] == 2)
	    {
	      rcSand.x = i * SPRITE_SIZE;
	      rcSand.y = j * SPRITE_SIZE;
	      SDL_BlitSurface(sand, NULL, screen, &rcSand);
	    }
	  if( MAP[x][y] == 3)
	    {
	      rcTree.x = i * SPRITE_SIZE;
	      rcTree.y = j * SPRITE_SIZE;
	      SDL_BlitSurface(tree, NULL, screen, &rcTree);
	    }
	   if( MAP[x][y] == 4 )
		{ 
		  rcGround_land.x = i * SPRITE_SIZE ;
		  rcGround_land.y = j * SPRITE_SIZE ;
		  SDL_BlitSurface(ground_land, NULL, screen, &rcGround_land);
		}
	}
    }
  
  /* draw the sprite */
  SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
  
  /* update the screen */
  SDL_UpdateRect(screen,0,0,0,0);
}
