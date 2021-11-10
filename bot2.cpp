#include "struct.h"
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// ******************************* Tout ce qui concerne le bot *************************************
lancer des_du_bot(lancer des_bot)
{
    des_bot.des1 = rand()%6 + 1;
    des_bot.des2 = rand()%6 + 1;

    return  des_bot;
}
joueur position_bot(joueur bot, lancer des_bot)
{                               //on crée une variable en static afin qu'elle ne soit pas redefinie a 0
    static int tours_joueur = 0;
    static unsigned int pre_position = 0;
    int somme_des = 0;

    somme_des =  des_bot.des1 + des_bot.des2;
    bot.position += somme_des;                                  // on calcule la position en fonction des dés et de la position précedentes
    pre_position = bot.position - somme_des;
    tours_joueur = bot.tours_de_plateau;

    if(bot.position > 39)
    {
        bot.position = (pre_position + somme_des)-40;
        bot.argent += 200;
        tours_joueur++;
    }
    if(bot.position == 0 && tours_joueur != 0)
    {
        bot.argent += 400;
    }

    bot.tours_de_plateau = tours_joueur;

    return bot;
}
joueur Affichage_bot(joueur bot, lancer des_bot)
{
    bot = position_bot(bot, des_bot);
    cout << "*******************************BOT **********************************" <<endl;
    cout << "le bot a : " << bot.argent << "e" <<endl;
    cout << "il est a la case : " << bot.position  << endl;

    des_bot = des_du_bot(des_bot);
    bot = position_bot(bot, des_bot);

    cout << endl;
    cout << "il a fait : " << des_bot.des1 << " et " << des_bot.des2 << endl;
    cout << "il passe a la case : " << bot.position << endl;
    cout << "il passe a : " << bot.argent << endl;

    return bot;
}
