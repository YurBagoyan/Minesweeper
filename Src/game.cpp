#include <ctime>
#include <iomanip>
#include <iostream>

#include "../Include/game.hpp"
#include "../Include/input.hpp"
#include "../Include/records.hpp"
#include "../Include/show.hpp"

///Main game
void game(int** Back, char** Front, int const size, int const level, int const bombCount, bool const GodModeOn, bool* exitToMenu, int* winRow, int* winCol)
{
    //Returns the current calendar time encoded as a std::time_t object
    std::time_t beginTime = std::time(nullptr);
    bool restart = false;
    int i = 1, j = 1, Fcount = 0;

    while (true) {
        bool returnToGame = false;

        if (*exitToMenu || restart) {
            break;
        }

        if (GodModeOn) {
            Show_GodMode(Back, size);
        }

        int const rowCenter = *winRow / 2 + 1;
        int const colCenter = *winCol / 2 + 1;
        int const matrixStartRow = rowCenter - 2 - size / 2;
        int const matrixStartCol = colCenter - size + 1;

        Show_Boards(size, matrixStartRow, matrixStartCol, 11);
        showNewFront(Front, size, rowCenter, colCenter, matrixStartRow, matrixStartCol);
        Show_ExitRestart(rowCenter, colCenter, 4);
        printGreenChar(Front, i, j, matrixStartRow, matrixStartCol);
        printBombCount(bombCount, Fcount, size, matrixStartRow, matrixStartCol);

        cbreak();
        while (true) {
            int const minWinRowSize = 30, minWinColSize = 82;
            if (winSizeChanged(winRow, winCol, minWinRowSize, minWinColSize) || returnToGame) {
                break;
            }

            int const time = Show_Timer(beginTime, size, matrixStartRow, matrixStartCol);
            //Checking the game status
            if (isWin(Front, size, bombCount)) {
                printBombCount(bombCount, bombCount, size, matrixStartRow, matrixStartCol);
                win(Back, Front, size, time, level, &restart, exitToMenu, GodModeOn, winRow, winCol);
            }

            int key = keypress();
            if (key == 'r' || key == 'R' || restart) {
                restart = true;
                break;
            }
            if (key == 27 || *exitToMenu) {
                *exitToMenu = true;
                break;
            }

            switch (key) {
            case 'w': case 'W':
                printChar(Front, i, j, matrixStartRow, matrixStartCol);
                i == 1 ? i = size - 2 : --i;
                printGreenChar(Front, i, j, matrixStartRow, matrixStartCol);
                break;

            case 's': case 'S':
                printChar(Front, i, j, matrixStartRow, matrixStartCol);
                i == size - 2 ? i = 1 : ++i;
                printGreenChar(Front, i, j, matrixStartRow, matrixStartCol);
                break;

            case 'a': case 'A':
                printChar(Front, i, j, matrixStartRow, matrixStartCol);
                j == 1 ? j = size - 2 : --j;
                printGreenChar(Front, i, j, matrixStartRow, matrixStartCol);
                break;

            case 'd': case 'D':
                printChar(Front, i, j, matrixStartRow, matrixStartCol);
                j == size - 2 ? j = 1 : ++j;
                printGreenChar(Front, i, j, matrixStartRow, matrixStartCol);
                break;

            case 'f': case 'F': //Flags 
                if (Front[i][j] == '#' && Fcount < bombCount) {
                    ++Fcount;
                    Front[i][j] = 'F';
                    printChar(Front, i, j, matrixStartRow, matrixStartCol);
                }
                else if (Front[i][j] == 'F') {
                    --Fcount;
                    Front[i][j] = '#';
                    printGreenChar(Front, i, j, matrixStartRow, matrixStartCol);
                }
                printBombCount(bombCount, Fcount, size, matrixStartRow, matrixStartCol);
                break;

            case 'p': case 'P':
                int pauseTime;
                pause(exitToMenu, &returnToGame, &pauseTime, winRow, winCol);
                beginTime += pauseTime;
                system("clear");
                break;

            case 10: //10 = Enter
                switch (Back[i][j]) {
                case -1: //There is mine under cage
                    if (Front[i][j] != 'F') {
                        Boom(Back, Front, size, exitToMenu, &restart, winRow, winCol);
                    }
                    break;

                case 0: //Empty cage
                    Empty(Back, Front, i, j, &Fcount, matrixStartRow, matrixStartCol);
                    printGreenChar(Front, i, j, matrixStartRow, matrixStartCol);
                    break;

                default: //There is a number under cage
                    if (Back[i][j] != 10 && Front[i][j] != 'F') {
                        if (Front[i][j] != '#') {
                            OpenAround(Back, Front, size, i, j, &Fcount, exitToMenu, &restart, matrixStartRow, matrixStartCol, winRow, winCol);
                        }
                        else {
                            Open(Back, Front, i, j, &Fcount, matrixStartRow, matrixStartCol);
                            //printGreenChar(Front, i, j, matrixStartRow, matrixStartCol);
                        }
                        break;
                    }
                    break;
                }
            }
        }
    }
}

