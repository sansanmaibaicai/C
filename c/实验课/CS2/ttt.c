#include<stdio.h>

char board[3][3];

void intboard(){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			board[i][j]=' ';
		
		}
	}
}

void printboard(){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf(" %c ",board[i][j]);
			if(j<2){
				printf("|");
			}
		}
		printf("\n");
		if(i<2){
			printf("---|---|---\n");
		}
	}
	printf("\n");
}

int checkwinner(){
	for(int i=0;i<3;i++){
		if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][0]!=' '){
			return 1;
		}
	}
	for(int j=0;j<3;j++){
		if(board[0][j]==board[1][j]&&board[1][j]==board[2][j]&&board[0][j]!=' '){
			return 1;
		}
	}
	if((board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[1][1]!=' ')||
	(board[2][0]==board[1][1]&&board[1][1]==board[0][2]&&board[1][1]!=' ')){
		return 1;
	}
	return 0;
}

int checkdraw(){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(board[i][j]==' '){
				return 0;
			}
		}
	}
	return 1;
}

int makemove(int raw,int col,char currentplayer){
	if(board[raw][col]==' '){
		board[raw][col]=currentplayer;
		return 1;
	}else{
		printf("当前格子已被占用，请选择其他格子\n");
		return 0;
	}

}

int main(){
	intboard();
	int raw;
	int col;
	char currentplayer = 'x';
	int gameover = 0;
	
	printf("现在开始井字棋游戏！\n");
	printboard();
	
	while(!gameover){
		printf("当前轮到%c玩家下棋\n",currentplayer);
		printf("请输入行 列\n");
		scanf("%d %d",&raw,&col);
	
		if(raw<0||raw>2||col<0||col>2){
			printf("输入格式错误，请重新输入！\n");
			continue;
			}
	

		if(makemove(raw,col,currentplayer)){
			printboard();
			if(checkwinner()){
				printf("玩家%c获胜，游戏结束。\n",currentplayer);
				gameover=1;
			}else if(checkdraw()){
				printf("玩家%c获胜，游戏结束。\n",currentplayer);
				gameover=1;
			}else{
				currentplayer = (currentplayer == 'x') ? 'o' : 'x';
		
			}
		
		}
	}
	return 0;
}



