#include "SDL.h"
#include "setting.c" // NEW

#define SCREEN_WIDTH  608
#define SCREEN_HEIGHT 480
#define SPRITE_SIZE    32
#define MAPlength      64
#define MAPheight      44


extern int MAP[MAPlength][MAPheight];
extern SDL_Surface *screen, *temp, *sprite, *grass, *water, *sand, *tree, *dirt, *pause;
extern SDL_Surface *rockwall, *rockwall_dl, *rockwall_dr, *rockwall_l, *rockwall_r, *rockwall_top, *rockwall_ucl, *rockwall_ucr, *rockwall_ul, *rockwall_ur;
extern SDL_Rect rcSprite, rcSrcSprite, rcGrass, rcWater, rcSand, rcTree, rcDirt, rcRock, rcPause;
extern SDL_Event event;
extern Uint8 *keystate;
extern int colorkey, gameover;
extern int coordplayerx, coordplayery;



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

   //drawing
void draw_grassGM(int i, int j);
void draw_grassPM(int i, int j);

void draw_waterGM(int i, int j);
void draw_waterPM(int i, int j);

void draw_sandGM(int i, int j);
void draw_sandPM(int i, int j);

void draw_treeGM(int i, int j);
void draw_treePM(int i, int j);

void draw_dirtGM(int i, int j);
void draw_dirtPM(int i, int j);



   //screen printing
void screen_printing_Gmove();
void screen_printing_Pmove();










/*---------------function-------------------*/


   /*-----movement-----*/
int check_move_ground(int x, int y)
{
  int res = 0;
  if( MAP[x][y] %2 == 0) // test if the player can walk on the ground
    {
      res = 1;
    }
  return res;
}


void move_down()
{
  rcSrcSprite.y = 0; 
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
	      for( i=0 ; i < SPRITE_SIZE ; i++)
		{
		  coordplayery += 1;
		  if( i%8 == 0 && i != 0)
		    {
		     rcSrcSprite.y += SPRITE_SIZE;
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
  if( check_move_ground( coordplayerx/SPRITE_SIZE , (coordplayery/SPRITE_SIZE) -1) )
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
	      for( i=0 ; i < SPRITE_SIZE ; i++ )
		{
		  coordplayerx += 1;
		  if( i%8 == 0 && i != 0)
		    {
		     rcSrcSprite.y += SPRITE_SIZE;
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
	      for( i=0 ; i < SPRITE_SIZE ; i++ )
		{
		  coordplayerx -= 1;
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


void draw_dirtPM(int i, int j)
{
  rcDirt.x = i * SPRITE_SIZE;
  rcDirt.y = j * SPRITE_SIZE;
  SDL_BlitSurface(dirt, NULL, screen, &rcDirt);
}

void draw_dirtGM(int i, int j)
{
  rcDirt.x = i * SPRITE_SIZE - (coordplayerx % SPRITE_SIZE);
  rcDirt.y = j * SPRITE_SIZE - (coordplayery % SPRITE_SIZE);
  SDL_BlitSurface(dirt, NULL, screen, &rcDirt);
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
		  draw_dirtGM(i , j);
		}          
	      if( MAP[x][y] == 5 )
		{
		    rcRock.x = i * SPRITE_SIZE;
		    rcRock.y = j * SPRITE_SIZE;
		    SDL_BlitSurface(rockwall, NULL, screen, &rcRock);
		}
	       if( MAP[x][y] == 6 )
		{
		    rcRock.x = i * SPRITE_SIZE;
		    rcRock.y = j * SPRITE_SIZE;
		    SDL_BlitSurface(rockwall_dl, NULL, screen, &rcRock);
		}
	        if( MAP[x][y] == 7 )
		{
		    rcRock.x == i * SPRITE_SIZE;
		    rcRock.y == j * SPRITE_SIZE;
		    SDL_BlitSurface(rockwall_dr, NULL, screen, &rcRock);
		}
		if( MAP[x][y] == 8 )
		  {
		    rcRock.x = i * SPRITE_SIZE;
		    rcRock.y = j * SPRITE_SIZE;
		    SDL_BlitSurface(rockwall_l, NULL, screen, &rcRock);
		  }
		 if( MAP[x][y] == 9 )
		{
		    rcRock.x = i * SPRITE_SIZE;
		    rcRock.y = j * SPRITE_SIZE;
		    SDL_BlitSurface(rockwall_r, NULL, screen, &rcRock);
		}
		 if( MAP[x][y] == 10 )
		   {
		    rcRock.x = i * SPRITE_SIZE;
		    rcRock.y = j * SPRITE_SIZE;
		    SDL_BlitSurface(rockwall_top, NULL, screen, &rcRock);
		   }
		 if( MAP[x][y] == 11 )
		   {
		     rcRock.x = i * SPRITE_SIZE;
		     rcRock.y = j * SPRITE_SIZE;
		     SDL_BlitSurface(rockwall_ucl, NULL, screen, &rcRock);
		   }
		 if( MAP[x][y] == 12 )
		   {
		     rcRock.x = i * SPRITE_SIZE;
		     rcRock.y = j * SPRITE_SIZE;
		     SDL_BlitSurface(rockwall_ucr, NULL, screen, &rcRock);
		   }
		 if( MAP[x][y] == 13 )
		   {
		     rcRock.x = i * SPRITE_SIZE;
		     rcRock.y = j * SPRITE_SIZE;
		     SDL_BlitSurface(rockwall_ul, NULL, screen, &rcRock);
		   }
		 if( MAP[x][y] == 14 )
		   {
		     rcRock.x = i * SPRITE_SIZE;
		     rcRock.y = j * SPRITE_SIZE;
		     SDL_BlitSurface(rockwall_ur, NULL, screen, &rcRock);
		   }
		 
		  
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
		  draw_dirtGM(i , j);
		}	  
	
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
	      draw_dirtPM(i , j);
	    }
	}
    }
  
  /* draw the sprite */
  SDL_BlitSurface(sprite, &rcSrcSprite, screen, &rcSprite);
  
  /* update the screen */
  SDL_UpdateRect(screen,0,0,0,0);
}
