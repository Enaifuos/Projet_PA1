#include "setting.c"
#define CAVElength 10
#define CAVEheight 8



/*----- prototypes -----*/
void cave();
void set_cave(SDL_Surface * map);



void cave_move_left();
void cave_move_right();
void cave_move_up();
void cave_move_down();








/*------ function -----*/

void cave()
{
  SDL_Surface * CAVE;
  CAVE = (SDL_Surface *)malloc(sizeof(SDL_Surface)*CAVElength*CAVEheight);
  set_cave(CAVE);
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
	      break;
	    }
	}
      
      /* handle sprite movement */
      keystate = SDL_GetKeyState(NULL);
      
      if( keystate[SDLK_LEFT] )
	{
	  cave_move_left();
	}
      if( keystate[SDLK_RIGHT] )
	{
	  cave_move_right();
	}
      if( keystate[SDLK_UP] )
	{
	  cave_move_up();
	}
      if( keystate[SDLK_DOWN] )
	{
	  cave_move_down();
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
	  map[j+i*CAVEheight] = *grass; //have to be changed by cave ground
	}
    }
}


void cave_move_left()
{
  printf("left");
}


void cave_move_right()
{
  printf("right");
}


void cave_move_up()
{
  printf("up");
}



void cave_move_down()
{
  printf("down");
}
