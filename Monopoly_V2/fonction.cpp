#include "struct.h"
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//int quitter()
//{
//    return 0;
//}
// *********************************** fonction generale *************************************
char menu_debut()
{
    char choix_debut = 0;
    cout << "Bienvenue sur le Monopoly by Ezion & Zoubir" << endl;
    cout << "Pour lancer la partie tapez 'l' et pour afficher les regles 'r'" << endl;
    cin >> choix_debut;

    return choix_debut;
}

void affichage_regles()
{
    cout << endl;
    cout << "La partie commence avec 1500e chacun" << endl;
    cout << "Pour quittez clicker sur la croix " << endl;
    cout << "il a deux bot " << endl;
    cout << "pour gagnez la partie les deux bots ne doivent plus avoir d'argent" << endl<< endl;
}


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
int position(lancer des_joueur)
{
    static int position = 0;                                //on crée une variable en static afin qu'elle ne soit pas redefinie a 0
    position += des_joueur.des1 + des_joueur.des2;          // on calcul la position en fonction des dés et de la position précedentes

    return position;                                        //on retourne la position
}
void Nouvelle_position_joueur(lancer des_joueur)
{
    des_joueur = des_du_joueur(des_joueur);                 //on recupere la valeur des dés

    int recup_position = position(des_joueur);              // on stock la position afin de l'afficher

    cout << endl;   // un peu d'affichage
    cout << "Vous avez fait : " << des_joueur.des1 << " et " << des_joueur.des2 << endl;
    cout << "Vous passer a la case : " << recup_position << endl;

}
void Affichage_joueur(joueur player, lancer des_joueur)
{
    // création de variable afin de recuperer la saisie du joueur et sa position pour le prochain tour
    char recup_saisie = 0;
    int recup_position = position(des_joueur);

    //un peu d'affichage
    cout << "******************************* JOUEUR **********************************" <<endl;
    cout << "Joueur, a vous de jouer ..." << endl;
    cout << "vous avez : " << player.argent << "e" <<endl;
    cout << "vous etes a la case : " << recup_position  << endl;

    //on vérifie la saisie que l'on a recuperer dans une variable
    recup_saisie = saisie_joueur();
    if(recup_saisie == 'l')
    {
        Nouvelle_position_joueur(des_joueur);
    }else if(recup_saisie == 's')
    {
        cout << "erreur lors de la saisie "<< endl;
    }
}


// ******************************* Tout ce qui concerne le bot1 *************************************
lancer des_du_bot1(lancer des_bot1)
{
    des_bot1.des1 = rand()%6 + 1;
    des_bot1.des2 = rand()%6 + 1;

    return  des_bot1;
}
int position_bot1(lancer des_bot1)
{
    static int position_bot1 = 0;
    position_bot1 += des_bot1.des1 + des_bot1.des2;

    return position_bot1;
}
void Affichage_bot1(joueur bot1, lancer des_bot1)
{
    int recup_position = position_bot1(des_bot1);
    cout << "*******************************BOT 1**********************************" <<endl;
    cout << "le bot1 a : " << bot1.argent << "e" <<endl;
    cout << "il est a la case : " << recup_position  << endl;

    des_bot1 = des_du_bot1(des_bot1);
    recup_position = position_bot1(des_bot1);

    cout << endl;
    cout << "il a fait : " << des_bot1.des1 << " et " << des_bot1.des2 << endl;
    cout << "il passe a la case : " << recup_position << endl;

}


// ******************************* Tout ce qui concerne le bot2 *************************************
lancer des_du_bot2(lancer des_bot2)
{
    des_bot2.des1 = rand()%6 + 1;
    des_bot2.des2 = rand()%6 + 1;

    return  des_bot2;
}
int position_bot2(lancer des_bot2)
{
    static int position_bot2 = 0;
    position_bot2 += des_bot2.des1 + des_bot2.des2;

    return position_bot2;
}
void Affichage_bot2(joueur bot2, lancer des_bot2)
{
    int recup_position = position_bot2(des_bot2);

    cout << "*******************************BOT 2**********************************" <<endl;
    cout << "le bot2 a : " << bot2.argent << "e" <<endl;
    cout << "il est a la case : " << recup_position  << endl;

    des_bot2 = des_du_bot2(des_bot2);
    recup_position = position_bot2(des_bot2);

    cout << endl;
    cout << "il a fait : " << des_bot2.des1 << " et " << des_bot2.des2 << endl;
    cout << "il passe a la case : " << recup_position << endl;

}


