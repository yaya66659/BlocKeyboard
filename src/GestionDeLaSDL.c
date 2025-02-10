#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdarg.h>

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include "headers/GestionDeLaSDL.h"
#include "headers/gestionBoutons.h"
#include"headers/fct.h"


/**************SDL GESTION DESTROY AND QUIT*************************/




void SDL_ExitWithError(char *message, booleen sdl2, booleen ttf){


SDL_Log("%s > %s\n", message, SDL_GetError());
    
    if(ttf != FAUX)
    TTF_Quit();
    
    if(sdl2 != FAUX)
    SDL_Quit();

    exit(EXIT_FAILURE);

}
void SDL_DestroyWindowsRenderreeAndTextures(SDL_Window * w, SDL_Renderer *r, SDL_Texture *t, ...){

     va_list listArgs;
SDL_Texture * AgrsTexture;
va_start(listArgs, t);
while ((AgrsTexture = va_arg(listArgs, SDL_Texture*)) != NULL)
{
 SDL_DestroyTexture(AgrsTexture);
}

       if(t != NULL)
    SDL_DestroyTexture(t); 
    

    if(r != NULL)
    SDL_DestroyRenderer(r);



    if(w != NULL)
SDL_DestroyWindow(w);
}
/*************CLEAR RENDERER***************************************/
SDL_Texture* ReCreateTextureFond(SDL_Window* window, SDL_Renderer *renderer, SDL_Rect rectFond, SDL_Texture * textureFond){





    SDL_Surface *surfaceImageFond = NULL;
    SDL_Texture * textureImageFond = NULL;

    surfaceImageFond = IMG_Load("images/fond.jpg");
    if(surfaceImageFond == NULL)
    {
        SDL_DestroyWindowsRenderreeAndTextures(window, renderer, NULL, NULL);
        SDL_ExitWithError("error surfaceImageFond = NULL",VRAI,VRAI);
    }
    textureImageFond = SDL_CreateTextureFromSurface(renderer, surfaceImageFond);
     SDL_FreeSurface(surfaceImageFond);

    if(textureImageFond == NULL)
    {
        SDL_DestroyWindowsRenderreeAndTextures(window,renderer, NULL,NULL);
        SDL_ExitWithError("error textureImageFond",VRAI,VRAI);
    }
               
    SDL_Rect rectImageFond;

    if(SDL_QueryTexture(textureImageFond, NULL, NULL,&rectImageFond.w, &
rectImageFond.h) != 0)
{
 SDL_DestroyWindowsRenderreeAndTextures(window, renderer, textureImageFond,
NULL);
 SDL_ExitWithError("error SDL_QueryTexture textureImageFond",VRAI,VRAI);
}
   
   rectImageFond.x = (WINDOW_W-rectImageFond.w)/2;
   rectImageFond.y = (WINDOW_H-rectImageFond.h)/2;
 
            

   if(SDL_RenderCopy(renderer, textureImageFond,NULL, &rectImageFond ) != 0){
     SDL_DestroyWindowsRenderreeAndTextures(window, renderer, textureImageFond, NULL);
 SDL_ExitWithError("error SDL_RenderCopy textureImageFond",VRAI,VRAI);
   }

SDL_RenderPresent(renderer);
   
   
   

    return textureFond;


}

/****************************************************************/

/*******************BOUCLE ENVENT***************************/

