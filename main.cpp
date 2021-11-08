#include <iostream>
#include "fonction.h"
#include "struct.h"
#include "playboard.h"
#include "properties.h"
#include "time.h"

using namespace std;

int main()
{
    joueur player;
    joueur bot1;
    joueur bot2;

    lancer des_joueur;
    lancer des_bot1;
    lancer des_bot2;

    allProperties estate;

    srand(time(NULL));

    game_master(player, des_joueur, bot1, des_bot1, bot2, des_bot2, estate);

    return 0;
}
