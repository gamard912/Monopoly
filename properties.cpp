#include "properties.h"
#include <iostream>
#include "struct.h"

void define_realEstate(allProperties estate){
    for (int i=1; i<11; i++){
        switch (i) {
            case 1:
                define_propGrp(estate.propGrp1,i);
            break;
            case 2:
                define_propGrp(estate.propGrp2,i);
            break;
            case 3:
                define_propGrp(estate.propGrp3,i);
            break;
            case 4:
                define_propGrp(estate.propGrp4,i);
            break;
            case 5:
                define_propGrp(estate.propGrp5,i);
            break;
            case 6:
                define_propGrp(estate.propGrp6,i);
            break;
            case 7:
                define_propGrp(estate.propGrp7,i);
            break;
            case 8:
                define_propGrp(estate.propGrp8,i);
            break;
            case 9:
                define_propGrp(estate.propGrpStations,i);
            break;
            case 10:
                define_propGrp(estate.propGrpCompanies,i);
            break;
            case 11:
                define_propGrp(estate.propGrpTaxes,i);
            break;
        }
    }
}
void define_propGrp(propertiesGrp propGrp, unsigned short int grpNumber){
    const int estatePrice[22]={60,60,100,100,120,140,140,160,180,180,200,220,220,240,260,260,280,300,300,320,350,400};
    const int stationsPrice=200;
    const int companiesPrice=150;
    const int estateInitalRent[22]={2,4,6,6,8,10,10,12,14,14,16,18,18,20,22,22,22,26,26,28,35,50};
    const int stationsInitRent=25;
    const int taxesRent[2]={200,100};
    const short estateTags[22]={};
    const int propPerGrp[11]={2,3,3,3,3,3,3,2,4,2,2};
    static unsigned int positions=0;
    static unsigned int j=0;
    for (unsigned int i=0;i<propPerGrp[grpNumber-1];i++){
        if(grpNumber>=1&&grpNumber<=8){
            switch (i){
                case 0:
                    propGrp.propA.price=estatePrice[j];
                    propGrp.propA.rent=estateInitalRent[j];
                    propGrp.propA.name=estateTags[j];
                    propGrp.propA.position=positions;
                    propGrp.propA.buy=false;
                    break;
                case 1:
                    propGrp.propB.price=estatePrice[j];
                    propGrp.propB.rent=estateInitalRent[j];
                    propGrp.propB.name=estateTags[j];
                    propGrp.propB.position=positions;
                    propGrp.propB.buy=false;
                    break;
                case 2:
                    propGrp.propC.price=estatePrice[j];
                    propGrp.propC.rent=estateInitalRent[j];
                    propGrp.propC.name=estateTags[j];
                    propGrp.propC.position=positions;
                    propGrp.propC.buy=false;
                    break;
                case 3:
                    propGrp.propD.price=estatePrice[j];
                    propGrp.propD.rent=estateInitalRent[j];
                    propGrp.propD.name=estateTags[j];
                    propGrp.propD.position=positions;
                    propGrp.propD.buy=false;
                    break;
            }
            j++;
        }
        else if(grpNumber==9){
        }
        else if(grpNumber==10){
        }
        else if(grpNumber==11){
        }
    }
}
