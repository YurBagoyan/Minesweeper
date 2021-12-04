#include <fstream>
#include <iomanip>
#include <iostream>

#include "../Headers/records.hpp"
#include "../Headers/input.hpp"
#include "../Headers/show.hpp"

void records(int* winRow, int* winCol)
{
    int level = 1;
    bool exitToMenu = false;
    while (true) {
        if (exitToMenu) {
            break;
        }

        int const rowCenter = *winRow / 2 + 1;
        int const colCenter = *winCol / 2 + 1;
        int const recStartRow = rowCenter, recStartCol = colCenter;

        printRecords(level, recStartRow, recStartCol, rowCenter, colCenter);

        cbreak();
        while (true) {
            int const minWinRowSize = 30, minWinColSize = 82;
            if (winSizeChanged(winRow, winCol, minWinRowSize, minWinColSize)) {
                break;
            }

            int key = keypress();
            if (key == 27) {
                exitToMenu = true;
                break;
            }

            switch (key) {
            case 'a': case 'A':
                level == 1 ? level = 5 : --level;
                printRecords(level, recStartRow, recStartCol, rowCenter, colCenter);
                break;

            case 'd': case 'D':
                level == 5 ? level = 1 : ++level;
                printRecords(level, recStartRow, recStartCol, rowCenter, colCenter);
                break;
            }
        }
    }
}

void printRecords(int const level, int const recStartRow, int const recStartCol, int const rowCenter, int const colCenter)
{
    system("clear");
    gotoxy(colCenter - 21, rowCenter * 2 - 4);
    colorCout("Press 'A' or 'D' to see the other level records", 7);

    gotoxy(colCenter - 16, rowCenter * 2 - 2);
    colorCout("Press Esc to return to MAIN MENU", 7);

    Show_levelName(level, rowCenter, colCenter);

    std::string topNickNames[7] = { "" };
    int topTimes[7] = { 0 };
    InputFromFile(topNickNames, topTimes, level);

    printTop(topNickNames, topTimes, rowCenter, colCenter);
}

std::string fileWay(int const level)
{
    std::string way;

    switch(level) {
        case 1: way = "Records/beginners.txt"; break;
        case 2: way = "Records/veterans.txt"; break;
        case 3: way = "Records/experts.txt"; break;
        case 4: way = "Records/pros.txt"; break;
        case 5: way = "Records/masters.txt"; break;
    }

    return way;
}

void InputFromFile(std::string* topNickNames, int* topTimes, int const level)
{
    std::string way = fileWay(level);

    std::ifstream readFromFile;
    readFromFile.open(way);

    if(!readFromFile.is_open()) {
        std::cout << "File ERROR\n";
        return;
    }
    
    std::string temp;
    for(int i = 1; !readFromFile.eof(); ++i) {
        if(i <= 5) {
            std::getline(readFromFile, topNickNames[i]);  
        }
        else if (i <= 10){
            std::getline(readFromFile, temp);
            topTimes[i - 5] = std::stoi(temp);
        }
        else {
            std::getline(readFromFile, temp);
        }
    }

    readFromFile.close();
}

void printTop(std::string* topNickNames, int* topTimes, int const rowCenter, int const colCenter)
{
    int const nicksStartRow = rowCenter - 2;
    int const nicksStartCol = colCenter - 15;

    int const timeStartRow = nicksStartRow;
    int const timeStartCol = nicksStartCol + 15;

    for (int i = 1; i < 6; ++i) {
        gotoxy(nicksStartCol, nicksStartRow + i - 1);
        std::cout << i << ". " << topNickNames[i] << std::endl;

        if (topTimes[i] != 1000000) {
            printTime(topTimes[i], timeStartRow + i - 1, timeStartCol);
        }
    }
}

void printTime(int const time, int const timeStartRow, int const timeStartCol)
{
    int const hours = time / 3600;
    int const min = (time % 3600) / 60;
    int const sec = (time % 3600) % 60;

    gotoxy(timeStartCol, timeStartRow);
    std::cout << std::setw(2) << hours << " : " << std::setw(2) << min << " : " << std::setw(2) << sec << "\n";
}

void checkingTimeInTop(int const time, int const level, int const rowCenter, int const colCenter)
{
    std::string topNickNames[7] = { "" };
    int topTimes[7] = { 0 };
    InputFromFile(topNickNames, topTimes, level);

    if (time < topTimes[5]) {
        newRecord(topNickNames, topTimes, time, level, rowCenter, colCenter);
    }
}

void newRecord(std::string* topNickNames, int* topTimes, int const time, int const level, int const rowCenter, int const colCenter)
{
    std::string userNickName = inputUserNickName(rowCenter, colCenter);

    int i = 5;
    while(time < topTimes[i] && i >= 1) {
        topTimes[i + 1] = topTimes[i];
        topTimes[i] = time;

        topNickNames[i + 1] = topNickNames[i];
        topNickNames[i] = userNickName;

        --i;
    }

    outputFile(topNickNames, topTimes, level);
}

std::string inputUserNickName(int const rowCenter, int const colCenter)
{
    std::string userNickName;

    do {
        gotoxy(colCenter - 30, rowCenter * 2 - 12);
        colorCout("Please enter your nickname which must be 10 characters long: ", 7);
        normal();
        gotoxy(colCenter + 31, rowCenter * 2 - 12);
        getline(std::cin, userNickName);
        gotoxy(colCenter - 30, rowCenter * 2 - 12);
        std::cout << "                                                                                  \n";
    } while (userNickName.length() > 10);

    return userNickName;
}

void outputFile(std::string* topNickNames, int* topTimes, int const level)
{
    std::string way = fileWay(level);

    std::ofstream writeInFile;
    writeInFile.open(way);

    if (!writeInFile.is_open()) {
        std::cout << "File ERROR\n";
        return;
    }

    for (int i = 1; i <= 10; ++i) {
        if (i <= 5) {
            writeInFile << topNickNames[i] << "\n";
        }
        else {
            writeInFile << topTimes[i - 5] << "\n";
        }
    }

    writeInFile.close();
}
