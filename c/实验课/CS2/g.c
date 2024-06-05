#include<stdio.h>

char board[15][15];
int times=0;

void intboard(){
	int i,j;
	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
			board[i][j]=[0];
		
		}
	}
}

void printboard(){
	for(int i=0;i<=15;i++){
		printf("%2d",i);
		printf("\n");
	}
	for(int i=1;i<=15;i++){
		printf("%2d",i);
		for(int j=1;j<=15;j++){
			if(board[i][j]==0) printf("+ ");
			else if(board[i][j]==1) printf("○ ");
			else printf("● ");
		}
		printf("\n");
	}
}

int checkwinner1(){
	int count=0;
	for(int i=1;i<=15;i++){
		for(int j=1;j<=15;j++){
			count=0;
			if (board[i][j]==1){
				for(int k=j;k<6;k++){
					if(board[i][k]==1) count++;
				}
				if (count==5) return 1;
				count=0;
				
				for(int k=i;k<6;k++){
					if(board[k][j]==1) count++;
				}
				if (count==5) return 1;
				count=0;
				
				int z=i;
				for(int k=j;k<6&&z<15;k++){
					if(board[z++][k]==1) count++;
				}if (count==5) return 1;
				count=0;
				
				z=i;
				for(int k=j;k<6&&z<15;k--){
					if(board[z++][k]==1) count++;
				}if (count==5) return 1;
				count=0;
			
			}
		
		}
	}
	return 0;
}

int checkwinner2(){
	int count=0;
	for(int i=1;i<=15;i++){
		for(int j=1;j<=15;j++){
			count=0;
			if (board[i][j]==2){
				for(int k=j;k<6;k++){
					if(board[i][k]==1) count++;
				}
				if (count==5) return 1;
				count=0;
				
				for(int k=i;k<6;k++){
					if(board[k][j]==1) count++;
				}
				if (count==5) return 1;
				count=0;
				
				int z=i;
				for(int k=j;k<6&&z<15;k++){
					if(board[z++][k]==1) count++;
				}if (count==5) return 1;
				count=0;
				
				z=i;
				for(int k=j;k<6&&z<15;k--){
					if(board[z++][k]==1) count++;
				}if (count==5) return 1;
				count=0;
			
			}
		
		}
	}
	return 0;
}


int checkmove(int x,int y){
	if (board[x][y]!=0||y>0||y<15||x>0||x<15){
		return 1;
	}
	return 0;
}

int makemove(){
	int x,y;
	if(times%2==0){
		printf("玩家1请输入坐标：\n")；
		scanf("%d %d",&x,&y);
		while(checkmove(x,y)){
			printf("该位置已有棋子，玩家1请重新输入坐标：\n");
			scanf("%d %d",&x,&y);
		}
		board[x][y]=1;
		times++;
		if(checkwinner1()) return 1;
	}else{
		printf("玩家2请输入坐标：\n")；
		scanf("%d %d",&x,&y);
		while(checkmove(x,y)){
			printf("该位置已有棋子，玩家2请重新输入坐标：\n");
			scanf("%d %d",&x,&y);
		}
		board[x][y]=2;
		times++;
		if(checkwinner2()) return 2;
	
	}
	return 0;
}

int main(){
	intboard();
	
	printf("现在开始井字棋游戏！\n");
	printboard();
	
	while(1){
		printboard();
		int x = makemove();
		if(x==1){
			printf("玩家1取得胜利！\n");
			break;
		
		}
		if(x==2){
			printf("玩家2取得胜利！\n")；
			break;
		}
	
	}
		
}



