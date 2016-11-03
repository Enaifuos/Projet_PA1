#include "SDL.h"

#define SCREEN_WIDTH  608   
#define SCREEN_HEIGHT 480
#define SPRITE_SIZE    32
#define MAPlength      64
#define MAPheight      44


int ** MAP;//[MAPlength][MAPheight];
SDL_Surface *screen, *temp, *sprite, *grass, *water, *sand, *tree, *dirt, *pause;
SDL_Surface *dirtg_d, *dirtg_dl, *dirtg_dr, *dirtg_l, *dirtg_r, *dirtg_u, *dirtg_ul, *dirtg_ur;
SDL_Surface *sandg_dl, *sandg_dr, *sandg_l, *sandg_r, *sandg_top, *sandg_ucl, *sandg_ucr, *sandg_ul, *sandg_ur;
SDL_Surface *sandw_dl, *sandw_dr, *sandw_l, *sandw_r, *sandw_top, *sandw_ucl, *sandw_ucr, *sandw_ul, *sandw_ur;
SDL_Surface *rockwall, *rockwall_dl, *rockwall_dr, *rockwall_l, *rockwall_r, *rockwall_top, *rockwall_ucl, *rockwall_ucr, *rockwall_ul, *rockwall_ur;
SDL_Rect rcSprite, rcSrcSprite, rcGrass, rcWater, rcTree, rcDirt, rcSand, rcRock, rcPause;
SDL_Event event;
Uint8 *keystate;
int colorkey, gameover, stepcount;
int coordplayerx, coordplayery;
