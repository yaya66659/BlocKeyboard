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


#ifndef _FCT_H_
#define _FTC_H_

#ifndef _BOOL_
#define _BOOL_

#define SIZE_T 255
typedef enum booleen{
FAUX,
VRAI
}booleen;

#endif /*_BOOL_*/

void videBuffer();
int verouille();
int deverouille();
int redemarrageSystem(char * message);











#endif //_FCT_H_
