#ifndef MENU
#define MENU

#include <iostream>
#include <stdlib.h>

#include "input.hpp"
#include "show.hpp"
#include "preGame.hpp"

const int MENU_ROW_COUNT = 5, menu_start_row = 22, menu_start_colum = 70;
 
void Selected_Menu(int const choose, int const rowCenter, int const colCenter)
{
    switch(choose) {
        case 0: preGame(/*rowCenter, colCenter*/); break;       //Start
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

    gotoxy(menuStartCol, menuStartRow);
    colorCout(Menu[0], 3);
    //Print menu
    for(int i = 1; i < menuRowCount; ++i) {
        gotoxy(menuStartCol, menuStartRow + i);
        std::cout << Menu[i];                                
    }
    std::cout << std::endl;
   
    //Need when the user returned the menu
    bool returnToMenu = false;
    int choose = 0;
    for(char key = -1; key != 27; ) {
        if (returnToMenu) {
            break;
        }

        cbreak();
        key = keypress();

        switch(key) {
            case 'w': case 'W':
                if(choose == 0) {
                    gotoxy(menuStartCol, menuStartRow);
                    std::cout << Menu[choose];
                    
                    choose = menuRowCount - 1;
                    gotoxy(menuStartCol, menuStartRow + choose);
                    colorCout(Menu[choose], 3);
                } else {    
                    gotoxy(menuStartCol, menuStartRow + choose);
                    std::cout << Menu[choose];
    
                    gotoxy(menuStartCol, menuStartRow + (--choose));
                    colorCout(Menu[choose], 3);
                }
                break;
                    
            case 's': case 'S':               
                if(choose == menuRowCount - 1) {        
                    gotoxy(menuStartCol, menuStartRow + choose);
                    std::cout << Menu[choose];
                                
                    choose = 0;
                    gotoxy(menuStartCol, menuStartRow);
                    colorCout(Menu[choose], 3);
                } else { 
                    gotoxy(menuStartCol, menuStartRow + choose);
                    std::cout << Menu[choose];
                    
                    gotoxy(menuStartCol, menuStartRow + (++choose));
                    colorCout(Menu[choose], 3);   
                }
                break;
            
            case 10:
                Selected_Menu(choose, rowCenter, colCenter);
                returnToMenu = true;
                break;
        }   
    }
}           
    
#endif
