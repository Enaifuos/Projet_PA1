#include "SDL.h"
#include "setting.c"
#include "drawing.c"
#include "global_variable.c"

#define SCREEN_WIDTH  608
#define SCREEN_HEIGHT 480
#define SPRITE_SIZE    32
#define MAPlength      64
#define MAPheight      44






/*-------------Prototypes------------*/



/* action in the game */

    //movement
int check_move_ground(int x, int y);
void move_down();
void move_up();
void move_right();
void move_left();


   //action in the game
void you_loose();
void menu_pause();
void stats();




/* screen printing */
void screen_printing_Gmove();
void screen_printing_Pmove();









/*---------------function-------------------*/




   /*-----movement-----*/
int check_move_ground(int x, int y)
{
  int res = 0;
  SDL_Surface pos = MAP[x][y];
  if( pos.pixels == (*grass).pixels || pos.pixels == (*dirt).pixels || pos.pixels == (*sand).pixels || pos.pixels == (*bridge1).pixels || pos.pixels == (*bridge2).pixels)
  {
    res = 1; //peut passer
   }
  
  //special sandg
  else if( pos.pixels == (*sandg_u).pixels || pos.pixels == (*sandg_d).pixels || pos.pixels == (*sandg_dl).pixels || pos.pixels == (*sandg_dr).pixels || pos.pixels == (*sandg_ul).pixels || pos.pixels == (*sandg_ur).pixels || pos.pixels == (*sandg_l).pixels || pos.pixels == (*sandg_r).pixels)
    {
      res = 1;
    }
  //special sandw
  else if( pos.pixels == (*sandw_u).pixels || pos.pixels == (*sandw_d).pixels || pos.pixels == (*sandw_dl).pixels || pos.pixels == (*sandw_dr).pixels || pos.pixels == (*sandw_ul).pixels || pos.pixels == (*sandw_ur).pixels || pos.pixels == (*sandw_l).pixels || pos.pixels == (*sandw_r).pixels )
    {
      res = 1;
    }
  //special dirt
  else if( pos.pixels == (*dirtg_u).pixels || pos.pixels == (*dirtg_d).pixels || pos.pixels == (*dirtg_ul).pixels || pos.pixels == (*dirtg_ur).pixels || pos.pixels == (*dirtg_dl).pixels || pos.pixels == (*dirtg_dr).pixels || pos.pixels == (*dirtg_l).pixels || pos.pixels == (*dirtg_r).pixels )
    {
      res = 1;
    }
  return res;
}


void move_down()
{
  // set the animation fram for the movement
  rcSrcSprite.y = 0; 
  if( coordplayery < (MAPheight-1) *  SPRITE_SIZE )
    {
      // check if the player can walk on the surface
      if( check_move_ground(coordplayerx/SPRITE_SIZE , (coordplayery/SPRITE_SIZE)+1) )
	{
	  int i;
	  stepcount += 1;
	  if( coordplayery/SPRITE_SIZE > MAPheight - 9 || coordplayery/SPRITE_SIZE <= 6 )
	    {
	      for( i=0 ; i<SPRITE_SIZE ; i++ )
		{
		  rcSprite.y += 1;
		  coordplayery += 1;
		  if( i%8 == 0 && i != 0)
		    {
		      rcSrcSprite.y += SPRITE_SIZE+1;
		    }
		  SDL_Delay(5);
		  screen_printing_Pmove();
		}
	    }
	  else
	    {
	      for( i=0 ; i < SPRITE_SIZE ; i++)
		{
		  coordplayery += 1;
		  if( i%8 == 0 && i != 0)
		    {
		      rcSrcSprite.y += SPRITE_SIZE+1;
		    }
		  SDL_Delay(5);
		  screen_printing_Gmove();
		}
	      //  SDL_Delay(150);
	    }
	}
    }
  
}



void move_up()
{
  rcSrcSprite.y = SPRITE_SIZE * 18;
  if(coordplayery >= SPRITE_SIZE)
    {
      if( check_move_ground( coordplayerx/SPRITE_SIZE , (coordplayery/SPRITE_SIZE) -1) )
	{
	  int i;
	  stepcount += 1;
	  if( coordplayery/SPRITE_SIZE > MAPheight - 8 || coordplayery/SPRITE_SIZE <= 7 )
	    {
	      for( i=0 ; i<SPRITE_SIZE ; i++ )
		{
		  rcSprite.y -= 1;
		  coordplayery -= 1;
		  if( i%8 == 0 && i != 0)
		    {
		     rcSrcSprite.y += SPRITE_SIZE;
		    }
		  SDL_Delay(5);
		  screen_printing_Pmove();
		}
	    }
	  else
	    {
	      for( i=0 ; i<SPRITE_SIZE ; i++)
		{
		  coordplayery -= 1;
		  if( i%8 == 0 && i != 0)
		    {
		     rcSrcSprite.y += SPRITE_SIZE;
		    }
		  SDL_Delay(5);
		  screen_printing_Gmove();
		}
	      //	      SDL_Delay(150);
	    }
	}
    }
}


