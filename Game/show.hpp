#ifndef SHOW
#define SHOW

#include <iostream>
#include <iomanip>

#include "input.hpp"

void Show_GameName(int const printCol, int const printRow)    
{ 
    system("clear");
    int const gameNameColor = 5;
    
    gotoxy(printCol, printRow);
    colorCout(R"(   _____ ______   ___  ________   _______   ________  ___       __   _______   _______   ________  _______   ________      )", gameNameColor);
    
    gotoxy(printCol, printRow + 1);
    colorCout(R"(  |\   _ \  _   \|\  \|\   ___  \|\  ___ \ |\   ____\|\  \     |\  \|\  ___ \ |\  ___ \ |\   __  \|\  ___ \ |\   __  \     )", gameNameColor);
    
    gotoxy(printCol, printRow + 2);
    colorCout(R"(  \ \  \\\__\ \  \ \  \ \  \\ \  \ \   __/ \ \  \___|\ \  \    \ \  \ \   __/ \ \   __/ \ \  \|\  \ \   __/ \ \  \|\  \    )", gameNameColor);
    
    gotoxy(printCol, printRow + 3);
    colorCout(R"(   \ \  \\|__| \  \ \  \ \  \\ \  \ \  \_| _\ \_____  \ \  \  __\ \  \ \  \_| _\ \  \_| _\ \   ____\ \  \_| _\ \   _  _\   )", gameNameColor);
  
    gotoxy(printCol, printRow + 4);
    colorCout(R"(    \ \  \    \ \  \ \  \ \  \\ \  \ \  \_|\ \|____|\  \ \  \|\__\_\  \ \  \_|\ \ \  \_|\ \ \  \___|\ \  \_|\ \ \  \\  \|  )", gameNameColor);
    
    gotoxy(printCol, printRow + 5);
    colorCout(R"(     \ \__\    \ \__\ \__\ \__\\ \__\ \_______\____\_\  \ \____________\ \_______\ \_______\ \__\    \ \_______\ \__\\ _\  )", gameNameColor);
     
    gotoxy(printCol, printRow + 6);
    colorCout(R"(      \|__|     \|__|\|__|\|__| \|__|\|_______|\_________\|____________|\|_______|\|_______|\|__|     \|_______|\|__|\|__| )", gameNameColor);
   
    gotoxy(printCol, printRow + 7); 
    colorCout(R"(                                              \|_________|                                                                 )", gameNameColor);

}

//Press Ecs or Restart
void Show_ExitRestart(int const rowCenter, int const colCenter, int const color)
{
    int const showExitStart = rowCenter*2 - 4;
    gotoxy(colCenter - 9, showExitStart);
    colorCout("Press R to ", 7);
    
    gotoxy(colCenter + 2, showExitStart);
    colorCout("RESTART", color); 

    gotoxy(colCenter - 16, showExitStart + 1);
    colorCout("Press Esc to return to ", 7); 

    gotoxy(colCenter + 7, showExitStart + 1);
    colorCout("MAIN MENU", color);
}

//How to play
void Show_Control( int const showControlRowStart, int const showControlColStart) 
{   
    gotoxy(showControlColStart + 15, showControlRowStart);
    colorCout("How to play", 4); 

    gotoxy(showControlColStart, showControlRowStart + 2);  
    
    std::cout << R"(         ____                   ____      )"; gotoxy(showControlColStart, showControlRowStart + 3);   
    std::cout << R"(        ||W ||                 ||F ||     )"; gotoxy(showControlColStart, showControlRowStart + 4);  
    std::cout << R"(        ||__||                 ||__||     )"; gotoxy(showControlColStart, showControlRowStart + 5);  
    std::cout << R"(        |/__\|                 |/__\|     )"; gotoxy(showControlColStart, showControlRowStart + 6);  
    std::cout << R"(   ____   ____   ____         _________   )"; gotoxy(showControlColStart, showControlRowStart + 7);  
    std::cout << R"(  ||A || ||S || ||D ||       || Enter ||  )"; gotoxy(showControlColStart, showControlRowStart + 8);  
    std::cout << R"(  ||__|| ||__|| ||__||       ||_______||  )"; gotoxy(showControlColStart, showControlRowStart + 9);  
    std::cout << R"(  |/__\| |/__\| |/__\|       |/_______\|  )";  
}

