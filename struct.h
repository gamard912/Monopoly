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

    int price;
    int rent;
    string name;
    unsigned int position;
    bool buy;

}property;

typedef struct{
    property propA;
    property propB;
    property propC;
    property propD;
}propertiesGrp;

typedef struct{
    propertiesGrp propGrp1;
    propertiesGrp propGrp2;
    propertiesGrp propGrp3;
    propertiesGrp propGrp4;
    propertiesGrp propGrp5;
    propertiesGrp propGrp6;
    propertiesGrp propGrp7;
    propertiesGrp propGrp8;
    propertiesGrp propGrpStations;
    propertiesGrp propGrpCompanies;
    propertiesGrp propGrpTaxes;
}allProperties;

#endif // STRUCT_H