/* Brief: To print a character in its specific color
 * Inputs: Front: [char]; i, j: integer
 * Pre: i < size; j < size; Front = { '#', 'X', 'F', ' ', '1' '2', '3', '4', '5', '6', '7', '8' }
 * Output: Front : [char]
 * Post: Front[i][j] with its specific color
 */
void printChar(char** Front, int const i, int const j, int const matrixStartRow, int const matrixStartCol)
{
    //The coordinate of F[i][j] in window
    gotoxy(matrixStartCol + j * 2, matrixStartRow + i);

    //Print new character in its specific color
    switch (Front[i][j]) {
    case 'X': colorCout("X", 5); break;  //Red
    case 'F': colorCout("►", 7); break;  //Yellow
    case ' ': std::cout << " ";  break;  //
    case '#': std::cout << "#";  break;  //White
    case '1': colorCout("1", 4); break;  //Cyan
    case '2': colorCout("2", 10); break; //Green
    case '3': colorCout("3", 5); break;  //Red
    case '4': colorCout("4", 2); break;  //Blue
    case '5': colorCout("5", 6); break;  //Pink
    case '6': colorCout("6", 1); break;  //Gray
    case '7': colorCout("7", 7); break;  //Yellow
    case '8': colorCout("8", 9); break;  //White  
    }
}

/* Brief: To print a character in green color, for cursor move
 * Inputs: Front: [char], i, j: integer
 * Pre: i < size, j < size; Front = { '#', 'X', 'F', ' ', '1' '2', '3', '4', '5', '6', '7', '8' }
 * Output: Front : [char]
 * Post: Front[i][j] with green color
 */
void printGreenChar(char** Front, int const i, int const j, int const matrixStartRow, int const matrixStartCol)
{
    //The coordinate of F[i][j] in window
    gotoxy(matrixStartCol + j*2, matrixStartRow + i);

    int cursorColor = 3; //3 = green
    switch(Front[i][j]) {
        case 'X': colorCout("X", cursorColor); break; 
        case 'F': colorCout("►", cursorColor); break; 
        case '#': colorCout("#", cursorColor); break;
        case ' ': colorCout("‒", cursorColor); break;
        case '1': colorCout("1", cursorColor); break;
        case '2': colorCout("2", cursorColor); break;
        case '3': colorCout("3", cursorColor); break;
        case '4': colorCout("4", cursorColor); break;
        case '5': colorCout("5", cursorColor); break;
        case '6': colorCout("6", cursorColor); break;
        case '7': colorCout("7", cursorColor); break;
        case '8': colorCout("8", cursorColor); break;
    }
}

void showNewFront(char** Front, int const size, int const rowCenter, int const colCenter, int const matrixStartRow, int const matrixStartCol)
{
    for (int i = 1; i < size - 1; ++i) {
        for (int j = 1; j < size - 1; ++j) {
            printChar(Front, i, j, matrixStartRow, matrixStartCol);
        }
    }
}

