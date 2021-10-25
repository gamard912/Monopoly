#include "struct.h"
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// ******************************* Tout ce qui concerne le bot2 *************************************
lancer des_du_bot2(lancer des_bot2)
{
    des_bot2.des1 = rand()%6 + 1;
    des_bot2.des2 = rand()%6 + 1;

    return  des_bot2;
}
joueur position_bot2(joueur bot2, lancer des_bot2)
{
    static int position_bot2 = 0;                                //on crée une variable en static afin qu'elle ne soit pas redefinie a 0
    static int argent_bot2 = 1500;
    static unsigned int pre_position_bot2 = 0;
    int somme_des_bot2 = 0;

    somme_des_bot2 =  des_bot2.des1 + des_bot2.des2;
    position_bot2 += somme_des_bot2;                                  // on calcul la position en fonction des dés et de la position précedentes
    pre_position_bot2 = position_bot2 - somme_des_bot2;

    if(position_bot2 > 40)
    {
        position_bot2 = (pre_position_bot2 + somme_des_bot2)-40;
        argent_bot2 += 200;
    }

    bot2.argent = argent_bot2;
    bot2.position = position_bot2;
    return bot2;
}
void Affichage_bot2(joueur bot2, lancer des_bot2)
{
    bot2 = position_bot2(bot2, des_bot2);
    cout << "*******************************BOT 2**********************************" <<endl;
    cout << "le bot2 a : " << bot2.argent << "e" <<endl;
    cout << "il est a la case : " << bot2.position  << endl;

    des_bot2 = des_du_bot2(des_bot2);
    bot2 = position_bot2(bot2, des_bot2);

    cout << endl;
    cout << "il a fait : " << des_bot2.des1 << " et " << des_bot2.des2 << endl;
    cout << "il passe a la case : " << bot2.position << endl;
    cout << "il passe a : " << bot2.argent << endl;

}
