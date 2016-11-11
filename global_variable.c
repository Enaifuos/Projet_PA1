#include "SDL.h"

#define SCREEN_WIDTH  608   
#define SCREEN_HEIGHT 480
#define SPRITE_SIZE    32
#define MAPlength      64
#define MAPheight      44


/*---- usufull for the code ----*/
SDL_Event event;
Uint8 *keystate;
int colorkey, gameover, stepcount, stepbfdie;
int coordplayerx, coordplayery;



/*---- usefull for the printing ----*/

//Ground int he map
SDL_Surface ** MAP; //[MAPlength][MAPheight]
SDL_Surface *screen, *temp, *sprite, *grass, *water, *sand, *tree, *dirt;
SDL_Surface *dirtg_d, *dirtg_dl, *dirtg_dr, *dirtg_l, *dirtg_r, *dirtg_u, *dirtg_ul, *dirtg_ur;
SDL_Surface *sandg_dl, *sandg_dr, *sandg_l, *sandg_r, *sandg_ul, *sandg_ur, *sandg_d, *sandg_u;
SDL_Surface *sandw_dl, *sandw_dr, *sandw_l, *sandw_r, *sandw_ul, *sandw_ur, *sandw_d, *sandw_u;
SDL_Surface *rockwall, *rockwall_dl, *rockwall_dr, *rockwall_l, *rockwall_r, *rockwall_top, *rockwall_ucl, *rockwall_ucr, *rockwall_ul, *rockwall_ur, *rockwall_door, *bridge1, *bridge2;
SDL_Surface *ladder1, *ladder2, *trap;
SDL_Rect rcSprite, rcSrcSprite, rcGround; 
SDL_Rect rcLadder, rcTrap;

//Object in the map
SDL_Surface **OBJECTMAP; //[MAPlength][MAPheight]
SDL_Surface  *box, *apple, *talismant;
SDL_Rect rcObject;

//pause menu & life
SDL_Rect rcPause, rcHeart;
SDL_Surface *pause, *empty_heart, *heart;
