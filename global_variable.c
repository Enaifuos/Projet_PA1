#include "SDL.h"

#define SCREEN_WIDTH  608   
#define SCREEN_HEIGHT 480
#define SPRITE_SIZE    32
#define MAPlength      64
#define MAPheight      44


int MAP[MAPlength][MAPheight];
SDL_Surface *screen, *temp, *sprite, *grass, *water, *sand, *tree, *dirt, *rockwall, *pause, *rockwall_dl, *rockwall_dr, *rockwall_l, *rockwall_r, *rockwall_top, *rockwall_ucl, *rockwall_ucr, *rockwall_ul, *rockwall_ur;
SDL_Rect rcSprite, rcSrcSprite, rcGrass, rcWater, rcTree, rcDirt, rcSand, rcRock, rcPause;
SDL_Event event;
Uint8 *keystate;
int colorkey, gameover, stepcount;
int coordplayerx, coordplayery;