void Show_About(int* winRow, int* winCol)
{
    bool exitFromAbout = false;
    while(!exitFromAbout) {
        system("clear");
      
        int const rowCenter = *winRow / 2 + 1;
        int const colCenter = *winCol / 2 + 1;       
        
        int const aboutStart = 3;
        gotoxy(colCenter - 8, aboutStart);
        colorCout("About Minesweeper", 4);
    
        int const textColSize = 51;
        gotoxy(colCenter - textColSize, aboutStart + 2); 
        std::cout << " Minesweeper is a single-player puzzle video game. The objective of the game is to clear a rectangular\n"; 
        gotoxy(colCenter - textColSize, aboutStart + 3);
        std::cout << "board containing hidden ""mines"" or bombs without detonating any of them, with help from clues\n";    
        gotoxy(colCenter - textColSize, aboutStart + 4);
        std::cout << "about the number of neighboring mines in each field. The game originates from the 1960s, and it has\n";   
        gotoxy(colCenter - textColSize, aboutStart + 5);
        std::cout << "been written for many computing platforms in use today. It has many variations and offshoots.\n";  
        
        gotoxy(colCenter - textColSize + 10, aboutStart + 6);
        colorCout("‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗", 4);

        int const gamePlayStart = 11;
        gotoxy(colCenter - 4, gamePlayStart);
        colorCout("Gameplay", 4);
        
        gotoxy(colCenter - textColSize, gamePlayStart + 2);
        std::cout << " In Minesweeper, mines (that resemble naval mines in the classic theme) are scattered throughout a\n"; 
        gotoxy(colCenter - textColSize, gamePlayStart + 3);
        std::cout << "board, which is divided into cells. Cells have three states: uncovered, covered and flagged.\n";
        gotoxy(colCenter - textColSize, gamePlayStart + 4);
        std::cout << "A covered cell is blank and clickable, while an uncovered cell is exposed. Flagged cells are those\n";
        gotoxy(colCenter - textColSize, gamePlayStart + 5);
        std::cout << "marked by the player to indicate a potential mine location.\n";


        gotoxy(colCenter - textColSize, gamePlayStart + 7);
        std::cout << " A player should press or a cell to uncover it. If a player uncovers a mined cell, the game ends, as\n";
        gotoxy(colCenter - textColSize, gamePlayStart + 8);
        std::cout << "there is only 1 life per game. Otherwise, the uncovered cells displays either a number, indicating the\n";
        gotoxy(colCenter - textColSize, gamePlayStart + 9);
        std::cout << "number of mines diagonally and/or adjacent to it, or a blank tile (or ""0""), and all adjacent non-mined\n";
        gotoxy(colCenter - textColSize, gamePlayStart + 10);
        std::cout << "cells will automatically be uncovered. Button on a cell will flag it, causing a flag to appear on it.\n";
        gotoxy(colCenter - textColSize, gamePlayStart + 11);
        std::cout << "Flagged cells are still considered covered, and a player can prees on them to uncover them.\n";
    
        gotoxy(colCenter - textColSize, gamePlayStart + 13);
        std::cout << " To win the game, players must uncover all non-mine cells, at which point,\n"; 
        gotoxy(colCenter - textColSize, gamePlayStart + 14);
        std::cout << "the timer is stopped. Flagging all the mined cells is not required.";
        
        gotoxy(colCenter - textColSize + 10, gamePlayStart + 15);
        colorCout("‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗", 4);
        
        int const showControlRowStart = gamePlayStart + 17;
        int const showControlColStart = colCenter - 21;
        Show_Control(showControlRowStart, showControlColStart);

        gotoxy(showControlColStart - 20, showControlRowStart + 10); 
        colorCout("‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗", 4);
        
        gotoxy(colCenter - 16, rowCenter*2 - 2);
        colorCout("Press Esc to return to MAIN MENU", 7);
        
        exitFromAbout = false;
        cbreak();
        while(true) {       
            int const minWinRowSize = 39, minWinColSize = 104;
            if(winSizeChanged(&(*winRow), &(*winCol), minWinRowSize, minWinColSize)) {
                break;
            }
                       
            int key = keypress();
            if(key == 27) {
                exitFromAbout = true;
                break;
            }
        }     
    }
}

