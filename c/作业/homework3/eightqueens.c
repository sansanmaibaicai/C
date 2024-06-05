/*
 *该程序用于解决八皇后问题
 *
 */



#include<stdio.h>

int sum=0;
int chess[8][8]={0};

int check(int row,int col){//判断每一位是否可以放置棋子|可以返回1，不可以返回0
	int i,j;
	for(i=0;i<8;i++){
		if(chess[i][col]==1){//判断该行是否已经有棋子
			return 0;
		}
	}
	for(i=row,j=col;i>=0&&j>=0;i--,j--){//对棋子的右对角线进行检查
		if(chess[i][j]==1){
			return 0;
		}
	}
	for(i=row,j=col;i>=0&&j<8;i--,j++){//对棋子的左对角线进行检查
		if(chess[i][j]==1){
			return 0;
		}
	}
	return 1;
}

void print(){
	int i,j;
	printf("第%d种解法\n",sum+1);
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if (chess[i][j]==1){
				printf("Q ");//在可以放置棋子的位置放上Q
			}else{
				printf("# ");//不能放置棋子的位置放上#
			}
		}
		printf("\n");
	}
	printf("\n");
}

int search(int row){
	if(row==8){
		print();
		sum++;
	}
	int col;
	for(col=0;col<8;col++){
		if (check(row,col)){//如果棋子可以放置在这一格
			chess[row][col]=1;//修改该值为1
			search(row+1);//进行下一次递归
			chess[row][col]=0;//重置被修改的值
		
		}
	
	}

}

int main(){
	search(0);
	printf("共有%d种解法\n",sum);
	return 0;
}

