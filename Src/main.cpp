#include <iostream>

#include "../Include/input.hpp"
#include "../Include/menu.hpp"
#include "../Include/show.hpp"

int main()
{
    //Don't show the console cursor in the game
    printf("\e[?25l");

    //The console window size, will change it in the game for dynamic size of console window
    int winRow, winCol;
    userWinSize(winRow, winCol);
    int const rowCenter = winRow / 2 + 1;
    int const colCenter = winCol / 2 + 1;
    
    cbreak();
    Show_GameNameAnimation(rowCenter, colCenter);

    //Menu in an endless loop, so declare the necessary variables here
    int choosedLevel = 1, soundsVolume = 10, musicVolume = 10, current = 0;
    int customSize = 5, customBombCount = 1;
    bool GodModeOn = false;

    //Menu
    while(true) {
        Menu_choose(current, customSize, customBombCount, choosedLevel, GodModeOn, soundsVolume, musicVolume, winRow, winCol);
    }
}