//Boards of playing field
void Show_Boards(int const size, int const matrixStartRow, int const matrixStartCol, int const color)
{
    for(int i = 0; i < size-1; ++i) {
        gotoxy(matrixStartCol, matrixStartRow + 1 + i);
        colorCout("█", color);
        
        gotoxy(matrixStartCol + size*2 - 2, matrixStartRow + i);
        colorCout("█", color);
    }
            
    for(int i = -1; i < (size-1)*2; ++i) {
        gotoxy(matrixStartCol + i + 1, matrixStartRow); 
        colorCout("▄", color);
        
        gotoxy(matrixStartCol + i + 1, matrixStartRow + size - 1);
        colorCout("▀", color);                                            
    }
}

void Show_GameOver(int const size ,int const rowCenter, int const colCenter, int const matrixStartRow, int const matrixStartCol)
{   
    int const gameOverColor = 5; //5 = red

    //Print red boards and letters because user is lose
    Show_ExitRestart(rowCenter, colCenter, gameOverColor);
    Show_Boards(size, matrixStartRow, matrixStartCol, gameOverColor);

    int const textColSize = 21, gameOverStart = 2;
    gotoxy(colCenter - textColSize, gameOverStart);
    colorCout("██████████████████████████████████████████", gameOverColor); gotoxy(colCenter - textColSize, gameOverStart + 1);
    colorCout("█────█────█─███─█───████────█─█─█───█────█", gameOverColor); gotoxy(colCenter - textColSize, gameOverStart + 2);
    colorCout("█─████─██─█──█──█─██████─██─█─█─█─███─██─█", gameOverColor); gotoxy(colCenter - textColSize, gameOverStart + 3);
    colorCout("█─█──█────█─█─█─█───████─██─█─█─█───█────█", gameOverColor); gotoxy(colCenter - textColSize, gameOverStart + 4);
    colorCout("█─██─█─██─█─███─█─██████─██─█───█─███─█─██", gameOverColor); gotoxy(colCenter - textColSize, gameOverStart + 5);
    colorCout("█────█─██─█─███─█───████────██─██───█─█─██", gameOverColor); gotoxy(colCenter - textColSize, gameOverStart + 6);
    colorCout("██████████████████████████████████████████", gameOverColor);
}

void Show_Win(int const size, int const rowCenter, int const colCenter, int const matrixStartRow, int const matrixStartCol)
{   
    int const winColor = 10; //10 = bright green 

    //Print green boards and letters because user is win
    Show_ExitRestart(rowCenter, colCenter, winColor);
    Show_Boards(size, matrixStartRow, matrixStartCol, winColor);

    int const textColSize = 21, winStart = 2;
    gotoxy(colCenter - textColSize, winStart);
    colorCout("██████████████████████████████████████████", winColor); gotoxy(colCenter - textColSize, winStart + 1);
    colorCout("█─███─█───█─██─█─██─█───█────███████─█─█─█", winColor); gotoxy(colCenter - textColSize, winStart + 2);
    colorCout("█─███─██─██──█─█──█─█─███─██─███████─█─█─█", winColor); gotoxy(colCenter - textColSize, winStart + 3);
    colorCout("█─█─█─██─██─█──█─█──█───█────███████─█─█─█", winColor); gotoxy(colCenter - textColSize, winStart + 4);
    colorCout("█─────██─██─██─█─██─█─███─█─██████████████", winColor); gotoxy(colCenter - textColSize, winStart + 5);  
    colorCout("██─█─██───█─██─█─██─█───█─█─████████─█─█─█", winColor); gotoxy(colCenter - textColSize, winStart + 6);
    colorCout("██████████████████████████████████████████", winColor); 
}

//Cheat mode for easy play
//When Gode mode is on, the user's nickname will not be added in records
void Show_GodMode(int** Back, int const size)
{
    for(int i = 1; i < size - 1; ++i) {
        for(int j = 1; j < size - 1; ++j) {
            gotoxy((j*3) - 2, i + 1);

            switch(Back[i][j]) {
                case  -1: std::cout << "\x1b[31;1m" << std::setw(3) << "X" << "\x1b[0m\n"; break;
                case   0: case 10: std::cout << std::setw(3) << "-"; break;
                default : std::cout << std::setw(3) << Back[i][j]; break;  
            }
        }   
    }   
}

