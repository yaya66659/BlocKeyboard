/*
    BlocKeyboard - Désactivation du clavier et du pavé tactile d'un PC portable.
    Copyright (C) 2024 Yann

    Ce programme est un logiciel libre : vous pouvez le redistribuer et/ou le modifier
    sous les termes de la Licence Publique Générale GNU v3, publiée par la Free Software Foundation.

    Ce programme est distribué en l'espoir qu'il sera utile,
    mais SANS AUCUNE GARANTIE, sans même la garantie implicite
    de COMMERCIALISATION ou d’ADÉQUATION À UN OBJECTIF PARTICULIER.
    Voir la Licence Publique Générale GNU pour plus de détails.

    Vous devriez avoir reçu une copie de la Licence Publique Générale GNU
    avec ce programme. Si ce n’est pas le cas, consultez :
    https://www.gnu.org/licenses/gpl-3.0.html



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdarg.h>

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include "headers/GestionDeLaSDL.h"
#include"headers/fct.h"
#include "headers/gestionBoutons.h"

/*******************AFFICHE RECTANGLE AVEC TEXTE*****************/
SDL_Texture *creationEtAffichageBoutton(SDL_Renderer *renderer, SDL_Rect rect, colorDraw color, char *text){
         DrawColors c;
    switch (color)
    {
    case BLANC:
      c.R = 255;
      c.G = 255;
      c.B = 255;
        break;

        case NOIR:
  c.R = 0;
  c.G = 0;
  c.B = 0;
    break;

    case ROUGE:
  c.R = 255;
  c.G = 0;
  c.B = 0;
    break;

    case VERT:
  c.R = 50;
  c.G = 200;
  c.B = 100;
    break;

    case BLEU:
  c.R = 0;
  c.G = 0;
  c.B = 255;
    break;
    
    default:
    return NULL;
        break;
    }

    if(SDL_SetRenderDrawColor(renderer,c.R, c.G, c.B, SDL_ALPHA_OPAQUE ) != 0)
    return NULL;

    



    if(SDL_RenderFillRect(renderer, &rect) != 0)
    return NULL;

    SDL_Surface *surfaceText = NULL;
    SDL_Texture *textureText = NULL;

    TTF_Font *font = NULL;
    SDL_Color colorText;

    colorText.r = 20;
    colorText.g = 200;
    colorText.b = 10;
    colorText.a = 255;


    font = TTF_OpenFont("police/police1.ttf",15);
    if(font == NULL)
    return NULL;

    surfaceText = TTF_RenderText_Blended(font, text, colorText);
    TTF_CloseFont(font);
    if(surfaceText == NULL)
    return NULL;


    
   textureText = SDL_CreateTextureFromSurface(renderer, surfaceText);
    SDL_FreeSurface(surfaceText);

   if(textureText == NULL)
   return NULL;

   if(SDL_QueryTexture(textureText, NULL, NULL,(&rect.w+20),(&rect.h-40)) != 0)
   {
         SDL_DestroyTexture(textureText); 
        return NULL;

   }

   if(SDL_RenderCopy(renderer, textureText, NULL, &rect) != 0)
   {
SDL_DestroyTexture(textureText);
return NULL;

   }

   SDL_RenderPresent(renderer);
        

    return textureText;
}
/****************MOUSE DANS LE BOUTON**********************/
booleen mouseEnterButon(int x, int y, SDL_Rect rect)
{
    booleen dedans = FAUX;
        for(int i = rect.x; i<=(rect.x+rect.w); i++){
     for(int j =rect.y; j<= (rect.y+rect.h); j++){
             if(x == i && y == j )
             {
                 dedans = VRAI;
             }
             
             
                               }
}
    return dedans;
}
