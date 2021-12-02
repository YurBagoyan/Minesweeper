#ifndef GAME_HPP
#define GAME_HPP

void Boom(int** Back, char** Front, int const size, bool* exitToMenu, bool* restart, int* winRow, int* winCol);

void Empty(int** Back, char** Front, int const i, int const j, int* Fcount, int const matrixStartRow, int const matrixStartCol);

void game(int** Back, char** Front, int const size, int const level, int const bombCount, bool const GodModeOn, bool* exitToMenu, int* winRow, int* winCol);

bool isWin(char** Front, int const size, int const bombCount);

void Open(int** Back, char** Front, int const i, int const j, int* Fcount, int const matrixStartRow, int const matrixStartCol);

void OpenAround(int** Back, char** Front, int const size, int const i, int const j, int* Fcount, bool* exitToMenu, bool* restart, int const matrixStartRow, int const matrixStartCol, int* winRow, int* winCol);

void pause(bool* exitToMenu, bool* returnToGame, int* pauseTime, int* winRow, int* winCol);

void printChar(char** Front, int const i, int const j, int const matrixStartRow, int const matrixStartCol);

void printBombCount(int const bombCount, int const Fcount, int const size, int const matrixStartRow, int const matrixStartCol);

void printGreenChar(char** Front, int const i, int const j, int const matrixStartRow, int const matrixStartCol);

void showNewFront(char** Front, int const size, int const rowCenter, int const colCenter, int const matrixStartRow, int const matrixStartCol);

void win(int** Back, char** Front, int const size, int const time, int const level, bool* restart, bool* exitToMenu, bool const GodModeOn, int* winRow, int* winCol);

#endif //GAME_HPP
