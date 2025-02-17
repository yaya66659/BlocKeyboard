<<<<<<< HEAD
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


=======
>>>>>>> 941fa3d (Sauvegarde des modifications avant pull)
#ifndef _GESTION_SDL_
#define _GESTION_SDL_

#define  WINDOW_H 600
#define WINDOW_W 800
#define _TIME_AVANT_REDEMARAGE_ 3000



#ifndef _BOOL_
#define _BOOL_
typedef enum booleen{
FAUX,
VRAI
}booleen;

#endif /*_BOOL_*/




void SDL_ExitWithError(char *message,booleen sdl2 ,booleen ttf);
void SDL_DestroyWindowsRenderreeAndTextures(SDL_Window* w, SDL_Renderer *r, SDL_Texture * t, ...);

SDL_Texture* ReCreateTextureFond(SDL_Window *window, SDL_Renderer *renderer, SDL_Rect rectFond, SDL_Texture * textureFond);

booleen eventBoucle(SDL_Event envent, SDL_Rect rectVerouiller, SDL_Rect rectDeverouille,SDL_Window *w,  SDL_Renderer * r, SDL_Texture *t);


   





<<<<<<< HEAD
#endif/*_GESTION_SDL_*/
=======
#endif/*_GESTION_SDL_*/
>>>>>>> 941fa3d (Sauvegarde des modifications avant pull)
