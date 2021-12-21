#ifndef PREGAME_HPP
#define PREGAME_HPP

void addNumbers(int** Back, const size_t size);

void aroundMine(int** Back, const size_t size, const int i, const int j);

void boundsOfMatrix(int** Back, const size_t size);

void level(int const choosedLevel, size_t& size, size_t& bombCount, const int customSize, const int customBombCount);

void mainPreGame(const int customSize, const int customBombCount, const int choosedLevel, const bool GodModeOn, bool& exitFromGame, int& winRow, int& winCol);

void preGame(const int customSize, const int customBombCount, const int choosedLevel, const bool GodModeOn, int& winRow, int& winCol);

void randomMines(int** Back, const size_t size, size_t bombCount);

#endif //PREGAME_HPP
