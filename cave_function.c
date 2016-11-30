#include "setting.c"




/*----- prototypes -----*/
void cave(Objmap * objcave);
void set_cave(SDL_Surface * map);



void cave_move_left(SDL_Rect *Coordplayer, SDL_Rect *rcSrc, SDL_Surface *map, Objmap * objcave);
void cave_move_right(SDL_Rect *Coordplayer, SDL_Rect *rcSrc, SDL_Surface *map, Objmap * objcave);
void cave_move_up(SDL_Rect *Coordplayer, SDL_Rect *rcSrc, SDL_Surface *map, Objmap * objcave);
void cave_move_down(SDL_Rect *Coordplayer, SDL_Rect *rcSrc, SDL_Surface *map, Objmap * objcave);


void check_life_win();
void check_object_cave(int x, int y, Objmap * objcave);


void print_cave(SDL_Surface * CAVE, SDL_Rect * rcCoord, SDL_Rect * rcSrcCoord, Objmap * objcave);
void print_ground_cave(SDL_Surface * CAVE, Objmap * objcave);
void print_object_cave(int i,int j, SDL_Rect *rcSrc, Objmap * objcav);
void print_player_cave(SDL_Rect * rcCoord, SDL_Rect * rcSrcCoord);
void print_life_letter();




/*------ function -----*/

void cave(Objmap * objcave)
{
  /*set the player cave coord */
  SDL_Rect coordplayertemp;
  coordplayertemp.x = SPRITE_SIZE*9;
  coordplayertemp.y = SPRITE_SIZE*11;
  SDL_Rect rcSrcPcave;

  rcSrcPcave.x = 0;
  rcSrcPcave.y = SPRITE_SIZE * 18;
  rcSrcPcave.h = SPRITE_SIZE;
  rcSrcPcave.w = SPRITE_SIZE;

  /*set the cave */
  SDL_Surface * CAVE;
  CAVE = (SDL_Surface *)malloc(sizeof(SDL_Surface)*CAVElength*CAVEheight);
  set_cave(CAVE);
  print_cave(CAVE, &coordplayertemp, &rcSrcPcave, objcave);
  quit = 0;
  check_life_win();
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
	      quit = 1;
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
	  cave_move_left(&coordplayertemp, &rcSrcPcave, CAVE, objcave);
	}
      if( keystate[SDLK_RIGHT] )
	{
	  cave_move_right(&coordplayertemp, &rcSrcPcave, CAVE, objcave);
	}
      if( keystate[SDLK_UP] )
	{
	  cave_move_up(&coordplayertemp, &rcSrcPcave, CAVE, objcave);
	}
      if( keystate[SDLK_DOWN] )
	{
	  cave_move_down(&coordplayertemp, &rcSrcPcave, CAVE, objcave);
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
void cave_move_left(SDL_Rect *Coordplayer, SDL_Rect *rcSrc, SDL_Surface *map, Objmap * objcave)
{
  (*rcSrc).y = SPRITE_SIZE * 6;
  if( (*Coordplayer).x > 4*SPRITE_SIZE)
    {
      stepbfdie -= 1;
      check_object_cave((*Coordplayer).x/SPRITE_SIZE-1, (*Coordplayer).y/SPRITE_SIZE, objcave);
      int i;
      for( i = 0 ; i < SPRITE_SIZE ; i++)
	{
	  (*Coordplayer).x -= 1;
	  if( i%8 == 0 && i != 0)
	    {
	      (*rcSrc).y += SPRITE_SIZE+1;
	    }
	  SDL_Delay(5);
	  print_cave(map, Coordplayer, rcSrc, objcave);
	}
    }
  check_object_cave((*Coordplayer).x/SPRITE_SIZE, (*Coordplayer).y/SPRITE_SIZE, objcave);
  check_life_win();
}


void cave_move_right(SDL_Rect *Coordplayer, SDL_Rect *rcSrc, SDL_Surface *map, Objmap * objcave)
{
  (*rcSrc).y = SPRITE_SIZE * 12;
  if( (*Coordplayer).x < 14*SPRITE_SIZE )
    {
      stepbfdie -= 1;
      check_object_cave((*Coordplayer).x/SPRITE_SIZE+1, (*Coordplayer).y/SPRITE_SIZE, objcave);
      int i;
      for( i = 0 ; i < SPRITE_SIZE ; i++)
	{
	  (*Coordplayer).x += 1;
	  if( i%8 == 0 && i != 0)
	    {
	      (*rcSrc).y += SPRITE_SIZE+1;
	    }
	  SDL_Delay(5);
	  print_cave(map, Coordplayer, rcSrc, objcave);		  
	}
    }
  check_object_cave((*Coordplayer).x/SPRITE_SIZE, (*Coordplayer).y/SPRITE_SIZE, objcave);
  check_life_win();
}


void cave_move_up(SDL_Rect *Coordplayer, SDL_Rect *rcSrc, SDL_Surface *map, Objmap * objcave)
{
  (*rcSrc).y = SPRITE_SIZE * 18;
  if( (*Coordplayer).y > 3*SPRITE_SIZE )
    {
      stepbfdie -= 1;
      check_object_cave((*Coordplayer).x/SPRITE_SIZE, (*Coordplayer).y/SPRITE_SIZE-1, objcave);
      int i;
      for( i = 0 ; i < SPRITE_SIZE ; i++)
	{
	  (*Coordplayer).y -= 1;
	  if( i%8 == 0 && i != 0)
	    {
	      (*rcSrc).y += SPRITE_SIZE;
	    }
	  SDL_Delay(5);
	  print_cave(map, Coordplayer, rcSrc, objcave);
	}
    }
  check_object_cave((*Coordplayer).x/SPRITE_SIZE, (*Coordplayer).y/SPRITE_SIZE, objcave);
  check_life_win();
}



void cave_move_down(SDL_Rect *Coordplayer, SDL_Rect *rcSrc, SDL_Surface *map, Objmap * objcave)
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
	  int i;
	  check_object_cave((*Coordplayer).x/SPRITE_SIZE, (*Coordplayer).y/SPRITE_SIZE+1, objcave);
	  for( i = 0 ; i < SPRITE_SIZE ; i++)
	    {
	      (*Coordplayer).y += 1;
	      if( i%8 == 0 && i != 0)
		{
		  (*rcSrc).y += SPRITE_SIZE+1;
		}
	      SDL_Delay(5);
	      print_cave(map, Coordplayer, rcSrc, objcave);
	    }
	}
    }
  check_object_cave((*Coordplayer).x/SPRITE_SIZE, (*Coordplayer).y/SPRITE_SIZE, objcave);
  check_life_win();
}







