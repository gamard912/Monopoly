#ifndef PROPERTIES_H
#define PROPERTIES_H
#include <struct.h>

const int estatePrice[22]={60,60,100,100,120,140,140,160,180,180,200,220,220,240,260,260,280,300,300,320,350,400};
const int stationsPrice=200;
const int companiesPrice=150;
const int estateInitalRent[22]={2,4,6,6,8,10,10,12,14,14,16,18,18,20,22,22,22,26,26,28,35,50};
const int stationsInitRent=25;
const int taxesRent[2]={200,100};
const string propNames[40]={"Start","Boulevard de Belleville","Caisse de Communauté","Rue Lecourbe","Impôts sur le revenu","Gare Montparnasse","Rue de Vaugirard","Chance","Boulevard Herteloup","Avenue de la République",
                             "Prison (Simple Visite)","Boulevard de la Vilette","Compagnie d'Electricité","Avenue de Neuilly","Rue du Paradis","Gare de Lyon","Avenue Grammont","Rue Gambetta","Caisse de Communauté",
                             "Boulevard Saint-Michel","Place Pigalle","Parc Gratuit","Avenue Matignon","Boulevard Malesherbes","Rue Nationale","Gare du Nord","Faubourg Saint-Honoré","Place de la Bourse","Compagnie des Eaux",
                             "Rue La Fayette","Allez en prison...","Avenue de Breteuil","Rue de Boulogne","Caisse de Communauté","Boulevard des Capucines","Gare Saint-Lazare","Chance","Avenue des Champs-Elysées",
                             "Taxe de Luxe","Rue de la Paix"};

allProperties define_realEstate(allProperties);//Define all properties datas

propertiesGrp define_propGrp(propertiesGrp, unsigned short int); //Define each properties group

unsigned int calcul_propPosition(unsigned int, unsigned int);//Calcul property' position

property define_basicProp(property, unsigned int, unsigned int);

property define_stations(property, unsigned int, unsigned int);

property define_companies(property, unsigned int, unsigned int);

property define_taxes(property, unsigned int, unsigned int, unsigned int);

#endif // PROPERTIES_H
