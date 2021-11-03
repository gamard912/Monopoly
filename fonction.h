#ifndef FONCTION_H
#define FONCTION_H
#include "struct.h"

// ******************************* Tout ce qui concerne le joueur *************************************
joueur Affichage_joueur(joueur player, lancer des_joueur);
char saisie_joueur();
int Nouvelle_position_joueur(joueur player,lancer des_joueur);
lancer des_du_joueur(lancer des_joueur);
joueur position(joueur player ,lancer des_joueur);


// ******************************* fonction generale *************************************
char menu_debut();
void affichage_regles();
int quitter();
void game_master(joueur player, lancer des_joueur, joueur bot1, lancer des_bot1, joueur bot2, lancer des_bot2);

#endif // FONCTION_H
