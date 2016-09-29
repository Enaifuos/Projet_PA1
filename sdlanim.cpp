// Aourinmouche Soufiane && Simon Lucas 
//Projet Méthodologie : Bubble Shooter 
#include "SDL.h"
#include <math.h> /* pour faire le sin cos */
#include <stdbool.h> /* pour faire le booléen move */
#include <time.h>




#define SCREEN_WIDTH  720
#define SCREEN_HEIGHT 540
#define SPRITE_SIZE   32
#define SPRITE_SIZE_H 187
#define SPRITE_SIZE_V 157
#define SPRITE_CENTER 94
#define SPRITE_DIV 48
#define BUB_SIZE 40
#define VELOCITY 1
#define PI 3.14159265359
#define BOARD_RIGHT 520
#define BOARD_LEFT 200
#define BOARD_BOTTOM 422
#define BOARD_TOP  33 
#define BUB_NX 8
#define BUB_NY 11
#define NUM_COLORS 8
#define ecart_lignes 35
#define VITESSE_FORME 60


int connect=1;
int gameover;
int num_fleche=0;   // counter that gives the number  of the arrow
int current_col;    // around randomly selected which sets the color of the bubble
int current_col_init;  // around randomly selected which sets the color of the bubbles in the 3 first lines initialising the game 
int bub_array[BUB_NY+1][BUB_NX]; // first array
int bub_array_centers[BUB_NY+1][BUB_NX][2];// second array
int bub_connected_component[BUB_NY][BUB_NX];// third array
int i=0; 
int j=0;
int ii,jj; //  counters named similary as the previous so as we don't confuse
float  dx , dy , distance ;/* source and destination rectangles */
int cases_vides=0; // number of empty cells in table to detect gameover if case_vides==88 (11*8) (bub_array is all empty)
int compteur_bulle = 0;
int countP = 0;
int stock;
int score = 0;
int colorkey;
int count;
int nb_bombe = 19 ; 


float x=SCREEN_WIDTH/2- BUB_SIZE/2,y=SCREEN_HEIGHT - SPRITE_SIZE_V -BUB_SIZE/2 +  SPRITE_CENTER;
float theta; // the angle to calculate the direction
float dir_x=0,dir_y=0;


bool move=false; // true bool if we click UP 
bool collide=false;  // collide detection with function (collision)
bool debut = true; // true at the beginning of the game
bool one_added;



SDL_Rect rcSrc, rcSprite,bub_pos, bub_src,dir,bub_dessine,rcGrass,rcMenu;

