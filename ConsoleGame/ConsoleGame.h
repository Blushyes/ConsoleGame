#pragma once
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_DOWN 80
#define KEY_RIGHT 77
#define RED 199
#define BLACK 0
#define YELLOW 238
#define Map(x) map[x]

int color, WIDTH, HEIGHT, *map;

void hideConsoleCursor();	//隐藏控制台光标

void moveCusorTo(int x, int y);	//移动光标到

void changeTextColor(int c);	//改变字体颜色

int getKeyState();	//检测当前按键

void initMap(int* m, const int W, const int H);	//初始化地图

void drawMap();	//画地图

void getMapCoord(int coord, int* x, int* y);	//反推地图的x，y坐标

void setColor(int c);

int getColor();

int coord(int x, int y);	//获取x，y在map中的坐标

void clear();