#include <iomanip>
#include <iostream>

#include "../Include/input.hpp"
#include "../Include/options.hpp"
#include "../Include/show.hpp"

constexpr int cursorColor = 3;
constexpr int levelInfoColor = 7;

void options(int& customSize, int& customBombCount, int& choosedLevel, bool& GodModeOn, int& soundsVolume, int& musicVolume, int& winRow, int& winCol)
{
    int current = 0; // cursor cordinate in option menu
    bool exitFromOptions = false;
    while (true) {
        system("clear");
        if (exitFromOptions) {
            break;
        }

        const int rowCenter = winRow / 2 + 1;
        const int colCenter = winCol / 2 + 1;

        Show_GameName(colCenter, rowCenter - 11);

        gotoxy(colCenter - 16, rowCenter * 2 - 2);
        colorCout("Press Esc to return to MAIN MENU", 7);

        constexpr int optionsSize = 11;
        const std::string options[optionsSize] = { "Beginner", "Veteran", "Expert", "Pro", "Master", "", "Sounds", "Music", "", "God Mode", "Custom Mode >" };

        constexpr size_t customMenuSize = 2;
        const std::string custom[customMenuSize] = { "Custom size: ", "Custom bomb count: " };

        constexpr size_t levelInfoSize = 11;
        const std::string levelInfo[levelInfoSize] = {  " Size = 8x8,   Mines = 10", // Beginnger
                                                        " Size = 10x10, Mines = 20", // Veteran
                                                        " Size = 12x12, Mines = 35", // Expert
                                                        " Size = 15x15, Mines = 50", // Pro
                                                        " Size = 18x18, Mines = 99", // Master
                                                        "", "", "", "", "", "" };

        constexpr size_t volumeSize = 11;
        const std::string volume[volumeSize] = {"[□□□□□□□□□□]   0%",
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

        const int optionsStartRow = rowCenter;
        const int optionsStartCol = colCenter - 4;
        printOptions(options, volume, custom, levelInfo, current, optionsSize, choosedLevel, GodModeOn, soundsVolume, musicVolume, optionsStartRow, optionsStartCol, customSize, customBombCount);

        bool sizeChanged = false;
        cbreak();
        while (true) {

            constexpr int minWinRowSize = 27, minWinColSize = 130;
            if (sizeChanged || winSizeChanged(winRow, winCol, minWinRowSize, minWinColSize)) {
                break;
            }

            int key = keypress();
            if (key == 27 || exitFromOptions) {
                exitFromOptions = true;
                break;
            }
            switch (key) {
            case 'w': case 'W':
                cursorMoveInOptions(options, levelInfo, key, current, choosedLevel, optionsSize, optionsStartRow, optionsStartCol);
                break;

            case 's': case 'S':
                cursorMoveInOptions(options, levelInfo, key, current, choosedLevel, optionsSize, optionsStartRow, optionsStartCol);
                break;

            case 'a': case 'A':
                gotoxy(optionsStartCol + 8, optionsStartRow + current);

                if (current == 6 && soundsVolume > 0) {
                    std::cout << volume[--soundsVolume] << std::endl;
                }
                else if (current == 7 && musicVolume > 0) {
                    std::cout << volume[--musicVolume] << std::endl;
                }
                break;

            case 'd': case 'D':
                gotoxy(optionsStartCol + 8, optionsStartRow + current);

                if (current == 6 && soundsVolume < 10) {
                    std::cout << volume[++soundsVolume] << std::endl;
                }
                else if (current == 7 && musicVolume < 10) {
                    std::cout << volume[++musicVolume] << std::endl;
                }
                break;

            case 10: //Enter
                switch (current) {
                case 9: // God Mode
                    gotoxy(optionsStartCol + 9, optionsStartRow + current);

                    if (GodModeOn) {
                        GodModeOn = false;
                        colorCout("Off", 5);
                    }
                    else {
                        GodModeOn = true;
                        colorCout("On ", 3);
                    }
                    break;

                case 6: case 7: // Sound, Music
                    break;

                case 10: //Custom Mode
                    gotoxy(optionsStartCol - 2, optionsStartRow + choosedLevel - 1);
                    std::cout << " ";
                    choosedLevel = 11;
                    gotoxy(optionsStartCol - 2, optionsStartRow + choosedLevel - 1);
                    colorCout("►", 7);
                    gotoxy(optionsStartCol, optionsStartRow + current);
                    std::cout << options[current];

                    customMode(custom, customSize, customBombCount, exitFromOptions, optionsStartRow, optionsStartCol, sizeChanged, winRow, winCol);

                    gotoxy(optionsStartCol, optionsStartRow + current);
                    colorCout(options[current], 3);
                    break;

                default:
                    gotoxy(optionsStartCol - 2, optionsStartRow + choosedLevel - 1);
                    std::cout << " ";
                    choosedLevel = current + 1;
                    gotoxy(optionsStartCol - 2, optionsStartRow + current);
                    colorCout("►", 7);
                    break;
                }
                break;
            
            }
        }
    }
}

void cursorMoveInOptions(const std::string* options, const std::string* levelInfo, const int key, int& current, const int choosedLevel, const int optionsSize, const int optionsStartRow, const int optionsStartCol)
{
    // Delete level info
    if (current < 5) {
        clearLine(optionsStartRow + current);
    }
    gotoxy(optionsStartCol, optionsStartRow + current);
    std::cout << options[current];

    //Choose cursor's next place
    if (key == 'w' || key == 'W') {
        switch (current) {
        case 0: current = optionsSize - 1; break;
        case 9: current = 7; break;
        case 6: current = 4; break;
        default: --current; break;
        }
    }
    else if (key == 's' || key == 'S') {
        switch (current) {
        case 10: current = 0; break;
        case 4: current = 6; break;
        case 7: current = 9; break;
        default: ++current;  break;
        }
    }

    //Print cursor in his new place
    gotoxy(optionsStartCol, optionsStartRow + current);
    colorCout(options[current], cursorColor);
    // Print new level info
    gotoxy(optionsStartCol + 9, optionsStartRow + current);
    colorCout(levelInfo[current], levelInfoColor);
    //Print choosed level if it was deleted
    gotoxy(optionsStartCol - 2, optionsStartRow + choosedLevel - 1);
    colorCout("►", 7);
}

void pressedGodMode(bool& GodModeOn, int& current, const int optionsStartRow, const int optionsStartCol)
{
    gotoxy(optionsStartCol + 9, optionsStartRow + current);

    if (GodModeOn) {
        GodModeOn = false;
        colorCout("Off", 5);
    }
    else {
        GodModeOn = true;
        colorCout("On ", 3);
    }
}

void printOptions(const std::string* options, const std::string* volume, const std::string* custom, const std::string* levelInfo, const int current, const int optionsSize, const int choosedLevel, const bool GodModeOn, const int soundsVolume, const int musicVolume, const int optionsStartRow, const int optionsStartCol, const int customSize, const int customBombCount)
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
    colorCout(options[current], cursorColor); //3 = green

    //Level Info
    gotoxy(optionsStartCol + 9, optionsStartRow + current);
    colorCout(levelInfo[current], levelInfoColor); //7 = yellow
    
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

    ///CUSTOM
    const int customStartRow = optionsStartRow + 10;
    const int customStartCol = optionsStartCol + 15;
    gotoxy(customStartCol, customStartRow);
    colorCout(custom[0], 7);

    gotoxy(customStartCol, customStartRow + 1);
    colorCout(custom[1], 7);

    //Print custom size
    const int customNumberStartCol = customStartCol + 19;
    gotoxy(customNumberStartCol, customStartRow);
    std::cout << std::setw(2) << customSize << std::endl;
    //Print custom bomb count
    gotoxy(customNumberStartCol, customStartRow + 1);
    std::cout << std::setw(2) << customBombCount << std::endl;

    std::cout << std::endl;
}

