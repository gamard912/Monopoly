
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

// ******************************* Tout ce qui concerne le joueur *************************************
joueur Affichage_joueur(joueur player, lancer des_joueur);
char saisie_joueur();
int affichage_Nouvelle_position_joueur(joueur player,lancer des_joueur);
lancer init_random_des_du_joueur(lancer des_joueur);
joueur gestion_position(joueur player ,lancer des_joueur);
int achat_prop(int propertiesData[40][4],joueur player,  lancer des_joueur);

#endif // JOUEUR_H
