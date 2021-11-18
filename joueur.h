
/*************************************************************
* Nom ............ : joueur.h
* Rôle ........... :
* Auteur ......... : prénom.nom
* Date création .. : 9/11/2021
* Version/Màj .... :
* Licence ........ : GPLv4
*************************************************************/
#ifndef JOUEUR_H
#define JOUEUR_H

#include "struct.h"

// ******************************* All human player functions *************************************
joueur Affichage_joueur(Data_joueur player);//Print the player interface

char saisie_joueur();//Get player input to roll the dices

joueur affichage_Nouvelle_position_joueur(Data_joueur player);//Print new position of the player, his dices roll and his money

lancer init_random_des_du_joueur(Data_joueur player);//Roll dices

joueur gestion_position(Data_joueur player);//Position management




#endif // JOUEUR_H
