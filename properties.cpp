#include <iostream>
#include "properties.h"

using namespace std;


Data_joueur achat_prop_joueur(int propertiesData[40][4], Data_joueur player)
{
    char choix = 0;
    if(propertiesData[player.human.position][0] == 0 )
    {
        cout << endl << propNames[player.human.position] << " est disponible" << endl;
        cout << "Le prix pour l'achat de la propriete est de :" << propertiesData[player.human.position][1] << endl;
        if(propertiesData[player.human.position][1] <= player.human.argent)
        {
            cout << "Tapez a pour achetez la proprieter :" << endl;
            cin >> choix;
            if(choix == 'a')
            {
                player.human.argent -=  propertiesData[player.human.position][1];
                propertiesData[player.human.position][0] = 1;
                propertiesData[player.human.position][3] = player.human.playerNumber;
                cout << "vous avez bien achetez cette prop" << endl;

            }else if(choix == 110){
                return player;
            }else{
                cout << "Erreur lors de la saisie" <<endl;
                return achat_prop_joueur(propertiesData, player);
            }
        }else{
            cout << "Vous n'avez pas les fonds nécessaire afin d'acheter la proprieter" << endl;
        }

    }else if(propertiesData[player.human.position][0] >= 2)
    {
        cout << endl <<"Bienvenue sur la case : " << propNames[player.human.position] << endl;

    }else if(propertiesData[player.human.position][0] == 1)
    {
        cout << "La propieter est deja acheter vous payer donc : " << propertiesData[player.human.position][2] <<"e " <<endl;
        player = take_rents(propertiesData, player, player.human);
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
            if(propertiesData[global.position][3] == player.bot1.playerNumber)
            {
                cout << "le bot 1 recoit donc : " << propertiesData[global.position][2] <<"e " <<endl;
                player.bot1.argent += propertiesData[player.human.position][2];
            }else if(propertiesData[global.position][3] == player.bot2.playerNumber)
            {
                cout << "le bot 2 recoit donc : " << propertiesData[global.position][2] <<"e " <<endl;
                player.bot2.argent += propertiesData[player.human.position][2];
            }else if(propertiesData[global.position][3] == player.human.playerNumber)
            {
                cout << "La propieter est deja acheter vous gagner donc : " << propertiesData[global.position][2] <<"e " <<endl;
                player.human.argent += propertiesData[global.position][2];
            }
        }
        else if (propertiesData[player.human.position][2]==(-1))
        {
            player.human.argent=player.human.argent-(player.human.dice * 4);
        }
    }
    return player;
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



Data_joueur achat_prop_bot(int propertiesData[40][4], joueur global, Data_joueur player)
{
    player.global = global;
    if(propertiesData[player.global.position][0] == 0 )
    {
        cout << endl << propNames[player.global.position] << " est disponible" << endl;
        cout << "Le prix pour l'achat de la propriete est de :" << propertiesData[player.global.position][1] << endl;
        if(propertiesData[player.global.position][1] <= player.global.argent)
        {
                player.global.argent -=  propertiesData[player.global.position][1];
                propertiesData[player.global.position][0] = 1;
                propertiesData[player.global.position][3] = player.global.playerNumber;
                cout << "vous avez bien achetez cette prop" << endl;
        }else{
            cout << "Le bot n'a pas les fonds nécessaire afin d'acheter la proprieter" << endl;
        }

    }else if(propertiesData[player.global.position][0] >= 2)
    {
        cout << endl <<"Bienvenue sur la case : " << propNames[player.global.position] << endl;

    }else if(propertiesData[player.global.position][0] == 1)
    {
        player = take_rents(propertiesData, player, global);
    }

    return player;
}
