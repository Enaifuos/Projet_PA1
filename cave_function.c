#include "setting.c"
#define CAVElength 19
#define CAVEheight 15








/*----- prototypes -----*/
void cave();
void set_cave(SDL_Surface * map);



void cave_move_left(SDL_Rect *Coordplayer, SDL_Rect *rcSrc, SDL_Surface *map);
void cave_move_right(SDL_Rect *Coordplayer, SDL_Rect *rcSrc, SDL_Surface *map);
void cave_move_up(SDL_Rect *Coordplayer, SDL_Rect *rcSrc, SDL_Surface *map);
void cave_move_down(SDL_Rect *Coordplayer, SDL_Rect *rcSrc, SDL_Surface *map);


void print_cave(SDL_Surface * CAVE, SDL_Rect * rcCoord, SDL_Rect * rcSrcCoord);
void print_ground_cave(SDL_Surface * CAVE);
void print_player_cave(SDL_Rect * rcCoord, SDL_Rect * rcSrcCoord);






/*------ function -----*/

void cave()
{
  /*set the player cave coord */
  SDL_Rect coordplayertemp;
  coordplayertemp.x = SPRITE_SIZE*9;
  coordplayertemp.y = SPRITE_SIZE*7;
  SDL_Rect rcSrcPcave;

  rcSrcPcave.x = 0;
  rcSrcPcave.y = 0;
  rcSrcPcave.h = SPRITE_SIZE;
  rcSrcPcave.w = SPRITE_SIZE;

  /*set the cave */
  SDL_Surface * CAVE;
  CAVE = (SDL_Surface *)malloc(sizeof(SDL_Surface)*CAVElength*CAVEheight);
  set_cave(CAVE);
  print_ground_cave(CAVE);
  print_player_cave(&coordplayertemp, &rcSrcPcave);
  quit = 0;
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
	  cave_move_left(&coordplayertemp, &rcSrcPcave, CAVE);
	}
      if( keystate[SDLK_RIGHT] )
	{
	  cave_move_right(&coordplayertemp, &rcSrcPcave, CAVE);
	}
      if( keystate[SDLK_UP] )
	{
	  cave_move_up(&coordplayertemp, &rcSrcPcave, CAVE);
	}
      if( keystate[SDLK_DOWN] )
	{
	  cave_move_down(&coordplayertemp, &rcSrcPcave, CAVE);
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
void cave_move_left(SDL_Rect *Coordplayer, SDL_Rect *rcSrc, SDL_Surface *map)
{
  (*rcSrc).y = SPRITE_SIZE * 6;
  if( (*Coordplayer).x > 4*SPRITE_SIZE)
    {
      stepbfdie -= 1;
      printf("left\n");
      int i;
      for( i = 0 ; i < SPRITE_SIZE ; i++)
	{
	  (*Coordplayer).x -= 1;
	  if( i%8 == 0 && i != 0)
	    {
	      (*rcSrc).y += SPRITE_SIZE+1;
	    }
	  SDL_Delay(5);
	  print_cave(map, Coordplayer, rcSrc);
	}
    }
}


void cave_move_right(SDL_Rect *Coordplayer, SDL_Rect *rcSrc, SDL_Surface *map)
{
  (*rcSrc).y = SPRITE_SIZE * 12;
  if( (*Coordplayer).x < 14*SPRITE_SIZE )
    {
      stepbfdie -= 1;
      printf("right\n");
      int i;
      for( i = 0 ; i < SPRITE_SIZE ; i++)
	{
	  (*Coordplayer).x += 1;
	  if( i%8 == 0 && i != 0)
	    {
	      (*rcSrc).y += SPRITE_SIZE+1;
	    }
	  SDL_Delay(5);
	  print_cave(map, Coordplayer, rcSrc);		  
	}
    }
}


void cave_move_up(SDL_Rect *Coordplayer, SDL_Rect *rcSrc, SDL_Surface *map)
{
  (*rcSrc).y = SPRITE_SIZE * 18;
  if( (*Coordplayer).y > 3*SPRITE_SIZE )
    {
      stepbfdie -= 1;
      printf("up\n");
      int i;
      for( i = 0 ; i < SPRITE_SIZE ; i++)
	{
	  (*Coordplayer).y -= 1;
	  if( i%8 == 0 && i != 0)
	    {
	      (*rcSrc).y += SPRITE_SIZE;
	    }
	  SDL_Delay(5);
	  print_cave(map, Coordplayer, rcSrc);
	}
    }
}



void cave_move_down(SDL_Rect *Coordplayer, SDL_Rect *rcSrc, SDL_Surface *map)
{
  if( (*Coordplayer).x == SPRITE_SIZE*9 && (*Coordplayer).y == SPRITE_SIZE*11 )
    {
      stepbfdie -= 1;
      quit = 1;
    }
  else
    {
      (*rcSrc).y = 0;
      if( (*Coordplayer).y < 11*SPRITE_SIZE )
	{
	  printf("down\n");
	  int i;
	  for( i = 0 ; i < SPRITE_SIZE ; i++)
	    {
	      (*Coordplayer).y += 1;
	      if( i%8 == 0 && i != 0)
		{
		  (*rcSrc).y += SPRITE_SIZE+1;
		}
	      SDL_Delay(5);
	      print_cave(map, Coordplayer, rcSrc);
	    }
	}
    }
}








/*---- screen printing ----*/

void print_cave(SDL_Surface * CAVE, SDL_Rect * rcCoord, SDL_Rect * rcSrcCoord)
{
  print_ground_cave(CAVE);
  print_player_cave(rcCoord, rcSrcCoord);
}



void print_ground_cave(SDL_Surface * CAVE)
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
}



void print_player_cave(SDL_Rect *rcCoord, SDL_Rect * rcSrcCoord)
{
  SDL_BlitSurface(sprite, rcSrcCoord, screen, rcCoord);
  SDL_UpdateRect(screen,0,0,0,0);
}
