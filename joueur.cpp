#include "struct.h"
#include <iostream>
#include "joueur.h"


using namespace std;
/*************************************************************
* Nom ............ : joueur.cpp
* Rôle ........... :
* Auteur ......... : prénom.nom
* Date création .. : 9/11/2021
* Version/Màj .... :
* Licence ........ : GPLv4
*************************************************************/
// ******************************* Tout ce qui concerne le joueur *************************************
char saisie_joueur()
{
    char saisie = 0;
    cout << "Pour lancer les des tapez 'l'" << endl;
    cin >> saisie;                                          // on recupere saisie afin de savoir si le joueur veut lancer les dés ou autres choses

    if(saisie != 'l')
    {
        cout << "Erreur lors de la saisie" << endl;
        saisie_joueur();
    }else
    {
        return saisie;
    }
    return 0;
    // on renvoie la valeur saisie par l'utilisateur
}

lancer init_random_des_du_joueur(lancer des_joueur)
{
    des_joueur.des1 = rand()%6 + 1;                         // lancement du premier dés du joueur
    des_joueur.des2 = rand()%6 + 1;                         // lancement du second dés du joueur

    return  des_joueur;                                     // renvoie la valeur des dés
}

joueur gestion_position(joueur player, lancer des_joueur)
{

    static int position = 0;                                //on crée une variable en static afin qu'elle ne soit pas redefinie a 0
    static int argent = 1500;
    static int tours_joueur = 0;
    static unsigned int pre_position = 0;
    int somme_des = 0;

    somme_des =  des_joueur.des1 + des_joueur.des2;
    position += somme_des;                                  // on calcule la position en fonction des dés et de la position précedentes
    pre_position = position - somme_des;
    tours_joueur = player.tours_de_plateau;

    if(position > 40)
    {
        position = (pre_position + somme_des)-40;
        argent += 200;
        tours_joueur++;
    }
    if(position == 0 && tours_joueur != 0)
    {
        argent += 400;
    }

    player.argent = argent;
    player.position = position;
    player.tours_de_plateau = tours_joueur;

    return player;                                        //on retourne la position
}

int affichage_Nouvelle_position_joueur(joueur player, lancer des_joueur)
{
    des_joueur = init_random_des_du_joueur(des_joueur);                 //on recupere la valeur des dés
    player = gestion_position(player, des_joueur);              // on stock la position afin de l'afficher

    cout << endl;   // un peu d'affichage
    cout << "Vous avez fait : " << des_joueur.des1 << " et " << des_joueur.des2 << endl;
    cout << "Vous passer a la case : " << player.position << endl;
    cout << "Vous avez maintenant : " << player.argent << "e "<< endl;
    return player.position;

}
joueur Affichage_joueur(joueur player,lancer des_joueur)
{
    // création de variable afin de recuperer la saisie du joueur et sa position pour le prochain tour
    player = gestion_position(player, des_joueur);


    //un peu d'affichage
    cout << "******************************* JOUEUR **********************************" <<endl;
    cout << "Joueur, a vous de jouer ..." << endl;
    cout << "vous avez : " << player.argent << "e" <<endl;
    cout << "vous etes a la case : " << player.position  << endl;

    //on vérifie la saisie que l'on a recuperer dans une variable
    saisie_joueur();

    player.position= affichage_Nouvelle_position_joueur(player, des_joueur);

    return player;
}
