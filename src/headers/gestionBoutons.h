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
*/


=======
>>>>>>> 941fa3d (Sauvegarde des modifications avant pull)
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



<<<<<<< HEAD
#endif
=======
#endif
>>>>>>> 941fa3d (Sauvegarde des modifications avant pull)