void Show_Timer(std::time_t beginTime, int const size, int const matrixStartRow, int const matrixStartCol)
{   
    std::time_t currentTime = std::time(nullptr);
    int const time = currentTime - beginTime;

    int const timerStartCol = matrixStartCol + 8 + 2*size; 
    int const timerStartRow = matrixStartRow + 1;
    
    gotoxy(timerStartCol - 2, timerStartRow);
    colorCout("T I M E\t\t\t\t\n", 7);

    int const hours = time / 3600;
    int const min = (time % 3600) / 60;
    int const sec = (time % 3600) % 60;

    gotoxy(timerStartCol - 5, timerStartRow + 1);
    std::cout << std::setw(2) << hours << " : " << std::setw(2) << min << " : " << std::setw(2) << sec << "\t\t\t\t\n";         
}

///Levels

void Show_Beginner(int const rowCenter, int const colCenter)
{
    int const textSize = 53, easyColor = 4;
    int const beginnerStartRow = rowCenter - 15;
    int const beginnerStartCol = colCenter - textSize/2;

    gotoxy(beginnerStartCol, beginnerStartRow);
    colorCout(R"( ______               _                            )", easyColor); gotoxy(beginnerStartCol, beginnerStartRow + 1);
    colorCout(R"( | ___ \             (_)                           )", easyColor); gotoxy(beginnerStartCol, beginnerStartRow + 2);
    colorCout(R"( | |_/ /  ___   __ _  _  _ __   _ __    ___  _ __  )", easyColor); gotoxy(beginnerStartCol, beginnerStartRow + 3);
    colorCout(R"( | ___ \ / _ \ / _` || || '_ \ | '_ \  / _ \| '__| )", easyColor); gotoxy(beginnerStartCol, beginnerStartRow + 4);
    colorCout(R"( | |_/ /|  __/| (_| || || | | || | | ||  __/| |    )", easyColor); gotoxy(beginnerStartCol, beginnerStartRow + 5);
    colorCout(R"( \____/  \___| \__, ||_||_| |_||_| |_| \___||_|    )", easyColor); gotoxy(beginnerStartCol, beginnerStartRow + 6);
    colorCout(R"(                __/ |                              )", easyColor); gotoxy(beginnerStartCol, beginnerStartRow + 7);
    colorCout(R"(               |___/                               )", easyColor);
}

void Show_Veteran(int const rowCenter, int const colCenter)
{
    int const textSize = 47, veteranColor = 3;
    int const veteranStartRow = rowCenter - 15;
    int const veteranStartCol = colCenter - textSize/2;

    gotoxy(veteranStartCol, veteranStartRow);
    colorCout(R"(  _   _        _                              )", veteranColor); gotoxy(veteranStartCol, veteranStartRow + 1);
    colorCout(R"( | | | |      | |                             )", veteranColor); gotoxy(veteranStartCol, veteranStartRow + 2);
    colorCout(R"( | | | |  ___ | |_   ___  _ __   __ _  _ __   )", veteranColor); gotoxy(veteranStartCol, veteranStartRow + 3);
    colorCout(R"( | | | | / _ \| __| / _ \| '__| / _` || '_ \  )", veteranColor); gotoxy(veteranStartCol, veteranStartRow + 4);
    colorCout(R"( \ \_/ /|  __/| |_ |  __/| |   | (_| || | | | )", veteranColor); gotoxy(veteranStartCol, veteranStartRow + 5);
    colorCout(R"(  \___/  \___| \__| \___||_|    \__,_||_| |_| )", veteranColor);
}

void Show_Expert(int const rowCenter, int const colCenter)
{
    int const textSize = 39, expertColor = 2;
    int const expertStartRow = rowCenter - 15;
    int const expertStartCol = colCenter - textSize/2;

    gotoxy(expertStartCol, expertStartRow);
    colorCout(R"(  _____                           _    )", expertColor);  gotoxy(expertStartCol, expertStartRow + 1);
    colorCout(R"( |  ___|                         | |   )", expertColor);  gotoxy(expertStartCol, expertStartRow + 2);
    colorCout(R"( | |__  __  __ _ __    ___  _ __ | |_  )", expertColor);  gotoxy(expertStartCol, expertStartRow + 3);
    colorCout(R"( |  __| \ \/ /| '_ \  / _ \| '__|| __| )", expertColor);  gotoxy(expertStartCol, expertStartRow + 4);
    colorCout(R"( | |___  >  < | |_) ||  __/| |   | |_  )", expertColor);  gotoxy(expertStartCol, expertStartRow + 5);
    colorCout(R"( \____/ /_/\_\| .__/  \___||_|    \__| )", expertColor);  gotoxy(expertStartCol, expertStartRow + 6);
    colorCout(R"(              | |                      )", expertColor);  gotoxy(expertStartCol, expertStartRow + 7);
    colorCout(R"(              |_|                      )", expertColor);

}

