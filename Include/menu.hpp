#ifndef MENU_HPP
#define MENU_HPP

void Menu_choose(int& current, int& customSize, int& customBombCount, int& choosedLevel, bool& GodModeOn, int& soudnsVolume, int& musicVolume, int& winRow, int& winCol);

void printMenu(std::string* Menu, int const menuSize, int const current, int const menuStartRow, int const menuStartCol);

void selectedMenu(int const current, int& customSize, int& customBombCount, int& choosedLevel, bool& GodModeOn, int& soundsVolume, int& musicVolume, int& winRow, int& winCol);

#endif //MENU_HPP
