#ifndef RECORDS_HPP
#define RECORDS_HPP

void checkingTimeInTop(int const time, int const level, bool* exitToMenu, int const rowCenter, int const colCenter);

std::string fileWay(int const level);

void InputFromFile(std::string* topNickNames, int* topTimes, int const level);

std::string inputUserNickName(int const rowCenter, int const colCenter);

void newRecord(std::string* topNickNames, int* topTimes, int const time, int const level, int const rowCenter, int const colCenter);

void outputFile(std::string* topNickNames, int* topTimes, int const level);

void printRecords(int const level, int const recStartRow, int const recStartCol, int const rowCenter, int const colCenter);

void printTime(int const time, int const timeStartRow, int const timeStartCol);

void printTop(std::string* topNickNames, int* topTimes, int const rowCenter, int const colCenter);

void records(int* winRow, int* winCol);

#endif //RECORDS_HPP