//Checking for a win
bool isWin(char** Front, int const size, int const bombCount)
{
    int tempFlagCount = 0, tempCloseCaseCount = 0;
    for(int i = 1; i < size - 1; ++i) {
        for(int j = 1; j < size - 1 ; ++j) {
            if(Front[i][j] == '#') {
                ++tempCloseCaseCount;
            }
            else if (Front[i][j] == 'F') {
                ++tempFlagCount;
            }
        }
    }
    
    if(tempCloseCaseCount + tempFlagCount == bombCount) {
        return true;
    }
    return false;
}

//Print after winning
void win(int** Back, char** Front, int const size, int const time, int const level, bool* restart, bool* exitToMenu, bool const GodModeOn, int* winRow, int* winCol)
{
    while(true) {
        if(*exitToMenu || *restart) {
            break;
        }

        int const rowCenter = *winRow / 2 + 1;
        int const colCenter = *winCol / 2 + 1; 
        int const matrixStartRow = rowCenter - 2 - size / 2; 
        int const matrixStartCol = colCenter - size + 1; 
        
        //Show inscription WINNER
        Show_Win(size, rowCenter, colCenter, matrixStartRow, matrixStartCol);
        
        //Show matrix in new position if window size is changed
        showNewFront(Front, size, rowCenter, colCenter, matrixStartRow, matrixStartCol);

        //Print all mines positions in green
        for(int i = 1; i < size-1; ++i) {
            for(int j = 1; j < size-1; ++j) {
                if(Back[i][j] == -1) {
                    Front[i][j] = 'X';
                    printGreenChar(Front, i, j, matrixStartRow, matrixStartCol);
                }    
            }
        }

        if (!GodModeOn && level != 11) {
            checkingTimeInTop(time, level, rowCenter, colCenter);
        }
   
        //Restart or Exit to main menu
        cbreak();
        while(true) {
            int const minWinRowSize = 28, minWinColSize = 82;      
            if(winSizeChanged(winRow, winCol, minWinRowSize, minWinColSize)) {
                break;
            }

            int key = keypress();
            if(key == 'r' || key == 'R') {
                *restart = true;
                break; 
            }
            if(key == 27) {
                *exitToMenu = true;
                break;
            }
        }
    }
}

//Game over, print all mines positions
void Boom(int** Back, char** Front, int const size, bool* exitToMenu, bool* restart, int* winRow, int* winCol)
{
    while (true) {
        if (*exitToMenu || *restart) {
            break;
        }

        int const rowCenter = *winRow / 2 + 1;
        int const colCenter = *winCol / 2 + 1;
        int const matrixStartRow = rowCenter - 2 - size / 2;
        int const matrixStartCol = colCenter - size + 1;

        //Show inscription Game Over
        Show_GameOver(size, rowCenter, colCenter, matrixStartRow, matrixStartCol);

        //Show matrix in new position if window size is changed
        showNewFront(Front, size, rowCenter, colCenter, matrixStartRow, matrixStartCol);

        //Show all mines in red because user lose
        for (int i = 1; i < size - 1; ++i) {
            for (int j = 1; j < size - 1; ++j) {
                if (Back[i][j] == -1) {
                    Front[i][j] = 'X';
                    printChar(Front, i, j, matrixStartRow, matrixStartCol);
                }
            }
        }

        cbreak();
        while (true) {
            int const minWinRowSize = 28, minWinColSize = 82;
            if (winSizeChanged(winRow, winCol, minWinRowSize, minWinColSize)) {
                break;
            }

            int key = keypress();
            if (key == 'r' || key == 'R') {
                *restart = true;
                break;
            }
            if (key == 27) {
                *exitToMenu = true;
                break;
            }
        }
    }
}

/* Brief: If there are no mines or numbers under #
 * Inputs: Back: [integer], Front : [char], i, j, Fcount: integer
 * Pre: i < size, j < size, Fcount < Bomb_Count, Back[i][j] = 0
 * Output: Back : [integer], Front : [char], Fcount : integer 
 * Post: Front[i][j] = '_', Back[i][j] = 10, 
 */
