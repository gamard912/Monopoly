#include "properties.h"
#include <iostream>
#include "struct.h"

allProperties define_realEstate(allProperties estate){
    for (int i=1; i<11; i++){
        switch (i) {
            case 1:
                estate.propGrp1=define_propGrp(estate.propGrp1,i);
            break;
            case 2:
                estate.propGrp2=define_propGrp(estate.propGrp2,i);
            break;
            case 3:
                estate.propGrp3=define_propGrp(estate.propGrp3,i);
            break;
            case 4:
                estate.propGrp4=define_propGrp(estate.propGrp4,i);
            break;
            case 5:
                estate.propGrp5=define_propGrp(estate.propGrp5,i);
            break;
            case 6:
                estate.propGrp6=define_propGrp(estate.propGrp6,i);
            break;
            case 7:
                estate.propGrp7=define_propGrp(estate.propGrp7,i);
            break;
            case 8:
                estate.propGrp8=define_propGrp(estate.propGrp8,i);
            break;
            case 9:
                estate.propGrpStations=define_propGrp(estate.propGrpStations,i);
            break;
            case 10:
                estate.propGrpCompanies=define_propGrp(estate.propGrpCompanies,i);
            break;
            case 11:
                estate.propGrpTaxes=define_propGrp(estate.propGrpTaxes,i);
            break;
        }
    }
    return estate;
}
propertiesGrp define_propGrp(propertiesGrp propGrp, unsigned short int grpNumber){
    static unsigned int position=0;
    static unsigned int j=0;
    for (int i=0;i<propPerGrp[grpNumber-1];i++){
        position=calcul_propPosition(position,j);
        if(grpNumber>=1&&grpNumber<=8){
            switch (i){
                case 0:
                    propGrp.propA=define_basicProp(propGrp.propA,j,position);
                    break;
                case 1:
                    propGrp.propB=define_basicProp(propGrp.propB,j,position);
                    break;
                case 2:
                    propGrp.propC=define_basicProp(propGrp.propC,j,position);
                    break;
                case 3:
                    propGrp.propD=define_basicProp(propGrp.propD,j,position);
                    break;
            }
            j++;
        }
        else if(grpNumber==9){
            switch (i){
                case 0:
                    propGrp.propA=define_stations(propGrp.propA,j,position);
                    break;
                case 1:
                    propGrp.propB=define_stations(propGrp.propB,j,position);
                    break;
                case 2:
                    propGrp.propC=define_stations(propGrp.propC,j,position);
                    break;
                case 3:
                    propGrp.propD=define_stations(propGrp.propD,j,position);
                    break;
            }
            j++;
        }
        else if(grpNumber==10){
            switch (i){
                case 0:
                    propGrp.propA=define_stations(propGrp.propA,j,position);
                    break;
                case 1:
                    propGrp.propB=define_stations(propGrp.propB,j,position);
                    break;
            }
            j++;
        }
        else if(grpNumber==11){
            switch (i){
                case 0:
                    propGrp.propA=define_taxes(propGrp.propA,j,position,0);
                    break;
                case 1:
                    propGrp.propB=define_taxes(propGrp.propB,j,position,1);
                    break;
            }
            j++;
        }
    }
    return propGrp;
}

unsigned int calcul_propPosition(unsigned int position, unsigned int j){
    position = estatePositions[j];
    return position;
}

property define_basicProp(property prop, unsigned int propNumber, unsigned int propPosition){
    prop.price=estatePrice[propNumber];
    prop.rent=estateInitalRent[propNumber];
    prop.name=estateTags[propNumber];
    prop.position=propPosition;
    prop.buy=false;
    return prop;
}

property define_stations(property prop, unsigned int propNumber, unsigned int propPosition){
    prop.price=stationsPrice;
    prop.rent=stationsInitRent;
    prop.name=estateTags[propNumber];
    prop.position=propPosition;
    prop.buy=false;
    return prop;
}

property define_companies(property prop, unsigned int propNumber, unsigned int propPosition){
    prop.price=companiesPrice;
    prop.rent=-1;
    prop.name=estateTags[propNumber];
    prop.position=propPosition;
    prop.buy=true;
    return prop;
}

property define_taxes(property prop, unsigned int propNumber, unsigned int propPosition, unsigned int propIndex){
    prop.price=0;
    prop.rent=taxesRent[propIndex];
    prop.name=estateTags[propNumber];
    prop.position=propPosition;
    prop.buy=true;
    return prop;
}
