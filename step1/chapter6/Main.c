#include<stdio.h>

//����ָ��
int main()
{
    //void b; �����Զ���void���͵ı���,��Ϊ��������֪��������������Ŀռ�
    //���ǿ��Զ���void *����,��Ϊָ�붼��4���ֽ�
    int  a = 10;
    short b = 10;
    void* p = (void*)&a;//����ָ����Ա�������ĵ�ַ
    void* q = &b;
    //printf("%d\n", *p);//err  p��void*,��֪��ȡ�����ֽڵĴ�С
    printf("%d\n", *(int*)p);// *(  (int *)��ַ)
    system("pause");
    return 0;
}

