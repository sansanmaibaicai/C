
#include <stdio.h>
#include <unistd.h>  // 使用 usleep
#include <stdlib.h>  // 使用 system("clear")

#define DISPLAY_WIDTH 20 // 定义滚动区域的宽度
#define SCROLL_SPEED 200000  // 微秒，滚动速度
#define START_ROW 0  // 滚动字幕的起始行

// 清除特定行
void clear_line(int y) {
    printf("\033[%d;%dH\033[K", y + 1, 0);  // 清除指定行
}

// 滚动文本
void scrollText(char str[], int len, int direction) {
    char temp;
    if (direction == 1) {  // 向左移动
        temp = str[0];
        for (int i = 0; i < len - 1; i++) {
            str[i] = str[i + 1];
        }
        str[len - 1] = temp;
    } else {  // 向右移动
        temp = str[len - 1];
        for (int i = len - 1; i > 0; i--) {
            str[i] = str[i - 1];
        }
        str[0] = temp;
    }
}

int main() {
    char str[] = "I LOVE YOU ";
    int len = sizeof(str) - 1;  // 字符串长度，不包含结束符 '\0'
    int direction = 1;  // 控制滚动方向：1 表示左移，0 表示右移

    while (1) {  // 无限循环
        clear_line(START_ROW);  // 只清除指定行，不影响其他内容

        // 创建一个滚动显示的窗口
        char display_text[DISPLAY_WIDTH + 1];
        
        // 获取窗口内的文本
        for (int i = 0; i < DISPLAY_WIDTH; i++) {
            int char_index = (direction == 1) ? ((i + len - (len % DISPLAY_WIDTH)) % len) : ((i + (len % DISPLAY_WIDTH)) % len);
            display_text[i] = str[char_index];
        }
        display_text[DISPLAY_WIDTH] = '\0';  // 确保字符串结束

        // 显示窗口内的文本
        printf("\033[%d;%dH\033[31m\033[47m%s\033[0m\n", START_ROW + 1, 1, display_text);  // 设置文本颜色和背景颜色

        // 移动文本
        scrollText(str, len, direction);  // 滚动字符

        // 控制滚动速度
        usleep(SCROLL_SPEED);  // 休眠 200 毫秒
    }

    return 0;
}
