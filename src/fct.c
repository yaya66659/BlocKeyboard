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



