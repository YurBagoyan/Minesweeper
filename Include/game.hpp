#ifndef GAME_HPP
#define GAME_HPP

/* Brief: User opened cell with mine, GAME OVER
 * Pre: Back[i][j] = -1 //Mine
 * Post: Exit to main menu or restart game
 */
void Boom(const int* const* Back, char** Front, const size_t size, bool& exitToMenu, bool& restart, int& winRow, int& winCol);

/* Brief: If there are no mines or numbers under # 
 * Inputs: Back: [integer], Front : [char], i, j, Fcount: integer
 * Pre: i < size, j < size, Fcount < Bomb_Count, Back[i][j] = 0
 * Output: Back : [integer], Front : [char], Fcount : integer
 * Post: Front[i][j] = '_', Back[i][j] = 10,
 */
void Empty(int** Back, char** Front, const int i, const int j, int& Fcount, const int matrixStartRow, const int matrixStartCol);

// Brief: Main game
void game(int** Back, char** Front, const size_t size, const int level, const size_t bombCount, const bool GodModeOn, bool& exitToMenu, int& winRow, int& winCol);

/* Brief: Checking are there closed cells or no
 * Output: ture or false
 */
bool isWin(const char* const* Front, const size_t size, const size_t bombCount);

/* Brief: Open Front[i][j]
 * Pre: 1 <= Back[i][j] <= 8; Front[i][j] = '#'
 * Post: 1 <= Front[i][j] <= 8
 */
void Open(const int* const* Back, char** Front, const int i, const int j, int& Fcount, const int matrixStartRow, const int matrixStartCol);

/* Brief: 
 * Inputs:
 * Pre:
 * Output:
 * Post:
 */
void OpenAround(int** Back, char** Front, const size_t size, const int i, const int j, int& Fcount, bool& exitToMenu, bool& restart, const int matrixStartRow, const int matrixStartCol, int& winRow, int& winCol);

/* Brief: Will pause the game
 * Pre: pressed key is 'p' or 'P'
 */
void pause(bool& exitToMenu, bool& returnToGame, int& pauseTime, int& winRow, int& winCol);

/* Brief: To print a character in its specific color
 * Inputs: Front: [char]; i, j: integer
 * Pre: i < size; j < size; Front = { '#', 'X', 'F', ' ', '1' '2', '3', '4', '5', '6', '7', '8' }
 * Output: Front : [char]
 * Post: Front[i][j] with its specific color
 */
void printChar(const char* const* Front, const int i, const int j, const int matrixStartRow, const int matrixStartCol);

// Brief: Print count of bombs
void printBombCount(const size_t bombCount, const int Fcount, const size_t size, const int matrixStartRow, const int matrixStartCol);

/* Brief: To print a character in green color, for cursor move
 * Inputs: Front: [char], i, j: integer
 * Pre: i < size, j < size; Front = { '#', 'X', 'F', ' ', '1' '2', '3', '4', '5', '6', '7', '8' }
 * Output: Front : [char]
 * Post: Front[i][j] with green color
 */
void printGreenChar(const char* const* Front, const int i, const int j, const int matrixStartRow, const int matrixStartCol);

//Brief: Print new game field in a new position, because the window size was change
void showNewFront(const char* const* Front, const size_t size, const int rowCenter, const int colCenter, const int matrixStartRow, const int matrixStartCol);

// Brief: If there are no closed cells its means that the user is win
void win(const int* const* Back, char** Front, const size_t size, const int time, const int level, bool& restart, bool& exitToMenu, const bool GodModeOn, int& winRow, int& winCol);

#endif //GAME_HPP
