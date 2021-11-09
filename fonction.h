#ifndef FONCTION_H
#define FONCTION_H
#include "struct.h"



// ******************************* fonction generale *************************************
char saisie_menu_debut();
void affichage_regles();
int quitter();
void game_master(joueur player, lancer des_joueur, joueur bot1, lancer des_bot1, joueur bot2, lancer des_bot2, int propertiesData);
void setup_screen();
void clear_screan();

#endif // FONCTION_H
