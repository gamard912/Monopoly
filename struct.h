#ifndef STRUCT_H
#define STRUCT_H
#include <string>

using namespace std;

typedef struct{

    int argent = 1500;
    int position = 0;  // case de depart
    int tours_de_plateau = 0;

}joueur;

typedef struct{

    int des1 = 0;
    int des2 =0;

} lancer ;

typedef struct{

    int rent;
    int price;
    string name;
    int position;
    bool buy;

}property;

#endif // STRUCT_H
