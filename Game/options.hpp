#ifndef OPTIONS
#define OPTIONS

#include <iostream>

#include "input.hpp"
#include "show.hpp"

void customMode(std::string* custom, int* customSize, int* customBombCount, bool* exitFromOptions, int const optionsStartRow, int const optionsStartCol, bool* sizeChanged, int* winRow, int* winCol);
void options(int* customSize, int* customBombCount, int* choosedLevel, bool* GodModeOn, int* soundsVolume, int* musicVolume, int* winRow, int* winCol);
void printOptions(std::string* options, std::string* volume, std::string* custom, std::string* levelInfo, int const current, int const optionsSize, int const choosedLevel, bool const GodModeOn, int const soundsVolume, int const musicVolume, int const optionsStartRow, int const optionsStartCol, int const customSize, int const customBombCount);

void options(int* customSize, int* customBombCount, int* choosedLevel, bool* GodModeOn, int* soundsVolume, int* musicVolume, int* winRow, int* winCol)
{
    int current = 0;
    bool exitFromOptions = false;
    while (true) {
        system("clear");
        if (exitFromOptions) {
            break;
        }

        int const rowCenter = *winRow / 2 + 1;
        int const colCenter = *winCol / 2 + 1;

        int const gameName = 67;
        Show_GameName(colCenter - gameName, rowCenter - 11);

        gotoxy(colCenter - 16, rowCenter * 2 - 2);
        colorCout("Press Esc to return to MAIN MENU", 7);

        int const optionsSize = 11;
        std::string options[optionsSize] = { "Beginner", "Veteran", "Expert", "Pro", "Master", "", "Sounds", "Music", "", "God Mode", "Custom Mode >" };

        std::string custom[2] = { "Custom size: ", "Custom bomb count: " };

        std::string levelInfo[5] = { "   Size = 8x8, Mines = 10", // Beginnger
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
        printOptions(options, volume, custom, levelInfo, current, optionsSize, *choosedLevel, *GodModeOn, *soundsVolume, *musicVolume, optionsStartRow, optionsStartCol, *customSize, *customBombCount);

        bool sizeChanged = false;
        cbreak();
        while (true) {

            int const minWinRowSize = 27, minWinColSize = 130;
            if (sizeChanged || winSizeChanged(&(*winRow), &(*winCol), minWinRowSize, minWinColSize)) {
                break;
            }

            int key = keypress();
            if (key == 27 || exitFromOptions) {
                exitFromOptions = true;
                break;
            }
            switch (key) {
            case 'w': case 'W':
                gotoxy(optionsStartCol, optionsStartRow + current);
                std::cout << options[current];

                switch (current) {
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

                if (current < 5) {
                    gotoxy(optionsStartCol + 9, optionsStartRow + current + 1);
                    std::cout << "                             ";
                    gotoxy(optionsStartCol + 9, optionsStartRow + current);
                    colorCout(levelInfo[current], 7);
                }
                break;

            case 's': case 'S':
                gotoxy(optionsStartCol, optionsStartRow + current);
                std::cout << options[current];
                if (current < 5) {
                    gotoxy(optionsStartCol + 9, optionsStartRow + current);
                    std::cout << "                             ";
                }

                switch (current) {
                case optionsSize - 1: current = 0; break;
                case 4: current = 6; break;
                case 7: current = 9; break;
                default: ++current;  break;
                }

                gotoxy(optionsStartCol, optionsStartRow + current);
                colorCout(options[current], 3);
                if (current < 5) {
                    gotoxy(optionsStartCol + 9, optionsStartRow + current - 1);
                    std::cout << "                             ";
                    gotoxy(optionsStartCol + 9, optionsStartRow + current);
                    colorCout(levelInfo[current], 7);
                }
                break;

            case 'a': case 'A':
                gotoxy(optionsStartCol + 8, optionsStartRow + current);

                if (current == 6 && *soundsVolume > 0) {
                    std::cout << volume[--(*soundsVolume)] << std::endl;
                }
                else if (current == 7 && *musicVolume > 0) {
                    std::cout << volume[--(*musicVolume)] << std::endl;
                }
                break;

            case 'd': case 'D':
                gotoxy(optionsStartCol + 8, optionsStartRow + current);

                if (current == 6 && *soundsVolume < 10) {
                    std::cout << volume[++(*soundsVolume)] << std::endl;
                }
                else if (current == 7 && *musicVolume < 10) {
                    std::cout << volume[++(*musicVolume)] << std::endl;
                }
                break;

            case 10: //Enter
                switch (current) {
                case 9: // God Mode
                    gotoxy(optionsStartCol + 9, optionsStartRow + current);

                    if (*GodModeOn) {
                        *GodModeOn = false;
                        colorCout("Off", 5);
                    }
                    else {
                        *GodModeOn = true;
                        colorCout("On ", 3);
                    }
                    break;

                case 6: case 7: // Sound, Music
                    break;

                case 10: //Custom Mode
                    gotoxy(optionsStartCol - 2, optionsStartRow + *choosedLevel - 1);
                    std::cout << " ";
                    *choosedLevel = 11;
                    gotoxy(optionsStartCol - 2, optionsStartRow + *choosedLevel - 1);
                    colorCout("►", 7);
                    gotoxy(optionsStartCol, optionsStartRow + current);
                    std::cout << options[current];

                    customMode(custom, &(*customSize), &(*customBombCount), &exitFromOptions, optionsStartRow, optionsStartCol, &sizeChanged, &(*winRow), &(*winCol));

                    gotoxy(optionsStartCol, optionsStartRow + current);
                    colorCout(options[current], 3);
                    break;

                default:
                    gotoxy(optionsStartCol - 2, optionsStartRow + *choosedLevel - 1);
                    std::cout << " ";
                    *choosedLevel = current + 1;
                    gotoxy(optionsStartCol - 2, optionsStartRow + current);
                    colorCout("►", 7);
                    break;
                }
                break;
            }
        }
    }
}

void printOptions(std::string* options, std::string* volume, std::string* custom, std::string* levelInfo, int const current, int const optionsSize, int const choosedLevel, bool const GodModeOn, int const soundsVolume, int const musicVolume, int const optionsStartRow, int const optionsStartCol, int const customSize, int const customBombCount)
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

    //CUSTOM
    int const customStartRow = optionsStartRow + 10;  
    int const customStartCol = optionsStartCol + 15;
    gotoxy(customStartCol, customStartRow);
    colorCout(custom[0], 7);

    gotoxy(customStartCol, customStartRow + 1);
    colorCout(custom[1], 7);

    //Print custom size
    int const customNumberStartCol = customStartCol + 20;
    gotoxy(customNumberStartCol, customStartRow);
    std::cout << customSize << std::endl;
    //Print custom bomb count
    gotoxy(customNumberStartCol, customStartRow + 1);
    std::cout << customBombCount << std::endl;

    std::cout << std::endl;
}

void customMode(std::string* custom, int* customSize, int* customBombCount, bool* exitFromOptions, int const optionsStartRow, int const optionsStartCol, bool* sizeChanged, int* winRow, int* winCol)
{      
    int const customStartRow = optionsStartRow + 10;  
    int const customStartCol = optionsStartCol + 15;
      
    //Print custom
    gotoxy(customStartCol, customStartRow);
    colorCout(custom[0], 3);

    gotoxy(customStartCol, customStartRow + 1);
    colorCout(custom[1], 7);

    //Print custom size
    int const customNumberStartCol = customStartCol + 19;
    gotoxy(customNumberStartCol, customStartRow);
    std::cout << std::setw(2) << *customSize << std::endl;
    //Print custom bomb count
    gotoxy(customNumberStartCol, customStartRow + 1);
    std::cout << std::setw(2) << *customBombCount << std::endl;
   
    int current = 0;
    cbreak();
    while(true) {
        int key = keypress();
        if(key == 27 || key == 10) {
            gotoxy(customStartCol, customStartRow);
            colorCout(custom[0], 7);

            gotoxy(customStartCol, customStartRow + 1);
            colorCout(custom[1], 7);

            if(key == 27) {
                *exitFromOptions = true; 
            }
            break;    
        }

        int const minWinRowSize = 27, minWinColSize = 130;
        if (winSizeChanged(&(*winRow), &(*winCol), minWinRowSize, minWinColSize)) {
            *sizeChanged = true;
            break;
        }

        switch(key) {
            case 'w': case 'W':
                gotoxy(customStartCol, customStartRow + current);
                colorCout(custom[current], 7);
                current == 0 ? current = 1 : --current;
                gotoxy(customStartCol, customStartRow + current);
                colorCout(custom[current], 3);
                break;

            case 's': case 'S':
                gotoxy(customStartCol, customStartRow + current);
                colorCout(custom[current], 7);
                current == 1 ? current = 0 : ++current;
                gotoxy(customStartCol, customStartRow + current);
                colorCout(custom[current], 3);
                break;

            case 'a': case 'A': 
                gotoxy(customNumberStartCol, customStartRow + current);

                if(current == 0 && *customSize > 5) {
                    //std::cout << "  "; 
                    gotoxy(customNumberStartCol, customStartRow + current);

                    std::cout << std::setw(2) << --(*customSize) << std::endl; 
                    if((*customSize)*(*customSize) < *customBombCount) {
                        *customBombCount = (*customSize)*(*customSize);
                        gotoxy(customNumberStartCol, customStartRow + 1);
                        //std::cout << "  ";
                        gotoxy(customNumberStartCol, customStartRow + 1);
                        std::cout << std::setw(2) << *customBombCount << std::endl;
                    }
                }
                else if (current == 1 && *customBombCount > 1) {   
                    //std::cout << "  "; 
                    gotoxy(customNumberStartCol, customStartRow + current);
                    std::cout << std::setw(2) << --(*customBombCount) << std::endl;
                }
                break;

            case 'd': case 'D': 
                gotoxy(customNumberStartCol, customStartRow + current);

                if(current == 0 && *customSize < 18) {  
                    //std::cout << "  ";
                    gotoxy(customNumberStartCol, customStartRow + current);
                    std::cout << std::setw(2) << ++(*customSize) << std::endl;                   
                }
                else if (current == 1 && *customBombCount < 99 && (*customSize)*(*customSize) > *customBombCount) { 
                    //std::cout << "  ";
                    gotoxy(customNumberStartCol, customStartRow + current);
                    std::cout << std::setw(2) << ++(*customBombCount) << std::endl;
                }
                break;
        }
    }
}


#endif