booleen eventBoucle(SDL_Event event, SDL_Rect rectVerouiller, SDL_Rect rectDeverouille,SDL_Window *w,SDL_Renderer * r, SDL_Texture * t){

    booleen launchEvent  = VRAI;
    booleen dedansVerouiller = FAUX;
    booleen dedansDeverouiller = FAUX;
    booleen redemarerD = FAUX;
    booleen redemarerV = FAUX;
   
   
  

    SDL_Texture * textureDeverouillerMouseEnter = NULL;
    SDL_Texture * textureVerouillerMouseDehors = NULL;

        SDL_Texture * textureVerouillerMouseEnter = NULL;
    SDL_Texture * textureDeverouillerMouseDehors = NULL;
    SDL_Rect rectFond;
    rectFond.x =(WINDOW_W-rectFond.w)/2;
    rectFond.y = (WINDOW_H-rectFond.h)/2;
    
    do/*boucle de fenetre lanche*/
    {
        while (SDL_PollEvent(&event))/*boucle detection d'evenement*/
            {

         
         
         
         
         
                switch (event.type)
                {
                    /*------Quitter en cilquent sur la croix rouge de la fenetre*/
                case SDL_QUIT:
                    launchEvent = FAUX;
                    break;
                    break;
                    /*------------------*/
                case SDL_MOUSEMOTION:
               
/*-----------------------------------si dans bouton verouiller---------------------*/
                if(mouseEnterButon(event.motion.x, event.motion.y, rectVerouiller) == VRAI)
                {
                     dedansVerouiller = VRAI;
                   
            
            
             
                }   /*-----------------------------------si dehors bouton verouiller---------------------*/
                else if (mouseEnterButon(event.motion.x,event.motion.y, rectVerouiller) == FAUX) {
                  
                                    
                        dedansVerouiller = FAUX;
                        
                }
/*-----------------------------------si dans bouton Deverouiller---------------------*/
                if(mouseEnterButon(event.motion.x, event.motion.y, rectDeverouille) == VRAI )
                {

                    dedansDeverouiller = VRAI;
                    
                }/*-----------------------------------si dehors bouton Deverouiller---------------------*/
                else if(mouseEnterButon(event.motion.x, event.motion.y, rectDeverouille) == FAUX)
                {

                   
                   

                     dedansDeverouiller = FAUX;
                   


                }

                                                    /*---------------Clear du rendu et recration texture de fond et 
boutons si la sourie 
passe sur ces derniers------------------------------------------------------*/
                                              
         if(dedansVerouiller == VRAI)
            {
                
                
               /* if(SDL_RenderClear(r) != 0)
                  return FAUX;*/
               

                     /*if((t = ReCreateTextureFond(w,r,rectFond, t )) == NULL)
                      { 
                          return FAUX;
                      }*/
                 // SDL_RenderPresent(r);








                textureVerouillerMouseEnter = creationEtAffichageBoutton(r, rectVerouiller,
                BLANC,"Verouiller Clavier" );
                if(textureVerouillerMouseEnter == NULL)
                return FAUX;
            }

    

    
            
            if(dedansVerouiller == FAUX)  
                     {      

                           
                           
                                     /*if(SDL_RenderClear(r) != 0)
                                return FAUX;/*
                            
                            
                            
                    
                           /* if((t = ReCreateTextureFond(w,r,rectFond, t )) == NULL)
                                { 
                                    return FAUX;
                                }
                            //SDL_RenderPresent(r);*/
                       
                       
                    
                       textureVerouillerMouseDehors = creationEtAffichageBoutton(r,rectVerouiller,NOIR,
                       "Verouiller Clavier" ); 
                       if(textureVerouillerMouseDehors == NULL )
                      return FAUX;
                    
            
               }

   
           


          
             if (dedansDeverouiller == VRAI)
             {
               
                            
                            
                                /*if(SDL_RenderClear(r) != 0)
                                         return FAUX;*/

                            
                             
                    
                         /*if((t = ReCreateTextureFond(w,r,rectFond, t )) == NULL)
                          { 
                              return FAUX;
                          }*/
                     // SDL_RenderPresent(r); 
  textureDeverouillerMouseEnter = creationEtAffichageBoutton(r, rectDeverouille , BLANC,"Deverouiller Clavier" );
          if(textureDeverouillerMouseEnter == NULL)
          return FAUX;
             }

    
    
             if(dedansDeverouiller == FAUX)
             {
                
                           
                           
                               /*if(SDL_RenderClear(r) != 0)
                                        return FAUX;*/
                            
                          

                         /*if((t = ReCreateTextureFond(w,r,rectDeverouille, t )) == NULL) 
                             { 
                                 return FAUX;
                             }*/
                        // SDL_RenderPresent(r);
                    textureDeverouillerMouseDehors = creationEtAffichageBoutton(r, rectDeverouille, 
NOIR, "Deverouille Clavier" ); 

                    if(textureDeverouillerMouseDehors == NULL )
                   return FAUX;
             }

              SDL_RenderPresent(r);          
             
                   break;

        /*------------------Si on clique sur un des bouton excute commandfe systeme verouillage, deverouillage et redemarrage */
                   case SDL_MOUSEBUTTONDOWN:
                   if(event.button.button == SDL_BUTTON_LEFT)
                   {
                       if(dedansVerouiller == VRAI && event.button.clicks >= 2 )
                     {

                        if(verouille() == 0)
                        {
                            redemarerV =VRAI;
                         printf("PC Verouiller\n");
                         printf( "L'ordinateur vas redemarer dans %d minute,\npour appliquer le VEROUILLAGE du clavier et du paveee tacile definitif (meme apres ARRET ou REDEMARAGE). \n", 2);
                        }
                        else{
                            redemarerV =FAUX;
                             printf("La commade de verouillage a echouer");

                        }
                         

                        if(redemarerV == VRAI)
                        {
                         if(redemarrageSystem("Redemarege pour aplication VEROUILLAGE  2 minutes.") 
                         == 0)
                         {

                             printf("Commande de redemarage executee avec succes \n");
                         }                          
                         else
                         {
                           

                            printf("la commande de redemmarge na pas pus etre execute.\nVouis devez REDEMMARER l'ordinateur pourapliquer le VEROUILLAGE.\n");
                         
                         }
                        }

                      }
                    
                   }

                   if(event.button.button == SDL_BUTTON_LEFT)
                   {

                     if(dedansDeverouiller == VRAI && event.button.clicks >= 2 )
                       {
                            if(deverouille() == 0)
                            {
                                redemarerD = VRAI;
                                printf("PC Deverouiller\n");
                        printf( "L'ordinateur vas redemarer dans %d minute,      \npour appliquer  le DEVEROUILLAGE du clavier et de paver tacile definitif (meme apres ARRET ou REDEMARAGE). \n", 2);
                            }
                            else{
                                redemarerD = FAUX;
                                printf("La commade de deverouillage a echouer");
                            }



                           
                            
                           
                          if(redemarerD == VRAI)
                          {

                           if(redemarrageSystem("Redemarage pour aplication DEVEROUILLAGE dans 2 minutes.") == 0)
                           {
                             printf("Commande de redemarage executee avec succes\n");
                           }
                              
                        else
                         {
                           printf("la commande de redemmarge na pas pus etreexecute.\nVous devez REDEMARAGE l'ordinateur pourapliquer le DEVEROUILLAGE.\n");
                           }
                          }
                         
                        }
                   }
                      break;                                                                             
                /*---------------------------------------------------------------------------*/
                
                default:
                    break;
                }
             
            
            
          
            }

            
    } while (launchEvent);/*boucle de fenetre*/
    
    
    
    
    
    


}
/************************************************************/