bool collision(int x1,int y1, int x2, int y2){
  int distx=fabs(x1-x2); // distance (x1,x2) 
  int disty=fabs(y1-y2); // distance (y1,y2)
  int a=sqrt((distx*distx)+(disty*disty));
  if((a<(BUB_SIZE)) {
    return true;
  }
  return false;
}


void HandleEvent(SDL_Event event)
{
  switch (event.type) {
    /* close button clicked */                
  case SDL_QUIT:
    gameover = 1;
    break;
			
    /* handle the keyboard */
  case SDL_KEYDOWN:
  
    switch (event.key.keysym.sym) {
      
    case SDLK_b : 
	
      if(nb_bombe>0){  /* pressing "b" , we  enter in  the loop several times ( not a constant number but apparently that varies in the range [ 3,7] ) , therefore , the counter decrements several times , we  have chosen to initialize the counter in 18 to ensure at least 3 bombs, and maximum 4*/ 
	if( ( ( bub_pos.x==SCREEN_WIDTH/2- BUB_SIZE/2 ) && (bub_pos.y==SCREEN_HEIGHT - SPRITE_SIZE_V -BUB_SIZE/2 +  SPRITE_CENTER ) )|| ( bub_pos.y==0 ) ){
	  // the second condition , to not change the bubble into a bombe while launching it 
	  current_col = 8;
	  nb_bombe = nb_bombe - 1 ;
  	   
	}	   
      }
      break ;
    case SDLK_q:
      gameover = 1;
      
      break;
    case SDLK_LEFT:
				 
      /*Limite à gauche*/
      if (rcSrc.y<500){
	break;}

      rcSrc.y -= SPRITE_SIZE_V  ;
      if (num_fleche>0)
	num_fleche-=1;
      // when you click the left direction , you go up the image of the pitcher , so the y decrements ( right arrow respectively)		  
      break;

     


    case SDLK_RIGHT:
      /*Limite à droite*/
      if (rcSrc.y>6500){
	break;}
		  
      rcSrc.y  += SPRITE_SIZE_V;
      if (num_fleche<45)
	num_fleche+=1;

      break;

			       
		
    case SDLK_SPACE:
		
				     
      move = true;
				    			       
					 
				      
      // I added this condition for not moving the bubble by pressing the SPACE after having launched once 
      if( ( ( bub_pos.x==SCREEN_WIDTH/2- BUB_SIZE/2 ) && (bub_pos.y==SCREEN_HEIGHT - SPRITE_SIZE_V -BUB_SIZE/2 +  SPRITE_CENTER ) )|| ( bub_pos.y==0 ) )
	{  theta = PI-( num_fleche+2 )*( PI/48 );
				      
	  dir_x = cos( theta )*VELOCITY;
	  dir_y = sin( theta )*VELOCITY;
	}
      break;
    }
    break;
  }
}




int main(int argc, char* argv[])
{
  SDL_Surface *screen, *temp, *sprite, *grass, *bub[NUM_COLORS],*background,*menu; /* i changed   *bub with another array *bub[num_colors] */
  SDL_Event event;

  srand( time ( NULL ) );
  /* initialize SDL */
  SDL_Init(SDL_INIT_VIDEO);

  /* set the title bar */
  SDL_WM_SetCaption("BUBBLE SHOOTER", "SDL Animation"); /*J'ai changé le title bar de SDL Animation au nom du jeu*/

  /* create window */
  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);

  /* set keyboard repeat */ /* to adjust velocity */ /* to keep the finger on the button */
  SDL_EnableKeyRepeat(10,10); /* c'était initialisé à 0,0*/


  /*load game over */
 
  temp=SDL_LoadBMP("gameov.bmp");
  background= SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  /* load menu */
  temp = SDL_LoadBMP("menu.bmp");
  menu = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

 


   

  /* load sprite */
  temp   = SDL_LoadBMP("k.jpg");
  sprite = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  /* setup sprite colorkey and turn on RLE */
  colorkey = SDL_MapRGB(screen->format, 255, 0, 255);
  SDL_SetColorKey(sprite, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);

  /* load grass */
	
  temp  = SDL_LoadBMP("frame_1p-1.bmp");
  grass = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  /* setup sprite colorkey and turn on RLE */
  SDL_SetColorKey(grass, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);

  /* set sprite position */
  rcSprite.x = SCREEN_WIDTH/2 - SPRITE_SIZE_H/2; /* Width of the window minus the width of the launcher, like that the G spot ( center ) of the launcher is in the axis  */
  rcSprite.y = SCREEN_HEIGHT - SPRITE_SIZE_V; /* window's length minus launcher's length */ 

  /* set animation frame */
  rcSrc.x = 0;
  rcSrc.y = 0; 
  rcSrc.w = 187; 
  rcSrc.h = 157; 


  /*fill the array with balle's pictures  */
  temp   = SDL_LoadBMP("bub_blue.bmp");
  bub[0] = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
	
  temp = SDL_LoadBMP("bub_black.bmp");
  bub[1] = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("bub_green.bmp");
  bub[2] = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("bub_orange.bmp");
  bub[3] = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("bub_purple.bmp");
  bub[4] = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("bub_red.bmp");
  bub[5] = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("bub_white.bmp");
  bub[6] = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("bub_yellow.bmp");
  bub[7] = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  temp = SDL_LoadBMP("bomb.bmp");
  bub[8] = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);


  /* setup bub colorkey and turn on RLE */
  for(i=0;i<9;i++)
    SDL_SetColorKey(bub[i], SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
	
  /*set animation bull*/
	
  bub_src.x = 0;
  bub_src.y = 0;
  bub_src.w = 40;
  bub_src.h = 40;

  /* Bubble's initial postion */
  bub_pos.x = SCREEN_WIDTH/2- BUB_SIZE/2;
  bub_pos.y = SCREEN_HEIGHT - SPRITE_SIZE_V -BUB_SIZE/2 +  SPRITE_CENTER;
	
	
  gameover = 0;
	
  /* message pump */

  /*arrays initialisation */
  for(j=0;j<BUB_NY+1;j++){
    for(i=0;i<BUB_NX-j%2;i++){
      bub_array[j][i] = 0;	      
      bub_array_centers[j][i][0]=BOARD_LEFT+i*BUB_SIZE+(BUB_SIZE/2)+(j%2)*BUB_SIZE/2;
      bub_array_centers[j][i][1]=BOARD_TOP+j*ecart_lignes+(BUB_SIZE/2);
      if (j<BUB_NY){ /*Pas besoin de la ligne ajoutée*/
	bub_connected_component[j][i]=0;
      }
    }
  }

  /*first 3 lines */
  for(j=0;j<3;j++){
    for(i=0;i<BUB_NX-j%2;i++){
      current_col_init=0;
      while (current_col_init==0){
	current_col_init = rand()%(NUM_COLORS);
	bub_array[j][i] = current_col_init;
      }
    }
  }

  
   
  while (!gameover)
    {
		
      /* Affichage de l'image de debut */
      if (debut){
	rcMenu.x = 0;
	rcMenu.y = 0;
	SDL_BlitSurface(menu, NULL, screen, &rcMenu);
	SDL_Flip(screen);
	SDL_Delay(2000);
	debut = false;
      }

      /* look for an event */
      if (SDL_PollEvent(&event)) {
	HandleEvent(event);			
      }
      
	



      /* draw black rectangle */

      SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
      

      /* draw the grass */
		
      rcGrass.x = 0 ;
      rcGrass.y = 0 ;
      SDL_BlitSurface(grass, NULL, screen, &rcGrass);
      
	

      /* draw the sprite */
		
      SDL_BlitSurface(sprite, &rcSrc, screen, &rcSprite);


      /* draw the bubble*/
		
	        
      SDL_BlitSurface(bub[current_col],&bub_src,screen,&bub_pos);	


      /*** launching the bubble ***/
      if (move){
	x += dir_x;
	y -= dir_y;
	bub_pos.x = (int)x;
	bub_pos.y = (int)y;
		 
      }
	       
    
      if(bub_pos.x < BOARD_LEFT){      // rebound left (limit)
	bub_pos.x = 2*BOARD_LEFT - bub_pos.x;
	dir_x = -dir_x;
      }
      
      if(bub_pos.x>BOARD_RIGHT - BUB_SIZE){ // rebound right (limit )
	bub_pos.x = 2*BOARD_RIGHT - bub_pos.x - 2*BUB_SIZE ;
	dir_x = -dir_x ;
      }
    
      if (bub_pos.y<BOARD_TOP){ // top limit
	bub_pos.y = BOARD_TOP;
	move = false;
			 
       		 
      }

      /* collade detection */
      collide = false;
      for(j=0;j<BUB_NY+1;j++){
	for(i=0;i<BUB_NX-j%2;i++){
	  if(bub_array[j][i]>0){
	    if(collision(bub_array_centers[j][i][0],bub_array_centers[j][i][1],bub_pos.x+BUB_SIZE/2,bub_pos.y+BUB_SIZE/2)){
	      collide = true;
	    }
	  }
	}
      }

      
      if (collide){
	one_added = true;
	count = 1;
	

	// réintialisation du tableau connected_component a 0 pour le calcul de toute les bulles connectésdes bulles de m^eme couleur connecté
	for(j=0;j<BUB_NY;j++){
	  for(i=0;i<BUB_NX-j%2;i++){
	    bub_connected_component[j][i]=0;
	  }
	}


	/* find the nearest empty */
	for(j=0;j<BUB_NY+1;j++){
	  for(i=0;i<BUB_NX-j%2;i++){
	    if(bub_array[j][i]==0){
	      dx = abs(bub_array_centers[j][i][0] - (bub_pos.x + (BUB_SIZE/2)));
	      dy = abs(bub_array_centers[j][i][1] - (bub_pos.y + (BUB_SIZE/2)));
	      distance = sqrt((dx*dx) + (dy*dy));
	      if(distance <= (BUB_SIZE/2)){
		bub_array[j][i] = current_col + 1; 
		bub_connected_component[j][i]=1;
	      }
	    }
	  }
	}


	/* Eclater les bulles */
	while (one_added) {
   	  one_added = false;
	  

   	  for(j=0;j<BUB_NY;j++){ 
   	    for(i=0;i<BUB_NY-j%2;i++){ 
   	      if(bub_array[j][i]==current_col+1  && bub_connected_component[j][i] == 0) {
		for(jj=0;jj<BUB_NY;jj++){
		  for(ii=0;ii<BUB_NX-jj%2;ii++){
		    if(bub_connected_component[jj][ii] == 1){
		      dx = bub_array_centers[jj][ii][0] - bub_array_centers[j][i][0];
		      dy = bub_array_centers[jj][ii][1] - bub_array_centers[j][i][1];
		      distance = sqrt ( (dx*dx) + (dy*dy));
		      if(distance<=sqrt(2)*BUB_SIZE){
			bub_connected_component[j][i]=1;
			one_added = true ;
			count ++ ;
		      }
		    }
		  }
		}
	      }
	    }
	  }
	}
	if(count >2){
	  for(j=0;j<BUB_NY;j++){
	    for(i=0;i<BUB_NX-j%2;i++){
	      if(bub_connected_component[j][i] == 1){
		bub_array[j][i] = 0;
		score ++ ;
		printf("\nVotre score :%d\n",score);
	      }
	    }
	  }
	}

       	if(countP >2){
	  for(i=0;i<BUB_NY;i++){
	    if(bub_connected_component[0][i] == 1){
	      bub_array[0][i] = 0;
	      score ++ ;
	      printf("\nVotre score :%d\n",score);
	    }
	  }
	}

	//connected componenet reintialisation to count connected bubbles
	for(j=0;j<BUB_NX;j++){
	  for(i=0;i<BUB_NY-j%2;i++){
	    bub_connected_component[j][i] = 0;
	  }
	}

	/* burst bubbles without conexion */
	for(i=0;i<BUB_NY;i++){ 
	  if (bub_array[0][i]>0){
	    bub_connected_component[0][i] = 1;
	  }
	}
	      
	for(j=0;j<BUB_NY;j++){ 
	  for(i=0;i<BUB_NY-j%2;i++){ 
	    if(bub_array[j][i] > 0  && bub_connected_component[j][i] == 1) {
	      for(jj=0;jj<BUB_NY;jj++){
		for(ii=0;ii<BUB_NX-jj%2;ii++){
		  if(bub_array[jj][ii] > 0) {
		    dx = bub_array_centers[jj][ii][0] - bub_array_centers[j][i][0];
		    dy = bub_array_centers[jj][ii][1] - bub_array_centers[j][i][1];
		    distance = sqrt ( (dx*dx) + (dy*dy));
		    if(distance<=sqrt(2)*BUB_SIZE){
		      bub_connected_component[jj][ii]=1;
		    }
		  }
		}
	      }
	    }
	  }
	}

	for(j=0;j<BUB_NY;j++){ 
	  for(i=0;i<BUB_NY-j%2;i++){ 
	    if (bub_connected_component[j][i]==0){
	      bub_array[j][i] = 0;
	    }
	  }
	}




	move = false;
	dir_x = 0.00;
	dir_y = 0.00;
	x = SCREEN_WIDTH/2-BUB_SIZE/2;
	y = SCREEN_HEIGHT-SPRITE_SIZE_V-BUB_SIZE/2+SPRITE_CENTER;
	bub_pos.x = x;
	bub_pos.y = y;
	current_col = rand()%(NUM_COLORS);  // to have bulls with different colors 
	

      } // Fin if (collide)


      // Gameover if there is collide between the last line and the next one 
      collide = false;
      for(i=0;i<BUB_NX-1;i++){
	if (bub_array[11][i]>0){
	  printf("\nGameover\n");
	  printf("\n **** VOTRE SCORE FINAL EST : %d ****\n",score);
	  gameover = 1;
	  SDL_BlitSurface(background,NULL,screen,NULL);
	  SDL_Flip(screen);
	  SDL_Delay(5000);
	}
      }


      
     
      if (gameover == 0){
		        
	//drawing bulls on the top	
	if ((bub_pos.y<=BOARD_TOP)){	
	  if (bub_pos.x<(BOARD_LEFT+BUB_SIZE/2)){      //premier maillage
	    bub_pos.x = BOARD_LEFT;
	    bub_array[0][0]=current_col+1;
	    dir_x = 0.00;
	    dir_y = 0.00;
	    //  After we designed the bubble, it must return to its original position ( center - launcher ) 
	    x = SCREEN_WIDTH/2- BUB_SIZE/2;
	    y = SCREEN_HEIGHT - SPRITE_SIZE_V -BUB_SIZE/2 +  SPRITE_CENTER;
			     						
				    
	    
	  }
	  for (i=0;i<6;i++){
	    if ((bub_pos.x>BOARD_LEFT+(BUB_SIZE+i*2*BUB_SIZE)/2) && (bub_pos.x<BOARD_LEFT+(3*BUB_SIZE+i*2*BUB_SIZE)/2)){    //second maillage
	      bub_pos.x = BOARD_LEFT+BUB_SIZE;
	      bub_array[0][i+1] = current_col+1;
	      dir_x=0.00;
	      dir_y=0.00;
	      // After we designed the bubble, it must return to its original position ( center - launcher ) 
	      x = SCREEN_WIDTH/2- BUB_SIZE/2;
	      y = SCREEN_HEIGHT - SPRITE_SIZE_V -BUB_SIZE/2 +  SPRITE_CENTER;
	    }				
	  }				
				    
         
	  if (bub_pos.x>BOARD_LEFT+(13/2)*BUB_SIZE){
	    bub_pos.x = BOARD_LEFT+7*BUB_SIZE;
	    bub_array[0][7] = current_col+1;
	    dir_x = 0.00;
	    dir_y = 0.00;
	    x = SCREEN_WIDTH/2-BUB_SIZE/2;
	    y = SCREEN_HEIGHT-SPRITE_SIZE_V-BUB_SIZE/2+SPRITE_CENTER;
	  }
	}

	/* Mouvement in bubbles */
	compteur_bulle = compteur_bulle + 1;
	if (compteur_bulle%VITESSE_FORME == 0){
	  compteur_bulle = 0;
	  bub_src.y = (bub_src.y + BUB_SIZE)%960;
	}


	// print all bubbles
	for(j=0;j<BUB_NY;j++){
	  for (i=0;i<BUB_NX-j%2;i++){
	    if (bub_array[j][i]>=1){
	      bub_dessine.x = bub_array_centers[j][i][0]-(BUB_SIZE/2);
	      bub_dessine.y = bub_array_centers[j][i][1]-(BUB_SIZE/2);
	      SDL_BlitSurface(bub[bub_array[j][i]-1],&bub_src,screen,&bub_dessine);
	    }
	  }
	}


	// If a mesh contains a bubble, then bub_array [j ] [i] > 1, the same box in bub_connected_component receives 1

	for(j=0;j<BUB_NY;j++){
	  for(i=0;i<BUB_NX-j%2;i++){
	    if(bub_array[j][i] == 9){
	      for(ii=0;ii<BUB_NY;ii++){
		for(jj=j;jj<BUB_NY;jj++){ // We burst all the lines after the bomb's one
		  bub_array[ii][i] = 0;
		}
	      }
	    }
	    if(bub_array[j][i]>0){
	      bub_connected_component[j][i] = 1;
	    }
	  }
	}
	


	
	        
		
	/* update the screen */
	SDL_UpdateRect(screen, 0, 0, 0, 0);		
      }

    }
  
  
  /* clean up */
  SDL_FreeSurface(sprite);
  SDL_FreeSurface(grass); 
  SDL_Quit();


 
  return 0;
    
}



	 
