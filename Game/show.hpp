#ifndef SHOW
#define SHOW

#include <iostream>

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
    int showExitStart = rowCenter*2 - 4;
    gotoxy(colCenter - 9, showExitStart);
    colorCout("Press R to ", 7);
    
    gotoxy(colCenter + 2, showExitStart);
    colorCout("RESTART", color); 

    gotoxy(colCenter - 16, ++showExitStart);
    colorCout("Press Esc to return to ", 7); 

    gotoxy(colCenter + 7, showExitStart);
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
    
        int const rowCenter = *winRow / 2 + 1;
        int const colCenter = *winCol / 2 + 1;

        exitFromAbout = false;

    system("clear");
    
    int aboutStart = 3;
    gotoxy(colCenter - 8, aboutStart);
    colorCout("About Minesweeper", 4);
    
    int const textColSize = 38;
    aboutStart += 2;
    gotoxy(colCenter - textColSize, aboutStart); 
    std::cout << " Minesweeper is a single-player puzzle video game. The objective of the game\n"; 
    gotoxy(colCenter - textColSize, ++aboutStart);
    std::cout << "is to clear a rectangular board containing hidden ""mines"" or bombs without\n";    
    gotoxy(colCenter - textColSize, ++aboutStart);
    std::cout << "detonating any of them, with help from clues about the number of neighboring\n";   
    gotoxy(colCenter - textColSize, ++aboutStart);
    std::cout << "mines in each field. The game originates from the 1960s, and it has been\n";  
    gotoxy(colCenter - textColSize, ++aboutStart);
    std::cout << "written for many computing platforms in use today. It has many variations and\n";
    gotoxy(colCenter - textColSize, ++aboutStart);
    std::cout << "offshoots.";

    aboutStart += 3;
    gotoxy(colCenter - 4, aboutStart);
    colorCout("Gameplay", 4);
    
    aboutStart += 2;
    gotoxy(colCenter - textColSize, aboutStart);
    std::cout << " In Minesweeper, mines (that resemble naval mines in the classic theme) are\n"; 
    gotoxy(colCenter - textColSize, ++aboutStart);
    std::cout << "scattered throughout a board, which is divided into cells. Cells have three\n";
    gotoxy(colCenter - textColSize, ++aboutStart);
    std::cout << "states: uncovered, covered and flagged. A covered cell is blank and clickable,\n";
    gotoxy(colCenter - textColSize, ++aboutStart);
    std::cout << "while an uncovered cell is exposed. Flagged cells are those marked by the\n";
    gotoxy(colCenter - textColSize, ++aboutStart);
    std::cout << "player to indicate a potential mine location. \n";
    
    aboutStart += 2;
    gotoxy(colCenter - textColSize, aboutStart);
    std::cout << " A player should press or a cell to uncover it. If a player uncovers a mined\n";
    gotoxy(colCenter - textColSize, ++aboutStart);
    std::cout << "cell, the game ends, as there is only 1 life per game. Otherwise, the\n";
    gotoxy(colCenter - textColSize, ++aboutStart);
    std::cout << "uncovered cells displays either a number, indicating the number of mines\n";
    gotoxy(colCenter - textColSize, ++aboutStart);
    std::cout << "diagonally and/or adjacent to it, or a blank tile (or ""0""), and all adjacent\n";
    gotoxy(colCenter - textColSize, ++aboutStart);
    std::cout << "non-mined cells will automatically be uncovered. Button on a cell will\n";
    gotoxy(colCenter - textColSize, ++aboutStart);
    std::cout << "flag it, causing a flag to appear on it. Flagged cells are still considered\n";
    gotoxy(colCenter - textColSize, ++aboutStart);
    std::cout << "covered, and a player can prees on them to uncover them. \n";

    aboutStart += 2;
    gotoxy(colCenter - textColSize, aboutStart);
    std::cout << " To win the game, players must uncover all non-mine cells, at which point,\n"; 
    gotoxy(colCenter - textColSize, ++aboutStart);
    std::cout << "the timer is stopped. Flagging all the mined cells is not required.";

    int showControlStart = aboutStart + 3;
    Show_Control(rowCenter, colCenter, showControlStart);

    gotoxy(colCenter - 16, showControlStart + 5);
    colorCout("Press Esc to return to MAIN MENU", 7);
    
    cbreak();
    while(true)
    {        
        int newWinRow, newWinCol;
        userWinSize(&newWinRow, &newWinCol);

        if(newWinRow != (*winRow) || newWinCol != (*winCol)) {
            if(newWinRow < 38 || newWinCol < 78) {
                *winRow = 38;
                *winCol = 78;
                std::cout << "\e[8;38;78t";
            } else {
                *winRow = newWinRow;
                *winCol = newWinCol;
            }
            break;
        }
        
        int key = keypress();
        if(key == 27)
        {
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
    Show_ExitRestart(rowCenter, colCenter, 5);
    Show_Boards(size, rowCenter, colCenter, 5);

    int const textColSize = 21;
    int gameOverStart = 2;
    gotoxy(colCenter - textColSize, gameOverStart);
    colorCout("██████████████████████████████████████████", 5);

    gotoxy(colCenter - textColSize, ++gameOverStart);
    colorCout("█────█────█─███─█───████────█─█─█───█────█", 5);

    gotoxy(colCenter - textColSize, ++gameOverStart);
    colorCout("█─████─██─█──█──█─██████─██─█─█─█─███─██─█", 5);

    gotoxy(colCenter - textColSize, ++gameOverStart);
    colorCout("█─█──█────█─█─█─█───████─██─█─█─█───█────█", 5);

    gotoxy(colCenter - textColSize, ++gameOverStart);
    colorCout("█─██─█─██─█─███─█─██████─██─█───█─███─█─██", 5);

    gotoxy(colCenter - textColSize, ++gameOverStart);
    colorCout("█────█─██─█─███─█───████────██─██───█─█─██", 5);

    gotoxy(colCenter - textColSize, ++gameOverStart);
    colorCout("██████████████████████████████████████████", 5);
}

void Show_Win(int const size, int const rowCenter, int const colCenter)
{    
    Show_ExitRestart(rowCenter, colCenter, 3);
    Show_Boards(size, rowCenter, colCenter, 3);

    int const textColSize = 21;
    int winStart = 2; 
    gotoxy(colCenter - textColSize, winStart);
    colorCout("██████████████████████████████████████████", 10);

    gotoxy(colCenter - textColSize, ++winStart);
    colorCout("█─███─█───█─██─█─██─█───█────███████─█─█─█", 10);

    gotoxy(colCenter - textColSize, ++winStart);
    colorCout("█─███─██─██──█─█──█─█─███─██─███████─█─█─█", 10);

    gotoxy(colCenter - textColSize, ++winStart);
    colorCout("█─█─█─██─██─█──█─█──█───█────███████─█─█─█", 10);

    gotoxy(colCenter - textColSize, ++winStart);
    colorCout("█─────██─██─██─█─██─█─███─█─██████████████", 10);

    gotoxy(colCenter - textColSize,++winStart);
    colorCout("██─█─██───█─██─█─██─█───█─█─████████─█─█─█", 10);

    gotoxy(colCenter - textColSize, ++winStart);
    colorCout("██████████████████████████████████████████", 10);
}

#endif
