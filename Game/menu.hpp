#ifndef MENU
#define MENU

#include <iostream>
#include <stdlib.h>

#include "input.hpp"
#include "show.hpp"

const int MENU_ROW_COUNT = 5, menu_start_row = 22, menu_start_colum = 70;
std::string Menu[MENU_ROW_COUNT] = { "Start", "Records", "Options", "About", "Exit" };

void Selected_Menu(int choose)
{
    switch(choose)
    {
        //case 0:                          //Start
        //case 1:                          //Records
        //case 2:                                 //Options
        case 3:  Show_About(); break;           //About
        case 4:  exit(0); break;                   //Exit
    }
}

void Menu_choose()
{
    gotoxy(0, 12);
    Show_GameName();

    gotoxy(menu_start_colum, menu_start_row);
    colorCout(Menu[0], 3);
    for(int i = 1; i < MENU_ROW_COUNT; ++i)
    {
        gotoxy(menu_start_colum, menu_start_row + i);
        std::cout << Menu[i];                                
    }
    std::cout << std::endl;

    int choose = 0;
    bool return_to_menu = false;
    for(char key = -1; key != 27; )
    {
        if (return_to_menu)
        {
            break;
        }
        cbreak();
        key = keypress();
        normal();

        switch(key)
        {
            case 'w': case 'W':
                for(int i = 22; i < 29; ++i)
                {
                    gotoxy(0, i);
                    std::cout << "  ";
                }

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
    
                    gotoxy(menu_start_colum, menu_start_row + (--choose));
                    colorCout(Menu[choose], 3);
                }
                break;
                    
            case 's': case 'S':
                for(int i = 22; i < 29; ++i)
                {
                    gotoxy(0, i);
                    std::cout << "  ";
                }

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
                    
                    gotoxy(menu_start_colum, menu_start_row + (++choose));
                    colorCout(Menu[choose], 3);   
                }
                break;
            
            case 0x0A:
                Selected_Menu(choose);
                return_to_menu = true;
                break;
            
        }   
    }
}           
    
#endif
