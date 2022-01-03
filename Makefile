main:
	gcc -I/usr/local/include src/main.c src/menu.c -L/usr/local/lib -Wl,-R/usr/local/lib -lncurses -o ui
