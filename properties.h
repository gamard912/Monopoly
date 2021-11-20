#ifndef PROPERTIES_H
#define PROPERTIES_H
#include <struct.h>

//Array with properties Names
const string propNames[40]={"Start","Boulevard de Belleville","Caisse de Communauté","Rue Lecourbe","Impôts sur le revenu","Gare Montparnasse","Rue de Vaugirard","Chance","Boulevard Heurteloup","Avenue de la République",
                             "Prison (Simple Visite)","Boulevard de la Vilette","Compagnie d'Electricité","Avenue de Neuilly","Rue du Paradis","Gare de Lyon","Avenue Grammont","Caisse de Communauté",
                             "Boulevard Saint-Michel","Place Pigalle","Parc Gratuit","Avenue Matignon","Chance","Boulevard Malesherbes","Rue Nationale","Gare du Nord","Faubourg Saint-Honoré","Place de la Bourse","Compagnie des Eaux",
                             "Rue La Fayette","Allez en prison...","Avenue de Breteuil","Rue de Boulogne","Caisse de Communauté","Boulevard des Capucines","Gare Saint-Lazare","Chance","Avenue des Champs-Elysées",
                             "Taxe de Luxe","Rue de la Paix"};

Data_joueur take_rents(int propertiesData[40][4], Data_joueur player, joueur global);//Calculating and take rents for each player

void affichage_prop (int propertiesData[40][4], joueur);//print real estate of human player

Data_joueur achat_prop_joueur(int propertiesData[40][4], Data_joueur player);//Purchase property for human player

Data_joueur achat_prop_bot(int propertiesData[40][4], joueur global, Data_joueur player);//Purchase property for bot player

Data_joueur verification_et_gestion_de_prop_joueur(int propertiesData[40][4],Data_joueur player);

Data_joueur verification_et_gestion_de_prop_bot(int propertiesData[40][4],Data_joueur player);

joueur ajout_sous_loyer(int propertiesData[40][4], joueur global, joueur);

#endif // PROPERTIES_H
