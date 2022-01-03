#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ncurses.h>

int highlight = 0;
int selected_item = 0;

int selected_window = 1;
// TODO: Figure out a better way to not use this variable
const int num_of_windows = 2;

void clear_refresh()
{
    clear();
    refresh();
}

void draw_menu(const int arr_size, const char* arr[], WINDOW * win)
{
    box(win, 0, 0);
    for (int i = 1; i < arr_size + 1; i++) {
        if (i == highlight + 1) {
            wattron(win, A_REVERSE);
        }
        mvwprintw(win, i, 1, arr[i - 1]);
        wattroff(win, A_REVERSE);
    }
}

void create_menu(const int arr_size, const char* arr[], WINDOW * win, int attr)
{
    wattron(win, COLOR_PAIR(attr));
    draw_menu(arr_size, arr, win);
    wattroff(win, COLOR_PAIR(attr));
}

void destroy_menu(const int arr_size, const char* arr[], WINDOW * win, int attr)
{
    wattroff(win, COLOR_PAIR(attr));
    draw_menu(arr_size, arr, win);
}

void menu_init(const int arr_size, const char* arr[], int* highlights, WINDOW * win, int attr)
{
    create_menu(arr_size, arr, win, attr);
    switch (wgetch(win)) {
    case 'k':
        highlight--;
        if (highlight == -1)
           highlight = 0;
        break;
    case 'j':
        highlight++;
        if (highlight == arr_size)
            highlight = arr_size - 1;
        break;
    case 'q':
        endwin();
        free(highlights);
        exit(0);
        break;
    case 'o':
        selected_item = highlight;
        break;
    case 'L':
        destroy_menu(arr_size, arr, win, attr);
        highlights[selected_window] = highlight;
        selected_window++;
        if (selected_window > num_of_windows) {
            selected_window = num_of_windows;
        }
        highlight = highlights[selected_window];
        break;
    case 'H':
        destroy_menu(arr_size, arr, win, attr);
        highlights[selected_window] = highlight;
        selected_window--;
        if (selected_window < 1) {
            selected_window = 1;
        }
        highlight = highlights[selected_window];
        break;
    }

    wrefresh(win);
}

WINDOW * create_window(const int height, int width, const int start_y, const int start_x, const int num_of_strings, const char* arr[])
{
    /* If the length of the string is larger than the requested width
    the box will adjust to fit the string inside of it */
    for (int i = 0; i < num_of_strings; i++){
        if (strlen(arr[i]) > width) {
            width = strlen(arr[i]) + 2;
        }
    }

    /* Inits the new window and creates the box */
    WINDOW * new_win = newwin(height, width, start_y, start_x);
    refresh();
    // box(new_win, 0, 0);

    wrefresh(new_win);
    return(new_win);
}
