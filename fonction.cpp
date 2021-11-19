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



// *********************************** General Functions *************************************


void affichage_regles(Data_joueur player)
{
    cout << endl;
    cout << "La partie commence avec 1500€ par joueur" << endl;
    cout << "Pour quitter, cliquez sur la croix." << endl;
    cout << "Deux joueurs ordinateurs vont jouer avec vous." << endl;
    cout << "Pour gagner la partie les deux autres joueurs ne doivent plus avoir d'argent." << endl<< endl;

    saisie_menu_debut(player);
}

Data_joueur saisie_menu_debut(Data_joueur player)
{
    char choix_debut = 0;
    cout << "Bienvenue sur le Monopoly by Ezio & Zoubir" << endl;
    cout << "Veuillez mettre la fenetre en pleine ecran " << endl;
    cout << "Pour lancer la partie tapez 'l' et pour afficher les règles 'r'" << endl;
    cin >> choix_debut;


    if(choix_debut != 'l' && choix_debut != 'r')
    {
        cout << "Erreur lors de la saisie" << endl;
        if(choix_debut=='d'){
            player.bot1.argent=100;
            player.bot2.argent=100;
            cout << "Debug mod ok"<<endl;
        }
        return player=saisie_menu_debut(player);
    }
    else if(choix_debut == 'l'){
        return player;
    }
    else{
        affichage_regles(player);
    }
    return player;
}



int saisie_passe(int propertiesData[40][4],joueur global)
{
    char saisie = 0;

    cout << "Tapez 'r' pour passer au prochain joueur et sur 'p' pour afficher vos propriétés" << endl;
    cin >> saisie;
    cin.clear();
    if(saisie == 'r')
    {
        return 0;
    }
    else if(saisie == 'p')
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
    bool flagElim = 0;
    if(player.human.tours_de_plateau == 0)
    {
        player = init_valeur_joueur(player);

        player=saisie_menu_debut(player);//print initial menu
        clear_screen();//clear all screen
    }
    do{

        player = pas_elim(player, propertiesData);//Call not eliminate function
        player = elim_bot1(player,propertiesData);//Call bot1 eliminatation function
        player = elim_bot2(player, propertiesData);//Same for bot2
        flagElim=Affichage_statut_joueur(propertiesData, player, flagElim);//If get out of loop, player has win or loose, so printing his statut

    }while(player.human.elimination == 0 && !flagElim);
    return 0;
}

bool Affichage_statut_joueur(int propertiesData[40][4] ,Data_joueur player, bool flagElim)
{
    player.human.elimination = verif_fin_de_partie(propertiesData,player.human);
    if(player.human.elimination == 1)
    {
        cout << "  _______  _______  _______  _______    _______           _______  _______  " << endl;
        cout << " (  ____ \\(  ___  )(       )(  ____ \\  (  ___  )|\\     /|(  ____ \\(  ____ ) " << endl;
        cout << " | (    \\/| (   ) || () () || (    \\/  | (   ) || )   ( || (    \\/| (    )| " << endl;
        cout << " | |      | (___) || || || || (__      | |   | || |   | || (__    | (____)| " << endl;
        cout << " | | ____ |  ___  || |(_)| ||  __)     | |   | |( (   ) )|  __)   |     __) " << endl;
        cout << " | | \\_  )| (   ) || |   | || (        | |   | | \\ \\_/ / | (      | (\\ (    " << endl;
        cout << " | (___) || )   ( || )   ( || (____/\\  | (___) |  \\   /  | (____/\\| ) \\ \\__ " << endl;
        cout << " (_______)|/     \\||/     \\|(_______/  (_______)   \\_/   (_______/|/   \\__/ " << endl;
        flagElim=1;
    }

//call each player management function
    else if(player.human.elimination == 0 && player.bot1.elimination == 1 && player.bot2.elimination == 1)
    {
        cout << "          _______                     _________ _       " << endl;
        cout << "|\\     /|(  ___  )|\\     /|  |\\     /|\\__   __/( (    /|" << endl;
        cout << "( \\   / )| (   ) || )   ( |  | )   ( |   ) (   |  \\  ( |" << endl;
        cout << " \\ (_) / | |   | || |   | |  | | _ | |   | |   |   \\ | |" << endl;
        cout << "  \\   /  | |   | || |   | |  | |( )| |   | |   | (\\ \\) |" << endl;
        cout << "   ) (   | |   | || |   | |  | || || |   | |   | | \\   |" << endl;
        cout << "   | |   | (___) || (___) |  | () () |___) (___| )  \\  |" << endl;
        cout << "   \\_/   (_______)(_______)  (_______)\\_______/|/    )_)" << endl;
        flagElim=1;
    }

//Define each player money to the initial Value
    return flagElim;
}

