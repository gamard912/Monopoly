#include <iostream>
#include "fonction.h"
#include "struct.h"

using namespace std;

int main()
{
    joueur player;
    joueur bot1;
    joueur bot2;

    lancer des_joueur;
    lancer des_bot1;
    lancer des_bot2;

    srand(time(NULL));

    for(int i = 0; i<20; i++)
    {
        Affichage_joueur(player, des_joueur);
        Affichage_bot1(bot1, des_bot1);
        Affichage_bot2(bot2, des_bot2);
    }


    return 0;
}
