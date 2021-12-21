#ifndef RECORDS_HPP
#define RECORDS_HPP

void checkingTimeInTop(const int time, const int level, bool& exitToMenu, const int rowCenter, const int colCenter);

std::string fileWay(const int level);

void InputFromFile(std::string* topNickNames, int* topTimes, const int level);

std::string inputUserNickName(const int rowCenter, const int colCenter);

void newRecord(std::string* topNickNames, int* topTimes, const int time, const int level, const int rowCenter, const int colCenter);

void outputFile(std::string* topNickNames, int* topTimes, const int level);

void printRecords(const int level, const int recStartRow, const int recStartCol, const int rowCenter, const int colCenter);

void printTime(const int time, const int timeStartRow, const int timeStartCol);

void printTop(std::string* topNickNames, int* topTimes, const int rowCenter, const int colCenter);

void records(int& winRow, int& winCol);

#endif //RECORDS_HPP
