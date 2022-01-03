#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ncurses.h>

#include "menu.h"

// NOTE: maybe just declare the variables in here?
extern int num_of_windows;
extern int selected_window;

int main()
{
    int* highlights = calloc(num_of_windows, sizeof(int));
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    const char* arr[3] = {"Test", "Test1", "Test222222"};
    const char* arr2[3] = {"Okay", "Okay1", "Okay22"};

    WINDOW * win = create_window(10, 20, 1, 1, 3, arr);
    WINDOW * win2 = create_window(10, 10, 1, 21, 3, arr2);

    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    // TODO: Make highlights and the last paramater as global variables instead of passing them
    while (1) {
        if (selected_window == 1) {
            menu_init(3, arr, highlights, win, 1);
        }
        if (selected_window == 2) {
            menu_init(3, arr2, highlights, win2, 1);
        }
    }
    free(highlights);
    endwin();
}
