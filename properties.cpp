#include <iostream>
#include "properties.h"

using namespace std;


int achat_prop_joueur(int propertiesData[40][4], Data_joueur player)
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
                propertiesData[player.human.position][3] = 1;
                cout << "vous avez bien achetez cette prop" << endl;

            }else if(choix == 110){
                return player.human.argent;
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
        cout << "la prop est deja acheter" << endl;
    }
    return player.human.argent;
}






int achat_prop_bot(int propertiesData[40][4], joueur global)
{
    if(propertiesData[global.position][0] == 0 )
    {
        cout << endl << propNames[global.position] << " est disponible" << endl;
        cout << "Le prix pour l'achat de la propriete est de :" << propertiesData[global.position][1] << endl;
        if(propertiesData[global.position][1] <= global.argent)
        {
                global.argent -=  propertiesData[global.position][1];
                propertiesData[global.position][0] = 1;
                propertiesData[global.position][3] = 1;
                cout << "vous avez bien achetez cette prop" << endl;
        }else{
            cout << "Le bot n'a pas les fonds nécessaire afin d'acheter la proprieter" << endl;
        }

    }else if(propertiesData[global.position][0] >= 2)
    {
        cout << endl <<"Bienvenue sur la case : " << propNames[global.position] << endl;

    }else if(propertiesData[global.position][0] == 1)
    {
        cout << "la prop est deja acheter" << endl;
    }
    return global.argent;
}
