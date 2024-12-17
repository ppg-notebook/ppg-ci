#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

int main01()
{
	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	int len = sizeof(arr) / sizeof(int);
	for (int i = 0; i < len/2; i++)
	{
		int temp = arr[i];
		arr[i] = arr[len - i - 1];
		arr[len - i - 1] = temp;
	}
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}

	return EXIT_SUCCESS;
}

int main02()
{
	char arr1[12] = { 0 };
	char arr2[12] = { 0 };
	scanf("%s", arr1);
	scanf("%s", arr2);
	printf("%s %s\n", arr1, arr2);
	printf("%d %d\n", strlen(arr1), strlen(arr2));
	fputs(arr1, stdout);
	putchar('\n');
	fputs(arr2, stdout);
	putchar('\n');
	srand(time(NULL));
	printf("%d\n", rand());
}

int main03()
{
	srand(time(NULL));
	int num;
	int inPut = 0;
LABLE:
	num = rand() % 100 + 1;
	while (1)
	{
		printf("输入：");
		scanf("%d", &inPut);
		if (inPut > num)
			printf("大了");
		else if (inPut < num)
			printf("小了");
		else break;
	}
	printf("对了:%d\n", num);
goto LABLE;
	return 0;
}

int main04()
{
	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			for (int k = 0; k < 60; k++)
			{
				Sleep(999);
				system("cls");
				printf("%02d:%02d:%02d\n", i, j, k);
			}
		}
	}
	return 0;
}

int main05()
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < i + 1; j++)
		{
			printf("%dx%d=%d\t", i, j, i * j);
		}
		printf("\n");
	}

	return 0;
}

int main06()
{
	for (int i = 9; i > 0; i--)
	{
		for (int j = i; j > 0; j--)
		{
			printf("%dx%d=%d\t", i, j, i * j);
		}
		printf("\n");
	}
	return 0;
}

int main()
{

	return 0;
}