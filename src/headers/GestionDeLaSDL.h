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


   





#endif/*_GESTION_SDL_*/