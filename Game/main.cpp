#include <iostream>

#include "input.hpp"
#include "show.hpp"
#include "menu.hpp"

int main()
{
    printf("\e[?25l");

    int winRow, winCol;
    userWinSize(&winRow, &winCol);
    int const rowCenter = winRow / 2 + 1;
    int const colCenter = winCol / 2 + 1;

    Show_GameNameAnimation(rowCenter, colCenter);

    int choosedLevel = 1, soundsVolume = 10, musicVolume = 10, current = 0;
    int customSize = 5, customBombCount = 1;
    bool GodModeOn = false;
    while(true) {
        Menu_choose(&current, &customSize, &customBombCount, &choosedLevel, &GodModeOn, &soundsVolume, &musicVolume, &winRow, &winCol);
    }
}

