#include "struct.h"
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// ******************************* All bots player functions *************************************
lancer des_du_bot(lancer des_global)
{
    des_global.des1 = rand()%6 + 1; //roll 1st dice
    des_global.des2 = rand()%6 + 1; //roll 2nd dice

    return  des_global ; //return dices
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

    if(global.position > 39) //If the position of the current player is superior at 39
    {
        global.position = (pre_position + somme_des)-40;
        if(global.position != 0)
        {
            global.argent += 200;//Just passing by the start case
        }
        else if(global.position == 0 && tours_joueur != 0)
        {
            global.argent += 400;//Stopping on the start case
        }

        tours_joueur++;
    }

    global .tours_de_plateau = tours_joueur;

    return global ;
}
joueur Affichage_bot(joueur global, lancer des_global)
{
   global  = position_bot(global, des_global);

    cout << "Le bot a : " << global .argent << "€" <<endl;
    cout << "Il est à la case : " << global .position  << endl;

   des_global  = des_du_bot(des_global);
   global  = position_bot(global, des_global);

    cout << endl;
    cout << "Il a fait : " << des_global.des1 << " et " << des_global.des2 << endl;
    cout << "Il passe donc à la case : " << global .position << endl;
    cout << "Il a maintenant : " << global .argent << "€" <<endl;

    return global ;
}
