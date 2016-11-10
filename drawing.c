#include "SDL.h"
#include "global_variable.c"

#define SPRITE_SIZE    32



 /*============ prototypes ==============*/

void draw_GroundPM(int i, int j, int x, int y);
void draw_GroundGM(int i, int j, int x, int y);








/*================== function ==================*/

void draw_GroundPM(int i, int j, int x, int y)
{
  rcGround.x = i * SPRITE_SIZE;
  rcGround.y = j * SPRITE_SIZE;
  SDL_BlitSurface(&MAP[x][y], NULL, screen, &rcGround);
}

void draw_GroundGM(int i, int j, int x, int y)
{  
  rcGround.x = i * SPRITE_SIZE - (coordplayerx % SPRITE_SIZE);
  rcGround.y = j * SPRITE_SIZE - (coordplayery % SPRITE_SIZE);
  SDL_BlitSurface(&MAP[x][y], NULL, screen, &rcGround);
}
