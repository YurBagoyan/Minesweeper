#ifndef MENU_HPP
#define MENU_HPP

void CursorMoveInMenu(const std::string* Menu, const size_t menuSize, int& current, const int key, const int menuStartCol, const int menuStartRow);

void Menu_choose(int& current, int& customSize, int& customBombCount, int& choosedLevel, bool& GodModeOn, int& soudnsVolume, int& musicVolume, int& winRow, int& winCol);

void printMenu(const std::string* Menu, const size_t menuSize, const int current, const int menuStartRow, const int menuStartCol);

void selectedMenu(const int current, int& customSize, int& customBombCount, int& choosedLevel, bool& GodModeOn, int& soundsVolume, int& musicVolume, int& winRow, int& winCol);

#endif //MENU_HPP
