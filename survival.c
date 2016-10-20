#include "SDL.h"
#include "fonction.c"

#define SCREEN_WIDTH  608   
#define SCREEN_HEIGHT 480
#define SPRITE_SIZE    32
#define MAPlength      64
#define MAPheight      44

   /* global variable */


int MAP[MAPlength][MAPheight];
SDL_Surface *screen, *temp, *sprite, *grass, *water, *sand, *tree, *dirt, *rockwall, *pause, *rockwall_dl, *rockwall_dr, *rockwall_l, *rockwall_r, *rockwall_top, *rockwall_ucl, *rockwall_ucr, *rockwall_ul, *rockwall_ur;
SDL_Rect rcSprite, rcSrcSprite, rcGrass, rcWater, rcTree, rcDirt, rcSand, rcRock, rcPause;
SDL_Event event;
Uint8 *keystate;
int colorkey, gameover, stepcount;
int coordplayerx, coordplayery;




        /*  MAIN   */

int main(int argc, char* argv[])
{
  int i, j;
  
  /* initialize video system */
  SDL_Init(SDL_INIT_VIDEO);
  
  /* set the title bar */
  SDL_WM_SetCaption("Survival", "game survival");
  
  /* create window */
  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
  
  /* set keyboard repeat */
  SDL_EnableKeyRepeat(1000, 1000);
  
  /* load sprite */
  temp   = SDL_LoadBMP("ressources/playersheet/player.bmp");
  sprite = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  
  /* setup sprite colorkey and turn on RLE */
  colorkey = SDL_MapRGB(screen->format, 255, 0, 255);
  SDL_SetColorKey(sprite, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
  
        /* load grass */
  temp  = SDL_LoadBMP("ressources/grass.bmp");
  grass = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  
	/* load water */
  temp = SDL_LoadBMP("ressources/water.bmp");
  water = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  
       /* load sand  */
  temp = SDL_LoadBMP("ressources/sand/sand.bmp");
  sand = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

       /* load tree */
  temp = SDL_LoadBMP("ressources/tree.bmp");
  tree = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

      /* load dirt  */
  temp = SDL_LoadBMP("ressources/dirt/dirt.bmp");
  dirt = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

    /* load pause menu */
  temp = SDL_LoadBMP("ressources/pause_menu.bmp");
  pause = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  
      /*  load rock */
  temp = SDL_LoadBMP("ressources/rockwall/rockwall.bmp");
  rockwall = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/rockwall/rockwall_dl.bmp");
  rockwall_dl = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/rockwall/rockwall_dr.bmp");
  rockwall_dr = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/rockwall/rockwall_l.bmp");
  rockwall_l = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/rockwall/rockwall_r.bmp");
  rockwall_r = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/rockwall/rockwall_top.bmp");
  rockwall_top = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/rockwall/rockwall_ucl.bmp");
  rockwall_ucl = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/rockwall/rockwall_ucr.bmp");
  rockwall_ucr = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/rockwall/rockwall_ul.bmp");
  rockwall_ul = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  
  temp = SDL_LoadBMP("ressources/rockwall/rockwall_ur.bmp");
  rockwall_ur = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);



   /* set sprite position */
  rcSprite.x = 9*SPRITE_SIZE;
  rcSprite.y = 7*SPRITE_SIZE;
  coordplayerx = 9*SPRITE_SIZE;   
  coordplayery = 7*SPRITE_SIZE;

  /* set the sprite frame */
  rcSrcSprite.x = 0;
  rcSrcSprite.y = 0;
  rcSrcSprite.h = SPRITE_SIZE;
  rcSrcSprite.w = SPRITE_SIZE;


  
  gameover = 0;
  
  /* set the MAP */
  
  set_map();
  
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
	  stepcount += 1;
	}
      if (keystate[SDLK_RIGHT] )
	{
	  move_right();
	  stepcount += 1;
	}
      if (keystate[SDLK_UP] )
	{
	  move_up();
	  stepcount += 1;
	}
      
      if (keystate[SDLK_DOWN] )
	{
	  move_down();
	  stepcount += 1;
	}

      if (keystate[SDLK_p])
	{
	  menu_pause();
	}
      
      /* collide with edges of screen */
      if ( coordplayerx == 0 )
	{
	  coordplayerx = 0;
	}
      
      else if ( coordplayerx > (MAPlength-1) * SPRITE_SIZE )
	{
	  coordplayerx = (MAPlength-1) * SPRITE_SIZE;
	}
      
      if ( coordplayery < 0 )
	{
	  coordplayery = 0;
	}
      
      else if ( coordplayery > (MAPheight-1) * SPRITE_SIZE )
	{
	  coordplayery = (MAPheight-1) * SPRITE_SIZE;
	}
      
      screen_printing_Gmove();
    }
  
  /* clean up */
  SDL_FreeSurface(sprite);
  SDL_FreeSurface(grass);
  SDL_FreeSurface(water);
  SDL_FreeSurface(sand);
  SDL_FreeSurface(dirt);
  SDL_FreeSurface(pause);
  SDL_FreeSurface(rockwall);
  SDL_FreeSurface(rockwall_dr);
  SDL_FreeSurface(rockwall_dl);
  SDL_FreeSurface(rockwall_top);
  SDL_FreeSurface(rockwall_r);
  SDL_FreeSurface(rockwall_l);
  SDL_FreeSurface(rockwall_ur);
  SDL_FreeSurface(rockwall_ul);
  SDL_FreeSurface(rockwall_ucr);
  SDL_FreeSurface(rockwall_ucl);

  SDL_Quit();
  
  return 0;
}


