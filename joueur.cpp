#include "struct.h"
#include <iostream>
#include "joueur.h"
#include "properties.h"


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

lancer init_random_des_du_joueur(Data_joueur player)
{
    player.des_human.des1 = rand()%6 + 1;                         // lancement du premier dés du joueur
    player.des_human.des2 = rand()%6 + 1;                         // lancement du second dés du joueur

    return player.des_human;                                     // renvoie la valeur des dés
}

joueur gestion_position(Data_joueur player)
{

    static int position = 0;                                //on crée une variable en static afin qu'elle ne soit pas redefinie a 0
    static int tours_joueur = 0;
    static unsigned int pre_position = 0;
    int somme_des = 0;

    somme_des =  player.des_human.des1 + player.des_human.des2;
    position += somme_des;                                  // on calcule la position en fonction des dés et de la position précedentes
    pre_position = position - somme_des;
    tours_joueur = player.human.tours_de_plateau;

    if(position > 39)
    {
        position = (pre_position + somme_des)-40;
        player.human.argent += 200;
        tours_joueur++;
    }
    if(position == 0 && tours_joueur != 0)
    {
        player.human.argent += 400;
    }

    player.human.position = position;
    player.human.tours_de_plateau = tours_joueur;

    return player.human;                                        //on retourne la position
}




joueur affichage_Nouvelle_position_joueur(Data_joueur player)
{
    player.des_human =init_random_des_du_joueur(player);                 //on recupere la valeur des dés
    player.human = gestion_position(player);              // on stock la position afin de l'afficher

    cout << endl;   // un peu d'affichage
    cout << "Vous avez fait : " << player.des_human.des1 << " et " << player.des_human.des2 << endl;
    cout << "Vous passer a la case : " << player.human.position << endl;
    cout << "Vous avez maintenant : " << player.human.argent << "e "<< endl;

    return player.human;

}
joueur Affichage_joueur(Data_joueur player)
{
    // création de variable afin de recuperer la saisie du joueur et sa position pour le prochain tour
    player.human = gestion_position(player);


    //un peu d'affichage
    cout << "******************************* JOUEUR **********************************" <<endl;
    cout << "Joueur, a vous de jouer ..." << endl;
    cout << "vous avez : " << player.human.argent << "e" <<endl;
    cout << "vous etes a la case : " << player.human.position  << endl;

    //on vérifie la saisie que l'on a recuperer dans une variable
    saisie_joueur();

    player.human = affichage_Nouvelle_position_joueur(player);

    return player.human;
}
