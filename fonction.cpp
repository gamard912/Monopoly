#include "struct.h"
#include "bot1.h"
#include "bot2.h"
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "playboard.h"
#include "properties.h"

using namespace std;

// ******************************* Tout ce qui concerne le joueur *************************************
char saisie_joueur()
{
    char saisie = 0;
    cout << "Pour lancer les des tapez 'l'" << endl;
    cin >> saisie;                                          // on recupere saisie afin de savoir si le joueur veut lancer les dés ou autres choses

    return saisie;                                          // on renvoie la valeur saisie par l'utilisateur
}

lancer des_du_joueur(lancer des_joueur)
{
    des_joueur.des1 = rand()%6 + 1;                         // lancement du premier dés du joueur
    des_joueur.des2 = rand()%6 + 1;                         // lancement du second dés du joueur

    return  des_joueur;                                     // renvoie la valeur des dés
}

joueur position(joueur player, lancer des_joueur)
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

int Nouvelle_position_joueur(joueur player, lancer des_joueur)
{
    des_joueur = des_du_joueur(des_joueur);                 //on recupere la valeur des dés
    player = position(player, des_joueur);              // on stock la position afin de l'afficher

    cout << endl;   // un peu d'affichage
    cout << "Vous avez fait : " << des_joueur.des1 << " et " << des_joueur.des2 << endl;
    cout << "Vous passer a la case : " << player.position << endl;
    cout << "Vous avez maintenant : " << player.argent << "e "<< endl;
    return player.position;

}
joueur Affichage_joueur(joueur player,lancer des_joueur)
{
    // création de variable afin de recuperer la saisie du joueur et sa position pour le prochain tour
    char recup_saisie = 0;
    player = position(player, des_joueur);


    //un peu d'affichage
    cout << "******************************* JOUEUR **********************************" <<endl;
    cout << "Joueur, a vous de jouer ..." << endl;
    cout << "vous avez : " << player.argent << "e" <<endl;
    cout << "vous etes a la case : " << player.position  << endl;

    //on vérifie la saisie que l'on a recuperer dans une variable
    recup_saisie = saisie_joueur();
    if(recup_saisie == 'l')
    {
        player.position=Nouvelle_position_joueur(player, des_joueur);
    }else if(recup_saisie == 's')
    {
        cout << "erreur lors de la saisie "<< endl;
    }
    return player;
}


// *********************************** fonction generale *************************************
char menu_debut()
{
    char choix_debut = 0;
    cout << "Bienvenue sur le Monopoly by Ezio & Zoubir" << endl;
    cout << "Pour lancer la partie tapez 'l' et pour afficher les regles 'r'" << endl;
    cin >> choix_debut;

    return choix_debut;
}

void affichage_regles()
{
    cout << endl;
    cout << "La partie commence avec 1500e chacun" << endl;
    cout << "Pour quittez cliquez sur la croix " << endl;
    cout << "il a deux bot " << endl;
    cout << "pour gagnez la partie les deux bots ne doivent plus avoir d'argent" << endl<< endl;
}

void game_master(joueur player, lancer des_joueur, joueur bot1, lancer des_bot1, joueur bot2, lancer des_bot2, allProperties estate)
{
    define_realEstate(estate);
    char recup_choix_debut = menu_debut();

    if(recup_choix_debut == 'l')
    {
        for(int i = 0; i<20; i++)
        {
            print_playboard(player, bot1, bot2);
            player=Affichage_joueur(player, des_joueur);
            print_playboard(player, bot1, bot2);
            bot1=Affichage_bot1(bot1, des_bot1);
            bot2=Affichage_bot2(bot2, des_bot2);
        }

    }else if(recup_choix_debut == 'r')
    {
        affichage_regles();
        game_master(player, des_joueur, bot1, des_bot1, bot2, des_bot2,estate);
    }else{
        game_master(player, des_joueur, bot1, des_bot1, bot2, des_bot2,estate);
    }
}
