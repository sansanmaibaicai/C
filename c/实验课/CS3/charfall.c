#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define WIDTH 80  // 终端宽度
#define HEIGHT 24  // 终端高度
#define CHAR_COUNT 800  // 同时掉落的字符数量
#define DROP_INTERVAL 50000  // 微秒，刷新速度

typedef struct {
    char character;  // 字符
    int x;  // 横向位置
    int y;  // 纵向位置
    int speed;  // 掉落速度
} FallingChar;

// 清除屏幕
void clear_screen() {
    printf("\033[H\033[J");
}

// 在指定位置绘制字符
void draw_char(int x, int y, char c) {
    if (y >= 0 && y < HEIGHT) {
        // 设置绿色
        printf("\033[32m");
        // 移动光标并绘制字符
        printf("\033[%d;%dH%c", y + 1, x + 1, c);
        // 重置颜色
        printf("\033[0m");
    }
}

// 重置光标到顶部
void reset_cursor() {
    printf("\033[0;0H");
}

// 初始化掉落字符数组
void init_falling_chars(FallingChar falling_chars[], int count) {
    for (int i = 0; i < count; i++) {
        falling_chars[i].character = 'A' + (rand() % 26);  // 随机生成字母
        falling_chars[i].x = rand() % WIDTH;  // 随机横向位置
        falling_chars[i].y = rand() % (HEIGHT / 2) - (HEIGHT / 2);  // 随机纵向位置
        falling_chars[i].speed = 1 ;  // 随机速度，介于 1 到 3
    }
}

int main() {
    // 初始化随机数生成器
    srand(time(NULL));

    // 创建掉落字符数组
    FallingChar falling_chars[CHAR_COUNT];
    init_falling_chars(falling_chars, CHAR_COUNT);

    // 动画循环
    while (1) {
        clear_screen();  // 清除屏幕

        for (int i = 0; i < CHAR_COUNT; i++) {
            // 更新位置
            falling_chars[i].y += falling_chars[i].speed;  // 按照速度掉落

            // 如果字符到达底部，则重新生成
            if (falling_chars[i].y >= HEIGHT) {
                falling_chars[i].character = 'A' + (rand() % 26);  // 随机生成字母
                falling_chars[i].x = rand() % WIDTH;  // 随机横向位置
                falling_chars[i].y = -1;  // 重新从顶部开始
                falling_chars[i].speed = 1 + (rand() % 3);  // 随机速度
            }

            // 绘制字符
            draw_char(falling_chars[i].x, falling_chars[i].y, falling_chars[i].character);
        }

        // 控制动画速度
        usleep(DROP_INTERVAL);  // 控制刷新间隔
    }

    return 0;
}
