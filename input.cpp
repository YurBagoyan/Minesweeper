#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>

int tty_mode = 0;
struct termios orig_tty;
struct termios new_tty;

// Sets up terminal for one-char-at-a-time reads
void cbreak()
{
   if (tty_mode == 0)
   {
      tcgetattr(0, &orig_tty);
      tty_mode = 1;
      new_tty = orig_tty;
   }

   new_tty.c_lflag &= ~(ICANON | ECHO);
   new_tty.c_cc[VMIN] = 1;
   new_tty.c_cc[VTIME] = 0;
   tcsetattr(0, TCSANOW, &new_tty);
}

// Returns terminal to normal state after cbreak ()
void normal()
{
   if (tty_mode == 1)
   {
      tcsetattr(0, TCSANOW, &orig_tty);
      new_tty = orig_tty;
   }
}

// Checks keyboard buffer (stdin) and returns key
// pressed, or -1 for no key pressed
int keypress()
{
   /*static*/ char keypressed;
   struct timeval waittime;
   int num_chars_read;
   fd_set mask;
   FD_SET(0, &mask);
   waittime.tv_sec = 0;
   waittime.tv_usec = 0;

   if (select (1, &mask, 0, 0, &waittime))
   {
      num_chars_read = read (0, &keypressed, 1);

      if (num_chars_read == 1)
         return ((int)keypressed);
   }

   return -1;
}
