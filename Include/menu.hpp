#ifndef MENU_HPP
#define MENU_HPP

void Menu_choose(int& current, int& customSize, int& customBombCount, int& choosedLevel, bool& GodModeOn, int& soudnsVolume, int& musicVolume, int& winRow, int& winCol);

void printMenu(const std::string* Menu, const int menuSize, const int current, const int menuStartRow, const int menuStartCol);

void selectedMenu(const int current, int& customSize, int& customBombCount, int& choosedLevel, bool& GodModeOn, int& soundsVolume, int& musicVolume, int& winRow, int& winCol);

#endif //MENU_HPP
