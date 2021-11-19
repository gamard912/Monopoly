#include <iostream>
#include "properties.h"

using namespace std;


Data_joueur achat_prop_joueur(int propertiesData[40][4], Data_joueur player)
{
    if(propertiesData[player.human.position][0] == 0 )
    {
        cout << endl << propNames[player.human.position] << " est disponible" << endl;
        cout << "Le prix pour l'achat de la propriété est de :" << propertiesData[player.human.position][1] <<"€" << endl;
        player = verification_et_gestion_de_prop_joueur(propertiesData, player);

    }
    else if(propertiesData[player.human.position][0] >= 2)
    {
        cout << endl <<"Bienvenue sur la case : " << propNames[player.human.position] << endl;

    }
    else if(propertiesData[player.human.position][0] == 1)
    {
        cout << "Cette propiété appartient à un autre joueur, vous lui devez donc un loyer de : " << propertiesData[player.human.position][2] <<"€ " <<endl;
        player = take_rents(propertiesData, player, player.human);
        player.human = player.global;

    }

    return player;
}

Data_joueur verification_et_gestion_de_prop_joueur(int propertiesData[40][4],Data_joueur player)
{
    char choix = 0;
    if(propertiesData[player.human.position][1] <= player.human.argent)
    {
        cout << "Tapez 'a' pour acheter cette propriété et 'n' pour refuser :" << endl;
        cin >> choix;
        if(choix == 'a')
        {
            player.human.argent -=  propertiesData[player.human.position][1];
            propertiesData[player.human.position][0] = 1;//Write this property is not available
            propertiesData[player.human.position][3] = player.human.playerNumber;//Write in the properties data at witch player belongs the property
            cout << "Vous avez bien acheté cette propriété !" << endl;

        }
        else if(choix == 110){
            return player;
        }
        else{
            cout << "Erreur lors de la saisie" <<endl;
            return achat_prop_joueur(propertiesData, player);
        }
    }
    else{
        cout << "Vous n'avez pas les fonds nécessaire afin d'acheter la propriété" << endl;
    }
    return player;
}


Data_joueur take_rents(int propertiesData[40][4], Data_joueur player, joueur global)
{
    if ((propertiesData[global.position][3] == (-1)) || (propertiesData[global.position][3]==0) || (propertiesData[global.position][2]==0))
    {
        cout << "Internal Error, Cannot get rent !" << endl;
        //return error, case cannot get rent (because property doesn't have a owner or property has a rent of 0)
    }
    else if(propertiesData[global.position][3] != global.playerNumber)
    {
        if (propertiesData[global.position][2] > 0)
        {
            global.argent = global.argent - propertiesData[global.position][2];

            player.human = ajout_sous_loyer(propertiesData, global, player.human);
            player.bot1 = ajout_sous_loyer(propertiesData, global, player.bot1);
            player.bot2 = ajout_sous_loyer(propertiesData, global, player.bot2);

        }
        else if (propertiesData[player.human.position][2]==(-1))
        {
            player.human.argent=player.human.argent-(player.human.dice * 4);
        }
    }
    player.global = global;
    return player;
}


joueur ajout_sous_loyer(int propertiesData[40][4], joueur global, joueur ajout_sous)
{
    if(propertiesData[global.position][3] == ajout_sous.playerNumber)
    {
        cout << ajout_sous.achat_prop << propertiesData[global.position][2] <<"€ " <<endl;
        ajout_sous.argent = ajout_sous.argent+propertiesData[global.position][2];

    }
    return ajout_sous;
}

void affichage_prop(int propertiesData[40][4],joueur global)
{

    cout << endl << "Ce joueur possede :" << endl;
    for(int i = 0; i <= 40; i++)
    {
        if(propertiesData[i][0] == 1 && propertiesData[i][3] == global.playerNumber)
        {
            cout << propNames[i] << endl;
        }
    }
    cout << endl;

}



Data_joueur achat_prop_bot(int propertiesData[40][4], joueur global, Data_joueur player)//Same as achat_prop_joueur for bots
{
    player.global = global;
    if(propertiesData[player.global.position][0] == 0 )
    {
        cout << endl << propNames[player.global.position] << " est disponible" << endl;
        cout << "Le prix pour l'achat de la propriete est de :" << propertiesData[player.global.position][1] << endl;

        player = verification_et_gestion_de_prop_bot(propertiesData, player);

    }
    else if(propertiesData[player.global.position][0] >= 2)
    {
        cout << endl <<"Bienvenue sur la case : " << propNames[player.global.position] << endl;

    }
    else if(propertiesData[player.global.position][0] == 1)
    {
        player = take_rents(propertiesData, player, global);

        if(global.playerNumber == 1)
        {
            player.bot1 = player.global;
        }
        else if(global.playerNumber == 2)
        {
            player.bot2 = player.global;
        }
    }

    return player;
}

Data_joueur verification_et_gestion_de_prop_bot(int propertiesData[40][4],Data_joueur player)
{
    if(propertiesData[player.global.position][1] <= player.global.argent)
    {
            player.global.argent -=  propertiesData[player.global.position][1];
            propertiesData[player.global.position][0] = 1;
            propertiesData[player.global.position][3] = player.global.playerNumber;
            cout << "Vous avez bien acheté cette propriété" << endl;
    }
    else{
        cout << "Le bot n'a pas les fonds nécessaires afin d'acheter cette propriété" << endl;
    }
    return player;
}
