#include <iostream>
#include <unistd.h>

#include "input.hpp"
#include "show.hpp"
#include "menu.hpp"

int main()
{
    int winRow, winCol;
    userWinSize(&winRow, &winCol);
    int const rowCenter = winRow / 2 + 1;
    int const colCenter = winCol / 2 + 1;

    //Gamename animation
    int const gameName = 62;
    for(int i = 0; i <= rowCenter - 12; ++i) {
        Show_GameName(colCenter - gameName, i);
        usleep(125000);
    }

    int choosedLevel = 1, soundsVolume = 10, musicVolume = 10, current = 0;
    int customSize = 5, customBombCount = 1;
    bool GodModeOn = false;
    while(true) {
        Menu_choose(&current, &customSize, &customBombCount, &choosedLevel, &GodModeOn, &soundsVolume, &musicVolume, &winRow, &winCol);
    }
}