void move_right()
{
  rcSrcSprite.y = SPRITE_SIZE * 12;
  if( coordplayerx < (MAPlength-1) * SPRITE_SIZE )
    {
      if(check_move_ground((coordplayerx/SPRITE_SIZE)+1 , coordplayery/SPRITE_SIZE))
	{
	  int i;
	  stepcount += 1;
	  if( coordplayerx/SPRITE_SIZE >= MAPlength - 10 || coordplayerx/SPRITE_SIZE <= 8 )
	    {
	      SDL_Delay(20);
	      for( i=0 ; i < SPRITE_SIZE ; i++ )
		{
		  rcSprite.x += 1;
		  coordplayerx += 1;
		  if( i%8 == 0 && i != 0)
		    {
		     rcSrcSprite.y += SPRITE_SIZE+1;
		    }
		  SDL_Delay(5);
		  screen_printing_Pmove();
		}
	    }
	   else
	    {
	      for( i=0 ; i < SPRITE_SIZE ; i++ )
		{
		  coordplayerx += 1;
		  if( i%8 == 0 && i != 0)
		    {
		     rcSrcSprite.y += SPRITE_SIZE+1;
		    }
		  SDL_Delay(5);
		  screen_printing_Gmove(); 
		}
	      //     SDL_Delay(150);
	    }	  
	}
    }
}





void move_left()
{
  rcSrcSprite.y = SPRITE_SIZE * 6;
  if( coordplayerx >= SPRITE_SIZE )
    {
      if( check_move_ground((coordplayerx/SPRITE_SIZE)-1 , coordplayery/SPRITE_SIZE) )
	{
	  int i;
	  stepcount += 1;
	  if( coordplayerx/SPRITE_SIZE >= MAPlength - 9  || coordplayerx/SPRITE_SIZE <= 9 ) 
	    {
	      SDL_Delay(20);
	      for( i=0 ; i < SPRITE_SIZE ; i++ )
		{
		  rcSprite.x -= 1;
		  coordplayerx -= 1;
		  if( i%8 == 0 && i != 0)
		    {
		     rcSrcSprite.y += SPRITE_SIZE+1;
		    }
		  SDL_Delay(5);
		  screen_printing_Pmove();
		}
	    }
	  else
	    {
	      for( i=0 ; i < SPRITE_SIZE ; i++ )
		{
		  coordplayerx -= 1;
		  if( i%8 == 0 && i != 0)
		    {
		     rcSrcSprite.y += SPRITE_SIZE+1;
		    }
		  SDL_Delay(5);
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

void menu_pause() //A finir
{
 int menu = 1;
  rcPause.x = 507;
  rcPause.y = 0;

  SDL_BlitSurface(pause, NULL, screen, &rcPause);
  SDL_UpdateRect(screen,0,0,0,0);

  while(menu)
    {
      if (SDL_PollEvent(&event))
	{
	  switch (event.type)
	    {
	      /* close the menu */
	    case SDL_QUIT:
	      pause = 0;
	      break;
	      
	      /* move the selection case */
	    case SDL_KEYDOWN:
	      switch (event.key.keysym.sym) 
		{
		case SDLK_ESCAPE:
		case SDLK_q:
		  menu = 0;
		  break;
		case SDLK_DOWN:
		  stats();
		  break;
		case SDLK_UP:
		  break;
		}
	      break;
	    }
	}
      
    } 
  screen_printing_Pmove();
}


void stats()
{
  long time;
  int min, sec;
  printf("You walked %d steps\n",stepcount);
  time = SDL_GetTicks();
  min = time /60000;
  printf("You played for %d", min);
  sec = (time /1000)%60;
  printf("min and %d s\n", sec);
}















/*--------- screen printing ----------*/


void screen_printing_Gmove()
{
  int i, j, x, y;
  if( (coordplayerx % SPRITE_SIZE) == 0 &&  (coordplayery % SPRITE_SIZE) == 0 )
    {
      /* draw the grass, water, sand, tree and ... */
      for( i=0 ; i < SCREEN_WIDTH/SPRITE_SIZE ; i++ )
	{
	  for( j=0 ; j < SCREEN_HEIGHT/SPRITE_SIZE ; j++ )
	    {
	      x = (coordplayerx - rcSprite.x)/SPRITE_SIZE + i;
	      y = (coordplayery - rcSprite.y)/SPRITE_SIZE + j;
	      draw_GroundGM(i, j, x, y);
	    }
	}
      
      
      /* draw the sprite */
      SDL_BlitSurface(sprite, &rcSrcSprite, screen, &rcSprite);
      
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
	      draw_GroundGM(i, j, x, y);
	    }
	}
      
      /* draw the sprite */
      SDL_BlitSurface(sprite, &rcSrcSprite, screen, &rcSprite);
      
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
	  draw_GroundPM(i, j, x, y);
	}
    }
  
  /* draw the sprite */
  SDL_BlitSurface(sprite, &rcSrcSprite, screen, &rcSprite);
  
  /* update the screen */
  SDL_UpdateRect(screen,0,0,0,0);
}


