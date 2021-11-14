#include "init.h"
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "playboard.h"
#include "properties.h"
#include "joueur.h"
#include "fonction.h"

#include "struct.h"
#include "bot1.h"
#include "bot2.h"

using namespace std;



// *********************************** fonction generale *************************************


void affichage_regles()
{
    cout << endl;
    cout << "La partie commence avec 1500e chacun" << endl;
    cout << "Pour quittez cliquez sur la croix " << endl;
    cout << "il a deux bot " << endl;
    cout << "pour gagnez la partie les deux bots ne doivent plus avoir d'argent" << endl<< endl;

    saisie_menu_debut();
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
    }else if(choix_debut == 'l'){
        return choix_debut;
    }else{
        affichage_regles();
    }

    return 0;
}



int saisie_passe(int propertiesData[40][4],joueur global)
{
    char saisie = 0;

    cout << "Tapez r pour passer au prochain joueur et p pour afficher les proprietez du joueur" << endl;
    cin >> saisie;
    cin.clear();
    if(saisie == 'r')
    {
        return 0;
    }else if(saisie == 'p')
    {
        affichage_prop(propertiesData, global);
    }
    else
    {
        cout << "Erreur lors de la saisie " << endl;
        return saisie_passe(propertiesData, global);
    }
return saisie_passe(propertiesData, global);
}

int game_master(Data_joueur player, int propertiesData[40][4])
{
    if(player.human.tours_de_plateau == 0)
    {
        player.human.argent = 1500;
        player.bot1.argent = 1500;
        player.bot2.argent = 1500;

        player.human.playerNumber = 3;
        player.bot1.playerNumber = 1;
        player.bot2.playerNumber = 2;

        saisie_menu_debut();
        clear_screen();
    }
    do{

        player = pas_elim(player, propertiesData);
        player = elim_bot1(player,propertiesData);
        player = elim_bot2(player, propertiesData);

    }while(player.human.elimination == 0);


    return 0;
}

Data_joueur pas_elim(Data_joueur player, int propertiesData[40][4])
{

    while(player.human.elimination == 0 && player.bot1.elimination == 0 && player.bot2.elimination == 0)
    {
        player.human = gestion_joueur(propertiesData,player);

        cout << "*******************************BOT 1 **********************************" <<endl;
        player.bot1 = gestion_bot(propertiesData ,player , player.bot1, 1);

        cout << "*******************************BOT 2 **********************************" <<endl;
        player.bot2 = gestion_bot(propertiesData, player ,player.bot2, 2);

        player.human.elimination = verif_fin_de_partie(propertiesData,player.human);
        player.bot1.elimination = verif_fin_de_partie(propertiesData,player.bot1);
        player.bot2.elimination = verif_fin_de_partie(propertiesData,player.bot2);
    }
    return player;
}

Data_joueur elim_bot1(Data_joueur player,  int propertiesData[40][4])
{

    if(player.human.elimination == 0 && player.bot1.elimination == 1 && player.bot2.elimination == 0)
    {
        Affichage_elim_bot(player.bot1);
    }
    while (player.human.elimination == 0 && player.bot1.elimination == 1 && player.bot2.elimination == 0) {

        player.human = gestion_joueur(propertiesData, player);

        cout << "*******************************BOT 2 **********************************" <<endl;
        player.bot2 = gestion_bot(propertiesData, player ,player.bot2, 2);


        player.human.elimination = verif_fin_de_partie(propertiesData,player.human);
        player.bot2.elimination = verif_fin_de_partie(propertiesData,player.bot2);
    }
    return player;
}

Data_joueur elim_bot2(Data_joueur player,  int propertiesData[40][4])
{
    if(player.human.elimination == 0 && player.bot1.elimination == 0 && player.bot2.elimination == 1)
    {
        Affichage_elim_bot(player.bot2);
    }
    while (player.human.elimination == 0 && player.bot1.elimination == 0 && player.bot2.elimination == 1) {


        player.human = gestion_joueur(propertiesData, player);

        cout << "*******************************BOT 1 **********************************" <<endl;
        player.bot1 = gestion_bot(propertiesData, player ,player.bot1, 1);

        player.human.elimination = verif_fin_de_partie(propertiesData,player.human);
        player.bot1.elimination = verif_fin_de_partie(propertiesData,player.bot1);
    }

    return player;
}

joueur gestion_joueur(int propertiesData[40][4],Data_joueur player)
{

    player.human = Affichage_joueur(player);
    print_playboard(player.human, player.bot1, player.bot2);
    player = achat_prop_joueur(propertiesData, player);
    player.human.elimination = verif_fin_de_partie(propertiesData,player.human);

    saisie_passe(propertiesData, player.human);
    clear_screen();



    return player.human;
}

joueur gestion_bot(int propertiesData[40][4], Data_joueur player, joueur global, int bot)
{
    static int appel = 0;
    player.global = global;
    appel++;


    player.global = Affichage_bot(player.global, player.des_global);
    if(bot == 1)
    {
        print_playboard(player.human, player.global, player.bot2);
    }else{
        print_playboard(player.human, player.bot1, player.global);
    }


    player = achat_prop_bot(propertiesData, player.global, player);
    player.global.elimination = verif_fin_de_partie(propertiesData,player.global);
    saisie_passe(propertiesData, player.global);
    clear_screen();

    return player.global;
}

void Affichage_elim_bot(joueur global)
{
    cout << "-----------------------------------------------------------------------------------------"<< endl;
    cout << "                                        Le Bot Numero " << global.playerNumber << "                                       "<<endl;
    cout << "                    HeHe plus qu'un bot a eliminer et vous gagner la game!!!             "<< endl;
    cout << "-----------------------------------------------------------------------------------------"<< endl;

}


bool verif_fin_de_partie(int propertiesData[40][4],joueur global)
{
    if(global.argent > 0)
    {
        return  0;
    }else{

        for(int i = 0; i <= 40; i++)
        {
            if(propertiesData[i][3] == global.playerNumber)
            {
                propertiesData[i][0] = 0;
                propertiesData[i][3] = 0;
            }
        }

        return 1;
    }

}


