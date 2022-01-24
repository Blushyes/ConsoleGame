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

int color;

void hideConsoleCursor();	//���ؿ���̨���

void moveCusorTo(int x, int y);	//�ƶ���굽

void changeTextColor(int c);	//�ı�������ɫ

int getKeyState();	//��⵱ǰ����

void initMap(int* map, const int W, const int H);	//��ʼ����ͼ

void drawMap(int* map, const int W, const int H);	//����ͼ

void getMapCoord(int coord, int* x, int* y, const int W);	//���Ƶ�ͼ��x��y����

void setColor(int c);

int getColor();


