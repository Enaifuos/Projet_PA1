#include "SDL.h"
#include "drawing.c"





/*-------------Prototypes------------*/



/* actions in the game */

    //check
void check_life(int step);
int check_win();
int check_move_ground(int x, int y);
int check_enter_rockwall(int x , int y );

    //movements
void move_down();
void move_up();
void move_right();
void move_left();


   //actions in the game
void you_lose();
void you_win();
void menu_pause();
void transition();
void intro();

   //help for the player
void stats();
void help();
void bag();


/* screen printing */
void print_player_life();
void print_player_letter();
void screen_printing_Gmove();
void screen_printing_Pmove();





/*---------------function-------------------*/




/*----------- check -----------*/

// A void to check if the player's life runs out 
void check_life(int step)
{
  if( step <= 0 )
    {
      you_lose();
    }
}


// A void to check if the player has win ( if all SURVIVAL lettes are collected )
int check_win()
{
  int i, res;
  res = 1;
  for( i = 0 ; i < 8 ; i++ )
    {
      res = res * SURVIVAL[i];
    }
  return res;
}




// Function returns 1 if we can walk on the ground type 
int check_move_ground(int x, int y)
{
  int allow = 0;

  //check if there is an object

  if( OBJECTMAP[x+y*MAPlength].objvalue )
    {
      if( OBJECTMAP[x+y*MAPlength].objvalue == 10) // apple
	{
	  stepbfdie += 30 ;
	}
      else if( OBJECTMAP[x+y*MAPlength].objvalue < 9 ) // letter
	{
	  SURVIVAL[(OBJECTMAP[x+y*MAPlength].objvalue)-1] = 1;
	}
      OBJECTMAP[x+y*MAPlength].objvalue = 0;
    }   

  allow = check_ground_MAP(x,y);

  if( check_enter_rockwall(x , y) )
    {
      transition();
      switch (y)
	{
	case 5: 
	  if( x == 14)
	    {
	      cave(OBJECTCAVE1);
	    }
	  else
	    {
	      cave(OBJECTCAVE2);
	    }
	  break;
	case 21:
	  cave(OBJECTCAVE3);
	  break;
	case 23:
	  cave(OBJECTCAVE4);
	  break;
	} 
      screen_printing_Pmove();
      allow = 0;
    }  

  return allow;
}


