#ifndef OPTIONS_HPP
#define OPTIONS_HPP

void cursorMoveInCustom(const std::string* custom, const int key, int& current, const int customStartRow, const int customStartCol);

void cursorMoveInOptions(const std::string* options, const std::string* levelInfo, const int key, int& current, const int choosedLevel, const int optionsSize, const int optionsStartRow, const int optionsStartCol);

void customMode(const std::string* custom, int& customSize, int& customBombCount, bool& exitFromOptions, const int optionsStartRow, const int optionsStartCol, bool& sizeChanged, int& winRow, int& winCol);

void options(int& customSize, int& customBombCount, int& choosedLevel, bool& GodModeOn, int& soundsVolume, int& musicVolume, int& winRow, int& winCol);

void pressedGodMode(bool& GodModeOn, int& current, const int optionsStartRow, const int optionsStartCol);

void printOptions(const std::string* options, const std::string* volume, const std::string* custom, const std::string* levelInfo, const int current, const int optionsSize, const int choosedLevel, const bool GodModeOn, const int soundsVolume, const int musicVolume, const int optionsStartRow, const int optionsStartCol, const int customSize, const int customBombCount);

#endif //OPTIONS_HPP
