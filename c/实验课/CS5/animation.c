#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define DISPLAY_WIDTH 80  // 显示区域的宽度
#define SCROLL_SPEED 200000  // 微秒，滚动速度
#define LINE_COUNT 4  // 显示的行数

// ANSI 颜色码
const char *COLORS[LINE_COUNT] = {
    "\033[31m",  // 红色
    "\033[32m",  // 绿色
    "\033[33m",  // 黄色
    "\033[34m"   // 蓝色
};

// 清除屏幕
void clear_screen() {
    printf("\033[H\033[J");
}

// 在指定位置显示文本
void draw_text(int x, int y, const char *color, const char *text) {
    printf("\033[%d;%dH%s%s\033[0m", y + 1, x + 1, color, text);  // 移动光标并显示带颜色的文本
}

// 清除行
void clear_line(int y) {
    printf("\033[%d;%dH\033[K", y + 1, 0);  // 清除指定行
}

int main() {
    // 要滚动的消息数组
    const char *messages[LINE_COUNT] = {
        " ***** ",
        "   *   ",
        "   *   ",
        "   *   "
    };
    int message_lengths[LINE_COUNT];

    // 获取每个消息的长度
    for (int i = 0; i < LINE_COUNT; i++) {
        message_lengths[i] = strlen(messages[i]);
    }

    int offsets[LINE_COUNT] = {0};  // 用于滚动的偏移量

    // 动画循环
    while (1) {
        // 清除每一行
        for (int i = 0; i < LINE_COUNT; i++) {
            clear_line(i);
        }

        // 绘制每一行的消息
        for (int i = 0; i < LINE_COUNT; i++) {
            // 创建一个显示区域
            char display_text[DISPLAY_WIDTH + 1];
            memset(display_text, ' ', DISPLAY_WIDTH); // 用空格填充显示区域
            display_text[DISPLAY_WIDTH] = '\0';  // 确保字符串结束

            int start_index = offsets[i];
            for (int j = 0; j < message_lengths[i]; j++) {
                int pos = start_index + j;
                if (pos >= 0 && pos < DISPLAY_WIDTH) {
                    display_text[pos] = messages[i][j];
                }
            }

            draw_text(0, i, COLORS[i], display_text);

            offsets[i]--;


            if (offsets[i] <= -message_lengths[i]) {
                offsets[i] = DISPLAY_WIDTH;
            }
        }

        usleep(SCROLL_SPEED);
    }

    return 0;
}

