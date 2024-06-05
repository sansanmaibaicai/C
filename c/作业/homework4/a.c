#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义最大行数和每行最大长度
#define MAX_LINES 100
#define MAX_LENGTH 100

// 函数声明
void count_words(const char *lines[], int num_lines);

int main() {
    char input[MAX_LENGTH]; // 用于存储输入的缓冲区
    const char *lines[MAX_LINES]; // 用于存储输入行的数组
    int num_lines = 0; // 已读取的行数

    // 提示用户输入多行文本，直到输入 "END"
    printf("Enter multiple lines of text (type END to finish):\n");
    while (1) {
        // 读取一行输入
        if (fgets(input, MAX_LENGTH, stdin) == NULL) {
            // 读取输入失败，终止程序
            fprintf(stderr, "Error reading input.\n");
            return EXIT_FAILURE;
        }

        // 如果输入是 "END\n"，结束读取
        if (strcmp(input, "END\n") == 0) {
            break;
        }

        // 将输入的行存储到数组中，并使用 strdup 复制字符串
        lines[num_lines] = strdup(input);
        if (lines[num_lines] == NULL) {
            // 内存分配失败，终止程序
            fprintf(stderr, "Memory allocation failed.\n");
            return EXIT_FAILURE;
        }

        num_lines++; // 增加行数

        // 如果超过最大行数，终止读取
        if (num_lines >= MAX_LINES) {
            fprintf(stderr, "Maximum number of lines reached.\n");
            break;
        }
    }

    // 统计单词
    count_words(lines, num_lines);

    // 释放存储输入行的内存
    for (int i = 0; i < num_lines; i++) {
        free((void *)lines[i]); // 转换指针类型为 void* 并释放
    }

    return 0;
}

void count_words(const char *lines[], int num_lines) {
    char *words[MAX_LINES * MAX_LENGTH]; // 存储单词的数组
    int counts[MAX_LINES * MAX_LENGTH] = {0}; // 存储每个单词的计数
    int num_words = 0; // 已找到的单词数

    // 遍历每一行
    for (int i = 0; i < num_lines; i++) {
        // 复制每行内容以确保原始数据不会被修改
        char *line = strdup(lines[i]);
        if (line == NULL) {
            // 内存分配失败
            fprintf(stderr, "Memory allocation failed.\n");
            return;
        }

        // 使用 strtok 分割单词，分隔符包括空格、制表符和换行符
        char *word = strtok(line, " \t\n");
        while (word != NULL) {
            int found = 0; // 是否找到现有的单词
            // 遍历已找到的单词，看看是否已存在
            for (int j = 0; j < num_words; j++) {
                if (strcmp(words[j], word) == 0) {
                    counts[j]++; // 如果找到，增加计数
                    found = 1; // 标记已找到
                    break;
                }
            }
            if (!found) {
                // 如果没找到，将单词添加到数组中
                words[num_words] = strdup(word);
                if (words[num_words] == NULL) {
                    // 内存分配失败
                    fprintf(stderr, "Memory allocation failed.\n");
                    free(line); // 释放临时行
                    return;
                }
                counts[num_words] = 1; // 初始化计数
                num_words++; // 增加单词数
            }

            // 获取下一个单词
            word = strtok(NULL, " \t\n");
        }

        // 释放复制的行
        free(line);
    }

    // 输出每个单词的计数
    printf("\nWord Counts:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: ", words[i]); // 输出单词名称
        // 遍历每一行，统计每行中单词的出现次数
        for (int j = 0; j < num_lines; j++) {
            char *line = strdup(lines[j]);
            if (line == NULL) {
                // 内存分配失败
                fprintf(stderr, "Memory allocation failed.\n");
                return;
            }

            int count = 0; // 每行的计数
            // 使用 strstr 找到单词的出现位置
            char *ptr = strstr(line, words[i]);
            while (ptr != NULL) {
                count++; // 如果找到，增加计数
                ptr = strstr(ptr + 1, words[i]); // 继续查找
            }

            // 输出每行的单词计数
            printf("%d ", count);

            // 释放复制的行
            free(line);
        }
        // 输出单词的总计数
        printf("(Total: %d)\n", counts[i]);
    }

    // 释放单词数组中所有分配的内存
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
}

