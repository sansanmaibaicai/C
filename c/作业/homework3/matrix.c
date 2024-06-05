/*
 *该程序要求实现矩阵A和矩阵B相乘的功能
 *
 *
 */


#include<stdio.h>

//矩阵乘法函数，将矩阵A和矩阵B相乘，并将结果保存在矩阵C中
void matrix_multi(double A[3][4], double B[4][5], double C[3][5]){
	
	//初始化矩阵c
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			C[i][j] = 0;//将c[i][j]设置为0
		}
	}
	//计算矩阵乘积A*B
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 4; k++) {
				C[i][j] += A[i][k] * B[k][j];
		}
	}
}
}

//打印矩阵c
void print_matrix(double C[3][5],int line,int column){
	for(int i=0;i<line;i++){
		for(int j=0;j<column;j++){
			printf("%0.2f ",C[i][j]);
		}
		printf("\n");
	}
}

int main(){
	//定义矩阵A
	double A[3][4]={
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};
	//定义矩阵B
	double B[4][5]={
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15},
		{16,17,18,19,20}
	};
	//定义空矩阵C
	double C[3][5];
	matrix_multi(A,B,C);
	printf("矩阵C的结果是：\n");
	print_matrix(C,3,5);
	return 0;
}
