#include "struct.h"
#include "bot1.h"
#include "bot2.h"
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "playboard.h"
#include "properties.h"
#include "joueur.h"

using namespace std;



// *********************************** fonction generale *************************************
void clear_screen()
{
    cout << "\x1B[2J\x1B[H" << "\n";
}

char saisie_menu_debut()
{
    char choix_debut = 0;
    cout << "Bienvenue sur le Monopoly by Ezio & Zoubir" << endl;
    cout << "Pour lancer la partie tapez 'l' et pour afficher les regles 'r'" << endl;
    cin >> choix_debut;



    if(choix_debut != 'l' && choix_debut != 'r')
    {
        cout << "Erreur lors de la saisie" << endl;
        return  saisie_menu_debut();
    }else{
        return choix_debut;
    }
}

void affichage_regles()
{
    cout << endl;
    cout << "La partie commence avec 1500e chacun" << endl;
    cout << "Pour quittez cliquez sur la croix " << endl;
    cout << "il a deux bot " << endl;
    cout << "pour gagnez la partie les deux bots ne doivent plus avoir d'argent" << endl<< endl;
}

int saisie_passe()
{
    char saisie = 0;

    cout << "Tapez r pour passer au prochain joueur (bot)" << endl;
    cin >> saisie;

    if(saisie != 114)
    {
        cout << "Erreur lors de la saisie " << endl;
        return saisie_passe();
    }else
    {
        return 0;
    }

}

void game_master(joueur player, lancer des_joueur, joueur bot1, lancer des_bot1, joueur bot2, lancer des_bot2, int propertiesData[40][4])
{
    char recup_choix_debut = saisie_menu_debut();
    player.argent = 1500;
    bot1.argent = 1500;
    bot2.argent = 1500;
          clear_screen();
    if(recup_choix_debut == 'l')
    {
        for(int i = 0; i<20; i++)
        {

            player = Affichage_joueur(player, des_joueur);
            print_playboard(player, bot1, bot2);
            player.argent = achat_prop_joueur(propertiesData, player);
            saisie_passe();
            clear_screen();


            bot1 = Affichage_bot(bot1, des_bot1);
            print_playboard(player, bot1, bot2);
            bot1.argent = achat_prop_bot(propertiesData, bot1);
            saisie_passe();
            clear_screen();


            bot2 = Affichage_bot(bot2, des_bot2);
            print_playboard(player, bot1, bot2);
            bot2.argent = achat_prop_bot(propertiesData, bot2);
            saisie_passe();
            clear_screen();
        }

    }else if(recup_choix_debut == 'r')
    {
        affichage_regles();
        game_master(player, des_joueur, bot1, des_bot1, bot2, des_bot2,propertiesData);
    }else{
        game_master(player, des_joueur, bot1, des_bot1, bot2, des_bot2,propertiesData);
    }
}
void setup_screen()
{
    cout << "\e[8;150;175t";
}


