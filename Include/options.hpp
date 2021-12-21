#ifndef OPTIONS_HPP
#define OPTIONS_HPP

void customMode(const std::string* custom, int& customSize, int& customBombCount, bool& exitFromOptions, int const optionsStartRow, int const optionsStartCol, bool& sizeChanged, int& winRow, int& winCol);

void options(int& customSize, int& customBombCount, int& choosedLevel, bool& GodModeOn, int& soundsVolume, int& musicVolume, int& winRow, int& winCol);

void printOptions(const std::string* options, const std::string* volume, const std::string* custom, const std::string* levelInfo, int const current, int const optionsSize, int const choosedLevel, bool const GodModeOn, int const soundsVolume, int const musicVolume, int const optionsStartRow, int const optionsStartCol, int const customSize, int const customBombCount);

#endif //OPTIONS_HPP
