#include <iostream>

#include "../Include/input.hpp"
#include "../Include/menu.hpp"
#include "../Include/options.hpp"
#include "../Include/preGame.hpp"
#include "../Include/records.hpp"
#include "../Include/show.hpp"

void Menu_choose(int& current, int& customSize, int& customBombCount, int& choosedLevel, bool& GodModeOn, int& soudnsVolume, int& musicVolume, int& winRow, int& winCol)
{
    const int rowCenter = winRow / 2 + 1;
    const int colCenter = winCol / 2 + 1;

    constexpr int gameName = 62;
    Show_GameName(colCenter - gameName, rowCenter - 11);

    constexpr size_t menuSize = 5;
    const std::string Menu[menuSize] = { "Start", "Options", "Records", "About", "Exit" };

    const int menuStartRow = rowCenter - 2;
    const int menuStartCol = colCenter - 3;
    printMenu(Menu, menuSize, current, menuStartRow, menuStartCol);

    //Need when the user will return to the menu
    bool returnToMenu = false;

    cbreak();
    while (true) {
        //Checking user windows size and change if it has changed
        constexpr int minWinRowSize = 22, minWinColSize = 132;
        if (winSizeChanged(winRow, winCol, minWinRowSize, minWinColSize) || returnToMenu) {
            break;
        }

        int key = keypress();
        switch (key) {
        case 'w': case 'W':
            gotoxy(menuStartCol, menuStartRow + current);
            std::cout << Menu[current];

            current == 0 ? current = menuSize - 1 : --current;

            gotoxy(menuStartCol, menuStartRow + current);
            colorCout(Menu[current], 3);
            break;

        case 's': case 'S':
            gotoxy(menuStartCol, menuStartRow + current);
            std::cout << Menu[current];

            current == menuSize - 1 ? current = 0 : ++current;

            gotoxy(menuStartCol, menuStartRow + current);
            colorCout(Menu[current], 3);
            break;

        case 10:
            selectedMenu(current, customSize, customBombCount, choosedLevel, GodModeOn, soudnsVolume, musicVolume, winRow, winCol);
            returnToMenu = true;
            break;
        }
    }
}

void printMenu(const std::string* Menu, const int menuSize, const int current, const int menuStartRow, const int menuStartCol)
{
    gotoxy(menuStartCol, menuStartRow);
    for(int i = 0; i < menuSize; ++i) {
        gotoxy(menuStartCol, menuStartRow + i);
        std::cout << Menu[i];                                
    }
    gotoxy(menuStartCol, menuStartRow + current);
    colorCout(Menu[current], 3);
    std::cout << std::endl;
}
         
void selectedMenu(const int current, int& customSize, int& customBombCount, int& choosedLevel, bool& GodModeOn, int& soundsVolume, int& musicVolume, int& winRow, int& winCol)
{
    switch (current) {
        //Start
        case 0: preGame(customSize, customBombCount, choosedLevel, GodModeOn, winRow, winCol); break;
        //Options
        case 1: options(customSize, customBombCount, choosedLevel, GodModeOn, soundsVolume, musicVolume, winRow, winCol); break;
        //Records
        case 2: records(winRow, winCol); break;
        //About
        case 3: Show_About(winRow, winCol); break;
        //Exit
        case 4: normal(); system("clear"); exit(0); break;
    }
}
