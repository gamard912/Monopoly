#include "struct.h"
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// ******************************* Tout ce qui concerne le bot *************************************
lancer des_du_bot(lancer des_global)
{
    des_global.des1 = rand()%6 + 1;
    des_global.des2 = rand()%6 + 1;

    return  des_global ;
}
joueur position_bot(joueur global, lancer des_global)
{                                                               //on crée une variable en static afin qu'elle ne soit pas redefinie a 0
    static int tours_joueur = 0;
    static unsigned int pre_position = 0;
    int somme_des = 0;

    somme_des =  des_global.des1 + des_global.des2;
    global.position += somme_des;                                  // on calcule la position en fonction des dés et de la position précedentes
    pre_position = global .position - somme_des;
    tours_joueur = global .tours_de_plateau;

    if(global .position > 39)
    {
        global .position = (pre_position + somme_des)-40;
        global .argent += 200;
        tours_joueur++;
    }
    if(global .position == 0 && tours_joueur != 0)
    {
        global .argent += 400;
    }

    global .tours_de_plateau = tours_joueur;

    return global ;
}
joueur Affichage_bot(joueur global, lancer des_global)
{
   global  = position_bot(global, des_global);

    cout << "le bot a : " << global .argent << "e" <<endl;
    cout << "il est a la case : " << global .position  << endl;

   des_global  = des_du_bot(des_global);
   global  = position_bot(global, des_global);

    cout << endl;
    cout << "il a fait : " << des_global.des1 << " et " << des_global.des2 << endl;
    cout << "il passe a la case : " << global .position << endl;
    cout << "il passe a : " << global .argent << endl;

    return global ;
}
