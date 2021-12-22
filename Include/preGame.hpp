#ifndef PREGAME_HPP
#define PREGAME_HPP

void addOneInCellsAround(int** Back, const size_t size, const int i, const int j);

void fillRandomMines(int** Back, const size_t size, size_t bombCount);

void fillBoundsOfMatrix(int** Back, const size_t size);

void fillNumbersAroundMines(int** Back, const size_t size);

void gamePreparation(const int customSize, const int customBombCount, const int choosedLevel, const bool GodModeOn, bool& exitFromGame, int& winRow, int& winCol);

void level(const int choosedLevel, size_t& size, size_t& bombCount, const int customSize, const int customBombCount);

void preGame(const int customSize, const int customBombCount, const int choosedLevel, const bool GodModeOn, int& winRow, int& winCol);

#endif //PREGAME_HPP
