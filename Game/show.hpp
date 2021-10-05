#ifndef SHOW
#define SHOW

#include <iostream>
#include <string>
#include <unistd.h>

#include "input.hpp"


void Show_GameName()    //Animation print of GameName
{
    int const CENTER_ROW = 12; 
    for(int i = 1; i <= CENTER_ROW; ++i)
    {
        system("clear");
        gotoxy(0, i);
        std::cout   << "\x1b[31;1m" << "\t      _____ ______   ___  ________   _______   ________  ___       __   _______   _______   ________  _______   ________     " << "\x1b[0m\n"
                    << "\x1b[31;1m" << "\t     |\\   _ \\  _   \\|\\  \\|\\   ___  \\|\\  ___ \\ |\\   ____\\|\\  \\     |\\  \\|\\  ___ \\ |\\  ___ \\ |\\   __  \\|\\  ___ \\ |\\   __  \\    " << "\x1b[0m\n"
                    << "\x1b[31;1m" << "\t     \\ \\  \\\\\\__\\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\   __/ \\ \\  \\___|\\ \\  \\    \\ \\  \\ \\   __/ \\ \\   __/ \\ \\  \\|\\  \\ \\   __/ \\ \\  \\|\\  \\   " << "\x1b[0m\n"
                    << "\x1b[31;1m" << "\t      \\ \\  \\\\|__| \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\_|  \\ \\_____  \\ \\  \\  __\\ \\  \\ \\  \\_|  \\ \\  \\_|  \\ \\   ____\\ \\  \\_|  \\ \\   _  _\\  " << "\x1b[0m\n"
                    << "\x1b[31;1m" << "\t       \\ \\  \\    \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\_|\\ \\|____|\\  \\ \\  \\|\\__\\_\\  \\ \\  \\_|\\ \\ \\  \\_|\\ \\ \\  \\___|\\ \\  \\_|\\ \\ \\  \\\\  \\| " << "\x1b[0m\n"
                    << "\x1b[31;1m" << "\t        \\ \\__\\    \\ \\__\\ \\__\\ \\__\\\\ \\__\\ \\_______\\____\\_\\  \\ \\____________\\ \\_______\\ \\_______\\ \\__\\    \\ \\_______\\ \\__\\\\ _\\ " << "\x1b[0m\n"
                    << "\x1b[31;1m" << "\t         \\|__|     \\|__|\\|__|\\|__| \\|__|\\|_______|\\_________\\|____________|\\|_______|\\|_______|\\|__|     \\|_______|\\|__|\\|__|" << "\x1b[0m\n"
                    << "\x1b[31;1m" << "\t                                                 \\|_________|                                                                " << "\x1b[0m\n";

        usleep(125000);
    }
}

// MENU
const int MENU_ROW_COUNT = 5;
std::string Menu[MENU_ROW_COUNT] = { " Start", "Records", "Options", " About", " Exit" };

void Show_Menu()    //Print Menu
{   
    gotoxy(70, 22);
    colorCout(Menu[0], 3);
    for(int i = 1; i < MENU_ROW_COUNT; ++i)
    {
        gotoxy(70, 22 + i);
        std::cout << Menu[i];
    }
    std::cout << std::endl;
}

#endif
