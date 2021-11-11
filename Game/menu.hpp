#ifndef MENU
#define MENU

#include <iostream>
#include <stdlib.h>

#include "input.hpp"
#include "show.hpp"
#include "preGame.hpp"
 
void selectedMenu(int const current, int const rowCenter, int const colCenter)
{
    switch(current) {
        case 0: preGame(rowCenter, colCenter); break;       //Start
        //case 1:                                           //Records
        //case 2:                                           //Options
        case 3:  Show_About(rowCenter, colCenter); break;   //About
        case 4:  exit(0); break;                            //Exit
    }
}

void Menu_choose(int const rowCenter, int const colCenter)
{
    Show_GameName(colCenter - 67, rowCenter - 12);

    int const menuRowCount = 5;
    std::string Menu[menuRowCount] = { "Start", "Records", "Optinos", "About", "Exit" };

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
    for(char key = -1; key != 27; ) {

        if (returnToMenu) {
            break;
        }

        key = keypress();

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
                selectedMenu(current, rowCenter, colCenter);
                returnToMenu = true;
                break;
        }   
    }
}           
    
#endif
