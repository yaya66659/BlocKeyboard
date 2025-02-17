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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include<SDL.h>
#include<SDL_ttf.h>
#include<SDL_image.h>


#include "headers/fct.h"

void videBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
             
}
int verouille(){
 int cmdCofig_i8042prt = 0;

    cmdCofig_i8042prt = system("sc config i8042prt start= disabled");
    if(cmdCofig_i8042prt == 0)
          return 0;
      else
         return 1;
     


}
int deverouille(){
   
 int cmdCofig_i8042prt = 0;
   cmdCofig_i8042prt = system("sc config i8042prt start= auto");
   if(cmdCofig_i8042prt == 0)
       return 0;
     else
   return 1;
       
}
int redemarrageSystem(char * message)
    {
        char cmdShutdown[SIZE_T] = "shutdown /r /t 120 /c \"";
         int shutdown = 0;


        strcat(cmdShutdown, message);
        strcat(cmdShutdown, "\"");

           shutdown = system(cmdShutdown);

        if(shutdown == 0)
            return 0;
            else
            return 1;
  
 
}    

/***COMMANDE DE CONFIGURATION CLAVIER ET PAVER INTERNE PC PORTABLE*****/
/*
--cmd desactiver :
sc config i8042prt start= disabled


--reactiver :
sc config i8042prt start= auto

*/



