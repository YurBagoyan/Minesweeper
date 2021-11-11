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

void Show_About(int const rowCenter, int const colCenter)
{
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

    aboutStart += 3;
    gotoxy(colCenter - 6, aboutStart);
    colorCout("Game Contol", 4);

    aboutStart += 2;
    gotoxy(colCenter - 39, aboutStart);
    std::cout << "[W] - Up   [S] - Down   [A] - Left   [D] - Right   [Enter] - Open   [F] - Flag";

    gotoxy(colCenter - 16, rowCenter*2 - 3);
    colorCout("Press Esc to retun to MAIN MENU", 7);
    
    cbreak();
    for(int key = -1; ; )
    {
        key = keypress(); 

        if(key == 27)
        {
            break;
        }
    }   
}

void Show_GameOver(int const rowCenter, int const colCenter)
{
    gotoxy(colCenter - 9, rowCenter*2 - 5);
    colorCout("Press R to ", 7);
    
    gotoxy(colCenter + 2, rowCenter*2 - 5);
    colorCout("RESTART", 5); 

    gotoxy(colCenter - 16, rowCenter*2 - 4);
    colorCout("Press Esc to return to ", 7); 

    gotoxy(colCenter + 8, rowCenter*2 - 4);
    colorCout("MAIN MENU", 5);
    
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

void Show_Win(int const rowCenter, int const colCenter)
{   
    gotoxy(colCenter - 9, rowCenter*2 - 5);
    colorCout("Press R to ", 7);

    gotoxy(colCenter + 2, rowCenter*2 - 5);
    colorCout("RESTART", 3); 
    
    gotoxy(colCenter - 16, rowCenter*2 - 4);
    colorCout("Press Esc to return to ", 7); 
    
    gotoxy(colCenter + 8, rowCenter*2 - 4);
    colorCout("MAIN MENU", 3);
    
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
