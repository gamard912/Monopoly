#ifndef FONCTION_H
#define FONCTION_H
#include "struct.h"

const int initialMoney=1500;


// ******************************* Generals Functions *************************************
char saisie_menu_debut(); //print the intial menu

void affichage_regles(); //print game's rules

bool verif_fin_de_partie(int propertiesData[40][4],joueur); //Check if the game is over or not

Data_joueur gestion_joueur(int propertiesData[40][4],Data_joueur player); //Human players' management

void Affichage_elim_bot( joueur global); //print a bot as been eliminated

Data_joueur  gestion_bot(int propertiesData[40][4], Data_joueur player, joueur, int); //Bot players' management

Data_joueur elim_bot2(Data_joueur player, int propertiesData[40][4]);//Management of the bot1 elimination
Data_joueur elim_bot1(Data_joueur player, int propertiesData[40][4]);//Same of bot2

Data_joueur pas_elim(Data_joueur player, int propertiesData[40][4]); //If the player is always on the game

int game_master(Data_joueur player, int propertiesData[40][4]); //Master function of the game

void Affichage_statut_joueur(int propertiesData[40][4] ,Data_joueur player); //Print the player statut (game over or win)

int saisie_passe(int propertiesData[40][4],joueur);//To let the player choice between skip his turn or see his properties

#endif // FONCTION_H
