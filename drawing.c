#include "SDL.h"
#include "setting.c"

#define SPRITE_SIZE    32



 /*============ prototypes ==============*/

//MAP
void draw_GroundPM(int i, int j, int x, int y);
void draw_GroundGM(int i, int j, int x, int y);

//OBJECT
void draw_ObjectPM(int i,int j,int x,int y);
void draw_ObjectGM(int i,int j,int x,int y);







/*================== function ==================*/

//MAP
void draw_GroundPM(int i, int j, int x, int y)
{
  rcGround.x = i * SPRITE_SIZE;
  rcGround.y = j * SPRITE_SIZE;
  SDL_BlitSurface(&MAP[x+y*MAPlength], NULL, screen, &rcGround);
}

void draw_GroundGM(int i, int j, int x, int y)
{  
  rcGround.x = i * SPRITE_SIZE - (coordplayerx % SPRITE_SIZE);
  rcGround.y = j * SPRITE_SIZE - (coordplayery % SPRITE_SIZE);
  SDL_BlitSurface(&MAP[x+y*MAPlength], NULL, screen, &rcGround);
}



//OBJECT
void draw_ObjectPM(int i,int j,int x,int y)
{
  rcObject.x = i * SPRITE_SIZE;
  rcObject.y = j * SPRITE_SIZE;
  SDL_BlitSurface(&OBJECTMAP[x+y*MAPlength].objsprite, NULL, screen, &rcObject);
}


void draw_ObjectGM(int i,int j,int x,int y)
{
  rcObject.x = i * SPRITE_SIZE - (coordplayerx % SPRITE_SIZE);
  rcObject.y = j * SPRITE_SIZE - (coordplayery % SPRITE_SIZE);
  SDL_BlitSurface(&OBJECTMAP[x+y*MAPlength].objsprite, NULL, screen, &rcObject);
}
