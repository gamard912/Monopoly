#include "playboard.h"
#include <iostream>
#include "struct.h"

using namespace std;

void print_playboard(joueur player, joueur bot1, joueur bot2){
    print_playerPosition(player);
    print_playerPosition(bot1);
    print_playerPosition(bot2);
    cout << endl;
    print_grid();
    cout << endl;
}

void print_playerPosition(joueur player){
    static unsigned short int playerIndex=0;
    for (int i=0;i<40;i++){
        cout << " ";
        if (i==player.position){
            switch (playerIndex){
                case 0:
                cout << "J ";
                break;

            case 1:
                cout << "B1";
            case 2:
                cout << "B2";
            }
        }
        else{cout<<"   ";}
    }
    if(playerIndex==2){
        playerIndex=0;
    }
    cout << endl;
}


void print_grid(){
    //Definition of cases names
    const char gridNames[5][40]={   {'S',32,32,32,32,32,32,32,32,32,'J',32,32,32,32,32,32,32,32,32,'F',32,32,32,32,32,32,32,32,32,'G',32,32,32,32,32,32,32,32,32},
                                    {'T',32,32,32,32,32,32,32,32,32,'A',32,32,32,32,32,32,32,32,32,'R',32,32,32,32,32,32,32,32,32,'O',32,32,32,32,32,32,32,32,32},
                                    {'A',32,32,32,32,32,32,32,32,32,'I',32,32,32,32,32,32,32,32,32,'E',32,32,32,32,32,32,32,32,32,' ',32,32,32,32,32,32,32,32,32},
                                    {'R',32,32,32,32,32,32,32,32,32,'L',32,32,32,32,32,32,32,32,32,'E',32,32,32,32,32,32,32,32,32,'T',32,32,32,32,32,32,32,32,32},
                                    {'T',32,32,32,32,32,32,32,32,32,' ',32,32,32,32,32,32,32,32,32,' ',32,32,32,32,32,32,32,32,32,'O',32,32,32,32,32,32,32,32,32}};
    //Printing of the grid
    for (int lines=0; lines<5; lines++){
        for(int i=0; i<40; i++){
            cout << " " << gridNames[lines][i] << " ";
            if (i<39){
                cout << "|";
            }
        }
        cout << endl;
    }
}
