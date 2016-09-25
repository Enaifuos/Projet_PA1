#include "SDL.h"

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
#define SPRITE_SIZE    32

int MAP[SCREEN_WIDTH/SPRITE_SIZE+1][SCREEN_HEIGHT/SPRITE_SIZE+1];


     /* prototypes  */

int check_move(int x, int y);











        /*  MAIN   */

int main(int argc, char* argv[])
{
  SDL_Surface *screen, *temp, *sprite, *grass, *water;
  SDL_Rect rcSprite, rcGrass, rcWater;
  SDL_Event event;
  Uint8 *keystate;
  int colorkey, gameover;
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
	temp  = SDL_LoadBMP("grass.bmp");
	grass = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);

	/* load water */
	temp = SDL_LoadBMP("water.bmp");
	water = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);

	/* set sprite position */
	rcSprite.x = 0;
	rcSprite.y = 0;

	gameover = 0;

	/* set the MAP */
	for( i=0 ; i < (SCREEN_WIDTH/SPRITE_SIZE) ; i++)
	  {
	    for( j=0 ; j < (SCREEN_HEIGHT/SPRITE_SIZE) ; j++)
	      {
		MAP[i][j] = 0;
	      }
	  }
	/* Test to see if water work */
	MAP[0][0] = 1; 
	MAP[0][1] = 1;
	MAP[1][SCREEN_HEIGHT/SPRITE_SIZE-1] = 1;

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
		    for( i=0 ; i<SPRITE_SIZE ; i++)
		      {
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
		if (keystate[SDLK_RIGHT] )
		  {
		    if(rcSprite.x <= SCREEN_WIDTH - SPRITE_SIZE -1)
		      {
			for( i=0 ; i<SPRITE_SIZE ; i++)
			  {
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
		if (keystate[SDLK_UP] )
		  {
		    rcSprite.y -= 1;
		  }
		if (keystate[SDLK_DOWN] )
		  {
		    rcSprite.y += 1;
		  }

		/* collide with edges of screen */
		if ( rcSprite.x < 0 )
		  {
		    rcSprite.x = 0;
		  }
		
		else if ( rcSprite.x > SCREEN_WIDTH-SPRITE_SIZE )
		  {
		    rcSprite.x = SCREEN_WIDTH-SPRITE_SIZE;
		  }
		
		if ( rcSprite.y < 0 )
		  {
		    rcSprite.y = 0;
		  }
		
		else if ( rcSprite.y > SCREEN_HEIGHT-SPRITE_SIZE )
		  {
		    rcSprite.y = SCREEN_HEIGHT-SPRITE_SIZE;
		  }

		/* draw the grass */
		for( i=0 ; i < SCREEN_WIDTH/SPRITE_SIZE ; i++)
		  {
		    for( j=0 ; j < SCREEN_HEIGHT/SPRITE_SIZE ; j++)
		      {
			if(MAP[i][j] == 0)
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
	
	/* clean up */
	SDL_FreeSurface(sprite);
	SDL_FreeSurface(grass);
	SDL_FreeSurface(water);
	SDL_Quit();

	return 0;
}





/*  function  */

int check_move(int x, int y)
{
  int res = 1;
  if(MAP[x][y])
    {
      res = 0;
    }
  return res;
}
