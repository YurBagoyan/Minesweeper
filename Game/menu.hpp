#ifndef MENU
#define MENU

#include <iostream>

#include "input.hpp"
#include "show.hpp"

const int MENU_ROW_COUNT = 5, menu_start_row = 22, menu_start_colum = 70;
std::string Menu[MENU_ROW_COUNT] = { " Start", "Records", "Options", " About", " Exit" };

void Show_Menu()    //Print Menu
{   
    gotoxy(menu_start_colum, menu_start_row);
    colorCout(Menu[0], 3);
    for(int i = 1; i < MENU_ROW_COUNT; ++i)
    {
        gotoxy(menu_start_colum, menu_start_row + i);
        std::cout << Menu[i];                                
    }
    std::cout << std::endl;
}


void Menu_choose()
{
    int choose = 0;
    for(char key = -1; key != 27; )
    {
        cbreak();
        key = keypress();
        normal();

        switch(key)
        {
        case 'w': case 'W':
            if(choose == 0)
            {
                gotoxy(menu_start_colum, menu_start_row);
                std::cout << Menu[choose];
                
                choose = MENU_ROW_COUNT - 1;
                gotoxy(menu_start_colum, menu_start_row + choose);
                colorCout(Menu[choose], 3);
            }
            else
            {
                gotoxy(menu_start_colum, menu_start_row + choose);
                std::cout << Menu[choose];

                --choose;
                gotoxy(menu_start_colum, menu_start_row + choose);
                colorCout(Menu[choose], 3);
            }
            break;
            
            
        case 's': case 'S':
            if(choose == MENU_ROW_COUNT - 1)
            {
                gotoxy(menu_start_colum, menu_start_row + choose);
                std::cout << Menu[choose];
                            
                choose = 0;
                gotoxy(menu_start_colum, menu_start_row);
                colorCout(Menu[choose], 3);
            }
            else
            {
                gotoxy(menu_start_colum, menu_start_row + choose);
                std::cout << Menu[choose];
                
                ++choose;
                gotoxy(menu_start_colum, menu_start_row + choose);
                colorCout(Menu[choose], 3);   
            }
            break;

        case 0x0A:
            gotoxy(70,28);
            std::cout << "Enter is pressed" << std::endl;
            break;
        }
    }
}

#endif
