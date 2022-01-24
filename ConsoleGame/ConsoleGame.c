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

void initMap(int* map, const int W, const int H) {
	int i, j;
	for (i = 0; i < H; ++i) {
		for (j = 0; j < W; ++j) {
			map[j + i * W] = 0;
		}
	}
}

void drawMap(int* map, const int W, const int H) {
	moveCusorTo(0, 0);
	int i, j;
	for (i = 0; i < H; ++i, _cputs("\n")) {
		for (j = 0; j < W; ++j) {
			changeTextColor(map[j + i * W]);
			_cputs("  ");
		}
	}
}

void getMapCoord(int coord, int* x, int* y, const int W) {  
	*y = coord % W;
	*x = (coord - *y) / W;
}

