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

    int propertiesData[40][4]={{2,0,0,-1},{0,60,2,0},{4,0,0,-1},{0,60,4,0},{1,0,200,-1},{0,200,25,0},{0,100,6,0},{3,0,0,-1},{0,100,6,0},{0,120,8,0},{5,0,0,-1},{0,140,10,0},{0,150,-1,-1},{0,140,10,0},{0,160,12,0},
                               {0,200,25,0},{0,180,14,0},{4,0,0,-1},{0,180,14,0},{0,200,16,0},{6,0,0,-1},{0,220,18,0},{3,0,0,-1},{0,220,18,0},{0,240,20,0},{0,200,25,0},{0,260,22,0},{0,260,22,0},{0,150,-1,-1},{0,280,24,0},
                               {7,0,0,-1},{0,300,26,0},{0,300,26,0},{4,0,0,-1},{0,320,28,0},{0,200,25,0},{3,0,0,-1},{0,350,35,0},{1,0,100,-1},{0,400,50,0}};

    srand(time(NULL));

    setup_screen();
    game_master(player, des_joueur, bot1, des_bot1, bot2, des_bot2, propertiesData);

    return 0;
}
