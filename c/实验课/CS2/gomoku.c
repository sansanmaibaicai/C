#include <stdio.h>

#define BOARD_SIZE 15
#define EMPTY '.'
#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define WIN_CONDITION 5


void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

// 打印棋盘
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d", i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
}

// 检查移动是否合法
int isValidMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == EMPTY;
}

// 检查获胜条件
int checkWinner(char board[BOARD_SIZE][BOARD_SIZE], char player, int row, int col) {
    int directions[4][2] = { {0, 1}, {1, 0}, {1, 1}, {1, -1} };
    
    for (int i = 0; i < 4; i++) {
        int count = 1;
        // 检查当前方向
        for (int j = 1; j < WIN_CONDITION; j++) {
            int newRow = row + directions[i][0] * j;
            int newCol = col + directions[i][1] * j;
            if (newRow >= 0 && newRow < BOARD_SIZE && newCol >= 0 && newCol < BOARD_SIZE && board[newRow][newCol] == player) {
                count++;
            } else {
                break;
            }
        }
        // 检查反方向
        for (int j = 1; j < WIN_CONDITION; j++) {
            int newRow = row - directions[i][0] * j;
            int newCol = col - directions[i][1] * j;
            if (newRow >= 0 && newRow < BOARD_SIZE && newCol >= 0 && newCol < BOARD_SIZE && board[newRow][newCol] == player) {
                count++;
            } else {
                break;
            }
        }
        if (count >= WIN_CONDITION) {
            return 1;
        }
    }
    return 0;
}

// 检查是否平局
int isDraw(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}

// 游戏逻辑
void playGame() {
    char board[BOARD_SIZE][BOARD_SIZE];
    char currentPlayer = PLAYER_X;
    int row, col;
    int gameOver = 0;

    initializeBoard(board);
    printBoard(board);

    while (!gameOver) {
        printf("当前玩家：%c\n", currentPlayer);
        printf("请输入行索引：");
        scanf("%d", &row);
        printf("请输入列索引：");
        scanf("%d", &col);

        if (isValidMove(board, row, col)) {
            board[row][col] = currentPlayer;
            printBoard(board);

            // 检查是否获胜
            if (checkWinner(board, currentPlayer, row, col)) {
                printf("玩家 %c 获胜！\n", currentPlayer);
                gameOver = 1;
            } else if (isDraw(board)) {
                printf("平局！\n");
                gameOver = 1;
            } else {
                // 切换玩家
                currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
            }
        } else {
            printf("无效的移动，请重试。\n");
        }
    }
}

int main() {
    playGame();
    return 0;
}
