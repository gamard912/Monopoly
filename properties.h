#ifndef PROPERTIES_H
#define PROPERTIES_H
#include <struct.h>

const int estatePrice[22]={60,60,100,100,120,140,140,160,180,180,200,220,220,240,260,260,280,300,300,320,350,400};
const int stationsPrice=200;
const int companiesPrice=150;
const int estateInitalRent[22]={2,4,6,6,8,10,10,12,14,14,16,18,18,20,22,22,22,26,26,28,35,50};
const int stationsInitRent=25;
const int taxesRent[2]={200,100};
const string estateTags[30]={"Boulevard de Belleville","Rue Lecourbe","Rue de Vaugirard","Boulevard Herteloup","Avenue de la République","Boulevard de la Vilette","Avenue de Neuilly","Rue du Paradis","Avenue Grammont",
                             "Boulevard Saint-Michel","Place Pigalle","Avenue Matignon","Boulevard Malesherbes","Rue Nationale","Faubourg Saint-Honoré","Place de la Bourse","Rue La Fayette","Avenue de Breteuil",
                             "Rue Gambetta","Boulevard des Capucines","Avenue des Champs-Elysées","Rue de la Paix","Gare Montparnasse","Gare de Lyon","Gare du Nord","Gare Saint-Lazare","Compagnie d'Electricité",
                             "Compagnie des Eaux","Impôts sur le revenu","Taxe de Luxe"};
const int propPerGrp[11]={2,3,3,3,3,3,3,2,4,2,2};
const unsigned int estatePositions[30]={1,3,6,8,9,11,13,14,16,18,19,21,23,24,26,27,29,31,32,34,37,39,5,15,25,35,12,28,2,38};

void define_realEstate(allProperties, unsigned short int);//Define all properties datas

void define_propGrp(propertiesGrp, unsigned short int); //Define each properties group

unsigned int calcul_propPosition(unsigned int, unsigned int);//Calcul property' position

property define_basicProp(property, unsigned int, unsigned int);

property define_stations(property, unsigned int, unsigned int);

property define_companies(property, unsigned int, unsigned int);

property define_taxes(property, unsigned int, unsigned int, unsigned int);

#endif // PROPERTIES_H
