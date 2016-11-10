#include "SDL.h"
#include "fonction.c"










        /*  MAIN   */

int main(int argc, char* argv[])
{
  int i, j;
   MAP = creerTable(MAPlength , MAPheight );
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
  
	/* load water */
  temp = SDL_LoadBMP("ressources/water.bmp");
  water = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

       /* load sand  */
  temp = SDL_LoadBMP("ressources/sand/sand.bmp");
  sand = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  
       /* load tree */
  temp = SDL_LoadBMP("ressources/tree.bmp");
  tree = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  /* load pause menu */
  temp = SDL_LoadBMP("ressources/pause_menu.bmp");
  pause = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  
      /* load dirt  */
  temp = SDL_LoadBMP("ressources/dirt/dirt.bmp");
  dirt = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  
  /* load the special sand with grass */
  temp = SDL_LoadBMP("ressources/sand/sandg_d.bmp");
  sandg_d = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandg_dl.bmp");
  sandg_dl = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandg_dr.bmp");
  sandg_dr = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandg_l.bmp");
  sandg_l = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandg_r.bmp");
  sandg_r = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandg_u.bmp");
  sandg_u = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandg_ul.bmp");
  sandg_ul = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandg_ur.bmp");
  sandg_ur = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);


  /* load the special sand with water */
  temp = SDL_LoadBMP("ressources/sand/sandw_d.bmp");
  sandw_d = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandw_dl.bmp");
  sandw_dl = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandw_dr.bmp");
  sandw_dr = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandw_l.bmp");
  sandw_l = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandw_r.bmp");
  sandw_r = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandw_u.bmp");
  sandw_u = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandw_ul.bmp");
  sandw_ul = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/sand/sandw_ur.bmp");
  sandw_ur = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);


  /* load the special dirt */
  temp = SDL_LoadBMP("ressources/dirt/dirtg_d.bmp");
  dirtg_d = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/dirt/dirtg_dl.bmp");
  dirtg_dl = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/dirt/dirtg_dr.bmp");
  dirtg_dr = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/dirt/dirtg_l.bmp");
  dirtg_l = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/dirt/dirtg_r.bmp");
  dirtg_r = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/dirt/dirtg_u.bmp");
  dirtg_u = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/dirt/dirtg_ul.bmp");
  dirtg_ul = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/dirt/dirtg_ur.bmp");
  dirtg_ur = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);


      /* load the special rockwall */
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

  /* load the bridge */
  temp = SDL_LoadBMP("ressources/bridge/bridge1.bmp");
  bridge1 = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("ressources/bridge/bridge2.bmp");
  bridge2 = SDL_DisplayFormat(temp);
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

  /* set the sprite frame */
  rcSrcSprite.x = 0;
  rcSrcSprite.y = 0;
  rcSrcSprite.h = SPRITE_SIZE;
  rcSrcSprite.w = SPRITE_SIZE;

  /* set sprite position */
  rcSprite.x = 9*SPRITE_SIZE;
  rcSprite.y = 7*SPRITE_SIZE;
  set_position();


  gameover = 0;
  
  /* set the MAP */
  printf("ok");
  set_map();
  
  //printing the map terminal
  /* for(i=0;i<SCREEN_HEIGHT /SPRITE_SIZE;i++) */
  /*   { */
  /*     for(j=0;j<SCREEN_WIDTH /SPRITE_SIZE;j++) */
  /* 	{ */
  /* 	  printf("%d ",MAP[j][i]); */
  /* 	} */
  /*     printf("\n"); */
  /*   } */

  screen_printing_Gmove();

  /* message pump */
  while (!gameover)
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
	      switch (event.key.keysym.sym) {
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
    }
  
  /* clean the array */ 
  //freeTable(MAP);

       /* clean up */
  SDL_FreeSurface(sprite);
  SDL_FreeSurface(grass);
  SDL_FreeSurface(water);
  SDL_FreeSurface(sand);
  SDL_FreeSurface(dirt);
  SDL_FreeSurface(pause);
  SDL_FreeSurface(rockwall);

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

  /* cleaning the bridge */
  SDL_FreeSurface(bridge1);
  SDL_FreeSurface(bridge2);

  /* cleaning the mystery box */
  SDL_FreeSurface(box);

  /* cleaning the ladder */
  SDL_FreeSurface(ladder1);
  SDL_FreeSurface(ladder2);
 
  SDL_Quit();
  
  return 0;
}


