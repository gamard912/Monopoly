#include <stdlib.h>
#include <iostream>
#include "init.h"

using namespace std;

void clear_screen()//Clear all screen
{
    cout << "\x1B[2J\x1B[H" << "\n";
}

void setup_screen()//Resize screen
{
    cout << "\e[8;150;175t";
}