void Show_Pro(int const rowCenter, int const colCenter)
{   
    int const textSize = 22, proColor = 6;
    int const proStartRow = rowCenter - 15;
    int const proStartCol = colCenter - textSize/2;

    gotoxy(proStartCol, proStartRow);
    colorCout(R"( ______               )", proColor); gotoxy(proStartCol, proStartRow + 1);
    colorCout(R"( | ___ \              )", proColor); gotoxy(proStartCol, proStartRow + 2);
    colorCout(R"( | |_/ / _ __   ___   )", proColor); gotoxy(proStartCol, proStartRow + 3);
    colorCout(R"( |  __/ | '__| / _ \  )", proColor); gotoxy(proStartCol, proStartRow + 4);
    colorCout(R"( | |    | |   | (_) | )", proColor); gotoxy(proStartCol, proStartRow + 5);
    colorCout(R"( \_|    |_|    \___/  )", proColor);
}

void Show_Master(int const rowCenter, int const colCenter)
{
    int const textSize = 41, masterColor = 5;
    int const masterStartRow = rowCenter - 15;
    int const masterStartCol = colCenter - textSize/2;

    gotoxy(masterStartCol, masterStartRow);
    colorCout(R"( ___  ___             _                )", masterColor); gotoxy(masterStartCol, masterStartRow + 1);
    colorCout(R"( |  \/  |            | |               )", masterColor); gotoxy(masterStartCol, masterStartRow + 2);
    colorCout(R"( | .  . |  __ _  ___ | |_   ___  _ __  )", masterColor); gotoxy(masterStartCol, masterStartRow + 3);
    colorCout(R"( | |\/| | / _` |/ __|| __| / _ \| '__| )", masterColor); gotoxy(masterStartCol, masterStartRow + 4);
    colorCout(R"( | |  | || (_| |\__ \| |_ |  __/| |    )", masterColor); gotoxy(masterStartCol, masterStartRow + 5);
    colorCout(R"( \_|  |_/ \__,_||___/ \__| \___||_|    )", masterColor);
}

void Show_levelName(int const level, int const rowCenter, int const colCenter)
{
    switch(level) {
        case 1: Show_Beginner(rowCenter, colCenter); break;
        case 2: Show_Veteran(rowCenter, colCenter);  break;
        case 3: Show_Expert(rowCenter, colCenter);   break;
        case 4: Show_Pro(rowCenter, colCenter);      break;
        case 5: Show_Master(rowCenter, colCenter);   break;
    }
}

void Show_Pause(int const rowCenter, int const colCenter)
{
    int const textSize = 33, pauseColor = 2;
    int const pauseStartRow = rowCenter - 15;
    int const pauseStartCol = colCenter - textSize/2;

    gotoxy(pauseStartCol, pauseStartRow);
    colorCout(R"( ______                           )", pauseColor); gotoxy(pauseStartCol, pauseStartRow + 1);
    colorCout(R"( | ___ \                          )", pauseColor); gotoxy(pauseStartCol, pauseStartRow + 2);
    colorCout(R"( | |_/ /  __ _  _   _  ___   ___  )", pauseColor); gotoxy(pauseStartCol, pauseStartRow + 3);
    colorCout(R"( |  __/  / _` || | | |/ __| / _ \ )", pauseColor); gotoxy(pauseStartCol, pauseStartRow + 4);
    colorCout(R"( | |    | (_| || |_| |\__ \|  __/ )", pauseColor); gotoxy(pauseStartCol, pauseStartRow + 5);
    colorCout(R"( \_|     \__,_| \__,_||___/ \___| )", pauseColor);

    gotoxy(colCenter - 12, rowCenter*2 - 4);
    colorCout("Press 'P' for resume game", 7);
    gotoxy(colCenter - 16, rowCenter*2 - 3);
    colorCout("Press Esc to return to MAIN MENU", 7);
}

#endif

