#ifndef SHOW
#define SHOW

#include <iostream>
#include <iomanip>

#include "input.hpp"

void Show_GameName(int const printCol, int printRow)    //Print Game Name
{ 
    system("clear");
    
    gotoxy(printCol, printRow);
    std::cout << "\x1b[31;1m" << "\t _____ ______   ___  ________   _______   ________  ___       __   _______   _______   ________  _______   ________     " << "\x1b[0m\n";
    
    gotoxy(printCol, ++printRow);
    std::cout << "\x1b[31;1m" << "\t|\\   _ \\  _   \\|\\  \\|\\   ___  \\|\\  ___ \\ |\\   ____\\|\\  \\     |\\  \\|\\  ___ \\ |\\  ___ \\ |\\   __  \\|\\  ___ \\ |\\   __  \\    " << "\x1b[0m\n";
    
    gotoxy(printCol, ++printRow);
    std::cout << "\x1b[31;1m" << "\t\\ \\  \\\\\\__\\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\   __/ \\ \\  \\___|\\ \\  \\    \\ \\  \\ \\   __/ \\ \\   __/ \\ \\  \\|\\  \\ \\   __/ \\ \\  \\|\\  \\   " << "\x1b[0m\n";
     
    gotoxy(printCol, ++printRow);
    std::cout << "\x1b[31;1m" << "\t \\ \\  \\\\|__| \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\_|  \\ \\_____  \\ \\  \\  __\\ \\  \\ \\  \\_|  \\ \\  \\_|  \\ \\   ____\\ \\  \\_|  \\ \\   _  _\\  " << "\x1b[0m\n";
    
    gotoxy(printCol, ++printRow);
    std::cout << "\x1b[31;1m" << "\t  \\ \\  \\    \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\_|\\ \\|____|\\  \\ \\  \\|\\__\\_\\  \\ \\  \\_|\\ \\ \\  \\_|\\ \\ \\  \\___|\\ \\  \\_|\\ \\ \\  \\\\  \\| " << "\x1b[0m\n";
    
    gotoxy(printCol, ++printRow);
    std::cout << "\x1b[31;1m" << "\t   \\ \\__\\    \\ \\__\\ \\__\\ \\__\\\\ \\__\\ \\_______\\____\\_\\  \\ \\____________\\ \\_______\\ \\_______\\ \\__\\    \\ \\_______\\ \\__\\\\ _\\ " << "\x1b[0m\n";
     
    gotoxy(printCol, ++printRow);
    std::cout << "\x1b[31;1m" << "\t    \\|__|     \\|__|\\|__|\\|__| \\|__|\\|_______|\\_________\\|____________|\\|_______|\\|_______|\\|__|     \\|_______|\\|__|\\|__|" << "\x1b[0m\n";
    
    gotoxy(printCol, ++printRow);
    std::cout << "\x1b[31;1m" << "\t                                            \\|_________|                                                            " << "\x1b[0m\n";

}

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

