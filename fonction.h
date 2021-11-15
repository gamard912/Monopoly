#ifndef FONCTION_H
#define FONCTION_H
#include "struct.h"




// ******************************* fonction generale *************************************
char saisie_menu_debut();
void affichage_regles();
int quitter();
bool verif_fin_de_partie(int propertiesData[40][4],joueur);
Data_joueur gestion_joueur(int propertiesData[40][4],Data_joueur player);
void Affichage_elim_bot( joueur global);
Data_joueur  gestion_bot(int propertiesData[40][4], Data_joueur player, joueur, int);
Data_joueur elim_bot2(Data_joueur player, int propertiesData[40][4]);
Data_joueur elim_bot1(Data_joueur player, int propertiesData[40][4]);
Data_joueur pas_elim(Data_joueur player, int propertiesData[40][4]);
int game_master(Data_joueur player, int propertiesData[40][4]);



int saisie_passe(int propertiesData[40][4],joueur);

#endif // FONCTION_H
