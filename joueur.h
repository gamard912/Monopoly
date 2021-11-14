
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
joueur Affichage_joueur(Data_joueur player);
char saisie_joueur();
joueur affichage_Nouvelle_position_joueur(Data_joueur player);
lancer init_random_des_du_joueur(Data_joueur player);
joueur gestion_position(Data_joueur player);


#endif // JOUEUR_H
