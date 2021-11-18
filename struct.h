#ifndef STRUCT_H
#define STRUCT_H
#include <string>

using namespace std;

typedef struct{

    int argent;
    int position;  // case de depart
    int tours_de_plateau;
    int dice;
    bool elimination;
    int playerNumber;
    string achat_prop;

}joueur;

typedef struct{

    int des1;
    int des2;

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
