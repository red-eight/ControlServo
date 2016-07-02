// "serial/serial.h" has to be above "InputManager.h" and <ncurses.h> because
// <ncurses.h> has a macro named timeout.

#include "serial/serial.h"
#include "InputManager.h"
#include <ncurses.h>


#include <string>

// ./ControlServo <serialPort>
int main (int argc, char *argv [])
{
    InputManager inputManager;

    if (argc < 2) {
        inputManager.PrintToScreen("Usage: ./ControlServo <serialPort> [baudRate]" "\n");
        return 1;
    }

    std::string const serialPort = argv [1];
    unsigned const serialBaudRate = (argc >= 3) ? std::stoi (argv [2]) : 9600;
    auto const timeout = serial::Timeout::simpleTimeout(1000);

    serial::Serial arduino (serialPort, serialBaudRate, timeout);

    if (!arduino.isOpen()) {
        inputManager.PrintToScreen("Could not open serial port." "\n");
        return 2;
    }

    inputManager.PrintToScreen(
        "Hello! "
        "Use the left and right arrow keys to control the servo motor." "\n"
     );

    while(true)
    {
        auto key = inputManager.GetKey();

        if (key == KEY_LEFT)
        {
            arduino.write("L");
        }

        else if (key == KEY_RIGHT)
        {
            arduino.write("R");
        }

        else if (key == 'q' || key == 'Q')
        {
            inputManager.PrintToScreen("Quitting, good bye!" "\n");
            break;
        }
    }
}
