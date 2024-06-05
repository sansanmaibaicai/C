/*
 * byte.c
 * 
 * 本程序通过sizeof()函数获取不同基本数据类型所占的字节数
 *
 */
#include<stdio.h>

int main()
{
	int a;
	short b;
	long c;
	long long d;
	float e;
	double f;
	char g;
	
	printf("The size of int is %ld bytes.\n",sizeof(a));
	printf("The size of short is %ld bytes.\n",sizeof(b));
	printf("The size of long is %ld bytes.\n",sizeof(c));
	printf("The size of long long is %ld bytes.\n",sizeof(d));
	printf("The size of float is %ld bytes.\n",sizeof(e));
	printf("The size of double is %ld bytes.\n",sizeof(f));
	printf("The size of char is %ld bytes.\n",sizeof(g));
 	
 	return 0;
}

