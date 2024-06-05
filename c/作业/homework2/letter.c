/*
 *letter.c
 *
 *该程序使用swich选择语句，根据输入的类型选择输出对应的形式
 */



#include<stdio.h>

int main()
{
	char x;
	
	printf("请在E H T三个字母中选择一个输入.\n");
	scanf("%c",&x);
	
	switch (x)
		{
		case 'E':
			printf("\033[35m*****\n*\n*\n***\n*\n*\n*****\033[0m\n");
			//转义字符\033[35m即将字符输出为紫色 \033[0m为取消设置
			break;
		case 'H':
			printf("\033[32m*   *\n*   *\n*****\n*   *\n*   *\033[0m\n");
			//将字符输出为绿色
			break;
		case 'T':
			printf("\033[34m*****\n  *  \n  *  \n  *  \n  *  \033[0m\n");
			//将字符输出为蓝色
			break;
		default:
			printf("输入的字母不在这三个字母中！\n");
		}

	
	return 0;
}
