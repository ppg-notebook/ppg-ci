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
	SNAKE* snake = (SNAKE*)malloc(sizeof(SNAKE));
	snake->size = 2;
	snake->body[0].ch = '@';
	snake->body[0].x = WEIGHT / 2;
	snake->body[0].y = HEIGHT / 2;
	snake->body[1].ch = '#';
	snake->body[1].x = WEIGHT / 2-1;
	snake->body[1].y = HEIGHT / 2;
	return snake;
}

// ��ʼ��ʳ��
DOT* initFood(SNAKE* snake)
{
	srand(time(NULL));
	DOT* food = (DOT*)malloc(sizeof(DOT));
	food->ch = '$';
	do {
		food->x = rand() % (WEIGHT - 2) + 1;
		food->y = rand() % (HEIGHT - 2) + 1;
	} while (getSnakeChar(snake, food->x, food->y)!=' ');
	return food;
}

// ����������ߺ�ʳ��
int showScene(DOT* food, SNAKE* snake, WALL* wall)
{
	// ���ԭ�л���
	system("cls");
	// ��ʾǽ
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WEIGHT; x++)
		{
			myPutChar(wall->wall[y][x]);
		}
	}
	// ��ʾ��
	for (int i = 0; i < snake->size; i++)
	{
		myPutChar(snake->body[i]);
	}
	//��ʾʳ��
	myPutChar(*food);

	return 0;

}

// �ƶ�����
SNAKE* moveSnake(int down,int right, SNAKE* snake)
{
	for (int i = 1; i < snake->size; i++)
	{
		if (i == 1)
		{
			snake->body[i] = snake->body[i - 1];
			snake->body[i].ch = '#';
		}
		else
		{
			snake->body[i] = snake->body[i - 1];
		}
	}
	snake->body[snake->size].ch = ' ';
	snake->body[0].x += right;
	snake->body[0].y += down;
	return snake;
}

// ��ײ�ж�
int collisionDetermination(DOT* food, SNAKE* snake, WALL* wall)
{
	for (int i = 1; i < snake->size; i++)
	{
		if (snake->body[0].x == snake->body[i].x && snake->body[0].y == snake->body[i].y)
			return -1;
	}

	if (snake->body[0].x == 0 || snake->body[0].x == WEIGHT - 1 || snake->body[0].y == 0 || snake->body[0].y == HEIGHT - 1)
		return -1;

	if (snake->body[0].x == food->x && snake->body[0].y == food->y)
	{
		snake->body[snake->size] = snake->body[snake->size-1];
		snake->body[snake->size].x--;
		snake->size++;

		free(food);
		food = initFood(snake);
	}

	return 0;
}

// ��ʼ��Ϸ
int startGame()
{
	// ��ʼ������
	WALL* wall = initWall();
	// ��ʼ����
	SNAKE* snake = initSnake();
	// ��ʼ��ʳ��
	DOT* food = initFood(snake);

	while (1)
	{
		Sleep(600);
		if (_kbhit())
		{
			char ch = getchar();
			if (ch == 'w' || ch == 'W')
			{
				moveSnake(-1, 0, snake);
			}
			else if (ch == 's' || ch == 'S')
			{
				moveSnake(1, 0, snake);
			}
			else if (ch == 'a' || ch == 'A')
			{
				moveSnake(0, -1, snake);
			}
			else if (ch == 'd' || ch == 'D')
			{
				moveSnake(0, 1, snake);
			}
		}
		showScene(food, snake, wall);
		if (collisionDetermination(food, snake, wall) == -1)
			break;
	}

	return 0;
}

// ������Ϸ
int endGame()
{
	COORD p;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	p.X = 0; p.Y = HEIGHT+1;
	SetConsoleCursorPosition(handle, p);
}

// ��λ�������ַ�
void myPutChar(DOT dot)
{
	COORD p;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	p.X = dot.x; p.Y = dot.y;
	SetConsoleCursorPosition(handle, p);
	putchar(dot.ch);
}

// ��ȡ����ĳһλ�õ��ַ�
char getSnakeChar(SNAKE* snake,int x,int y)
{
	for (int i = 0; i < snake->size; i++)
	{
		if (snake->body[i].x == x || snake->body[i].y == y)
		{
			return snake->body->ch;
		}
	}
	return ' ';
}