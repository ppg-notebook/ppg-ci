#include<stdio.h>

int main01()
{
    char* p1;
    short* p2;
    int* p3;
    int** p4;//p4Ҳ��һ��ָ�����  int **
    printf("%d\n", sizeof(p1));
    printf("%d\n", sizeof(p2));
    printf("%d\n", sizeof(p3));
    printf("%d\n", sizeof(p4));
    system("pause");
    return 0;
}

int main()
{
    int  num = 0x01020304;
    char* p1 = (char*)&num;//int *
    short* p2 = (short*)&num;
    int* p3 = &num;
    //ͨ��*ȡָ�������ָ���ǿ�ռ�����ʱ,ȡ���ڴ�Ŀ�Ⱥ�ָ���������������й�
    printf("%x\n", *p1);
    printf("%x\n", *p2);
    printf("%x\n", *p3);
    system("pause");
    return 0;
}