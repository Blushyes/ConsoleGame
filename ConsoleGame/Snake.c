#include"ConsoleGame.h"
#define W 10
#define H 10

int main() {
	int map[W * H], snake[100], length = 1, direction[] = {-1, 0, 1, 0, -1}, head, food, buffer = 0;
	hideConsoleCursor();
	initMap(map, W, H);

	//蛇状态初始化
	srand((unsigned)time(NULL));
	snake[0] = rand() % (W * H);
	head = rand() % 4;
	Map(snake[0]) = RED;

	//食物初始化
	food = rand() % (W * H);
	Map(food) = YELLOW;

	//游戏主循环
	drawMap(map);
	while (1) {
		int i, x, y, r, c, tmp, last;

		//检测游戏是否结束
		for (i = 1; i < length; ++i) {
			if (snake[0] == snake[i]) {
				clear();
				changeTextColor(7);
				_cputs("game over!");
				while(1);
			}
		}

		//控制蛇
		getKeyState();
		switch (getKeyState()) {
			case KEY_UP: if (head != 2) head = 0; break;
			case KEY_LEFT: if (head != 1) head = 3; break;
			case KEY_DOWN: if (head != 0) head = 2; break;
			case KEY_RIGHT: if (head != 3) head = 1; break;
		}

		//蛇的自动移动
		if (buffer > 100) {
			getMapCoord(snake[0], &x, &y);
			tmp = x + direction[head];
			r = tmp < 0 ? H - 1 : tmp >= H ? 0 : tmp;
			tmp = y + direction[head + 1];
			c = tmp < 0 ? W - 1 : tmp >= W ? 0 : tmp;
			last = snake[length - 1];
			if (coord(r, c) == food) {
				food = rand() % (W * H);
				while (1) {
					for (i = 0; i < length; ++i) {
						if (food == snake[i]) {
							food = rand() % (W * H);
							continue;
						}
					}
					break;
				}
				Map(food) = YELLOW;
				++length;
			}
			for (i = length - 1; i > 0; --i) {
				snake[i] = snake[i - 1];
			}
			snake[0] = coord(r, c);
			for (i = 0; i < length; ++i) {
				Map(snake[i]) = RED;
			}
			Map(last) = BLACK;
			buffer %= 100;
		}

		buffer += 7;
		Sleep(10);

		drawMap();
	}
}