void check_life_win()
{
  /*----- check the life -----*/
  if( stepbfdie <= 0 )
    {
      quit = 1;
    }

  /*------ check le letter ------*/
  int i, res;
  res = 1;
  for( i = 0 ; i < 8 ; i++ )
    {
      res = res * SURVIVAL[i];
    }
  if( res > 0 )
    {
      quit = 1;
    }
}




void check_object_cave(int x, int y, Objmap * objcave)
{
  if( objcave[x+y*CAVElength].objvalue > 0 && objcave[x+y*CAVElength].objvalue < 9)
    {
      SURVIVAL[(objcave[x+y*CAVElength].objvalue)-1] = 1;
      objcave[x+y*CAVElength].objvalue = 0;
    }
}






/*-------------- screen printing ----------------*/

void print_cave(SDL_Surface * CAVE, SDL_Rect * rcCoord, SDL_Rect * rcSrcCoord, Objmap * objcave)
{
  print_ground_cave(CAVE, objcave);
  print_player_cave(rcCoord, rcSrcCoord);
  print_life_letter();
  SDL_UpdateRect(screen,0,0,0,0);
}



void print_ground_cave(SDL_Surface * CAVE, Objmap * objcave)
{
  int i,j;
  for(i = 0 ; i < CAVEheight ; i++ )
    {
      for( j = 0 ; j < CAVElength ; j++ )
	{
	  rcGround.x = j * SPRITE_SIZE;
	  rcGround.y = i * SPRITE_SIZE;
	  SDL_BlitSurface(&CAVE[j+i*CAVElength], NULL, screen, &rcGround);
	  if( objcave[i+j*CAVElength].objvalue > 0 && objcave[i+j*CAVElength].objvalue < 9 )
	    {
	      printf("on a un objet\n");
	      rcSrcLetter.x = 0;
	      print_object_cave(i, j, &rcSrcLetter, objcave);
	    }
	}
    }
} 



void print_object_cave(int i,int j, SDL_Rect *rcSrc, Objmap * objcav)
{
  rcObject.x = i * SPRITE_SIZE;
  rcObject.y = j * SPRITE_SIZE;
  SDL_BlitSurface(letter, rcSrc, screen, &rcObject);
  SDL_UpdateRect(screen,0,0,0,0);
}




void print_player_cave(SDL_Rect *rcCoord, SDL_Rect * rcSrcCoord)
{
  SDL_BlitSurface(sprite, rcSrcCoord, screen, rcCoord);
}





void print_life_letter()
{
  /*----- life -----*/
  int i;
  rcHeart.x = 1 ;
  rcHeart.y = SCREEN_HEIGHT - 20;
  SDL_BlitSurface(heart, NULL, screen, &rcHeart);
  for( i = 0 ; i < 4 ; i++ )
    {
      rcHeart.x += 20 ;
      if( stepbfdie/10 >= i+1 )
	{
	  SDL_BlitSurface(heart, NULL, screen, &rcHeart);
	}
      else
	{
	  SDL_BlitSurface(empty_heart, NULL, screen, &rcHeart);
	}
    }



  /*----- letter ------*/
  rcSrcLetter.x = 0;
  rcSrcLetter.y = 0;
  rcSrcLetter.w = SPRITE_SIZE;
  rcSrcLetter.h = SPRITE_SIZE;
  
  rcLetter.x = SCREEN_WIDTH-1 -256;
  rcLetter.y = SCREEN_HEIGHT-1 -SPRITE_SIZE;

  if( SURVIVAL[0] )
    {
      SDL_BlitSurface(letter, &rcSrcLetter, screen, &rcLetter);
    }
  else
    {
      SDL_BlitSurface(empty_letter, &rcSrcLetter, screen, &rcLetter);
    }
  for(i = 0; i < 7 ; i++)
    {
      rcSrcLetter.x += SPRITE_SIZE;
      rcLetter.x += SPRITE_SIZE;
      if( SURVIVAL[i+1] )
	{
	  SDL_BlitSurface(letter, &rcSrcLetter, screen, &rcLetter);
	}
      else
	{
	  SDL_BlitSurface(empty_letter, &rcSrcLetter, screen, &rcLetter);
	}     
    }
}
