#include "SDL.h"

#define SCREEN_WIDTH  608   
#define SCREEN_HEIGHT 480
#define SPRITE_SIZE    32
#define MAPlength      64
#define MAPheight      44
#define NumbTalis       6
#define DAY_DURATION  50

/*---- usufull for the code ----*/
SDL_Event event;
Uint8 *keystate;
int colorkey, gameover, stepcount, stepbfdie;
int coordplayerx, coordplayery;
int countertalismant;


/*---- usefull for the printing ----*/

//Ground int he map
SDL_Surface ** MAP; //[MAPlength][MAPheight]
SDL_Surface *screen, *temp, *sprite, *grass, *grass_night, *water, *water_night, *sand, *tree, *tree_night, *dirt;
SDL_Surface *dirtg_d, *dirtg_dl, *dirtg_dr, *dirtg_l, *dirtg_r, *dirtg_u, *dirtg_ul, *dirtg_ur;
SDL_Surface *sandg_dl, *sandg_dr, *sandg_l, *sandg_r, *sandg_ul, *sandg_ur, *sandg_d, *sandg_u;
SDL_Surface *sandw_dl, *sandw_dr, *sandw_l, *sandw_r, *sandw_ul, *sandw_ur, *sandw_d, *sandw_u;
SDL_Surface *rockwall, *rockwall_night,  *rockwall_dl, *rockwall_dl_night, *rockwall_dr, *rockwall_dr_night, *rockwall_l, *rockwall_l_night, *rockwall_r, *rockwall_r_night, *rockwall_top, *rockwall_top_night, *rockwall_ucl, *rockwall_ucl_night, *rockwall_ucr, *rockwall_ucr_night, *rockwall_ul, *rockwall_ul_night, *rockwall_ur, *rockwall_ur_night, *rockwall_door, *rockwall_door_night, *bridge1, *bridge1_night, *bridge2, *bridge2_night;
SDL_Surface *ladder1, *ladder2, *trap;
SDL_Rect rcSprite, rcSrcSprite, rcGround; 
SDL_Rect rcLadder, rcTrap;

//Object in the map
SDL_Surface **OBJECTMAP; //[MAPlength][MAPheight]
SDL_Surface  *box, *apple, *talismant;
SDL_Rect rcObject;

//pause menu & life
SDL_Rect rcPause, rcHeart, rcRedrect;
SDL_Surface *pause, *empty_heart, *heart, *redrect;
