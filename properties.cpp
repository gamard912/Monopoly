#include <iostream>
#include "properties.h"

joueur take_rents(int propertiesData[40][4], int playerNumber,joueur player){
    if ((propertiesData[player.position][3]==(-1)) || (propertiesData[player.position][3]==0) || (propertiesData[player.position][2]==0)){
        std::cout << "Internal Error, Cannot get rent !" << endl;
        //return error, case cannot get rent (because property doesn't have a owner or property has a rent of 0)
    }
    else if(propertiesData[player.position][3] == 0){
        if (propertiesData[player.position][2]>0){
            player.argent=player.argent-propertiesData[player.position][2];
        }
        else if (propertiesData[player.position][2]==(-1)){
            player.argent=player.argent-(player.dice * 4);
        }
    }
    return player;
}
