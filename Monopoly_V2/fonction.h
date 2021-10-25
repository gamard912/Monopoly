#ifndef FONCTION_H
#define FONCTION_H
#include "struct.h"

// ******************************* Tout ce qui concerne le joueur *************************************
void Affichage_joueur(joueur player, lancer des_joueur);
char saisie_joueur();
void Nouvelle_position_joueur(lancer des_joueur);
lancer des_du_joueur(lancer des_joueur);
int position(lancer des_joueur);

// ******************************* Tout ce qui concerne le bot1 *************************************

void Affichage_bot1(joueur bot1, lancer des_bot1);
lancer des_du_bot1(lancer des_bot1);
int position_bot1(lancer des_bot1);

// ******************************* Tout ce qui concerne le bot2 *************************************

void Affichage_bot2(joueur bot2, lancer des_bot2);
lancer des_du_bot2(lancer des_bot2);
int position_bot2(lancer des_bot2);

// ******************************* fonction generale *************************************
char menu_debut();
void affichage_regles();
int quitter();

#endif // FONCTION_H
