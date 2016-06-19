#ifndef SN_INPUT_MANAGER_H
#define SN_INPUT_MANAGER_H

#include <ncurses.h>

class InputManager
{
public:
    InputManager()
    {
        initscr();
        raw();
        keypad(stdscr, TRUE);
        nodelay(stdscr, TRUE);
        noecho();
    }

    InputManager(const InputManager &other) = delete;
    InputManager(InputManager &&other) = delete;

    ~InputManager()
    {
        endwin();
    }

    auto operator=(InputManager other) -> InputManager& = delete;

    auto GetKey() const -> int
    {
        return getch();
    }

    auto PrintToScreen(const char *message) const -> void
    {
        printw(message);
        refresh();
    }

private:
};

#endif
