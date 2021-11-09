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

    int propertiesData[40][3]={{2,0,0},{}

    };

    srand(time(NULL));

    setup_screen();
    game_master(player, des_joueur, bot1, des_bot1, bot2, des_bot2, propertiesData);

    return 0;
}
