#ifndef STRUCT_H
#define STRUCT_H
#include <string>

using namespace std;

typedef struct{

    int argent;
    int position = 0;  // case de depart
    int tours_de_plateau = 0;
    int dice;
    bool elimination = 0;
    int playerNumber;

}joueur;

typedef struct{

    int des1 = 0;
    int des2 =0;

} lancer ;

typedef struct{

    joueur human;
    joueur bot1;
    joueur bot2;
    joueur bot;
    joueur global;

    lancer des_human;
    lancer des_bot1;
    lancer des_bot2;
    lancer des_bot;
    lancer des_global;

}Data_joueur;




#endif // STRUCT_H
