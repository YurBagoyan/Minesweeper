#include <iostream>
#include <string>
#include "input.hpp"

void show_menu(std::string Menu_Rows[], int const Menu_Count, int const select)
{
    system("clear");
    
    for(int i = 0; i < Menu_Count; ++i)
    {
        if(i == select)
        {
            std::cout << ">  " << Menu_Rows[i] << "\n";
        }
        else
        {
            std::cout << "  " << Menu_Rows[i] << "\n";
        }
    }
}   

int main()
{

    const int Menu_Count = 5;
    std::string Menu_Rows[Menu_Count] = { "Start", "Records", "Options", "About", "Exit" };

    int select = 0;
    show_menu(Menu_Rows, Menu_Count, select);
    
    for(char key = 0; key != 27; )
    {
        cbreak();
        key = keypress();
        normal();

        switch(key)
        {
            case 'w':
            case 'W':
                if(select == 0)
                {
                    select = 4;
                    show_menu(Menu_Rows, Menu_Count, select);
                }
                else
                {
                    --select;
                    show_menu(Menu_Rows, Menu_Count, select);
                }
                break;
            
            /*case 'W':
                if(select == 0)
                {
                    select = 4;
                    show_menu(Menu_Rows, Menu_Count, select);
                }
                else
                {
                    --select;
                    show_menu(Menu_Rows, Menu_Count, select);
                }
                break;*/


            case 's':
            case 'S':
                if(select == 4)
                {
                    select = 0;
                    show_menu(Menu_Rows, Menu_Count, select);
                }
                else
                {
                    ++select;
                    show_menu(Menu_Rows, Menu_Count, select);
                }
                break;

            /*case 'S':
                if(select == 4)
                {
                    select = 0;
                    show_menu(Menu_Rows, Menu_Count, select);
                }
                else
                {
                    ++select;
                    show_menu(Menu_Rows, Menu_Count, select);
                }
                break;*/
        }
    }
}
