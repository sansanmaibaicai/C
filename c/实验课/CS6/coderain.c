#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define WIDTH 80         // 控制台宽度
#define HEIGHT 25        // 控制台高度
#define SPEED 100000     // 定义下落速度（微秒）
#define MAX_DROP_LENGTH 5 // 最大雨滴长度

void moveTo(int x, int y) {
    // 移动光标到指定位置
    printf("\033[%d;%dH", y, x);
}

void printRain(char rain[HEIGHT][WIDTH]) {
    // 打印雨滴并设置颜色
    for (int i = 0; i < HEIGHT; ++i) {
        moveTo(1, i + 1);
        for (int j = 0; j < WIDTH; ++j) {
            if (rain[i][j] != ' ') {
                printf("\033[32m%c\033[0m", rain[i][j]); // 设置为绿色
            } else {
                printf(" ");
            }
        }
    }
    fflush(stdout); // 刷新输出缓冲区
}

char getRandomChar() {
    // 返回一个随机字母、数字或特殊字符
    const char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+[]{}|;:',.<>/?";
    int index = rand() % (sizeof(chars) - 1);
    return chars[index];
}

int main() {
    char rain[HEIGHT][WIDTH] = {0};
    int lengths[WIDTH] = {0};    // 记录每列雨滴的长度
    int positions[WIDTH] = {0};  // 记录每列雨滴的位置
    int intervals[WIDTH] = {0};  // 记录每列雨滴的间隔
    int disappearing[WIDTH] = {0}; // 记录每列雨滴是否在消失

    // 初始化随机种子
    srand(time(NULL));

    // 初始化雨滴数组
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            rain[i][j] = ' ';
        }
    }

    // 隐藏光标
    printf("\033[?25l");

    while (1) {
        // 移动雨滴
        for (int j = 0; j < WIDTH; ++j) {
            if (intervals[j] > 0) {
                intervals[j]--;
            } else {
                if (!disappearing[j]) {
                    // 移动雨滴
                    for (int i = HEIGHT - 1; i > 0; --i) {
                        rain[i][j] = rain[i - 1][j];
                    }
                    rain[0][j] = (positions[j] < lengths[j]) ? getRandomChar() : ' ';
                    positions[j]++;

                    // 当雨滴达到底部或完整长度后标记为消失状态
                    if (positions[j] >= HEIGHT || rain[HEIGHT - 1][j] != ' ') {
                        lengths[j] = rand() % MAX_DROP_LENGTH + 1;
                        positions[j] = 0;
                        intervals[j] = rand() % 20 + 1; // 随机间隔时间
                        disappearing[j] = 1; // 标记为消失状态
                    }
                } else {
                    // 逐个消失雨滴
                    int i;
                    for (i = HEIGHT - 1; i >= 0; --i) {
                        if (rain[i][j] != ' ') {
                            rain[i][j] = ' ';
                            break;
                        }
                    }

                    // 如果整列雨滴都消失了，则重置标记
                    if (i < 0) {
                        disappearing[j] = 0;
                    }
                }
            }
        }

        // 打印雨滴
        printRain(rain);

        // 控制下落速度
        usleep(SPEED);
    }

    // 显示光标
    printf("\033[?25h");

    return 0;
}

