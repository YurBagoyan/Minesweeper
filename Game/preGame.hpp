#ifndef PREGAME_HPP
#define PREGAME_HPP

void addNumbers(int** Back, int const size);

void aroundMine(int** Back, int const size, int const i, int const j);

void boundsOfMatrix(int** Back, char** Front, int const size);

void level(int const choosedLevel, int* size, int* bombCount, int const customSize, int const customBombCount);

void mainPreGame(int const customSize, int const customBombCount, int const choosedLevel, bool const GodModeOn, bool* exitFromGame, int* winRow, int* winCol);

void preGame(int const customSize, int const customBombCount, int const choosedLevel, bool const GodModeOn, int* winRow, int* winCol);

void randomMines(int** Back, int const size, int bombCount);

#endif //PREGAME_HPP
