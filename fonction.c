#include "SDL.h"
#include "drawing.c"





/*-------------Prototypes------------*/



/* action in the game */

    //check
void check_life(int step);
int check_win();
int check_move_ground(int x, int y);
int check_enter_rockwall(int x , int y );

    //movement
void move_down();
void move_up();
void move_right();
void move_left();


   //action in the game
void you_lose();
void you_win();
void menu_pause();

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

void check_life(int step)
{
  if( step <= 0 )
    {
      //  you_lose();
    }
}



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




   
int check_move_ground(int x, int y)
{
  int allow = 0;
  SDL_Surface pos = MAP[x+y*MAPlength];

  //check if there is an object

  if( OBJECTMAP[x+y*MAPlength].objvalue )
    {
      if( OBJECTMAP[x+y*MAPlength].objvalue == 10)
	{
	  stepbfdie += 15 ;
	}
      if( OBJECTMAP[x+y*MAPlength].objvalue < 9 )
	{
	  SURVIVAL[(OBJECTMAP[x+y*MAPlength].objvalue)-1] = 1;
	}
      OBJECTMAP[x+y*MAPlength].objvalue = 0;
    }   

   
  //DAY
  if( day )
    {
      /* check if the player can go*/
      if( pos.pixels == (*grass).pixels || pos.pixels == (*dirt).pixels || pos.pixels == (*sand).pixels || pos.pixels == (*bridge1).pixels || pos.pixels == (*bridge2).pixels)
	{
	  allow = 1;
	}
       
      //special sandg
      else if( pos.pixels == (*sandg_u).pixels || pos.pixels == (*sandg_d).pixels || pos.pixels == (*sandg_dl).pixels || pos.pixels == (*sandg_dr).pixels || pos.pixels == (*sandg_ul).pixels || pos.pixels == (*sandg_ur).pixels || pos.pixels == (*sandg_l).pixels || pos.pixels == (*sandg_r).pixels)
	{
	  allow = 1;
	}
      //special sandw
      else if( pos.pixels == (*sandw_u).pixels || pos.pixels == (*sandw_d).pixels || pos.pixels == (*sandw_dl).pixels || pos.pixels == (*sandw_dr).pixels || pos.pixels == (*sandw_ul).pixels || pos.pixels == (*sandw_ur).pixels || pos.pixels == (*sandw_l).pixels || pos.pixels == (*sandw_r).pixels )
	{
	  allow = 1;
	}
      //special dirt
      else if( pos.pixels == (*dirtg_u).pixels || pos.pixels == (*dirtg_d).pixels || pos.pixels == (*dirtg_ul).pixels || pos.pixels == (*dirtg_ur).pixels || pos.pixels == (*dirtg_dl).pixels || pos.pixels == (*dirtg_dr).pixels || pos.pixels == (*dirtg_l).pixels || pos.pixels == (*dirtg_r).pixels )
	{
	  allow = 1;
	}
       //inside the rockwall 
      else if( pos.pixels == (*rockwall_inside).pixels ){
	allow = 1;
      }
    }





  //NIGHT
  else
    {
      if( pos.pixels == (*grass_night).pixels || pos.pixels == (*dirt_night).pixels || pos.pixels == (*sand_night).pixels || pos.pixels == (*bridge1_night).pixels || pos.pixels == (*bridge2_night).pixels)
	{
	  allow = 1;
	}
      else if( pos.pixels == (*sandg_u_night).pixels || pos.pixels == (*sandg_d_night).pixels || pos.pixels == (*sandg_dl_night).pixels || pos.pixels == (*sandg_dr_night).pixels || pos.pixels == (*sandg_ul_night).pixels || pos.pixels == (*sandg_ur_night).pixels || pos.pixels == (*sandg_l_night).pixels || pos.pixels == (*sandg_r_night).pixels)
	{
	  allow = 1;
	}
      //special sandw
      else if( pos.pixels == (*sandw_u_night).pixels || pos.pixels == (*sandw_d_night).pixels || pos.pixels == (*sandw_dl_night).pixels || pos.pixels == (*sandw_dr_night).pixels || pos.pixels == (*sandw_ul_night).pixels || pos.pixels == (*sandw_ur_night).pixels || pos.pixels == (*sandw_l_night).pixels || pos.pixels == (*sandw_r_night).pixels )
	{
	  allow = 1;
	}
      //special dirt
      else if( pos.pixels == (*dirtg_u_night).pixels || pos.pixels == (*dirtg_d_night).pixels || pos.pixels == (*dirtg_ul_night).pixels || pos.pixels == (*dirtg_ur_night).pixels || pos.pixels == (*dirtg_dl_night).pixels || pos.pixels == (*dirtg_dr_night).pixels || pos.pixels == (*dirtg_l_night).pixels || pos.pixels == (*dirtg_r_night).pixels )
	{
	  allow = 1;
	}
    }


  if( check_enter_rockwall(x , y) )
    {
      printf("entree de grotte\n");
      cave();
      allow = 0;
    }  

  //return allow;
  return allow;
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
  printf("**********\n YOU LOSE\n**********\n");
  
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
  printf("**********\n fin youlose\n**********\n");
}


void you_win()
{
  printf(" YOU WIN !!!!! \n\n");
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
  printf(" fin you win!!!! \n\n");

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
