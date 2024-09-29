#ifndef _SNAKE_H__
#define _SNAKE_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include <conio.h>

#define HEIGHT 20
#define WEIGHT 60

// һ����Ĺ���
typedef struct Dot
{
	int x;	// ������
	int y;	// ������
	char ch;// �õ���ʾ���ַ�
}DOT;

// ��������
typedef struct Wall
{
	DOT wall[HEIGHT][WEIGHT];
}WALL;

// �ߵ�����
typedef struct Snake
{
	int size;							// �ߵ������С
	DOT body[(HEIGHT-2)*(WEIGHT-2)];	// �ߵ�����
}SNAKE;

// ��ʼ����ͼ
WALL* initWall();

// ��ʼ����
SNAKE* initSnake();

// ��ʼ��ʳ��
DOT* initFood(SNAKE*snake);

// �������
int showScene(DOT* food,SNAKE *snake,WALL *wall);

// �ƶ�����
SNAKE* moveSnake(int down,int right,SNAKE*snake);

// ��ײ�ж�
int collisionDetermination(DOT* food, SNAKE* snake, WALL* wall);

// ��ʼ��Ϸ
int startGame();

// ������Ϸ
int endGame();

// ��λ�������ַ�
void myPutChar(DOT dot);

// ��ȡ����ĳһλ�õ��ַ�
char getSnakeChar(SNAKE* snake,int x,int y);

#endif // !_SNAKE_H__