Data_joueur pas_elim(Data_joueur player, int propertiesData[40][4])
{

    while(player.human.elimination == 0 && player.bot1.elimination == 0 && player.bot2.elimination == 0)
    {
        player = gestion_joueur(propertiesData,player);

        cout << "******************************* BOT 1 **********************************" <<endl;
        player = gestion_bot(propertiesData ,player , player.bot1, 1);
        player.bot1 = player.global;


        cout << "******************************* BOT 2 **********************************" <<endl;
        player = gestion_bot(propertiesData, player ,player.bot2, 2);
        player.bot2 = player.global;

        //Check for each player if there are in bankroute or not
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

        player = gestion_joueur(propertiesData, player);

        cout << "******************************* BOT 2 **********************************" <<endl;
        player = gestion_bot(propertiesData, player ,player.bot2, 2);
        player.bot2 = player.global;

        //Check for each player still in game if there are in bankroute or not
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


        player = gestion_joueur(propertiesData, player);

        cout << "******************************* BOT 1 **********************************" <<endl;
        player = gestion_bot(propertiesData, player ,player.bot1, 1);
        player.bot1 = player.global;

        //Check for each player still in game if there are in bankroute or not
        player.human.elimination = verif_fin_de_partie(propertiesData,player.human);
        player.bot1.elimination = verif_fin_de_partie(propertiesData,player.bot1);
    }

    return player;
}

Data_joueur gestion_joueur(int propertiesData[40][4],Data_joueur player)
{
    player.human = Affichage_joueur(player);//Print all player data (money, dices, etc)
    print_playboard(player.human, player.bot1, player.bot2);//print the playboard
    player = achat_prop_joueur(propertiesData, player);//Check if the player can buy a property

    player.human.elimination = verif_fin_de_partie(propertiesData,player.human);//Loose or not ?

    saisie_passe(propertiesData, player.human);
    clear_screen();



    return player;
}

Data_joueur gestion_bot(int propertiesData[40][4], Data_joueur player, joueur global, int bot)
{
    static int appel = 0;
    player.global = global;
    appel++;


    player.global = Affichage_bot(player.global, player.des_global);
    if(bot == 1)
    {
        print_playboard(player.human, player.global, player.bot2);
    }
    else{
        print_playboard(player.human, player.bot1, player.global);
    }


    player = achat_prop_bot(propertiesData, player.global, player);
    player.global.elimination = verif_fin_de_partie(propertiesData,player.global);
    saisie_passe(propertiesData, player.global);
    clear_screen();

    return player;
}

void Affichage_elim_bot(joueur global)
{
    cout << "-----------------------------------------------------------------------------------------"<< endl;
    cout << endl;
    cout << "                                        Le Bot Numero " << global.playerNumber << "                                       "<<endl;
    cout << "                    HeHe plus qu'un bot a eliminer et vous gagnerez la partie !!!             "<< endl;
    cout << endl;
    cout << "-----------------------------------------------------------------------------------------"<< endl;

}


bool verif_fin_de_partie(int propertiesData[40][4],joueur global)
{
    if(global.argent > 0)
    {
        return  0;
    }
    else{

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


