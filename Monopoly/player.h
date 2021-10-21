
/*************************************************************
* Nom ............ : player.h
* Rôle ........... :
* Auteur ......... : prénom.nom
* Date création .. : 21/10/2021
* Version/Màj .... :
* Licence ........ : GPLv4
*************************************************************/
#ifndef PLAYER_H
#define PLAYER_H

typedef struct{

    char pseudo[10];
    int argent = 1500;
    int position = 0;
    int a = 0;
}joueur;

typedef struct{

    int des1 = 0;
    int des2 =0;

} lancer ;

int position(lancer des, joueur joueur1);
lancer lancer_des(lancer des);
void menu_debut(joueur joueur1);
void saisie_debut(joueur joueur1);
joueur saisie_joueur(joueur joueur1);
void affichage_joueur(joueur joueur1, lancer des);

#endif // PLAYER_H
