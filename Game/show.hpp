#ifndef SHOW_HPP
#define SHOW_HPP

#include <ctime>

void Show_About(int* winRow, int* winCol);

void Show_Beginner(int const rowCenter, int const colCenter);

void Show_Boards(int const size, int const matrixStartRow, int const matrixStartCol, int const color);

void Show_Control(int const showControlRowStart, int const showControlColStart);

void Show_ExitRestart(int const rowCenter, int const colCenter, int const color);

void Show_Expert(int const rowCenter, int const colCenter);

void Show_GameName(int const printCol, int const printRow);

void Show_GameNameAnimation(int const rowCenter, int const colCenter);

void Show_GameOver(int const size, int const rowCenter, int const colCenter, int const matrixStartRow, int const matrixStartCol);

void Show_GodMode(int** Back, int const size);

void Show_levelName(int const level, int const rowCenter, int const colCenter);

void Show_Master(int const rowCenter, int const colCenter);

void Show_Pause(int const rowCenter, int const colCenter);

void Show_Pro(int const rowCenter, int const colCenter);

int  Show_Timer(std::time_t beginTime, int const size, int const matrixStartRow, int const matrixStartCol);

void Show_Veteran(int const rowCenter, int const colCenter);

void Show_Win(int const size, int const rowCenter, int const colCenter, int const matrixStartRow, int const matrixStartCol);

#endif //SHOW_HPP