void customMode(const std::string* custom, int& customSize, int& customBombCount, bool& exitFromOptions, const int optionsStartRow, const int optionsStartCol, bool& sizeOfWinChanged, int& winRow, int& winCol)
{      
    const int customStartRow = optionsStartRow + 10;
    const int customStartCol = optionsStartCol + 15;
      
    //Print custom
    gotoxy(customStartCol, customStartRow);
    colorCout(custom[0], cursorColor);

    gotoxy(customStartCol, customStartRow + 1);
    colorCout(custom[1], 7);

    //Print custom size
    const int customNumberStartCol = customStartCol + 19;
    gotoxy(customNumberStartCol, customStartRow);
    std::cout << std::setw(2) << customSize << std::endl;
    //Print custom bomb count
    gotoxy(customNumberStartCol, customStartRow + 1);
    std::cout << std::setw(2) << customBombCount << std::endl;
   
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
                exitFromOptions = true; 
            }
            break;    
        }

        constexpr int minWinRowSize = 27, minWinColSize = 130;
        if (winSizeChanged(winRow, winCol, minWinRowSize, minWinColSize)) {
            sizeOfWinChanged = true;
            break;
        }

        switch(key) {
            case 'w': case 'W':
                cursorMoveInCustom(custom, key, current, customStartRow, customStartCol);
                break;

            case 's': case 'S':
                cursorMoveInCustom(custom, key, current, customStartRow, customStartCol);
                break;

            case 'a': case 'A': 
                gotoxy(customNumberStartCol, customStartRow + current);

                if(current == 0 && customSize > 5) {
                    gotoxy(customNumberStartCol, customStartRow + current);

                    std::cout << std::setw(2) << --customSize << std::endl; 
                    if(customSize * customSize < customBombCount) {
                        customBombCount = customSize * customSize;
                        gotoxy(customNumberStartCol, customStartRow + 1);
                        gotoxy(customNumberStartCol, customStartRow + 1);
                        std::cout << std::setw(2) << customBombCount << std::endl;
                    }
                }
                else if (current == 1 && customBombCount > 1) {
                    gotoxy(customNumberStartCol, customStartRow + current);
                    std::cout << std::setw(2) << --customBombCount << std::endl;
                }
                break;

            case 'd': case 'D': 
                gotoxy(customNumberStartCol, customStartRow + current);

                if(current == 0 && customSize < 18) {  
                    gotoxy(customNumberStartCol, customStartRow + current);
                    std::cout << std::setw(2) << ++customSize << std::endl;                   
                }
                else if (current == 1 && customBombCount < 99 && customSize * customSize > customBombCount) { 
                    gotoxy(customNumberStartCol, customStartRow + current);
                    std::cout << std::setw(2) << ++customBombCount << std::endl;
                }
                break;
        }
    }
}

void cursorMoveInCustom(const std::string* custom, const int key, int& current, const int customStartRow, const int customStartCol)
{
    gotoxy(customStartCol, customStartRow + current);
    colorCout(custom[current], 7);

    if (key == 'w' || key == 'W') {
        current == 0 ? current = 1 : --current;
    }
    else if (key == 's' || key == 'S') {
        current == 1 ? current = 0 : ++current;
    }

    gotoxy(customStartCol, customStartRow + current);
    colorCout(custom[current], cursorColor);
}
