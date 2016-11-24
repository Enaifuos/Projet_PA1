#include "SDL.h"
#include <time.h>

#define SCREEN_WIDTH  608   
#define SCREEN_HEIGHT 480
#define SPRITE_SIZE    32
#define MAPlength      64
#define MAPheight      44
#define DAY_DURATION   10



//struct object in the map
typedef struct Objectmap Objmap;
struct Objectmap
{
  SDL_Surface objsprite;
  int objvalue;
};






/*---- usufull for the code ----*/
SDL_Event event;
Uint8 *keystate;
int colorkey, gameover, day;
int coordplayerx, coordplayery;
int stepcount, stepbfdie;
int SURVIVAL[8];


/*---- usefull for the printing ----*/

//Ground int he map
SDL_Surface * MAP; //[MAPlength][MAPheight]
SDL_Surface *screen, *temp, *sprite, *grass, *grass_night, *water, *water_night, *sand, *sand_night, *tree, *tree_night, *dirt, *dirt_night;
SDL_Surface *dirtg_d, *dirtg_d_night,  *dirtg_dl, *dirtg_dl_night, *dirtg_dr, *dirtg_dr_night, *dirtg_l, *dirtg_l_night, *dirtg_r, *dirtg_r_night, *dirtg_u, *dirtg_u_night, *dirtg_ul, *dirtg_ul_night,  *dirtg_ur, *dirtg_ur_night;
SDL_Surface *sandg_dl, *sandg_dl_night, *sandg_dr, *sandg_dr_night, *sandg_l, *sandg_l_night,*sandg_r,*sandg_r_night, *sandg_ul,*sandg_ul_night, *sandg_ur, *sandg_ur_night, *sandg_d, *sandg_d_night, *sandg_u, *sandg_u_night;
SDL_Surface *sandw_dl, *sandw_dl_night, *sandw_dr, *sandw_dr_night, *sandw_l, *sandw_l_night, *sandw_r, *sandw_r_night, *sandw_ul, *sandw_ul_night, *sandw_ur, *sandw_ur_night, *sandw_d, *sandw_d_night, *sandw_u, *sandw_u_night;
SDL_Surface *rockwall, *rockwall_night,  *rockwall_dl, *rockwall_dl_night, *rockwall_dr, *rockwall_dr_night, *rockwall_l, *rockwall_l_night, *rockwall_r, *rockwall_r_night, *rockwall_top, *rockwall_top_night, *rockwall_ucl, *rockwall_ucl_night, *rockwall_ucr, *rockwall_ucr_night, *rockwall_ul, *rockwall_ul_night, *rockwall_ur, *rockwall_ur_night, *rockwall_door, *rockwall_door_night, *bridge1, *bridge1_night, *bridge2, *bridge2_night;
SDL_Surface *cave_d, *cave_u, *cave_l, *cave_r,*cave_ur, *cave_ul, *cave_top, *cave_ground;
SDL_Surface *ladder1, *ladder2, *trap;
SDL_Rect rcSprite, rcSrcSprite, rcGround; 
SDL_Rect rcLadder, rcTrap;

//Object in the map
Objmap *OBJECTMAP; //[MAPlength][MAPheight]
SDL_Surface  *box, *apple, *letter, *empty_letter;
SDL_Rect rcObject, rcLetter, rcSrcLetter;

//pause menu & life
SDL_Rect rcPause, rcHeart, rcRedrect, rcHelp;
SDL_Surface *pause, *empty_heart, *heart, *redrect, *help_picture;
