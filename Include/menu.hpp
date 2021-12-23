#ifndef MENU_HPP
#define MENU_HPP

/* Brief : Moves the cursor
 * Inputs: current: integer
 * Pre : current < size of menu
 * Output: current: integer, new cursor place
 * Post : current < size of menu
 */
void CursorMoveInMenu(const std::string* Menu, const size_t menuSize, int& current, const int key, const int menuStartCol, const int menuStartRow);

//Brief: Main Menu
void Menu_choose(int& current, int& customSize, int& customBombCount, int& choosedLevel, bool& GodModeOn, int& soudnsVolume, int& musicVolume, int& winRow, int& winCol);

// Brief: Print all menu objects 
void printMenu(const std::string* Menu, const size_t menuSize, const int current, const int menuStartRow, const int menuStartCol);

// Brief: Launches the choosed menu option
void selectedMenu(const int current, int& customSize, int& customBombCount, int& choosedLevel, bool& GodModeOn, int& soundsVolume, int& musicVolume, int& winRow, int& winCol);

#endif //MENU_HPP
