#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    FILE* fp;

    fp = fopen("example.txt", "w+");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    fprintf(fp, "Hello, World!");
    fflush(fp);  // ǿ�ƽ�����������д���ļ�

    fclose(fp);
    return 0;
}