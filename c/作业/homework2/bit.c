/*
 *bit.c
 *打印给定字符的二进制表示中每一位的值
 *利用 & 运算符  确定该位是0还是1
 *
 *原理：设输入x=2 -- 10
 *将1左移动0位  1  & 10 = 00 
 *将1左移动1位  10 & 10 = 10
 *
 *代码实现了一个函数printbit，其作用是打印给定字符的二进制表示中每一位的值
 *并在main函数中调用该函数
 */
#include<stdio.h>

void printbit(char c) {
    printf("The eighth bit is %d,\n", (c & (1 << 7)) >> 7);
    //向左移7位，判断最高位，之后再恢复原位
    printf("The seventh bit is %d,\n", (c & (1 << 6)) >> 6);
    printf("The sixth bit is %d,\n", (c & (1 << 5)) >> 5);
    printf("The fifth bit is %d,\n", (c & (1 << 4)) >> 4);
    printf("The fourth bit is %d,\n", (c & (1 << 3)) >> 3);
    printf("The third bit is %d,\n", (c & (1 << 2)) >> 2);
    printf("The second bit is %d,\n", (c & (1 << 1)) >> 1);
    printf("The first bit is %d.\n", c & 1);
}

int main(){
 	char x;
 	printf("请输入一个字符：\n");
 	scanf("%c",&x);
 	printbit(x);//将读取的数据交给printbit函数处理
 	return 0;
}
