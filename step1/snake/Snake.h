#ifndef _SNAKE_H__
#define _SNAKE_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>


#define HEIGHT 20
#define WEIGHT 60

// һ���������
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
	int size;					// �ߵ������С
	DOT body[HEIGHT-2][WEIGHT-2];	// �ߵ�����
}SNAKE;

// ��ʼ����ͼ
WALL* initWall();

// ��ʼ����
SNAKE* initSnake();

// ��ʼ��ʳ��
DOT* initFood();

// �������
int showScene(DOT* food,SNAKE *snake,WALL *wall);

// �ƶ�����
int moveSnake(int up,int down,int left,int right,SNAKE*snake);

// ��ײ�ж�
int collisionDetermination(DOT* food, SNAKE* snake, WALL* wall);

// ��ʼ��Ϸ
int startGame();

// ��λ�������ַ�
void myPutChar(DOT dot);

#endif // !_SNAKE_H__