#include "setting.c"
#define CAVElength 19
#define CAVEheight 15



struct coord
{
  int y;
  int x;
};







/*----- prototypes -----*/
void cave();
void set_cave(SDL_Surface * map);



void cave_move_left(struct coord Coordplayer);
void cave_move_right(struct coord Coordplayer);
void cave_move_up(struct coord Coordplayer);
void cave_move_down(struct coord Coordplayer);



void print_cave(SDL_Surface * CAVE);





/*------ function -----*/

void cave()
{
  /*set the player cave coord */
  struct coord coordplayertemp;
  coordplayertemp.x = SPRITE_SIZE*9;
  coordplayertemp.y = SPRITE_SIZE*7;

  /*set the cave */
  SDL_Surface * CAVE;
  CAVE = (SDL_Surface *)malloc(sizeof(SDL_Surface)*CAVElength*CAVEheight);
  set_cave(CAVE);
  print_cave(CAVE);

  int quit = 0;
  while (!quit)
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
	      switch (event.key.keysym.sym) 
		{
		case SDLK_ESCAPE:
		case SDLK_q:
		  quit = 1;
		  gameover = 1;
		  break;
		}
	      break;
	    }
	}
      
      /* handle sprite movement */
      keystate = SDL_GetKeyState(NULL);
      
      if( keystate[SDLK_LEFT] )
	{
	  cave_move_left(coordplayertemp);
	}
      if( keystate[SDLK_RIGHT] )
	{
	  cave_move_right(coordplayertemp);
	}
      if( keystate[SDLK_UP] )
	{
	  cave_move_up(coordplayertemp);
	}
      if( keystate[SDLK_DOWN] )
	{
	  cave_move_down(coordplayertemp);
	}
    }


  
  free(CAVE);
}


void set_cave(SDL_Surface * map)
{
  int i, j;
  for( i = 0 ; i < CAVEheight ; i++ )
    {
      for( j= 0 ; j < CAVElength ; j++ )
	{
	  map[j+i*CAVEheight] = *cave_ground; //have to be changed by cave ground
	}
    }
}


void cave_move_left(struct coord Coordplayer)
{
  printf("left");
}


void cave_move_right(struct coord Coordplayer)
{
  printf("right");
}


void cave_move_up(struct coord Coordplayer)
{
  printf("up");
}



void cave_move_down(struct coord Coordplayer)
{
  printf("down");
}








void print_cave(SDL_Surface * CAVE)
{
  int i,j;
  for(i = 0 ; i < CAVEheight ; i++ )
    {
      for( j = 0 ; j < CAVElength ; j++ )
	{
	  rcGround.x = i * SPRITE_SIZE;
	  rcGround.y = j * SPRITE_SIZE;
	  SDL_BlitSurface(&CAVE[j+i*CAVElength], NULL, screen, &rcGround);
	}
    }
  SDL_UpdateRect(screen,0,0,0,0);
    
}
