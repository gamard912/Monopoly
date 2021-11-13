#ifndef FONCTION_H
#define FONCTION_H
#include "struct.h"



// ******************************* fonction generale *************************************
char saisie_menu_debut();
void affichage_regles();
int quitter();
bool verif_fin_de_partie(joueur);
joueur gestion_joueur(int propertiesData[40][4],Data_joueur player);
joueur gestion_bot(int propertiesData[40][4], Data_joueur player, joueur);
Data_joueur elim_bot2(Data_joueur player, int propertiesData[40][4]);
Data_joueur elim_bot1(Data_joueur player, int propertiesData[40][4]);
Data_joueur pas_elim(Data_joueur player, int propertiesData[40][4]);
int game_master(Data_joueur player, int propertiesData[40][4]);


void setup_screen();
void clear_screan();
int saisie_passe();

#endif // FONCTION_H
