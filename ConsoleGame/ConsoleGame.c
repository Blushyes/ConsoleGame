#include "ConsoleGame.h"

void hideConsoleCursor() {
	SetConsoleCursorInfo(GetStdHandle((DWORD)-11), &(CONSOLE_CURSOR_INFO) { 1 });
}

void moveCusorTo(int x, int y) {
	SetConsoleCursorPosition(GetStdHandle((DWORD)-11), (COORD) { x, y });
}

void changeTextColor(int c) {
	setColor(c);
	SetConsoleTextAttribute(GetStdHandle((DWORD)-11), getColor());
}

void setColor(int c) {
	color = c;
}

int getColor() {
	return color;
}

int getKeyState() {
	return _kbhit() ? _getch() : 0;
}

void initMap(int* m, const int W, const int H) {
	int i, j;
	WIDTH = W;
	HEIGHT = H;
	map = m;
	for (i = 0; i < HEIGHT; ++i) {
		for (j = 0; j < WIDTH; ++j) {
			map[coord(i, j)] = 0;
		}
	}
}

void drawMap() {
	moveCusorTo(0, 0);
	int i, j;
	for (i = 0; i < HEIGHT; ++i, _cputs("\n")) {
		for (j = 0; j < WIDTH; ++j) {
			changeTextColor(map[coord(i, j)]);
			_cputs("  ");
		}
	}
}

void getMapCoord(int coord, int* x, int* y) {  
	*y = coord % WIDTH;
	*x = (coord - *y) / WIDTH;
}

int coord(int x, int y) {
	return y + x * WIDTH;
}

void clear() {
	system("cls");
}