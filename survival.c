#include "SDL.h"
#include "fonction.c"

#define SCREEN_WIDTH  608   
#define SCREEN_HEIGHT 480
#define SPRITE_SIZE    32


   /* global variable */

int MAP[2 * (SCREEN_WIDTH/SPRITE_SIZE+1)][2 * (SCREEN_HEIGHT/SPRITE_SIZE+1)];
SDL_Surface *screen, *temp, *sprite, *grass, *water;
SDL_Rect rcSprite, rcGrass, rcWater;
SDL_Event event;
Uint8 *keystate;
int colorkey, gameover;
int coordplayerx, coordplayery;




        /*  MAIN   */

int main(int argc, char* argv[])
{
  int i, j;
  
  /* initialize video system */
  SDL_Init(SDL_INIT_VIDEO);
  
  /* set the title bar */
  SDL_WM_SetCaption("SDL Move", "SDL Move");
  
  /* create window */
  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
  
  /* set keyboard repeat */
  SDL_EnableKeyRepeat(1000, 1000);
  
  /* load sprite */
  temp   = SDL_LoadBMP("sprite.bmp");
  sprite = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  
  /* setup sprite colorkey and turn on RLE */
  colorkey = SDL_MapRGB(screen->format, 255, 0, 255);
  SDL_SetColorKey(sprite, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
  
        /* load grass */
  temp  = SDL_LoadBMP("herbe.bmp");
  grass = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  
	/* load water */
  temp = SDL_LoadBMP("water2.bmp");
  water = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  
  /* set sprite position */
  rcSprite.x = 9*SPRITE_SIZE;
  rcSprite.y = 7*SPRITE_SIZE;
  coordplayerx = 9*SPRITE_SIZE;   
  coordplayery = 7*SPRITE_SIZE;

  
  gameover = 0;
  
  /* set the MAP */
  
  set_map();
  
  /* Test to see if water work */
  MAP[0][0] = 1; 
  MAP[0][1] = 1;
  MAP[0][2] = 1;
  MAP[0][3] = 1;
  MAP[1][8] = 1;
  MAP[3][2] = 1;
  
  for( i=0 ; i < (SCREEN_HEIGHT/SPRITE_SIZE) ; i++)
    {
      for( j=0 ; j < (SCREEN_WIDTH/SPRITE_SIZE) ; j++)
	{
	  printf("%d ",MAP[j][i]);
	}
      printf("\n");
    }
  /* message pump */
  while (!gameover)
    {
      /* look for an event */
      if (SDL_PollEvent(&event))
	{
	  /* an event was found */
	  switch (event.type)
	    {
	      /* close button clicked */
	    case SDL_QUIT:
	      gameover = 1;
	      break;
	      
	      /* handle the keyboard */
	    case SDL_KEYDOWN:
	      switch (event.key.keysym.sym) {
	      case SDLK_ESCAPE:
	      case SDLK_q:
		gameover = 1;
		break;
	      }
	      break;
	    }
	}
      
      /* handle sprite movement */
      keystate = SDL_GetKeyState(NULL);
      
      if (keystate[SDLK_LEFT] )
	{
	  move_left();		    
	}
      if (keystate[SDLK_RIGHT] )
	{
	  move_right();
	}
      if (keystate[SDLK_UP] )
	{
	  move_up();
	}
      
      if (keystate[SDLK_DOWN] )
	{
	  move_down();
	}
      
      /* collide with edges of screen */
      if ( coordplayerx == 0 )
	{
	  coordplayerx = 0;
	}
      
      else if ( coordplayerx > (2*SCREEN_WIDTH) - SPRITE_SIZE )
	{
	  coordplayerx = (2*SCREEN_WIDTH) - SPRITE_SIZE;
	}
      
      if ( coordplayery < 0 )
	{
	  coordplayery = 0;
	}
      
      else if ( coordplayery > (2*SCREEN_HEIGHT) - SPRITE_SIZE )
	{
	  coordplayery = (2*SCREEN_HEIGHT)-SPRITE_SIZE;
	}
      
      screen_printing();
    }
  
  /* clean up */
  SDL_FreeSurface(sprite);
  SDL_FreeSurface(grass);
  SDL_FreeSurface(water);
  SDL_Quit();
  
  return 0;
}


