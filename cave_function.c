#include "setting.c"
#define CAVElength 19
#define CAVEheight 15








/*----- prototypes -----*/
void cave();
void set_cave(SDL_Surface * map);



int cave_move_left(SDL_Rect Coordplayer);
int cave_move_right(SDL_Rect Coordplayer);
int cave_move_up(SDL_Rect Coordplayer);
int cave_move_down(SDL_Rect Coordplayer);



void print_cave(SDL_Surface * CAVE);
void print_player_cave(SDL_Rect * rcCoord);






/*------ function -----*/

void cave()
{
  /*set the player cave coord */
  SDL_Rect coordplayertemp;
  coordplayertemp.x = SPRITE_SIZE*9;
  coordplayertemp.y = SPRITE_SIZE*7;
  SDL_Rect rcSrcPcave;


  /*set the cave */
  SDL_Surface * CAVE;
  CAVE = (SDL_Surface *)malloc(sizeof(SDL_Surface)*CAVElength*CAVEheight);
  set_cave(CAVE);
  print_cave(CAVE);
  print_player_cave(&coordplayertemp);
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
	   coordplayertemp.x = cave_move_left(coordplayertemp);
	}
      if( keystate[SDLK_RIGHT] )
	{
	  coordplayertemp.x = cave_move_right(coordplayertemp);
	}
      if( keystate[SDLK_UP] )
	{
	  coordplayertemp.y = cave_move_up(coordplayertemp);
	}
      if( keystate[SDLK_DOWN] )
	{
	  coordplayertemp.y = cave_move_down(coordplayertemp);
	}
    }


  
  free(CAVE);
}



//---- set the cave
void set_cave(SDL_Surface * map)
{
  int i, j;
  for( i = 0 ; i < CAVEheight ; i++ )
    {
      for( j= 0 ; j < CAVElength ; j++ )
	{
	  map[j+i*CAVElength] = *cave_ground; 
	}
    }
  for( i = 0 ; i < CAVElength ; i++ )
    {
      map[i] = *cave_top;
      map[i+CAVElength] = *cave_top;
      map[i+2*CAVElength] = *cave_u;
      map[i+(CAVElength*(CAVEheight-1))] = *cave_top;
      map[i+(CAVElength*(CAVEheight-2))] = *cave_top;
      map[i+(CAVElength*(CAVEheight-3))] = *cave_d;
    }
  for( i = 2 ; i < CAVEheight-2 ; i++ )
    {
      map[i*CAVElength] = *cave_top;
      map[i*CAVElength+1] = *cave_top;
      map[i*CAVElength+2] = *cave_top;  
      map[i*CAVElength+3] = *cave_l;
      map[i*CAVElength+15] = *cave_r;
      map[i*CAVElength+16] = *cave_top;
      map[i*CAVElength+17] = *cave_top;
      map[i*CAVElength+18] = *cave_top;
    }
  map[3+2*CAVElength] = *cave_ul;
  map[15+2*CAVElength] = *cave_ur;
  map[3+CAVElength*(CAVEheight-3)] = *cave_top;
  map[15+CAVElength*(CAVEheight-3)] = *cave_top;
  map[9+CAVElength*(CAVEheight-3)] = *cave_door;

}






/* movement*/
int cave_move_left(SDL_Rect Coordplayer)
{
  if( Coordplayer.x > 4*SPRITE_SIZE)
    {
      printf("left");
      return (Coordplayer.x+SPRITE_SIZE);
    }
  return Coordplayer.x;
}


int cave_move_right(SDL_Rect Coordplayer)
{
  if( Coordplayer.x < 10*SPRITE_SIZE )
    {
      printf("right");
      return (Coordplayer.x-SPRITE_SIZE);
    }
  return Coordplayer.x;
}


int cave_move_up(SDL_Rect Coordplayer)
{
  if( Coordplayer.y > 5*SPRITE_SIZE )
    {
      printf("up");
      return (Coordplayer.y-SPRITE_SIZE);
    }
  return Coordplayer.y;
}



int cave_move_down(SDL_Rect Coordplayer)
{
  if( Coordplayer.y < 10*SPRITE_SIZE )
    {
      printf("down");
      return (Coordplayer.y+SPRITE_SIZE);
    }
  return Coordplayer.y;
}








/*---- screen printing ----*/

void print_cave(SDL_Surface * CAVE)
{
  int i,j;
  for(i = 0 ; i < CAVEheight ; i++ )
    {
      for( j = 0 ; j < CAVElength ; j++ )
	{
	  rcGround.x = j * SPRITE_SIZE;
	  rcGround.y = i * SPRITE_SIZE;
	  SDL_BlitSurface(&CAVE[j+i*CAVElength], NULL, screen, &rcGround);
	}
    }
  SDL_UpdateRect(screen,0,0,0,0);
}



void print_player_cave(SDL_Rect *rcCoord)
{
  SDL_BlitSurface(sprite, &rcSrcSprite, screen, rcCoord);
  SDL_UpdateRect(screen,0,0,0,0);
}
