#include "playboard.h"
#include <iostream>
#include "struct.h"
#include "color.h"

using namespace std;

void print_playboard(joueur player, joueur bot1, joueur bot2){
    cout << "******************************* PLATEAU DE JEU **********************************"<<endl;
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
    const int gridColors[2][40]={   { 1 , 2, 6 , 2, 0, 0 , 0, 5 , 0, 0, 3 , 0, 0 , 0, 0, 0 , 0, 6 , 0, 0, 1 , 0, 5 , 0, 0, 0 , 3, 3, 4 , 3, 4 , 0, 0, 0 , 0, 0 , 7 , 0, 0, 0},//txt color
                                    { 7 , 7, 0 , 7, 0, 7 , 6, 0 , 6, 6, 0 , 5, 0 , 5, 5, 7 , 3, 0 , 3, 3, 7 , 1, 0 , 1, 1, 7 , 0, 0, 0 , 0, 1 , 2, 2, 0 , 2, 7 , 0 , 4, 4, 4}};//Background color

    //Printing of the grid
    for (int lines=0; lines<5; lines++){
        for(int i=0; i<40; i++){
            setColor(gridColors[0][i],gridColors[1][i]);
            cout << " " << gridNames[lines][i] << " ";
            setColor(9,9);
            if (i<39){
                cout << "|";
            }
        }
        cout << endl;
    }
}

void setColor(int txtColor, int backgColor){ //Function to set the next cout color
    const unsigned short int colorLimit=7;
    //NB : 0-Black, 1-Red, 2-Green, 3-Orange, 4-Blue, 5-Magenta, 6-Cyan, 7-White, 9-Reset
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

