#include "InputManager.h"
#include <ncurses.h>

int main (int argc, char *argv [])
{
    InputManager inputManager;
    inputManager.PrintToScreen("Hello, world!" "\n");

    while(true)
    {
        auto key = inputManager.GetKey();

        if (key == KEY_LEFT)
        {
            inputManager.PrintToScreen("Left key pressed." "\n");
        }

        else if (key == KEY_RIGHT)
        {
            inputManager.PrintToScreen("Right key pressed." "\n");
        }

        else if (key == 'q' || key == 'Q')
        {
            inputManager.PrintToScreen("Quitting, good bye!" "\n");
            break;
        }
    }
}
