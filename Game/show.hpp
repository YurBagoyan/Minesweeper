#ifndef SHOW
#define SHOW

#include <iostream>

#include "input.hpp"


void Show_GameName()    //Print Game Name
{ 
    system("clear");

    std::cout   << "\x1b[31;1m" << "\t      _____ ______   ___  ________   _______   ________  ___       __   _______   _______   ________  _______   ________     " << "\x1b[0m\n"
                    << "\x1b[31;1m" << "\t     |\\   _ \\  _   \\|\\  \\|\\   ___  \\|\\  ___ \\ |\\   ____\\|\\  \\     |\\  \\|\\  ___ \\ |\\  ___ \\ |\\   __  \\|\\  ___ \\ |\\   __  \\    " << "\x1b[0m\n"
                    << "\x1b[31;1m" << "\t     \\ \\  \\\\\\__\\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\   __/ \\ \\  \\___|\\ \\  \\    \\ \\  \\ \\   __/ \\ \\   __/ \\ \\  \\|\\  \\ \\   __/ \\ \\  \\|\\  \\   " << "\x1b[0m\n"
                    << "\x1b[31;1m" << "\t      \\ \\  \\\\|__| \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\_|  \\ \\_____  \\ \\  \\  __\\ \\  \\ \\  \\_|  \\ \\  \\_|  \\ \\   ____\\ \\  \\_|  \\ \\   _  _\\  " << "\x1b[0m\n"
                    << "\x1b[31;1m" << "\t       \\ \\  \\    \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\_|\\ \\|____|\\  \\ \\  \\|\\__\\_\\  \\ \\  \\_|\\ \\ \\  \\_|\\ \\ \\  \\___|\\ \\  \\_|\\ \\ \\  \\\\  \\| " << "\x1b[0m\n"
                    << "\x1b[31;1m" << "\t        \\ \\__\\    \\ \\__\\ \\__\\ \\__\\\\ \\__\\ \\_______\\____\\_\\  \\ \\____________\\ \\_______\\ \\_______\\ \\__\\    \\ \\_______\\ \\__\\\\ _\\ " << "\x1b[0m\n"
                    << "\x1b[31;1m" << "\t         \\|__|     \\|__|\\|__|\\|__| \\|__|\\|_______|\\_________\\|____________|\\|_______|\\|_______|\\|__|     \\|_______|\\|__|\\|__|" << "\x1b[0m\n"
                    << "\x1b[31;1m" << "\t                                                 \\|_________|                                                                " << "\x1b[0m\n";

    
}


void Show_About()
{
    system("clear");

    gotoxy(66, 5);
    colorCout("About Minesweeper", 4);

    gotoxy(0, 7); 
    std::cout <<    "\t\t\t\t   Minesweeper is a single-player puzzle video game. The objective of the game\n" << 
                    "\t\t\t\t  is to clear a rectangular board containing hidden ""mines"" or bombs without\n" << 
                    "\t\t\t\t  detonating any of them, with help from clues about the number of neighboring\n" << 
                    "\t\t\t\t  mines in each field. The game originates from the 1960s, and it has been\n" << 
                    "\t\t\t\t  written for many computing platforms in use today. It has many variations and\n" << 
                    "\t\t\t\t  offshoots.";

    gotoxy(69, 15);
    colorCout("Gameplay", 4);
    
    gotoxy(0, 17);
    std::cout <<    "\t\t\t\t   In Minesweeper, mines (that resemble naval mines in the classic theme) are\n" << 
                    "\t\t\t\t  scattered throughout a board, which is divided into cells. Cells have three\n" << 
                    "\t\t\t\t  states: uncovered, covered and flagged. A covered cell is blank and clickable,\n" << 
                    "\t\t\t\t  while an uncovered cell is exposed. Flagged cells are those marked by the\n" << 
                    "\t\t\t\t  player to indicate a potential mine location. \n\n" <<
        
                    "\t\t\t\t   A player should press or a cell to uncover it. If a player uncovers a mined\n " << 
                    "\t\t\t\t  cell, the game ends, as there is only 1 life per game. Otherwise, the\n " << 
                    "\t\t\t\t  uncovered cells displays either a number, indicating the number of mines\n" << 
                    "\t\t\t\t  diagonally and/or adjacent to it, or a blank tile (or ""0""), and all \n" << 
                    "\t\t\t\t  tadjacent non-mined cells will automatically be uncovered. button on a cell\n" << 
                    "\t\t\t\t  will flag it, causing a flag to appear on it. Flagged cells are still\n " << 
                    "\t\t\t\t  tconsidered covered, and a player can prees on them to uncover them. \n\n" <<

                    "\t\t\t\t   To win the game, players must uncover all non-mine cells, at which point,\n" << 
                    "\t\t\t\t  the timer is stopped. Flagging all the mined cells is not required.";

    gotoxy(58,37);
    colorCout("Press Esc to retun to main menu", 7);
    
    for(int key = -1; ; )
    {
        cbreak();
        key = keypress(); 

        if(key == 27)
        {
            system("clear");
            break;
        }
    }   
}

