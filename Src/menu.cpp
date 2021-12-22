#include <iostream>

#include "../Include/input.hpp"
#include "../Include/menu.hpp"
#include "../Include/options.hpp"
#include "../Include/preGame.hpp"
#include "../Include/records.hpp"
#include "../Include/show.hpp"

constexpr int cursorColor = 3; // 3 = green

void Menu_choose(int& current, int& customSize, int& customBombCount, int& choosedLevel, bool& GodModeOn, int& soudnsVolume, int& musicVolume, int& winRow, int& winCol)
{
    const int rowCenter = winRow / 2 + 1;
    const int colCenter = winCol / 2 + 1;

    Show_GameName(colCenter, rowCenter - 11);

    constexpr size_t menuSize = 5;
    const std::string Menu[menuSize] = { "Start", "Options", "Records", "About", "Exit" };

    const int menuStartRow = rowCenter - 2;
    const int menuStartCol = colCenter - 3;
    printMenu(Menu, menuSize, current, menuStartRow, menuStartCol);

    bool returnToMenu = false;

    cbreak();
    while (true) {
        //Checking user windows size and change if it has changed by user
        constexpr int minWinRowSize = 22, minWinColSize = 132;
        if (winSizeChanged(winRow, winCol, minWinRowSize, minWinColSize) || returnToMenu) {
            break;
        }

        int key = keypress();
        switch (key) {
        // UP
        case 'w': case 'W': CursorMoveInMenu(Menu, menuSize, current, key, menuStartCol, menuStartRow); break;
        // DOWN
        case 's': case 'S': CursorMoveInMenu(Menu, menuSize, current, key, menuStartCol, menuStartRow); break;
        // Enter
        case 10:
            selectedMenu(current, customSize, customBombCount, choosedLevel, GodModeOn, soudnsVolume, musicVolume, winRow, winCol);
            returnToMenu = true;
            break;
        }
    }
}

void CursorMoveInMenu(const std::string* Menu, const size_t menuSize, int& current, const int key, const int menuStartCol, const int menuStartRow)
{
    gotoxy(menuStartCol, menuStartRow + current);
    std::cout << Menu[current];

    if (key == 'w' || key == 'W') {
        current == 0 ? current = menuSize - 1 : --current;
    }
    else if (key == 's' || key == 'S') {
        current == menuSize - 1 ? current = 0 : ++current;
    }

    gotoxy(menuStartCol, menuStartRow + current);
    colorCout(Menu[current], cursorColor);
}

void printMenu(const std::string* Menu, const size_t menuSize, const int current, const int menuStartRow, const int menuStartCol)
{
    for (size_t i = 0; i < menuSize; ++i) {
        if (i == current) {
            gotoxy(menuStartCol, menuStartRow + current);
            colorCout(Menu[current], cursorColor);
            continue;
        }
        gotoxy(menuStartCol, menuStartRow + i);
        std::cout << Menu[i];
        std::cout << std::endl;
    }
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
