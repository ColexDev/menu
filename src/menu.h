#ifndef MENU
#define MENU

#include <ncurses.h>

void clear_refresh();
void draw_menu(const int arr_size, const char** arr, WINDOW * win);
void create_menu(const int arr_size, const char** arr, WINDOW * win, int attr);
void unfocus_menu(const int arr_size, const char** arr, WINDOW * win, int attr);
void menu_init(const int rows, const int max_arr_size, const char* arr[rows][max_arr_size], WINDOW* windows[], int attr);
WINDOW * create_window(const int height, size_t width, const int start_y, const int start_x, const int num_of_strings, const char** arr);

#endif
