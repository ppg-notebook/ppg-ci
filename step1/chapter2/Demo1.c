#include<stdio.h>

int main01()
{
    //��ӡʱ,Ĭ�����6λС����
    //float�����ܹ���֤�ľ�����7λ��Ч����
    //double  �����ܹ���֤�ľ�����15λ��Ч����
    register float a = 3.1415926456;
    register double b = 3.1415926456;
    int num = 0;
ppg:
    printf("a=%011.8f\n", a);
    printf("a=%.10lf\n", b);
    num++;
    if (num < 100)
    {
        goto ppg;
    }
    system("pause");
    return 0;
}

//����ĳ�ʼ��
int main()
{

    //int  num[10] = {1,2,3,4,5,6,7,8,9,10};
    //�������ֻ��ʼ������Ԫ��,����Ԫ�ر���ʼ��Ϊ0
    //int  num[10] = { 1,2 };
    //int num[10] = { 0 };//����������Ԫ�س�ʼ��Ϊ0
    //int  num[10] = {[5]=5};
    //int num[]; err  ����ʱû�и�֪�м���Ԫ��
    int  num[] = { 1,2,3 };//�������ʱ,[]��û��ֵ,��������Ԫ�ظ�����{}�����Ԫ�ظ�������
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}