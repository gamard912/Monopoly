//#include "struct.h"
//#include <iostream>
//#include <time.h>
//#include <stdio.h>
//#include <stdlib.h>

//using namespace std;
//// ******************************* Tout ce qui concerne le bot1 *************************************
//lancer des_du_bot1(lancer des_bot1)
//{
//    des_bot1.des1 = rand()%6 + 1;
//    des_bot1.des2 = rand()%6 + 1;

//    return  des_bot1;
//}
//joueur position_bot1(joueur bot1, lancer des_bot1)
//{
//    static int position_bot1 = 0;                                //on crée une variable en static afin qu'elle ne soit pas redefinie a 0
//    static int argent_bot1 = 1500;
//    static unsigned int pre_position_bot1 = 0;
//    int somme_des_bot1 = 0;

//    somme_des_bot1 =  des_bot1.des1 + des_bot1.des2;
//    position_bot1 += somme_des_bot1;                                  // on calcul la position en fonction des dés et de la position précedentes
//    pre_position_bot1 = position_bot1 - somme_des_bot1;

//    if(position_bot1 > 40)
//    {
//        position_bot1 = (pre_position_bot1 + somme_des_bot1)-40;
//        argent_bot1 += 200;
//    }
//    if(position_bot1 == 1)
//    {
//        argent_bot1 += 400;
//    }

//    bot1.argent = argent_bot1;
//    bot1.position = position_bot1;
//    return bot1;
//}
//joueur Affichage_bot1(joueur bot1, lancer des_bot1)
//{
//    bot1 = position_bot1(bot1, des_bot1);
//    cout << "*******************************BOT 1**********************************" <<endl;
//    cout << "le bot1 a : " << bot1.argent << "e" <<endl;
//    cout << "il est a la case : " << bot1.position  << endl;

//    des_bot1 = des_du_bot1(des_bot1);
//    bot1 = position_bot1(bot1, des_bot1);

//    cout << endl;
//    cout << "il a fait : " << des_bot1.des1 << " et " << des_bot1.des2 << endl;
//    cout << "il passe a la case : " << bot1.position << endl;
//    cout << "il passe a : " << bot1.argent << endl;
//    return bot1;
//}

