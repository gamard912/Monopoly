#ifndef STRUCT_H
#define STRUCT_H
#include <string>

using namespace std;

typedef struct{

    int argent;
    int position = 0;  // case de depart
    int tours_de_plateau = 0;
    int dice;

}joueur;

typedef struct{

    int des1 = 0;
    int des2 =0;

} lancer ;


#endif // STRUCT_H
