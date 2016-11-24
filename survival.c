#include "SDL.h"
#include "fonction.c"










        /*  MAIN   */

int main(int argc, char* argv[])
{
  int i, j;
  unsigned int Time = 0 ;
  unsigned int TimePrev = 1;
  day = 1; // use to check if it's the day

  MAP = (SDL_Surface *)malloc(sizeof(SDL_Surface)*MAPlength*MAPheight);
  OBJECTMAP = (Objmap *)malloc(sizeof(Objmap)*MAPlength*MAPheight);
  
  set_countletter();

  /* initialize video system */
  SDL_Init(SDL_INIT_VIDEO);
  
  /* set the title bar */
  SDL_WM_SetCaption("Survival", "game survival");
  
  /* create window */
  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
  
  /* set keyboard repeat */
  SDL_EnableKeyRepeat(1000, 1000);
  
  /* load sprite */
  temp   = SDL_LoadBMP("ressources/playersheet/player.bmp");
  sprite = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  
  /* setup sprite colorkey and turn on RLE */
  colorkey = SDL_MapRGB(screen->format, 255, 0, 255);
  SDL_SetColorKey(sprite, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
  
        /* load grass */
  temp  = SDL_LoadBMP("ressources/grass.bmp");
  grass = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  
  temp = SDL_LoadBMP("ressources/grass_night.bmp");
  grass_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

	/* load water */
  temp = SDL_LoadBMP("ressources/water.bmp");
  water = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/water_night.bmp");
  water_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  

       /* load sand  */
  temp = SDL_LoadBMP("ressources/sand/sand.bmp");
  sand = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
 
  temp = SDL_LoadBMP("ressources/sand/sand_night.bmp");
  sand_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  
       /* load tree */
  temp = SDL_LoadBMP("ressources/tree.bmp");
  tree = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/tree_night.bmp");
  tree_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  /* load pause menu */
  temp = SDL_LoadBMP("ressources/pause_menu.bmp");
  pause = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  /* load the red rectangle */
  temp = SDL_LoadBMP("ressources/select_rectangle.bmp");
  redrect = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  
  /* setup heart colorkey and turn on RLE */
  colorkey = SDL_MapRGB(screen->format, 255, 0, 255);
  SDL_SetColorKey(redrect, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
  
      /* load dirt  */
  temp = SDL_LoadBMP("ressources/dirt/dirt.bmp");
  dirt = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  
  temp = SDL_LoadBMP("ressources/dirt/dirt_night.bmp");
  dirt_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  /* load the special sand with grass */
  temp = SDL_LoadBMP("ressources/sand/sandg_d.bmp");
  sandg_d = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandg_d_night.bmp");
  sandg_d_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandg_dl.bmp");
  sandg_dl = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandg_dl_night.bmp");
  sandg_dl_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandg_dr.bmp");
  sandg_dr = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandg_dr_night.bmp");
  sandg_dr_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);


  temp = SDL_LoadBMP("ressources/sand/sandg_l.bmp");
  sandg_l = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandg_l_night.bmp");
  sandg_l_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandg_r.bmp");
  sandg_r = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandg_r_night.bmp");
  sandg_r_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandg_u.bmp");
  sandg_u = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandg_u_night.bmp");
  sandg_u_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandg_ul.bmp");
  sandg_ul = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandg_ul_night.bmp");
  sandg_ul_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  
  temp = SDL_LoadBMP("ressources/sand/sandg_ur.bmp");
  sandg_ur = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandg_ur_night.bmp");
  sandg_ur_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  /* load the special sand with water */
  temp = SDL_LoadBMP("ressources/sand/sandw_d.bmp");
  sandw_d = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandw_d_night.bmp");
  sandw_d_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandw_dl.bmp");
  sandw_dl = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandw_dl_night.bmp");
  sandw_dl_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandw_dr.bmp");
  sandw_dr = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandw_dr_night.bmp");
  sandw_dr_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandw_l.bmp");
  sandw_l = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandw_l_night.bmp");
  sandw_l_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandw_r.bmp");
  sandw_r = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  
  temp = SDL_LoadBMP("ressources/sand/sandw_r_night.bmp");
  sandw_r_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandw_u.bmp");
  sandw_u = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandw_u_night.bmp");
  sandw_u_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  
  temp = SDL_LoadBMP("ressources/sand/sandw_ul.bmp");
  sandw_ul = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandw_ul_night.bmp");
  sandw_ul_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandw_ur.bmp");
  sandw_ur = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandw_ur_night.bmp");
  sandw_ur_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);


  /* load the special dirt */
  temp = SDL_LoadBMP("ressources/dirt/dirtg_d.bmp");
  dirtg_d = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/dirt/dirtg_d_night.bmp");
  dirtg_d_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);


  temp = SDL_LoadBMP("ressources/dirt/dirtg_dl.bmp");
  dirtg_dl = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/dirt/dirtg_dl_night.bmp");
  dirtg_dl_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/dirt/dirtg_dr.bmp");
  dirtg_dr = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/dirt/dirtg_dr_night.bmp");
  dirtg_dr_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  
  temp = SDL_LoadBMP("ressources/dirt/dirtg_l.bmp");
  dirtg_l = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/dirt/dirtg_l_night.bmp");
  dirtg_l_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);


  temp = SDL_LoadBMP("ressources/dirt/dirtg_r.bmp");
  dirtg_r = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/dirt/dirtg_r_night.bmp");
  dirtg_r_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/dirt/dirtg_u.bmp");
  dirtg_u = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/dirt/dirtg_u_night.bmp");
  dirtg_u_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  
  temp = SDL_LoadBMP("ressources/dirt/dirtg_ul.bmp");
  dirtg_ul = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  
  temp = SDL_LoadBMP("ressources/dirt/dirtg_ul_night.bmp");
  dirtg_ul_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/dirt/dirtg_ur.bmp");
  dirtg_ur = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/dirt/dirtg_ur_night.bmp");
  dirtg_ur_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  
      /* load the special rockwall (day) */
  temp = SDL_LoadBMP("ressources/rockwall/rockwall.bmp");
  rockwall = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/rockwall/rockwall_dl.bmp");
  rockwall_dl = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/rockwall/rockwall_dr.bmp");
  rockwall_dr = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/rockwall/rockwall_l.bmp");
  rockwall_l = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/rockwall/rockwall_r.bmp");
  rockwall_r = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/rockwall/rockwall_top.bmp");
  rockwall_top = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/rockwall/rockwall_ucl.bmp");
  rockwall_ucl = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/rockwall/rockwall_ucr.bmp");
  rockwall_ucr = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/rockwall/rockwall_ul.bmp");
  rockwall_ul = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  
  temp = SDL_LoadBMP("ressources/rockwall/rockwall_ur.bmp");
  rockwall_ur = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/rockwall/rockwall_door.bmp");
  rockwall_door = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);


  /* load the rockwall (night) */
  temp = SDL_LoadBMP("ressources/rockwall_night/rockwall_night.bmp");
  rockwall_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/rockwall_night/rockwall_dl_night.bmp");
  rockwall_dl_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/rockwall_night/rockwall_dr_night.bmp");
  rockwall_dr_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/rockwall_night/rockwall_l_night.bmp");
  rockwall_l_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  
  temp = SDL_LoadBMP("ressources/rockwall_night/rockwall_r_night.bmp");
  rockwall_r_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/rockwall_night/rockwall_top_night.bmp");
  rockwall_top_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/rockwall_night/rockwall_ucl_night.bmp");
  rockwall_ucl_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/rockwall_night/rockwall_ucr_night.bmp");
  rockwall_ucr_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  
  temp = SDL_LoadBMP("ressources/rockwall_night/rockwall_ul_night.bmp");
  rockwall_ul_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/rockwall_night/rockwall_ur_night.bmp");
  rockwall_ur_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/rockwall_night/rockwall_door_night.bmp");
  rockwall_door_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  /* load the bridge */
  temp = SDL_LoadBMP("ressources/bridge/bridge1.bmp");
  bridge1 = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/bridge/bridge2.bmp");
  bridge2 = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/bridge/bridge1_night.bmp");
  bridge1_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  
  temp = SDL_LoadBMP("ressources/bridge/bridge2_night.bmp");
  bridge2_night = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);


  /*load cave*/
  temp = SDL_LoadBMP("ressources/inside_rockwall/cave_u.bmp");
  cave_u = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/inside_rockwall/cave_d.bmp");
  cave_d = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/inside_rockwall/cave_l.bmp");
  cave_l = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/inside_rockwall/cave_r.bmp");
  cave_r = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/inside_rockwall/cave_ur.bmp");
  cave_ur = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/inside_rockwall/cave_ul.bmp");
  cave_ul = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/inside_rockwall/cave_top.bmp");
  cave_top = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  
  temp = SDL_LoadBMP("ressources/inside_rockwall/cave_ground.bmp");
  cave_ground = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  /* load the mystery_box */
  temp = SDL_LoadBMP("ressources/box/mystery_box.bmp");
  box = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  /* load the ladder */
  temp = SDL_LoadBMP("ressources/ladder/ladder1.bmp");
  ladder1 = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/ladder/ladder2.bmp");
  ladder2 = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  /* load the trap */
  temp = SDL_LoadBMP("ressources/trap/trap.bmp");
  trap = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  /* load the empty heart */
  temp = SDL_LoadBMP("ressources/empty_heart.bmp");
  empty_heart = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  
  /* setup empty heart colorkey and turn on RLE */
  colorkey = SDL_MapRGB(screen->format, 255, 0, 255);
  SDL_SetColorKey(empty_heart, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
  
  /* load the heart */
  temp = SDL_LoadBMP("ressources/heart.bmp");
  heart = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  
  /* setup heart colorkey and turn on RLE */
  colorkey = SDL_MapRGB(screen->format, 255, 0, 255);
  SDL_SetColorKey(heart, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);

  /* load the apple */
  temp = SDL_LoadBMP("ressources/apple.bmp");
  apple = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  
  /* setup apple colorkey and turn on RLE */
  colorkey = SDL_MapRGB(screen->format, 255, 0, 255);
  SDL_SetColorKey(apple, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
  
  
  /* load the insiede rockwall sprites */
  temp = SDL_LoadBMP("ressources/rockwall_inside.bmp");
  rockwall_inside = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  /* load the insiede rockwall sprites */
  temp = SDL_LoadBMP("ressources/Survival.bmp");
  letter = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  /* setup heart colorkey and turn on RLE */
  colorkey = SDL_MapRGB(screen->format, 255, 0, 255);
  SDL_SetColorKey(letter, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);

  /* load the empty letter */
  temp = SDL_LoadBMP("ressources/Survival_empty.bmp");
  empty_letter = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  /* setup heart colorkey and turn on RLE */
  colorkey = SDL_MapRGB(screen->format, 255, 0, 255);
  SDL_SetColorKey(empty_letter, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);

  /*set the letter fram */
  rcSrcLetter.x = 0;
  rcSrcLetter.y = 0;
  rcSrcLetter.w = SPRITE_SIZE;
  rcSrcLetter.h = SPRITE_SIZE;
  
  /* set the letter position */
  rcLetter.x = 0;
  rcLetter.y = 0;

  
  /* set the heart position */
  rcHeart.x = 0;
  rcHeart.y = 0;

  
  /* set the sprite frame */
  rcSrcSprite.x = 0;
  rcSrcSprite.y = 0;
  rcSrcSprite.h = SPRITE_SIZE;
  rcSrcSprite.w = SPRITE_SIZE;

  /* set sprite position */
  rcSprite.x = 9*SPRITE_SIZE;
  rcSprite.y = 7*SPRITE_SIZE;
  set_position();

  //set the step number you can do before die
  stepbfdie = 75;
  
  gameover = 0;
  
  /* set the MAP and objectMAP*/
  set_map(MAP, 1);
  set_objectmap(OBJECTMAP);
  
  screen_printing_Gmove();

  while (!gameover)
    {
      /* managing the time to set the day or the night */
      Time = SDL_GetTicks();
      Time = ((Time / 1000)/ DAY_DURATION) % 2; 
      if( !Time && Time != TimePrev)// && !inside_rock ) //day
	{
	  day = 1;
	  set_map(MAP, day);
	  screen_printing_Gmove();
	  TimePrev = Time;
	}
	else if( Time && Time != TimePrev)//  && !inside_rock) // night
	{
	  day = 0;
	  printf("1\n");
	  set_map(MAP, day);
	  printf("2\n");
	  screen_printing_Gmove();
	  TimePrev = Time;
	}

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
	  move_left();
	}
      if( keystate[SDLK_RIGHT] )
	{
	  move_right();
	}
      if( keystate[SDLK_UP] )
	{
	  move_up();
	}
      if( keystate[SDLK_DOWN] )
	{
	  move_down();
	}
      if( keystate[SDLK_p])
	{
	  menu_pause();
	}
      if( check_win() )
	{
	  you_win();
	}
    }
  
  
  
    /* clean the array */ 
  free(MAP);
  free(OBJECTMAP);

       /* clean up */
  SDL_FreeSurface(sprite);
  SDL_FreeSurface(grass);
  SDL_FreeSurface(grass_night);
  SDL_FreeSurface(water);
  SDL_FreeSurface(water_night);
  SDL_FreeSurface(sand);
  SDL_FreeSurface(dirt);
  SDL_FreeSurface(dirt_night);
  SDL_FreeSurface(pause);
  SDL_FreeSurface(rockwall);
  SDL_FreeSurface(rockwall_night);

  /* cleaning the special dirt */
  SDL_FreeSurface(dirtg_d);
  SDL_FreeSurface(dirtg_u);
  SDL_FreeSurface(dirtg_dr);
  SDL_FreeSurface(dirtg_dl);
  SDL_FreeSurface(dirtg_ur);
  SDL_FreeSurface(dirtg_ul);
  SDL_FreeSurface(dirtg_r);
  SDL_FreeSurface(dirtg_l);

  /* cleaning special sand */
  SDL_FreeSurface(sandw_d);
  SDL_FreeSurface(sandw_u);
  SDL_FreeSurface(sandw_dr);
  SDL_FreeSurface(sandw_dl);
  SDL_FreeSurface(sandw_ur);
  SDL_FreeSurface(sandw_ul);
  SDL_FreeSurface(sandw_r);
  SDL_FreeSurface(sandw_l);

  SDL_FreeSurface(sandg_d);
  SDL_FreeSurface(sandg_u);
  SDL_FreeSurface(sandg_dr);
  SDL_FreeSurface(sandg_dl);
  SDL_FreeSurface(sandg_ur);
  SDL_FreeSurface(sandg_ul);
  SDL_FreeSurface(sandg_r);
  SDL_FreeSurface(sandg_l);


  
  /* cleaning the special rockwall */
  SDL_FreeSurface(rockwall_dr);
  SDL_FreeSurface(rockwall_dl);
  SDL_FreeSurface(rockwall_top);
  SDL_FreeSurface(rockwall_r);
  SDL_FreeSurface(rockwall_l);
  SDL_FreeSurface(rockwall_ur);
  SDL_FreeSurface(rockwall_ul);
  SDL_FreeSurface(rockwall_ucr);
  SDL_FreeSurface(rockwall_ucl);
  SDL_FreeSurface(rockwall_door);

  SDL_FreeSurface(rockwall_dr_night);
  SDL_FreeSurface(rockwall_dl_night);
  SDL_FreeSurface(rockwall_top_night);
  SDL_FreeSurface(rockwall_r_night);
  SDL_FreeSurface(rockwall_l_night);
  SDL_FreeSurface(rockwall_ur_night);
  SDL_FreeSurface(rockwall_ul_night);
  SDL_FreeSurface(rockwall_ucr_night);
  SDL_FreeSurface(rockwall_ucl_night);
  SDL_FreeSurface(rockwall_door_night);

  /* cleaning the bridge */
  SDL_FreeSurface(bridge1);
  SDL_FreeSurface(bridge2);
  SDL_FreeSurface(bridge1_night);
  SDL_FreeSurface(bridge2_night);

  /* cleaning the cave */
  SDL_FreeSurface(cave_u);
  SDL_FreeSurface(cave_d);
  SDL_FreeSurface(cave_l);
  SDL_FreeSurface(cave_r);
  SDL_FreeSurface(cave_ul);
  SDL_FreeSurface(cave_ur);
  SDL_FreeSurface(cave_top);
  SDL_FreeSurface(cave_ground);
 

  /* cleaning the object */
  SDL_FreeSurface(box);
  SDL_FreeSurface(heart);
  SDL_FreeSurface(empty_heart);
  SDL_FreeSurface(redrect);
  SDL_FreeSurface(empty_letter);


  /* cleaning the ladder */
  SDL_FreeSurface(ladder1);
  SDL_FreeSurface(ladder2);

  /* cleaning the trap */
  SDL_FreeSurface(trap);

  /* cleaning inside the rockwall */
  SDL_FreeSurface(rockwall_inside);
 

  SDL_Quit();
  
  return 0;
}




