#include"Snake.h"

// ��ʼ����ͼ
WALL* initWall()
{
	WALL* wall = (WALL*)malloc(sizeof(WALL));
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WEIGHT; x++)
		{
			if (y == 0 || x == 0 || y == HEIGHT - 1 || x == WEIGHT - 1)
			{
				wall->wall[y][x].ch='#';
			}
			else
			{
				wall->wall[y][x].ch = ' ';
			}
			wall->wall[y][x].x = x;
			wall->wall[y][x].y = y;
		}
	}
	return wall;
}

// ��ʼ����
SNAKE* initSnake()
{

}

// ��ʼ��ʳ��
DOT* initFood()
{

}

// �������
int showScene(DOT* food, SNAKE* snake, WALL* wall)
{

}

// �ƶ�����
int moveSnake(int up, int down, int left, int right, SNAKE* snake)
{

}

// ��ײ�ж�
int collisionDetermination(DOT* food, SNAKE* snake, WALL* wall)
{

}

// ��ʼ��Ϸ
int startGame()
{
	WALL* wall = initWall();
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WEIGHT; x++)
		{
			myPutChar(wall->wall[y][x]);
		}
	}
	return 0;
}

void myPutChar(DOT dot)
{
	COORD p;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	p.X = dot.x; p.Y = dot.y;
	SetConsoleCursorPosition(handle, p);
	putchar(dot.ch);
}