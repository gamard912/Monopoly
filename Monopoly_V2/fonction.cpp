#include "struct.h"
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

char saisie_joueur()
{
    char saisie = 0;
    cout << "Pour lancer les des tapez 'l'" << endl;
    cin >> saisie;

    return saisie;
}

lancer des_du_joueur(lancer des_joueur)
{
    des_joueur.des1 = rand()%6 + 1;
    des_joueur.des2 = rand()%6 + 1;

    return  des_joueur;
}

int position(lancer des_joueur)
{
    static int position = 0;
    position += des_joueur.des1 + des_joueur.des2;

    return position;
}

void Nouvelle_position_joueur(lancer des_joueur)
{
    des_joueur = des_du_joueur(des_joueur);

    int recup_position = position(des_joueur);

    cout << endl;
    cout << "Vous avez fait : " << des_joueur.des1 << " et " << des_joueur.des2 << endl;
    cout << "Vous passer a la case : " << recup_position << endl;
    cout << "*************************************************************" <<endl;

}

void Affichage_joueur(joueur player, lancer des_joueur)
{
    char recup_saisie = 0;
    int recup_position = position(des_joueur);

    cout << "Joueur, a vous de jouer ..." << endl;
    cout << "vous avez : " << player.argent << "e" <<endl;
    cout << "vous etes a la case : " << recup_position  << endl;


    recup_saisie = saisie_joueur();
    if(recup_saisie == 'l')
    {
        Nouvelle_position_joueur(des_joueur);
    }
}