void showGameOver(int const matrix_start_col, int const matrix_start_row, int const size)
{
    gotoxy(matrix_start_col + 1, matrix_start_row + size + 2);
    colorCout("Press R to ", 7);
    gotoxy(matrix_start_col + 12, matrix_start_row + size + 2);
    colorCout("RESTART", 5); 
    gotoxy(matrix_start_col + 1, matrix_start_row + size + 3); 
    colorCout("Press Esc to return to ", 7); 
    gotoxy(matrix_start_col + 24, matrix_start_row + size + 3);
    colorCout("MAIN MENU", 5);
    
    gotoxy(matrix_start_col - 6, matrix_start_row - 9);
    colorCout("██████████████████████████████████████████", 5);
    gotoxy(matrix_start_col - 6, matrix_start_row - 8);
    colorCout("█────█────█─███─█───████────█─█─█───█────█", 5);
    gotoxy(matrix_start_col - 6, matrix_start_row - 7);
    colorCout("█─████─██─█──█──█─██████─██─█─█─█─███─██─█", 5);
    gotoxy(matrix_start_col - 6, matrix_start_row - 6);
    colorCout("█─█──█────█─█─█─█───████─██─█─█─█───█────█", 5);
    gotoxy(matrix_start_col - 6, matrix_start_row - 5);
    colorCout("█─██─█─██─█─███─█─██████─██─█───█─███─█─██", 5);
    gotoxy(matrix_start_col - 6, matrix_start_row - 4);
    colorCout("█────█─██─█─███─█───████────██─██───█─█─██", 5);
    gotoxy(matrix_start_col - 6, matrix_start_row - 3);
    colorCout("██████████████████████████████████████████", 5);

}

void showWin(int const matrix_start_col, int const matrix_start_row, int const size)
{    
    gotoxy(matrix_start_col + 1, matrix_start_row + size + 2);
    colorCout("Press R to ", 7);
    gotoxy(matrix_start_col + 12, matrix_start_row + size + 2);
    colorCout("RESTART", 3); 
    gotoxy(matrix_start_col + 1, matrix_start_row + size + 3); 
    colorCout("Press Esc to return to ", 7); 
    gotoxy(matrix_start_col + 24, matrix_start_row + size + 3);
    colorCout("MAIN MENU", 3);

    gotoxy(matrix_start_col - 6, matrix_start_row - 9);
    colorCout("██████████████████████████████████████████", 10);
    gotoxy(matrix_start_col - 6, matrix_start_row - 8);
    colorCout("█─███─█───█─██─█─██─█───█────███████─█─█─█", 10);
    gotoxy(matrix_start_col - 6, matrix_start_row - 7);
    colorCout("█─███─██─██──█─█──█─█─███─██─███████─█─█─█", 10);
    gotoxy(matrix_start_col - 6, matrix_start_row - 6);
    colorCout("█─█─█─██─██─█──█─█──█───█────███████─█─█─█", 10);
    gotoxy(matrix_start_col - 6, matrix_start_row - 5);
    colorCout("█─────██─██─██─█─██─█─███─█─██████████████", 10);
    gotoxy(matrix_start_col - 6, matrix_start_row - 4);
    colorCout("██─█─██───█─██─█─██─█───█─█─████████─█─█─█", 10);
    gotoxy(matrix_start_col - 6, matrix_start_row - 3);
    colorCout("██████████████████████████████████████████", 10);


}



#endif
