#ifndef PREGAME_HPP
#define PREGAME_HPP

/* Brief: +1 in the cells around Back[i][j]
 * Inputs: Back: [integer]; i, j: integer
 * Pre: Back[i][j] = -1 //Mine
 * Output: Back: [integer]; i, j: integer
 * Post: 
 */
void addOneInCellsAround(int** Back, const size_t size, const int i, const int j);

/* Brief: Fill the matrix with mines
 * Inputs: Back: [integer]; size, bombCount: integer
 * Pre: Back[i][j] = 0
 * Output: Back: [integer]
 * Post: if Back[i][j] = -1 => that's mine
 */
void fillRandomMines(int** Back, const size_t size, size_t bombCount);

/* Brief: Bounds of matrix will initialized -2
 * Inputs: Back: [integer]; size: integer
 * Output: Back: [integer]; size: 
 */
void fillBoundsOfMatrix(int** Back, const size_t size);

/* Brief: +1 in the cells around all mines
 * Inputs: Back: [integer]; size: integer
 * Output: Back: [integer]; size: integer;
 * Post: -1 <= Back[i][j] <= 8
 */
void fillNumbersAroundMines(int** Back, const size_t size);

// Brief: Create matixes
void gamePreparation(const int customSize, const int customBombCount, const int choosedLevel, const bool GodModeOn, bool& exitFromGame, int& winRow, int& winCol);

/* Brief: Selection size of the matrix and bomb count depending on the choice of level from user
 * Inputs: choosedLevel: integer
 * Pre: 1 <= choosedLevel <= 5
 * Output: size, bombCount: integer
 * Post: size <= 18, bombCount <= 99
 */
void level(const int choosedLevel, size_t& size, size_t& bombCount, const int customSize, const int customBombCount);

// Brief: Preparation for the game
void preGame(const int customSize, const int customBombCount, const int choosedLevel, const bool GodModeOn, int& winRow, int& winCol);

#endif //PREGAME_HPP
