#include <stdio.h>
#include <ncurses.h>

#include "menu.h"
#include "config.h"

int main()
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);

    // const char* arr[2] = {"Test1", "Test2"};
    const char* arr[NUM_OF_WINDOWS][MAX_ARR_SIZE] = {
        {"test1", "test2", "test3", NULL},
        {"test4", "test5", NULL},
        {"test6", "test7", "test8", "test9", NULL}
    };

    // TODO: Make this into an autogenerated array
    WINDOW* windows[NUM_OF_WINDOWS] = {
        create_window(10, 20, 1, 1, 3, arr[0]),
        create_window(10, 10, 1, 21, 2, arr[1]),
        create_window(10, 10, 1, 31, 4, arr[2])
    };

    while (1) {
        // NUM_OF_WINDOWS, MAX_ARR_SIZE, array of menu options, array of windows, color pair
        menu_init(NUM_OF_WINDOWS, MAX_ARR_SIZE, arr, windows, 1);
    }
    endwin();
}
