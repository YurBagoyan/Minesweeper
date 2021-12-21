#ifndef GAME_HPP
#define GAME_HPP

void Boom(const int* const* Back, char** Front, const size_t size, bool& exitToMenu, bool& restart, int& winRow, int& winCol);

void Empty(int** Back, char** Front, const int i, const int j, int& Fcount, const int matrixStartRow, const int matrixStartCol);

void game(int** Back, char** Front, const size_t size, const int level, const size_t bombCount, const bool GodModeOn, bool& exitToMenu, int& winRow, int& winCol);

bool isWin(const char* const* Front, const size_t size, const size_t bombCount);

void Open(const int* const* Back, char** Front, const int i, const int j, int& Fcount, const int matrixStartRow, const int matrixStartCol);

void OpenAround(int** Back, char** Front, const size_t size, const int i, const int j, int& Fcount, bool& exitToMenu, bool& restart, const int matrixStartRow, const int matrixStartCol, int& winRow, int& winCol);

void pause(bool& exitToMenu, bool& returnToGame, int& pauseTime, int& winRow, int& winCol);

void printChar(const char* const* Front, const int i, const int j, const int matrixStartRow, const int matrixStartCol);

void printBombCount(const size_t bombCount, const int Fcount, const size_t size, const int matrixStartRow, const int matrixStartCol);

void printGreenChar(const char* const* Front, const int i, const int j, const int matrixStartRow, const int matrixStartCol);

void showNewFront(const char* const* Front, const size_t size, const int rowCenter, const int colCenter, const int matrixStartRow, const int matrixStartCol);

void win(const int* const* Back, char** Front, const size_t size, const int time, const int level, bool& restart, bool& exitToMenu, const bool GodModeOn, int& winRow, int& winCol);

#endif //GAME_HPP