void Empty(int** Back, char** Front, int const i, int const j, int* Fcount, int const matrixStartRow, int const matrixStartCol)
{
    Front[i][j] = ' ';
    Back[i][j] = 10;
    printChar(Front, i, j, matrixStartRow, matrixStartCol);
    
    //Opening all around if under # is empty
    for(int row_i = i - 1; row_i <= i + 1; ++row_i) {
        for(int col_j = j - 1; col_j <= j + 1; ++col_j) {
            if(Front[row_i][col_j] == '#' || Front[row_i][col_j] == 'F') {
                if(Front[row_i][col_j] == 'F') {
                    //Flag count
                    --(*Fcount);
                }

                if(Back[row_i][col_j] == 0) {
                    Empty(Back, Front, row_i, col_j, Fcount, matrixStartRow, matrixStartCol);
                }
                else if(Back[row_i][col_j] < 9 && Back[row_i][col_j] != -2) {
                    Open(Back, Front, row_i, col_j, Fcount, matrixStartRow, matrixStartCol);
                }
            }
        }   
    }
}

//Open the number
void Open(int** Back, char** Front, int const i, int const j, int* Fcount, int const matrixStartRow, int const matrixStartCol)
{
    if (Front[i][j] == 'F') {
        --(*Fcount);
    }

    //In ASCII table symbol of the number = number + 48
    Front[i][j] = Back[i][j] + 48;
    printChar(Front, i, j, matrixStartRow, matrixStartCol);
}

void OpenAround(int** Back, char** Front, int const size, int const i, int const j, int* Fcount, bool* exitToMenu, bool* restart, int const matrixStartRow, int const matrixStartCol, int* winRow, int* winCol)
{
    int tempFlugs = 0;
    //checking
    for (int row_i = i - 1; row_i <= i + 1; ++row_i) {
        for (int col_j = j - 1; col_j <= j + 1; ++col_j) {
            if (Front[row_i][col_j] == 'F') {
                ++tempFlugs;
            }
        }
    }

    if (tempFlugs == Back[i][j]) {
        for (int row_i = i - 1; row_i <= i + 1; ++row_i) {
            for (int col_j = j - 1; col_j <= j + 1; ++col_j) {
                if (Front[row_i][col_j] == '#' && Front[row_i][col_j] != 'F') {
                    switch (Back[row_i][col_j]) {
                    case 0:
                        Empty(Back, Front, row_i, col_j, Fcount, matrixStartRow, matrixStartCol);
                        break;

                    case -1:
                        Boom(Back, Front, size, exitToMenu, restart, winRow, winCol);
                        break;

                    default:
                        if (Back[row_i][col_j] != 10)
                            Open(Back, Front, row_i, col_j, Fcount, matrixStartRow, matrixStartCol);
                        break;
                    }
                }
            }
        }
    }

    printGreenChar(Front, i, j, matrixStartRow, matrixStartCol);
}

void printBombCount(int const bombCount, int const Fcount, int const size, int const matrixStartRow, int const matrixStartCol)
{
    int const bombCountStartCol = matrixStartCol + 4 + 2 * size;
    int const bombCountStartRow = matrixStartRow + 4;

    gotoxy(bombCountStartCol, bombCountStartRow);
    colorCout("Mines count", 4);

    gotoxy(bombCountStartCol + 4, bombCountStartRow + 1);
    std::cout << std::setw(2) << bombCount - Fcount << std::endl;
}

void pause(bool* exitToMenu, bool* returnToGame, int* pauseTime, int* winRow, int* winCol)
{
    std::time_t pauseStart = std::time(nullptr);
       while(true) {
        if(*exitToMenu || *returnToGame) {
            break;
        }

        system("clear");
        int const rowCenter = *winRow / 2 + 1;
        int const colCenter = *winCol / 2 + 1;
        Show_Pause(rowCenter, colCenter);
       
        cbreak();
        while(true) {
            int const minWinRowSize = 30, minWinColSize = 82; 
            if(winSizeChanged(winRow, winCol, minWinRowSize, minWinColSize)) {
                break;
            }

            int key = keypress();
            if(key == 'p' || key == 'P') { 
                std::time_t currentTime = std::time(nullptr);
                *pauseTime = currentTime - pauseStart;
                *returnToGame = true;
                break;
            }
            else if(key == 27) { 
                *exitToMenu = true;
                break;
            }
        }
    }
}
