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
    const int estateInitalRent[22]={2,4,6,6,8,10,10,12,14,14,16,18,18,20,22,22,22,26,26,28,35,50};
    int propertiesData[40][3]={{2,0,0},{0,60,2},{4,0,0},{0,60,4},{1,0,200},{0,200,25},{0,100,6},{3,0,0},{0,100,6},{0,120,8},{5,0,0},{0,140,10},{0,150,-1},{0,140,10},{0,160,12},{0,200,25},{0,180,14},{4,0,0},{0,180,14},
                               {0,200,16},{6,0,0},{0,220,18},{3,0,0},{0,220,18},{0,240,20},{0,200,25},{0,260,22},{0,260,22},{0,150,-1},{0,280,24},{7,0,0},{0,300,26},{0,300,26},{4,0,0},{0,320,28},{0,200,25},{3,0,0},
                               {0,350,35},{1,0,100},{0,400,50}};

    srand(time(NULL));

    setup_screen();
    game_master(player, des_joueur, bot1, des_bot1, bot2, des_bot2, propertiesData);

    return 0;
}
