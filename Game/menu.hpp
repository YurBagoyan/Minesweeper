#ifndef MENU
#define MENU

#include <iostream>

#include "input.hpp"
#include "show.hpp"
#include "preGame.hpp"
#include "options.hpp"
 
void selectedMenu(int const current, int* choosedLevel, bool* GodModeOn, int* soundsVolume, int* musicVolume, int* winRow, int* winCol)
{
    switch(current) {
        //Start
        case 0: preGame(*choosedLevel, *GodModeOn, &(*winRow), &(*winCol)); break;
        //Options
        case 1: options(&(*choosedLevel), &(*GodModeOn), &(*soundsVolume), &(*musicVolume), &(*winRow), &(*winCol)); break;
        //case 2:
        //About
        case 3: Show_About(&(*winRow), &(*winCol)); break;
        //Exit
        case 4: system("clear"); exit(0); break;
    }
}

void printMenu(std::string* Menu, int const menuSize, int const current, int const menuStartRow, int const menuStartCol)
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

void Menu_choose(int* current, int* choosedLevel, bool* GodModeOn, int* soudnsVolume, int* musicVolume, int* winRow, int* winCol)
{
    int const rowCenter = *winRow / 2 + 1;
    int const colCenter = *winCol / 2 + 1;

    int const gameName = 67;
    Show_GameName(colCenter - gameName, rowCenter - 11);

    int const menuSize = 5;
    std::string Menu[menuSize] = { "Start", "Options", "Records", "About", "Exit" };

    int const menuStartRow = rowCenter - 2;
    int const menuStartCol = colCenter - 3; 
    printMenu(Menu, menuSize, *current, menuStartRow, menuStartCol);
   
    //Need when the user will return to the menu
    bool returnToMenu = false;

    cbreak();
    while(true) {
        //Checking user windows size and change if it has changed
        int const minWinRowSize = 23, minWinColSize = 132;
        if (winSizeChanged(&(*winRow), &(*winCol), minWinRowSize, minWinColSize) || returnToMenu) {
            break;
        }
        
        int key = keypress();
        switch(key) {
            case 'w': case 'W':
                gotoxy(menuStartCol, menuStartRow + *current);
                std::cout << Menu[*current];

                *current == 0 ? *current = menuSize - 1 : --(*current);

                gotoxy(menuStartCol, menuStartRow + *current);
                colorCout(Menu[*current], 3);
                break;
                    
            case 's': case 'S':    
                gotoxy(menuStartCol, menuStartRow + *current);
                std::cout << Menu[*current];
                
                *current == menuSize - 1 ? *current = 0 : ++(*current);

                gotoxy(menuStartCol, menuStartRow + *current);
                colorCout(Menu[*current], 3);
                break;
            
            case 10:
                selectedMenu(*current, &(*choosedLevel), &(*GodModeOn), &(*soudnsVolume), &(*musicVolume), &(*winRow), &(*winCol));
                returnToMenu = true;
                break;
        }   
    }
}           
    
#endif

