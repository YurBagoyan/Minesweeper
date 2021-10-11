#include <iostream>
#include <unistd.h>

#include "input.hpp"
#include "show.hpp"
#include "menu.hpp"

int main()
{
    //Gamename animation
    for(int  i = 1; i <= 12; ++i)
    {
        gotoxy(0, i);
        Show_GameName();
        usleep(125000);
    }
    while(true)
    {
        Menu_choose();
    }
}

