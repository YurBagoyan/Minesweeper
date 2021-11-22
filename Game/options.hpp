#ifndef OPTIONS
#define OPTIONS

#include <iostream>

#include "input.hpp"
#include "show.hpp"

void printOptions(std::string* options, std::string* volume, std::string* levelInfo, int const current, int const optionsSize, int const choosedLevel, bool const GodModeOn, int const soundsVolume, int const musicVolume, int const optionsStartRow, int const optionsStartCol)
{
    //Print options in cyan color
    gotoxy(optionsStartCol, optionsStartRow - 2);
    colorCout("Options", 4); //4 = cyan

    //Print options in white color
    for(int i = 0; i < optionsSize; ++i) {
        gotoxy(optionsStartCol, optionsStartRow + i);
        std::cout << options[i];                                
    }

    //Print current row in green color
    gotoxy(optionsStartCol, optionsStartRow + current);
    colorCout(options[current], 3); //3 = green

    //Level Info
    gotoxy(optionsStartCol + 9, optionsStartRow + current);
    colorCout(levelInfo[current], 7); //7 = yellow
    
    //Volume
    gotoxy(optionsStartCol + 8, optionsStartRow + 6);
    std::cout << volume[soundsVolume];
    gotoxy(optionsStartCol + 8, optionsStartRow + 7);
    std::cout << volume[musicVolume]; 

    //Gode Mode On or Off
    gotoxy(optionsStartCol + 9, optionsStartRow + 9);
    GodModeOn ? colorCout("On ", 3) : colorCout("Off", 5);

    //Choosed Level
    gotoxy(optionsStartCol - 2, optionsStartRow + choosedLevel - 1);
    colorCout("►", 7); //7 = yellow

    std::cout << std::endl;
}

void options(int* choosedLevel, bool* GodModeOn, int* soundsVolume, int* musicVolume, int* winRow, int* winCol)
{
    int current = 0;
    int exitFromOptions = false;
    while(true) {
        system("clear");
        if(exitFromOptions) {
            break;
        }

        int const rowCenter = *winRow / 2 + 1;
        int const colCenter = *winCol / 2 + 1;
 
        int const gameName = 67;
        Show_GameName(colCenter - gameName, rowCenter - 11);
        
        gotoxy(colCenter - 16, rowCenter*2 - 2);
        colorCout("Press Esc to return to MAIN MENU", 7);

        int const optionsSize = 11;
        std::string options[optionsSize] = {"Beginner", "Veteran", "Expert", "Pro", "Master", " ", "Sounds", "Music", " ", "God Mode", "Custom Mode"};
        std::string levelInfo[5] = {  " Size = 8x8,   Mines = 10", // Beginnger
                                      " Size = 10x10, Mines = 20", // Veteran
                                      " Size = 12x12, Mines = 35", // Expert                                   
                                      " Size = 15x15, Mines = 50", // Pro                               
                                      " Size = 18x18, Mines = 99", // Master
                                    };

        std::string volume[11] = { "[□□□□□□□□□□]   0%",
                                   "[■□□□□□□□□□]  10%",
                                   "[■■□□□□□□□□]  20%",
                                   "[■■■□□□□□□□]  30%",
                                   "[■■■■□□□□□□]  40%",
                                   "[■■■■■□□□□□]  50%",
                                   "[■■■■■■□□□□]  60%",
                                   "[■■■■■■■□□□]  70%",
                                   "[■■■■■■■■□□]  80%",
                                   "[■■■■■■■■■□]  90%",
                                   "[■■■■■■■■■■] 100%" };

        int const optionsStartRow = rowCenter;
        int const optionsStartCol = colCenter - 4; 
        printOptions(options, volume, levelInfo, current, optionsSize, *choosedLevel, *GodModeOn, *soundsVolume, *musicVolume, optionsStartRow, optionsStartCol);
   
        cbreak();
        while(true) {

            int const minWinRowSize = 25, minWinColSize = 132;
            if (winSizeChanged(&(*winRow), &(*winCol), minWinRowSize, minWinColSize)) {
                break;
            }

            int key = keypress();
            if(key == 27) {
                exitFromOptions = true;
                break;
            }
            switch(key) {
                case 'w': case 'W':
                    gotoxy(optionsStartCol, optionsStartRow + current);
                    std::cout << options[current]; 

                    switch(current) {
                        case 0:  
                            gotoxy(optionsStartCol + 9, optionsStartRow + current);
                            std::cout << "                             ";
                            current = optionsSize - 1;
                            break;
                        case 9: current = 7; break;
                        case 6: current = 4; break;
                        default: --current; break;
                    }
                           
                    gotoxy(optionsStartCol, optionsStartRow + current);
                    colorCout(options[current], 3);
                
                    if(current < 5) {
                        gotoxy(optionsStartCol + 9, optionsStartRow + current + 1);
                        std::cout << "                             ";
                        gotoxy(optionsStartCol + 9, optionsStartRow + current);
                        colorCout(levelInfo[current], 7);
                    }
                    break;
            
                case 's': case 'S':    
                    gotoxy(optionsStartCol, optionsStartRow + current);
                    std::cout << options[current];
                    if(current < 5) {
                        gotoxy(optionsStartCol + 9, optionsStartRow + current);
                        std::cout << "                             ";
                    }
            
                    switch(current) {
                        case optionsSize - 1: current = 0; break;
                        case 4: current = 6; break;
                        case 7: current = 9; break;
                        default: ++current;  break;
                    }
            
                    gotoxy(optionsStartCol, optionsStartRow + current);
                    colorCout(options[current], 3);
                    if(current < 5) {
                        gotoxy(optionsStartCol + 9, optionsStartRow + current - 1);
                        std::cout << "                             ";
                        gotoxy(optionsStartCol + 9, optionsStartRow + current);
                        colorCout(levelInfo[current], 7);
                    }
                    break;
    
                case 'a': case 'A':
                    if(current == 6 && soundsVolume > 0) {
                        gotoxy(optionsStartCol + 8, optionsStartRow + current);
                        std::cout << volume[--(*soundsVolume)] << std::endl;
                    }
                    else if(current == 7 && *musicVolume > 0) {
                    gotoxy(optionsStartCol + 8, optionsStartRow + current);
                    std::cout << volume[--(*musicVolume)] << std::endl;
                    }
                    break;
    
                case 'd': case 'D':            
                    if(current == 6 && *soundsVolume < 10) {
                        gotoxy(optionsStartCol + 8, optionsStartRow + current);
                        std::cout << volume[++(*soundsVolume)] << std::endl;
                    }
                    else if(current == 7 && *musicVolume < 10) {
                        gotoxy(optionsStartCol + 8, optionsStartRow + current);
                        std::cout << volume[++(*musicVolume)] << std::endl;
                    }
                    break;

                case 10:
                    switch(current) {
                        case 9:
                            gotoxy(optionsStartCol + 9, optionsStartRow + current);
        
                            if(*GodModeOn) {
                                *GodModeOn = false;
                                colorCout("Off", 5);
                            }
                            else {
                                *GodModeOn = true;
                                colorCout("On ", 3);
                            }
                            break;

                        case 6: case 7:
                            break;
                    
                        case 10:
                            break;

                        default: 
                            gotoxy(optionsStartCol - 2, optionsStartRow + *choosedLevel - 1);
                            std::cout << " ";
                            *choosedLevel = current + 1;
                            gotoxy(optionsStartCol - 2, optionsStartRow + *choosedLevel - 1);
                            colorCout("►", 7);
                            break;
                    }
                    break;
            }        
        }
    }
}    

#endif

