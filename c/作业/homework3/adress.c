/*
 *编写程序探索C语言使用的二维数组的存放方式是哪一种（按行、按列）
 *
 */


#include<stdio.h>

int main(){
	int A[2][3]={{1,2,3},{4,5,6}};
	int i=0;
	int j=0;
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			printf("A[%d][%d]=%p\n",i,j,&A[i][j]);
		}
	
	}
	return 0;
}
