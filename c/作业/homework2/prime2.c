/*
 *prime2.c
 *
 *整体判断素数的思路与prime.c相同
 *使用for语句的嵌套
 *遍历从2到输入值之间的每一个数，并判断其是否是素数
 *若是，则打印出来，若不是，则继续循环
 */




#include<stdio.h>

int main(){
	int x;//输入值
	int i;//参与从2到输入值的循环
	int n;//参与从2到i的循环
	printf("请输入一个正数\n");
	scanf("%d",&x);
	printf("%d以内的素数为：\n",x);
	
	for(i=2;i<x;i++){
	//1不是素数所以直接从2开始，一直循环到输入值
		for(n=2;n<i;n++){
			if(i%n==0) break;//若可以整除则停止循环，开始判断
		}
		if(n<i){
			continue;//不是素数，继续循环
		}else{
			printf("%d ",i);//是素数，打印出来
		}
	}
	printf("\n");
	return 0;
}
