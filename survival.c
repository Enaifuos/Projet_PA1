#include "SDL.h"
#include "fonction.c"

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
#define SPRITE_SIZE    32


   /* global variable */

int MAP[SCREEN_WIDTH/SPRITE_SIZE+1][SCREEN_HEIGHT/SPRITE_SIZE+1];
SDL_Surface *screen, *temp, *sprite, *grass, *water;
SDL_Rect rcSprite, rcGrass, rcWater;
SDL_Event event;
Uint8 *keystate;
int colorkey, gameover;




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
	rcSprite.x = 0;
	rcSprite.y = 0;

	gameover = 0;

	/* set the MAP */
	for( i=0 ; i < (SCREEN_WIDTH/SPRITE_SIZE) ; i++)
	  {
	    for( j=0 ; j < (SCREEN_HEIGHT/SPRITE_SIZE) ; j++)
	      {
	        
		MAP[i][j] = 0;}
        
	  }
	/* Test to see if water work */
	MAP[0][0] = 1; 
	MAP[0][1] = 1;
	MAP[0][2] = 1;
		for( i=0 ; i < (SCREEN_WIDTH/SPRITE_SIZE) ; i++)
	  {
	    for( j=0 ; j < (SCREEN_HEIGHT/SPRITE_SIZE) ; j++){
	      if(i==0 || i==19 || j==0 || j==14){
		//	MAP[i][j] = 1 ;
	      }
	    }
	  }
	MAP[1][SCREEN_HEIGHT/SPRITE_SIZE-1] = 1;

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
	 //  printf("\n%d,%d\n",rcSprite.x,rcSprite.y);
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
		if ( rcSprite.x == 0 )
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
