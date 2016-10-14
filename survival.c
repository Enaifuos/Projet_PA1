#include "SDL.h"
#include "fonction.c"

#define SCREEN_WIDTH  608   
#define SCREEN_HEIGHT 480
#define SPRITE_SIZE    32
#define MAPlength      64
#define MAPheight      44

   /* global variable */


int MAP[MAPlength][MAPheight];
SDL_Surface *screen, *temp, *sprite, *grass, *water, *sand, *tree, *ground_land, *cascade1, *cascade2, *cascade3, *cascade4, *cascade5, *cascade6, *cascade7, *cascade8, *cascade9, *cascade10, *cascade11, *cascade12 ;
SDL_Rect rcSprite, rcGrass, rcWater, rcTree, rcGround_land, rcSand, rcC1, rcC2, rcC3, rcC4, rcC5, rcC6, rcC7, rcC8, rcC9, rcC10, rcC11, rcC12;
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
  temp = SDL_LoadBMP("water.bmp");
  water = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  
       /* load sand  */
  temp = SDL_LoadBMP("sand.bmp");
  sand = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

       /* load tree */
  temp = SDL_LoadBMP("tree.bmp");
  tree = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

      /* load ground_land  */
  temp = SDL_LoadBMP("ground_land.bmp");
  ground_land = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  
  /* ********************************* Mes changements commence ici ******************************/
  /* load waterfall 1  */
  temp = SDL_LoadBMP("cascade1.bmp");
  cascade1 = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  /* load waterfall 2 */
  temp = SDL_LoadBMP("cascade2.bmp");
  cascade2 = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  /* load waterfall 3 */
  temp = SDL_LoadBMP("cascade3.bmp");
  cascade3 = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  /* load waterfall 4 */
  temp = SDL_LoadBMP("cascade4.bmp");
  cascade4 = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  /* load waterfall 5 */
  temp = SDL_LoadBMP("cascade5.bmp");
  cascade5 = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  /* load waterfall 6 */
  temp = SDL_LoadBMP("cascade6.bmp");
  cascade6 = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  /* load waterfall 7 */
  temp = SDL_LoadBMP("cascade7.bmp");
  cascade7 = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  /* load waterfall 8 */
  temp = SDL_LoadBMP("cascade8.bmp");
  cascade8 = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  /* load waterfall 9 */
  temp = SDL_LoadBMP("cascade9.bmp");
  cascade9 = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
 /* load waterfall 10 */
  temp = SDL_LoadBMP("cascade10.bmp");
  cascade10 = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
 /* load waterfall 11 */
  temp = SDL_LoadBMP("cascade11.bmp");
  cascade11 = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
/* load waterfall 11 */
  temp = SDL_LoadBMP("cascade12.bmp");
  cascade12 = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  /********************************* Et finissent ici ************************************************/

  /* set sprite position */
  rcSprite.x = 9*SPRITE_SIZE;
  rcSprite.y = 7*SPRITE_SIZE;
  coordplayerx = 9*SPRITE_SIZE;   
  coordplayery = 7*SPRITE_SIZE;

  
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
  SDL_FreeSurface(sand);
  SDL_FreeSurface(ground_land);
  SDL_FreeSurface(cascade1);
  SDL_FreeSurface(cascade2);
  SDL_FreeSurface(cascade3);
  SDL_FreeSurface(cascade4);
  SDL_FreeSurface(cascade5);
  SDL_FreeSurface(cascade6);
  SDL_FreeSurface(cascade7);
  SDL_FreeSurface(cascade8);
  SDL_FreeSurface(cascade9);
  SDL_FreeSurface(cascade10);
  SDL_FreeSurface(cascade11);

  SDL_Quit();
  
  return 0;
}


