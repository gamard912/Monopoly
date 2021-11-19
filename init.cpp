#include <stdlib.h>
#include <iostream>
#include "init.h"

using namespace std;

void clear_screen()//Clear all screen
{
    cout << "\x1B[2J\x1B[H";
}

void setup_screen()//Resize screen
{
    cout << "\e[8;150;175t" ;
}

Data_joueur init_valeur_joueur(Data_joueur player)
{
    //Define each player money to the initial Value
    player.human.argent = 1500;
    player.bot1.argent = 1500;
    player.bot2.argent = 1500;

    //Define inital position for each player
    player.human.position = 0;
    player.bot1.position = 0;
    player.bot2.position = 0;

    //Define the player index for each player
    player.human.playerNumber = 3;
    player.bot1.playerNumber = 1;
    player.bot2.playerNumber = 2;

    player.human.achat_prop = "La propiété est deja achetée vous gagner donc :";
    player.bot1.achat_prop = "Le bot 1 recoit donc :";
    player.bot2.achat_prop = "Le bot 2 recoit donc :";

    //Define intial value of human player dices
    player.des_human.des1 = 0;
    player.des_human.des2 = 0;


    return player;
}
