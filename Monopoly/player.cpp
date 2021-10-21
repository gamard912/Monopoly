
/*************************************************************
* Nom ............ : player.cpp
* Rôle ........... :
* Auteur ......... : prénom.nom
* Date création .. : 21/10/2021
* Version/Màj .... :
* Licence ........ : GPLv4
*************************************************************/
#include <iostream>
#include "player.h"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void menu_debut(joueur joueur1)
{
    char premier_choix = 0;

     cout << "Bienvenue sur le Monopoly by Ezio et Zoubir " << endl;
     cout << "Tapez 'p' pour commencez la partie, Echap pour quittez et r pour afficher les regles" << endl;
     cin >> premier_choix;

     if (premier_choix == 'p')
     {
         saisie_joueur(joueur1);

     }else if(premier_choix == 27)
     {
         //quittez la partie

     }else if(premier_choix == 'r')
     {
         // affichage des regles
     }else{
         cout << "Erreur lors de la saisie" << endl;
     }
}

joueur saisie_joueur(joueur joueur1)
{
    cout << "Veuillez saisir votre pseudo : " << endl;

    do{
        joueur1.pseudo[joueur1.a] = getchar();
        joueur1.a++;
    }while(joueur1.pseudo[joueur1.a - 1] != 10);

    return joueur1;
}

void affichage_joueur(joueur joueur1, lancer des)
{
    int i = 0;
    //char lancer = 0;


    joueur1 = saisie_joueur(joueur1);
    joueur1.position = position(des, joueur1);

    cout <<"**********************************************" << endl;
    for(i = 0; i < joueur1.a; i++)
    {
        cout << joueur1.pseudo[i];
    }
    cout <<"Vous avez :"<< joueur1.argent << "e" << endl;
    cout <<"Vous etes a la case :"<< joueur1.position << endl;

    cout <<"**********************************************" << endl;


//    cout << "Tapez l pour lancer les des"<< endl;
//    cin  >> lancer;

//    if(lancer == 'l')
//    {
//        lancer_des(des, joueur1);
//    }

}

lancer lancer_des(lancer des)
{
    srand(time(NULL));
    des.des1 = rand()%6 + 1;
    des.des2 = rand()%6 + 1;

    return  des;
}

int position(lancer des, joueur joueur1)
{
    des = lancer_des(des);
    joueur1.position = des.des1 + des.des2;

    return joueur1.position;
}



