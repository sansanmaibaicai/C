/*
 *本程序要求对一个char型的二维数组A进行排序
 *a)如果 i < j,那么第i行字符的ASCII码的和不大于第j行字符ASCII码的和。
 *(b)对于任意一行k，如果 i < j ，那么A[k][i] <= A[k][j]  
 *
 */




#include<stdio.h>

#define line 5
#define column 6


void sort_each_line(char A[line][column]){  //对每一行进行排序（b）
	for(int i=0;i<line;i++){
		for(int j=0;j<column-1;j++){
			for(int k=j+1;k<column;k++){
				if(A[i][j]>=A[i][k]){
					char tmp=A[i][j];
					A[i][j]=A[i][k];
					A[i][k]=tmp;
				}
			}
		}
	}
}

int sum_line(const char lines[],int columns){ //计算每行ascll码的和
	int sum=0;
	for(int i=0;i<columns;i++){
			sum=sum+lines[i];
	}
	return sum;
}


void sort_lines(char A[line][column]){ //对行进行排序（a）
	for(int i=0;i<line-1;i++){
		for(int j=i+1;j<line;j++){
			if (sum_line(A[i],column)>sum_line(A[j],column)){
				for(int k=0;k<column;k++){
					char tmp=A[i][k];
					A[i][k]=A[j][k];
					A[j][k]=tmp;
				}
			}
		}
	}		
}

void print_array(char A[line][column]){ //打印出结果
	for(int i=0;i<line;i++){
		for(int j=0;j<column;j++){
			printf("%c ",A[i][j]);
		}
		printf("\n");
	}
}

int main(){
	char A[5][6]={
		{'S','D','U','Y','E','S'},
		{'C','H','I','N','A','!'},
		{'A','F','T','E','R','X'},
		{'h','e','r','o','a','b'},
		{'C','y','y','D','S','!'}
	};
	
	printf("Before sorting:\n");
	print_array(A);


	sort_each_line(A);
	sort_lines(A);

	printf("After sorting:\n");
	print_array(A);

	return 0;
}
