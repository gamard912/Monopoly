#include "playboard.h"
#include <iostream>
#include "struct.h"
#include "color.h"

using namespace std;

void print_playboard(joueur player, joueur bot1, joueur bot2){
    print_playerPosition(player,0);
    print_playerPosition(bot1,1);
    print_playerPosition(bot2,2);
    cout << endl;
    print_grid();
    cout << endl;
}

void print_playerPosition(joueur player, int playerIndex){
    for (int i=0;i<40;i++){
        cout << " ";
        if (i==player.position){
            switch (playerIndex){
                case 0:
                    cout << "J ";
                    break;
                case 1:
                    cout << "B1";
                    break;
                case 2:
                    cout << "B2";
                    break;
            }
        }
        else{cout<<"   ";}
    }
    cout << endl;
}


void print_grid(){
    //Definition of cases names
    const char gridNames[5][40]={   {'S',32,'C',32,32,'R',32,'L',32,32,'J',32,'E',32,32,'R',32,'C',32,32,'F',32,'L',32,32,'R',32,32,'W',32,'G',32,32,'C',32,'R','L',32,32,32},
                                    {'T',32,'O',32,32,'A',32,'U',32,32,'A',32,'L',32,32,'A',32,'O',32,32,'R',32,'U',32,32,'A',32,32,'A',32,'O',32,32,'O',32,'A','U',32,32,32},
                                    {'A',32,'M',32,32,'I',32,'C',32,32,'I',32,'E',32,32,'I',32,'M',32,32,'E',32,'C',32,32,'I',32,32,'T',32,' ',32,32,'M',32,'I','C',32,32,32},
                                    {'R',32,'M',32,32,'L',32,'K',32,32,'L',32,'C',32,32,'L',32,'M',32,32,'E',32,'K',32,32,'L',32,32,'E',32,'T',32,32,'M',32,'L','K',32,32,32},
                                    {'T',32,'U',32,32,' ',32,' ',32,32,' ',32,' ',32,32,' ',32,'U',32,32,' ',32,' ',32,32,' ',32,32,'R',32,'O',32,32,'U',32,' ',' ',32,32,32}};
    //Definition of cases color
    const int gridColors[40]=       { 2 , 8, 3 , 8, 6, 15 ,11, 5 ,11,11, 8 , 5, 3 , 5, 5, 15 ,10, 3 ,10,10, 6 , 4, 5 , 4, 4, 15 ,14,14, 0 ,14, 1 , 6, 6, 3 , 6, 15 , 5 , 1,14, 1};

    //Printing of the grid
    for (int lines=0; lines<5; lines++){
        for(int i=0; i<40; i++){
            setColor(gridColors[i],0);
            cout << " " << gridNames[lines][i] << " ";
            setColor(15,0);
            if (i<39){
                cout << "|";
            }
        }
        cout << endl;
    }
}

void setColor(int txtColor, int backgColor){ //Function to set the next cout color
    const unsigned short int colorLimit=7;
    //NB : 0-Black, 1-Red, 2-Green, 3-Yellow, 4-Blue, 5-Magenta, 6-Cyan, 7-White, 9-Reset
    if (txtColor>colorLimit && backgColor>colorLimit){
        cout << ALL_RESET;
    }
    else if (txtColor>colorLimit && backgColor<colorLimit){
        cout << TXT_DEFAULT;
    }
    else if (backgColor>colorLimit && txtColor<colorLimit){
        cout << BACKG_DEFAULT;
    }
    else{
        cout << IDENT << txtColor+30 <<CLOSER<<IDENT<<backgColor+40<<CLOSER;
    }
}

