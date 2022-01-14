#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ncurses.h>

#include "menu.h"

#define NUM_OF_WINDOWS 2
#define ARR_SIZE 4

// NOTE: maybe just declare the variables in here?
extern int num_of_windows;
extern int selected_window;

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
    const char* arr[NUM_OF_WINDOWS][ARR_SIZE] = {
        {"test1", "test2", "test3", NULL},
        {"test4", "test5", NULL}
    };

    WINDOW* windows[NUM_OF_WINDOWS] = {
        create_window(10, 20, 1, 1, 2, arr[0]),
        create_window(10, 10, 1, 21, 2, arr[1])
    };

    while (1) {
        menu_init(NUM_OF_WINDOWS, ARR_SIZE, arr, windows, 1);
    }
    endwin();
}
