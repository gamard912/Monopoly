#include "playboard.h"
#include <iostream>
#include "struct.h"
#include "color.h"


using namespace std;

void print_playboard(joueur human, joueur bot1, joueur bot2){//Master playboard function
    cout << "******************************* PLATEAU DE JEU **********************************"<<endl;
    print_playerPosition(human,0);
    print_playerPosition(bot1,1);
    print_playerPosition(bot2,2);
    cout << endl;
    print_grid();
    cout << endl;
}

void print_playerPosition(joueur global, int playerIndex){
    for (int i=0;i<40;i++){
        cout << " ";
        if (i == global.position){
            switch (playerIndex){//Switch a letter for each player
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
    const char gridNames[5][40]={   {'S','B','C',' ','T','R',' ','L','B',' ','J','B','E',' ',' ','R',' ','C','B','P','F',' ','L','B',' ','R','F','P','W',' ','G',' ',' ','C','B','R','L',' ','L',' '},
                                    {'T','L','O','R','A','A','R','U','L','A','A','L','L','A','R','A','A','O','L','L','R','A','U','L','R','A','B','L','A','R','O','A','R','O','L','A','U','A','U','R'},
                                    {'A','V','M','U','X','I','U','C','V','V','I','V','E','V','U','I','V','M','V','A','E','V','C','V','U','I','O','A','T','U',' ','V','U','M','V','I','C','V','X','U'},
                                    {'R','R','M','E','E','L','E','K','R',' ','L','R','C',' ','E','L',' ','M','R','C','E',' ','K','R','E','L','U','C','E','E','T',' ','E','M','R','L','K',' ','E','E'},
                                    {'T','D','U',' ','S',' ',' ',' ','D',' ',' ','D',' ',' ',' ',' ',' ','U','D','E',' ',' ',' ','D',' ',' ','R','E','R',' ','O',' ',' ','U','D',' ',' ',' ',' ',' '}};
    //Definition of cases color
    const int gridColors[2][40]={   { 1 , 2 , 6 , 2 , 7 , 0 , 0 , 5 , 0 , 0 , 7 , 0 , 3 , 0 , 0 , 0 , 0 , 6 , 0 , 0 , 1 , 0 , 5 , 0 , 0 , 0 , 3 , 3 , 4 , 3 , 7 , 0 , 0 , 6 , 0 , 0 , 5 , 7 , 7 , 7},//txt color
                                    { 7 , 7 , 0 , 7 , 0 , 7 , 6 , 0 , 6 , 6 , 3 , 5 , 0 , 5 , 5 , 7 , 3 , 0 , 3 , 3 , 7 , 1 , 0 , 1 , 1 , 7 , 0 , 0 , 0 , 0 , 3 , 2 , 2 , 0 , 2 , 7 , 0 , 4 , 0 , 4}};//Background color

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