void Show_Control(int const rowCenter, int const colCenter, int showControlStart) 
{
    gotoxy(colCenter - 6, showControlStart);
    colorCout("Game Contol", 4);

    showControlStart += 2;
    gotoxy(colCenter - 39, showControlStart);
    std::cout << "[W] - Up   [S] - Down   [A] - Left   [D] - Right   [Enter] - Open   [F] - Flag";
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
    
        int const textColSize = 38;
        gotoxy(colCenter - textColSize, aboutStart + 2); 
        std::cout << " Minesweeper is a single-player puzzle video game. The objective of the game\n"; 
        gotoxy(colCenter - textColSize, aboutStart + 3);
        std::cout << "is to clear a rectangular board containing hidden ""mines"" or bombs without\n";    
        gotoxy(colCenter - textColSize, aboutStart + 4);
        std::cout << "detonating any of them, with help from clues about the number of neighboring\n";   
        gotoxy(colCenter - textColSize, aboutStart + 5);
        std::cout << "mines in each field. The game originates from the 1960s, and it has been\n";  
        gotoxy(colCenter - textColSize, aboutStart + 6);
        std::cout << "written for many computing platforms in use today. It has many variations and\n";
        gotoxy(colCenter - textColSize, aboutStart + 7);
        std::cout << "offshoots.";
    
        int const gamePlayStart = 13;
        gotoxy(colCenter - 4, gamePlayStart);
        colorCout("Gameplay", 4);
        
        gotoxy(colCenter - textColSize, gamePlayStart + 2);
        std::cout << " In Minesweeper, mines (that resemble naval mines in the classic theme) are\n"; 
        gotoxy(colCenter - textColSize, gamePlayStart + 3);
        std::cout << "scattered throughout a board, which is divided into cells. Cells have three\n";
        gotoxy(colCenter - textColSize, gamePlayStart + 4);
        std::cout << "states: uncovered, covered and flagged. A covered cell is blank and clickable,\n";
        gotoxy(colCenter - textColSize, gamePlayStart + 5);
        std::cout << "while an uncovered cell is exposed. Flagged cells are those marked by the\n";
        gotoxy(colCenter - textColSize, gamePlayStart + 6);
        std::cout << "player to indicate a potential mine location. \n";
        
        gotoxy(colCenter - textColSize, gamePlayStart + 8);
        std::cout << " A player should press or a cell to uncover it. If a player uncovers a mined\n";
        gotoxy(colCenter - textColSize, gamePlayStart + 9);
        std::cout << "cell, the game ends, as there is only 1 life per game. Otherwise, the\n";
        gotoxy(colCenter - textColSize, gamePlayStart + 10);
        std::cout << "uncovered cells displays either a number, indicating the number of mines\n";
        gotoxy(colCenter - textColSize, gamePlayStart + 11);
        std::cout << "diagonally and/or adjacent to it, or a blank tile (or ""0""), and all adjacent\n";
        gotoxy(colCenter - textColSize, gamePlayStart + 12);
        std::cout << "non-mined cells will automatically be uncovered. Button on a cell will\n";
        gotoxy(colCenter - textColSize, gamePlayStart + 13);
        std::cout << "flag it, causing a flag to appear on it. Flagged cells are still considered\n";
        gotoxy(colCenter - textColSize, gamePlayStart + 14);
        std::cout << "covered, and a player can prees on them to uncover them. \n";
    
        gotoxy(colCenter - textColSize, gamePlayStart + 16);
        std::cout << " To win the game, players must uncover all non-mine cells, at which point,\n"; 
        gotoxy(colCenter - textColSize, gamePlayStart + 17);
        std::cout << "the timer is stopped. Flagging all the mined cells is not required.";
    
        int const showControlStart = 33;
        Show_Control(rowCenter, colCenter, showControlStart);
        
        gotoxy(colCenter - 16, showControlStart + 5);
        colorCout("Press Esc to return to MAIN MENU", 7);
        
        exitFromAbout = false;
        cbreak();
        while(true) {       
            int const minWinRowSize = 38, minWinColSize = 78;
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

void Show_Boards(int const size, int const rowCenter, int const colCenter, int const color)
{
    for(int i = 0; i < size; ++i) {
        gotoxy(colCenter - size + 1, rowCenter - size/2 + i);
        colorCout("█", color);
        
        gotoxy(colCenter + size - 1, rowCenter - size/2 + i);
        colorCout("█", color);
    }
            
    for(int i = 1; i < size*2; ++i) {
        gotoxy(colCenter - size + i, rowCenter - size/2); 
        colorCout("▄", color);
        
        gotoxy(colCenter - size + i, rowCenter + (size-1)/2);
        colorCout("▀", color);                                            
    }
}

void Show_GameOver(int const size ,int const rowCenter, int const colCenter)
{   
    int gameOverColor = 5; //5 = red

    //Print red boards and letters because user is lose
    Show_ExitRestart(rowCenter, colCenter, gameOverColor);
    Show_Boards(size, rowCenter, colCenter, gameOverColor);

    int const textColSize = 21, gameOverStart = 2;
    gotoxy(colCenter - textColSize, gameOverStart);
    colorCout("██████████████████████████████████████████", gameOverColor);

    gotoxy(colCenter - textColSize, gameOverStart + 1);
    colorCout("█────█────█─███─█───████────█─█─█───█────█", gameOverColor);

    gotoxy(colCenter - textColSize, gameOverStart + 2);
    colorCout("█─████─██─█──█──█─██████─██─█─█─█─███─██─█", gameOverColor);

    gotoxy(colCenter - textColSize, gameOverStart + 3);
    colorCout("█─█──█────█─█─█─█───████─██─█─█─█───█────█", gameOverColor);

    gotoxy(colCenter - textColSize, gameOverStart + 4);
    colorCout("█─██─█─██─█─███─█─██████─██─█───█─███─█─██", gameOverColor);

    gotoxy(colCenter - textColSize, gameOverStart + 5);
    colorCout("█────█─██─█─███─█───████────██─██───█─█─██", gameOverColor);

    gotoxy(colCenter - textColSize, gameOverStart + 6);
    colorCout("██████████████████████████████████████████", gameOverColor);
}

void Show_Win(int const size, int const rowCenter, int const colCenter)
{   
    int winColor = 10; //10 = bright green 

    //Print green boards and letters because user is win
    Show_ExitRestart(rowCenter, colCenter, winColor);
    Show_Boards(size, rowCenter, colCenter, winColor);

    int const textColSize = 21, winStart = 2;
    gotoxy(colCenter - textColSize, winStart);
    colorCout("██████████████████████████████████████████", winColor);

    gotoxy(colCenter - textColSize, winStart + 1);
    colorCout("█─███─█───█─██─█─██─█───█────███████─█─█─█", winColor);

    gotoxy(colCenter - textColSize, winStart + 2);
    colorCout("█─███─██─██──█─█──█─█─███─██─███████─█─█─█", winColor);

    gotoxy(colCenter - textColSize, winStart + 3);
    colorCout("█─█─█─██─██─█──█─█──█───█────███████─█─█─█", winColor);

    gotoxy(colCenter - textColSize, winStart + 4);
    colorCout("█─────██─██─██─█─██─█─███─█─██████████████", winColor);

    gotoxy(colCenter - textColSize, winStart + 5);
    colorCout("██─█─██───█─██─█─██─█───█─█─████████─█─█─█", winColor);

    gotoxy(colCenter - textColSize, winStart + 6);
    colorCout("██████████████████████████████████████████", winColor);
}

//Cheat mode for easy play
//When Gode mode is on, the user's nickname will not be added in records
void GodeMode(int** Back, int const size)
{
    for(int i = 1; i < size - 1; ++i) {
        for(int j = 1; j < size - 1; ++j) {
            gotoxy((j*3) - 2, i + 1);

            switch(Back[i][j]) {
                case  -1: std::cout << "\x1b[31;1m" << std::setw(3) << "X" << "\x1b[0m\n"; break;
                case   0: std::cout << std::setw(3) << "-"; break;
                default : std::cout << std::setw(3) << Back[i][j]; break;  
            }
        }   
    }   
}


#endif
