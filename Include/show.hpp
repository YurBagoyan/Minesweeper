#ifndef SHOW_HPP
#define SHOW_HPP

#include <ctime>

void Show_About(int& winRow, int& winCol);

void Show_Beginner(const int rowCenter, const int colCenter);

void Show_Boards(const size_t size, const int matrixStartRow, const int matrixStartCol, const int color);

void Show_Control(const int showControlRowStart, const int showControlColStart);

void Show_ExitRestart(const int rowCenter, const int colCenter, const int color);

void Show_Expert(const int rowCenter, const int colCenter);

void Show_GameName(const int printCol, const int printRow);

void Show_GameNameAnimation(const int rowCenter, const int colCenter);

void Show_GameOver(const size_t size, const int rowCenter, const int colCenter, const int matrixStartRow, const int matrixStartCol);

void Show_GodMode(const int* const* Back, const size_t size);

void Show_levelName(const int level, const int rowCenter, const int colCenter);

void Show_Master(const int rowCenter, const int colCenter);

void Show_Pause(const int rowCenter, const int colCenter);

void Show_Pro(const int rowCenter, const int colCenter);

int  Show_Timer(const std::time_t beginTime, const size_t size, const int matrixStartRow, const int matrixStartCol);

void Show_Veteran(const int rowCenter, const int colCenter);

void Show_Win(const size_t size, const int rowCenter, const int colCenter, const int matrixStartRow, const int matrixStartCol);

#endif //SHOW_HPP
