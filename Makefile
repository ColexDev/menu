main:
	gcc -I/usr/local/include src/main.c src/menu.c -L/usr/local/lib -Wl,-R/usr/local/lib -lncurses -o ui -D_FORTIFY_SOURCE=2 -fstack-clash-protection -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wshadow -Wsign-conversion -Wstrict-overflow=5 -Wundef
