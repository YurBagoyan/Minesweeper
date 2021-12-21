#ifndef INPUT_HPP
#define INPUT_HPP

/*
* Brief: Sets up terminal for one-char-at-a-time reads
*/
void cbreak();

/*
* Brief: Resets terminal to normal state after cbreak()
*/
void normal();

/*
* Brief: Checks keyboard buffer (stdin) and returns the pressed key
* Return: Pressed key or -1
*/
int keypress();

void gotoxy(int,int);

void colorCout(const std::string, const int);

void userWinSize(int&, int&);

bool winSizeChanged(int&, int&, const int, const int);

void clearLine(const int);

#endif // INPUT_HPP
