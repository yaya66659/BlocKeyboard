
/*gcc src/*.c -o bin/SDL2prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 
-lSDL2_image -lSDL2_ttf*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdarg.h>

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>


#include"headers/GestionDeLaSDL.h"
#include"headers/fct.h"
#include "headers/gestionBoutons.h"

int main(int argc, char *argv[])
{

    short choix = 0;
    int retScanfChoixMenu = -1;
    booleen launch = FAUX;

    booleen sdl2 = FAUX;
    booleen ttf = FAUX;

    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_ExitWithError("erreure SDL_init video",sdl2, ttf);
    }

    sdl2 = VRAI;

    if(TTF_Init() != 0)
    {
        SDL_ExitWithError("erreure ttf_init",sdl2, ttf);
    }
        ttf = VRAI;

    SDL_Window * window = NULL;
    SDL_Renderer * renderer = NULL;
    
    if(SDL_CreateWindowAndRenderer(WINDOW_W, WINDOW_H, 0, &window, &renderer) != 0)
    {
        SDL_ExitWithError("erreure SDL_CreateWindowAndRenderer",sdl2,ttf);
    }

   

    if(window == NULL)
    {
        SDL_ExitWithError("erreure window = NULL", VRAI,VRAI);
    }

     SDL_SetWindowTitle(window, "Bloc KeyBoard");

    if(renderer == NULL){
        SDL_DestroyWindowsRenderreeAndTextures(window,NULL,NULL);
        SDL_ExitWithError("erreure renderer = NULL",sdl2,ttf);
    }

    SDL_Surface *surfaceImageFond = NULL;
    SDL_Texture * textureImageFond = NULL;

    surfaceImageFond = IMG_Load("images/fond.jpg");
    if(surfaceImageFond == NULL)
    {
        SDL_DestroyWindowsRenderreeAndTextures(window, renderer, NULL, NULL);
        SDL_ExitWithError("error surfaceImageFond = NULL",sdl2,ttf);
    }
    textureImageFond = SDL_CreateTextureFromSurface(renderer, surfaceImageFond);
     SDL_FreeSurface(surfaceImageFond);

    if(textureImageFond == NULL)
    {
        SDL_DestroyWindowsRenderreeAndTextures(window,renderer, NULL,NULL);
        SDL_ExitWithError("error textureImageFond",sdl2,ttf);
    }
               
    SDL_Rect rectImageFond;

    if(SDL_QueryTexture(textureImageFond, NULL, NULL,&rectImageFond.w, &
rectImageFond.h) != 0)
{
 SDL_DestroyWindowsRenderreeAndTextures(window, renderer, textureImageFond,
NULL);
 SDL_ExitWithError("error SDL_QueryTexture textureImageFond",sdl2,ttf);
}
   
   rectImageFond.x = (WINDOW_W-rectImageFond.w)/2;
   rectImageFond.y = (WINDOW_H-rectImageFond.h)/2;
 
            

   if(SDL_RenderCopy(renderer, textureImageFond,NULL, &rectImageFond ) != 0){
     SDL_DestroyWindowsRenderreeAndTextures(window, renderer, textureImageFond, NULL);
 SDL_ExitWithError("error SDL_RenderCopy textureImageFond",sdl2,ttf);
   }

SDL_RenderPresent(renderer);

                /***BOUTON CLAVIER VEROUILLER*******/
   

   SDL_Texture * textureVerouiller = NULL;
   SDL_Rect rectVerouiller;
   rectVerouiller.w = 200;
   rectVerouiller.h = 100;
   rectVerouiller.x = (WINDOW_W-rectVerouiller.w)/2; 
    rectVerouiller.y = (WINDOW_H-rectVerouiller.h)/4;

        textureVerouiller = creationEtAffichageBoutton(renderer,rectVerouiller, NOIR, "Verouiller Clavier");

    if(textureVerouiller == NULL)
    {
        SDL_DestroyWindowsRenderreeAndTextures(window,renderer, textureImageFond,NULL);
SDL_ExitWithError("error creationEtAffichageBoutton > textureVerouiller",sdl2,ttf);
    }

                    /***BOUTON CLAVIER DEVEROUILLER*******/
     SDL_Texture * textureDeVerouiller = NULL;
 SDL_Rect rectDeVerouiller;
 rectDeVerouiller.w = 200;
 rectDeVerouiller.h = 100;
 rectDeVerouiller.x = (WINDOW_W-rectDeVerouiller.w)/2; 
  rectDeVerouiller.y = (WINDOW_H-rectDeVerouiller.h)/2;

          textureDeVerouiller = creationEtAffichageBoutton(renderer,rectDeVerouiller, NOIR, 
"Deverouiller Clavier");

    if(textureDeVerouiller == NULL)
    {
        SDL_DestroyWindowsRenderreeAndTextures(window,renderer, textureImageFond,textureVerouiller, NULL);
SDL_ExitWithError("error creationEtAffichageBoutton > textureDeVerouiller",sdl2,ttf);
    }

/*****************BOUTON AVERTISSEMENTS VEROUILLE BLOQUE LE CLAVIER ET LE PAVER TACTIL D'UN PC PORTABLE MEME APRES ARRET OU REDEMARAGE VOUS POUREZ TOUJOUR UTILISER DES PERIPHERIQUES EXTERNES****************** */
SDL_Texture *textureAvertiement = NULL;
SDL_Rect rectAvertissement;
rectAvertissement.w =(WINDOW_W-200);
rectAvertissement.h =80;
rectAvertissement.x =(WINDOW_W-rectAvertissement.w)/2; 
rectAvertissement.y = (WINDOW_H-rectAvertissement.h)/1.1;

    textureAvertiement = creationEtAffichageBoutton(renderer, rectAvertissement, BLANC, "!!Les commandes ce lances sans demande de confirmation!!");

    if(textureAvertiement == NULL)
    {
                SDL_DestroyWindowsRenderreeAndTextures(window,renderer, textureImageFond,
textureVerouiller, textureDeVerouiller, NULL);
SDL_ExitWithError("error creationEtAffichageBoutton > textureAvertiement",sdl2,
ttf);
    }






/***************BOUCLE DE GESTION DES EVENEMENT*************************/

   SDL_Event event;
    if(eventBoucle(event, rectVerouiller, rectDeVerouiller, window, renderer, textureImageFond) != VRAI){
        SDL_DestroyWindowsRenderreeAndTextures(window, renderer, textureImageFond, textureVerouiller, textureDeVerouiller,textureAvertiement, NULL);
        SDL_ExitWithError("error event boucle", sdl2, ttf);

    }


     /****************LIBERATION DE LA MEMOIRE************************************************/                                             
    
         SDL_DestroyWindowsRenderreeAndTextures(window, renderer, 
textureImageFond, textureVerouiller, textureDeVerouiller, textureAvertiement,NULL);
    
    
    

    TTF_Quit();
    SDL_Quit();



return 0;
}