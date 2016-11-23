#include "setting.c"
#define CAVElength 10
#define CAVEheight 8



/*----- prototypes -----*/
void cave();
void set_cave(SDL_Surface * map);







/*------ function -----*/

void cave()
{
  SDL_Surface * CAVE;
  CAVE = (SDL_Surface *)malloc(sizeof(SDL_Surface)*CAVElength*CAVEheight);
  set_cave(CAVE);
  
  
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


