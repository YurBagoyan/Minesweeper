#ifndef MENU
#define MENU

#include <iostream>
#include <stdlib.h>

#include "input.hpp"
#include "show.hpp"
#include "preGame.hpp"
 
void selectedMenu(int const current, int* winRow, int* winCol)
{
    switch(current) {
        case 0: preGame(&(*winRow), &(*winCol)); break;     //Start
        //case 1:                                
        //case 2:                                
        case 3: Show_About(&(*winRow), &(*winCol)); break;  //About
        case 4: system("clear"); exit(0); break;            //Exit
    }
}

void Menu_choose(int* winRow, int* winCol)
{
    int const rowCenter = *winRow / 2 + 1;
    int const colCenter = *winCol / 2 + 1;

    int const gameName = 67;
    Show_GameName(colCenter - gameName, rowCenter - 11);

    int const menuRowCount = 5;
    std::string Menu[menuRowCount] = { "Start", "Records", "Options", "About", "Exit" };

    int const menuStartRow = rowCenter - 2;
    int const menuStartCol = colCenter - 3; 

    //Print Menu
    gotoxy(menuStartCol, menuStartRow);
    colorCout(Menu[0], 3);
    for(int i = 1; i < menuRowCount; ++i) {
        gotoxy(menuStartCol, menuStartRow + i);
        std::cout << Menu[i];                                
    }
    std::cout << std::endl;
   
    //Need when the user returned the menu
    bool returnToMenu = false;
    int current = 0;

    cbreak();
    while(true) {
        if(*winRow < 23 || *winCol < 132) {
                *winRow = 23;
                *winCol = 132;
                std::cout << "\e[8;23;132t";
        }

        int newWinRow, newWinCol;
        userWinSize(&newWinRow, &newWinCol);

        if(newWinRow != (*winRow) || newWinCol != (*winCol)) {
            if(newWinRow < 23 || newWinCol < 132) {
                *winRow = 23;
                *winCol = 132;
                std::cout << "\e[8;23;132t";
            } else {
                *winRow = newWinRow; 
                *winCol = newWinCol;
            }
            system("clear");
            break;
        }

        if (returnToMenu) {
            break;
        }

        int key = keypress();
        switch(key) {
            case 'w': case 'W':
                if(current == 0) {
                    gotoxy(menuStartCol, menuStartRow);
                    std::cout << Menu[current];
                    
                    current = menuRowCount - 1;
                    gotoxy(menuStartCol, menuStartRow + current);
                    colorCout(Menu[current], 3);
                } else {    
                    gotoxy(menuStartCol, menuStartRow + current);
                    std::cout << Menu[current];
    
                    gotoxy(menuStartCol, menuStartRow + (--current));
                    colorCout(Menu[current], 3);
                }
                break;
                    
            case 's': case 'S':               
                if(current == menuRowCount - 1) {        
                    gotoxy(menuStartCol, menuStartRow + current);
                    std::cout << Menu[current];
                                
                    current = 0;
                    gotoxy(menuStartCol, menuStartRow);
                    colorCout(Menu[current], 3);
                } else { 
                    gotoxy(menuStartCol, menuStartRow + current);
                    std::cout << Menu[current];
                    
                    gotoxy(menuStartCol, menuStartRow + (++current));
                    colorCout(Menu[current], 3);   
                }
                break;
            
            case 10:
                selectedMenu(current, &(*winRow), &(*winCol));
                returnToMenu = true;
                break;
        }   
    }
}           
    
#endif
