#include <iostream>
#include "properties.h"

using namespace std;


int achat_prop_joueur(int propertiesData[40][4], joueur player)
{
    char choix = 0;
    if(propertiesData[player.position][0] == 0 )
    {
        cout << endl << propNames[player.position] << " est disponible" << endl;
        cout << "Le prix pour l'achat de la propriete est de :" << propertiesData[player.position][1] << endl;
        if(propertiesData[player.position][1] <= player.argent)
        {
            cout << "Tapez a pour achetez la proprieter :" << endl;
            cin >> choix;
            if(choix == 'a')
            {
                player.argent -=  propertiesData[player.position][1];
                propertiesData[player.position][0] = 1;
                propertiesData[player.position][3] = 1;
                cout << "vous avez bien achetez cette prop" << endl;

            }else if(choix == 110){
                return player.argent;
            }else{
                cout << "Erreur lors de la saisie" <<endl;
                return achat_prop_joueur(propertiesData, player);
            }
        }else{
            cout << "Vous n'avez pas les fonds nécessaire afin d'acheter la proprieter" << endl;
        }

    }else if(propertiesData[player.position][0] >= 2)
    {
        cout << endl <<"Bienvenue sur la case : " << propNames[player.position] << endl;

    }else if(propertiesData[player.position][0] == 1)
    {
        cout << "la prop est deja acheter" << endl;
    }
    return player.argent;
}






int achat_prop_bot(int propertiesData[40][4], joueur bot)
{
    if(propertiesData[bot.position][0] == 0 )
    {
        cout << endl << propNames[bot.position] << " est disponible" << endl;
        cout << "Le prix pour l'achat de la propriete est de :" << propertiesData[bot.position][1] << endl;
        if(propertiesData[bot.position][1] <= bot.argent)
        {
                bot.argent -=  propertiesData[bot.position][1];
                propertiesData[bot.position][0] = 1;
                propertiesData[bot.position][3] = 1;
                cout << "vous avez bien achetez cette prop" << endl;
        }else{
            cout << "Le bot n'a pas les fonds nécessaire afin d'acheter la proprieter" << endl;
        }

    }else if(propertiesData[bot.position][0] >= 2)
    {
        cout << endl <<"Bienvenue sur la case : " << propNames[bot.position] << endl;

    }else if(propertiesData[bot.position][0] == 1)
    {
        cout << "la prop est deja acheter" << endl;
    }
    return bot.argent;
}
