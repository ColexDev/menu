# Simple ncurses Menu System (WIP)

## Features
- Create simple and sibling menus 

---

## Documentation
- Create 3 menus

```c
#include <stdio.h>
#include <ncurses.h>

#include "menu.h"
#include "config.h"

int main()
{
    /* Inits ncurses */
    initscr();
    noecho();
    curs_set(0);

    /* Sets up the color pair of the selected menu */
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);

    /* Each sub-array is the text of said windows/menu */
    const char* arr[NUM_OF_WINDOWS][MAX_ARR_SIZE] = {
        {"test1", "test2", "test3", NULL},
        {"test4", "test5", NULL},
        {"test6", "test7", "test8", "test9", NULL}
    };

    /* This creates the menus/windows with the text above */
    WINDOW* windows[NUM_OF_WINDOWS] = {
        create_window(10, 20, 1, 1, 2, arr[0]),
        create_window(10, 10, 1, 21, 2, arr[1]),
        create_window(10, 10, 1, 31, 2, arr[2])
    };

    /* This creates the actual menu */
    while (1) {
        menu_init(NUM_OF_WINDOWS, MAX_ARR_SIZE, arr, windows, 1);
    }
    endwin();
}
```
### Output
![output](http://0x0.st/oHIF.png)

![output](http://0x0.st/oXmd.gif)

---

## Keybindings
```
j - move cursor down
k - move cursor up
H - select menu to the left
L - select menu to the right
```

---

## Todo
- Make accessing the functions more user friendly
- An indicator showing which menu is currently selected
- Add other types of menus
