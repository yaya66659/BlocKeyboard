#ifndef _GESTION_BOUTON_H
#define _GESTION_BOUTON_H

#define SIZE_T 255

typedef enum colorDraw{
        BLANC,
        NOIR,
        VERT,
        ROUGE,
        BLEU
}colorDraw;

typedef struct DrawColors{

int R;
int G;
int B;


}DrawColors;

SDL_Texture* creationEtAffichageBoutton(SDL_Renderer *renderer, SDL_Rect rect, colorDraw color, char *texte);

booleen mouseEnterButon(int x, int y, SDL_Rect rect);



#endif