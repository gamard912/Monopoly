#include "playboard.h"
#include <iostream>
#include "struct.h"
#include <windows.h>

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
    const int gridColors[40]=       { 6 , 8, 3 , 8, 6, 15 ,11, 5 ,11,11, 8 , 5, 3 , 5, 5, 15 ,10, 3 ,10,10, 6 , 4, 5 , 4, 4, 15 ,14,14, 0 ,14, 1 , 6, 6, 3 , 6, 15 , 5 , 1,14, 1};

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
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),txtColor/*16+backgColor*/);
    //NB : 0-Black, 1-Dark Blue, 2-Dark Green, 3-Turquoise, 4-Dark Red, 5-Purple, 6-Green Goose Poop, 7-Light Gray, 8-Dark Gray, 9-Light Blue, 10-Light Green, 11-Turquoise
    //12-Light Red, 13-Purple 2, 14-Yellow, 15-White

}

