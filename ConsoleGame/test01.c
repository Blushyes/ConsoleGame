#if 0
#include "ConsoleGame.h"

int main() {
	hideConsoleCursor();
	_cputs("Hello World!");
	changeTextColor(0xC);
	draw("  ", 1, 0);
	changeTextColor(199);
	draw("  ", 1, 1);
	int i = 1;
	while (1) {
		move(i + 1, 1, i + 2, 1);
		move(i, 1, i + 1, 1);
		++i;
		Sleep(500);
	}
}
#endif // 0