// Function returns 1 if the player can enter into the cave rockwall
int check_enter_rockwall(int x , int y )
{
  if( (y == 5 && (x == 14 || x == 25)) || (x == 12 && y == 21) || ( x == 25 && y == 23) )
    {
      SDL_Surface *enter;
      SDL_Rect rcEnter;
      rcEnter.x = 10;
      rcEnter.y = 240;
      temp = SDL_LoadBMP("ressources/enter.bmp");
      enter = SDL_DisplayFormat(temp);
      SDL_FreeSurface(temp);
      SDL_SetColorKey(enter, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
      SDL_BlitSurface(enter, NULL, screen, &rcEnter);
      SDL_Flip(screen);
      SDL_Delay(500);
      screen_printing_Pmove();
      SDL_FreeSurface(enter);
      return 1;
    }
  else
    {
      return 0;
    }
}





/*-----movement-----*/



void move_down()
{
  // set the animation fram for the movement
  rcSrcSprite.y = 0;
  if( coordplayery < (MAPheight-1) *  SPRITE_SIZE )
    {
      // check if the player can walk on the surface
      if(  check_move_ground(coordplayerx/SPRITE_SIZE , (coordplayery/SPRITE_SIZE)+1) )
	{
	  int i;
	  stepcount += 1;
	  stepbfdie -= 1;
	  if( coordplayery/SPRITE_SIZE > MAPheight - 9 || coordplayery/SPRITE_SIZE <= 6 )
	    {
	      for( i=0 ; i<SPRITE_SIZE ; i++ )
		{
		  rcSprite.y += 1;
		  coordplayery += 1;
		  if( i%8 == 0 && i != 0)
		    {
		      rcSrcSprite.y += SPRITE_SIZE+1;
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
		      rcSrcSprite.y += SPRITE_SIZE+1;
		    }
		  SDL_Delay(5);
		  screen_printing_Gmove();
		}
	      //  SDL_Delay(150);
	    }
	}
    }
  check_life(stepbfdie);
}



void move_up()
{
  rcSrcSprite.y = SPRITE_SIZE * 18;
  if(coordplayery >= SPRITE_SIZE)
    {
      if( check_move_ground( coordplayerx/SPRITE_SIZE , (coordplayery/SPRITE_SIZE) -1) )
	{
	  int i;
	  stepcount += 1;
	  stepbfdie -= 1;
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
  check_life(stepbfdie);
}


void move_right()
{
  rcSrcSprite.y = SPRITE_SIZE * 12;
  if( coordplayerx < (MAPlength-1) * SPRITE_SIZE )
    {
      if(  check_move_ground((coordplayerx/SPRITE_SIZE)+1 , coordplayery/SPRITE_SIZE))
	{
	  int i;
	  stepcount += 1;
	  stepbfdie -= 1;
	  if( coordplayerx/SPRITE_SIZE >= MAPlength - 10 || coordplayerx/SPRITE_SIZE <= 8 )
	    {
	      SDL_Delay(20);
	      for( i=0 ; i < SPRITE_SIZE ; i++ )
		{
		  rcSprite.x += 1;
		  coordplayerx += 1;
		  if( i%8 == 0 && i != 0)
		    {
		     rcSrcSprite.y += SPRITE_SIZE+1;
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
		     rcSrcSprite.y += SPRITE_SIZE+1;
		    }
		  SDL_Delay(5);
		  screen_printing_Gmove(); 
		}
	      //     SDL_Delay(150);
	    }	  
	}
    }
  check_life(stepbfdie);
}





void move_left()
{
  rcSrcSprite.y = SPRITE_SIZE * 6;
  if( coordplayerx >= SPRITE_SIZE )
    {
      if(  check_move_ground((coordplayerx/SPRITE_SIZE)-1 , coordplayery/SPRITE_SIZE) )
	{
	  int i;
	  stepcount += 1;
	  stepbfdie -= 1;
	  if( coordplayerx/SPRITE_SIZE >= MAPlength - 9  || coordplayerx/SPRITE_SIZE <= 9 ) 
	    {
	      SDL_Delay(20);
	      for( i=0 ; i < SPRITE_SIZE ; i++ )
		{
		  rcSprite.x -= 1;
		  coordplayerx -= 1;
		  if( i%8 == 0 && i != 0)
		    {
		     rcSrcSprite.y += SPRITE_SIZE+1;
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
		     rcSrcSprite.y += SPRITE_SIZE+1;
		    }
		  SDL_Delay(5);
		  screen_printing_Gmove(); 
		}
	      //	      SDL_Delay(150);
	    }
	}
    }
  check_life(stepbfdie);
}











/*--------action in the game---------*/


void you_lose()
{
  /* print a loosing picture */
  SDL_Surface *lose;
  temp = SDL_LoadBMP("ressources/you_lose.bmp");
  lose = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  SDL_SetColorKey(lose, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
  SDL_BlitSurface(lose, NULL, screen, NULL);
  SDL_Flip(screen);
  SDL_Delay(1800);

  /* restart the game */
  set_countletter();
  set_map(MAP, day);
  set_position();
  set_objectmap(OBJECTMAP);
  stepbfdie = 75;
  screen_printing_Gmove();

  SDL_FreeSurface(lose);
}


void you_win()
{
  SDL_Surface *win;
  temp = SDL_LoadBMP("ressources/you_win.bmp");
  win = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  SDL_SetColorKey(win, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
  SDL_BlitSurface(win, NULL, screen, NULL);
  SDL_Flip(screen);
  SDL_Delay(1800);

  /* restart the game */
  set_countletter();
  set_map(MAP, day);
  set_position();
  set_objectmap(OBJECTMAP);
  stepbfdie = 75;
  screen_printing_Gmove();


  SDL_FreeSurface(win);
}





void menu_pause()
{
  int menu = 1;
  int optionselect = 0;
  
  rcPause.x = 507;
  rcPause.y = 0;
  SDL_BlitSurface(pause, NULL, screen, &rcPause);

  rcRedrect.x = SCREEN_WIDTH - 88;
  rcRedrect.y = 16;
  SDL_BlitSurface(redrect, NULL, screen, &rcRedrect);

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
		  if( optionselect < 2 )
		    {
		      optionselect += 1;
		    }
		  break;
		case SDLK_UP:
		  if( optionselect > 0 )
		    {
		      optionselect -= 1;
		    }
		  break;
		case SDLK_RETURN:
		  switch (optionselect)
		    {
		    case 0:
		      bag();
		      break;
		    case 1 :
		      stats();
		      break;
		    case 2:
		      help();
		      break;
		    }
		  break;
		}
	      break;
	    }
	}
      switch (optionselect)
	{
	case 0:
	  rcRedrect.y = 16;
	  break;
	case 1 :
	  rcRedrect.y = 67;
	  break;
	case 2 :
	  rcRedrect.y = 117 ;
	  break;
	}
      //printing the menu
      SDL_BlitSurface(pause, NULL, screen, &rcPause);
      SDL_BlitSurface(redrect, NULL, screen, &rcRedrect);
      SDL_UpdateRect(screen,0,0,0,0);
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



void help()
{
  SDL_Surface *help_picture;
  SDL_Rect rcHelp;
  rcHelp.x = 10;
  rcHelp.y = SCREEN_HEIGHT - 240;
  temp = SDL_LoadBMP("ressources/help.bmp");
  help_picture = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  SDL_SetColorKey(help_picture, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
  SDL_BlitSurface(help_picture, NULL, screen, &rcHelp);
  SDL_Flip(screen);
  SDL_Delay(7200);
  screen_printing_Pmove();
  SDL_FreeSurface(help_picture);
}



void bag()
{

}









/*--------- screen printing ----------*/

void print_player_letter()
{
  int i;
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




void print_player_life()
{
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
}





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
	      draw_GroundGM(i, j, x, y);
	      if( OBJECTMAP[x+y*MAPlength].objvalue > 0  &&  OBJECTMAP[x+y*MAPlength].objvalue < 9 )
		{
		  rcSrcLetter.x = (OBJECTMAP[x+y*MAPlength].objvalue -1) * SPRITE_SIZE;
		  draw_ObjectGM(i, j, x, y, &rcSrcLetter);
		}
	      else if( OBJECTMAP[x+y*MAPlength].objvalue >= 9 )
		{
		  draw_ObjectGM(i, j, x, y, NULL);
		}
	    }
	}
      
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
	      draw_GroundGM(i, j, x, y);
	      if( OBJECTMAP[x+y*MAPlength].objvalue > 0  &&  OBJECTMAP[x+y*MAPlength].objvalue < 9 )
		{
		  rcSrcLetter.x = (OBJECTMAP[x+y*MAPlength].objvalue -1) * SPRITE_SIZE;
		  draw_ObjectGM(i, j, x, y, &rcSrcLetter);
		}
	      else if( OBJECTMAP[x+y*MAPlength].objvalue >= 9 )
		{
		  draw_ObjectGM(i, j, x, y, NULL);
		}
	    }
	}
    }
  /* draw the sprite */
  SDL_BlitSurface(sprite, &rcSrcSprite, screen, &rcSprite);

  /* draw the player lifepoint */
  print_player_life();
  
  /* draw the player letter found */
  print_player_letter();

  
  /* update the screen */
  SDL_UpdateRect(screen,0,0,0,0);
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
	  draw_GroundPM(i, j, x, y);
	  if( OBJECTMAP[x+y*MAPlength].objvalue > 0  &&  OBJECTMAP[x+y*MAPlength].objvalue < 9 )
	    {
	      rcSrcLetter.x = (OBJECTMAP[x+y*MAPlength].objvalue -1) * SPRITE_SIZE;
	      draw_ObjectPM(i, j, x, y, &rcSrcLetter);
	    }
	  else if( OBJECTMAP[x+y*MAPlength].objvalue >= 9 )
	    {
	      draw_ObjectPM(i, j, x, y, NULL);
	    }
	}
    }
  
  /* draw the sprite */
  SDL_BlitSurface(sprite, &rcSrcSprite, screen, &rcSprite);

  /* draw ther player lifepoint */
  print_player_life();

  /* draw the player letter found */
  print_player_letter();
  
  /* update the screen */
  SDL_UpdateRect(screen,0,0,0,0);
}


// Transition when the player enters into the rockwall cave
void transition()
{
  SDL_Surface *transit;
  SDL_Rect rcTransit;
  rcTransit.x = 0;
  rcTransit.y = 0;
  temp = SDL_LoadBMP("ressources/transition.bmp");
  transit = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  SDL_SetColorKey(transit, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
  SDL_BlitSurface(transit, NULL, screen, &rcTransit);
  SDL_Flip(screen);
  SDL_Delay(1600);
  screen_printing_Pmove();
  SDL_FreeSurface(transit);
}


// A void to set an intro picture 
void intro(){
  SDL_Surface *intro;
  SDL_Rect rcIntro ;
  temp = SDL_LoadBMP("ressources/intro.bmp");
  intro = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  rcIntro.x = 0 ;
  rcIntro.y = 0 ;
  SDL_BlitSurface(intro, NULL, screen,&rcIntro);
  SDL_Flip(screen);
  SDL_Delay(2500);
}
