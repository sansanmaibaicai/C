/*
程序从用户接收多行英文字符串。当用户结束输入后，程序统计出在用户的输入中所出现过的单词，以及这些单词在每一行出现的次数、在用户输入中总共出现的次数。
注意事项：
当用户输入“END”（或者其他自定义结束字符串时）可以视为用户要结束输入。
请使用指针数组来存放用户输入的数据，让我们默认用户的输入不会超过100行。
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//定义最大行数和每行最大长度
#define MAX_LINES 100
#define MAX_LENGTH 100

//函数声明
void count_words(const char *lines[], int num_lines);

int main() {
    char input[MAX_LENGTH];//用于储存输入的缓冲区
    const char *lines[MAX_LINES];//用于储存输入行的缓冲区
    int num_lines = 0;//已读取的行数

    printf("Enter multiple lines of text (type END to finish):\n");
    while (1) {
        fgets(input, MAX_LENGTH, stdin);
        //如果输入是END\n，结束读取
        if (strcmp(input, "END\n") == 0) {
            break;
        }
        lines[num_lines++] = strdup(input);
    }

    count_words(lines, num_lines);//统计单词

    //释放存储输入行的内存
    for (int i = 0; i < num_lines; i++) {
        free((void *)lines[i]);
    }

    return 0;
}

void count_words(const char *lines[], int num_lines) {
    char *words[MAX_LINES * MAX_LENGTH];//存储单词的数组
    int counts[MAX_LINES * MAX_LENGTH] = {0};//存储每个单词的计数
    int total_count = 0;
    int num_words = 0;//已经找到的单词数
    //遍历每一行
    for (int i = 0; i < num_lines; i++) {
        char *line = strdup(lines[i]);
        //复制每一行内容以保证原始数据不会被修改
        char *word = strtok(line, " \t\n");
        //使用stork分割单词
        while (word != NULL) {
            int found = 0;
            //遍历已经找到的单词，看是否已经存在
            for (int j = 0; j < num_words; j++) {
                if (strcmp(words[j], word) == 0) {
                    counts[j]++;//若找到，增加计数
                    found = 1;//标记已经找到
                    break;
                }
            }
            if (!found) {
            	//如果没找到，将单词添加到数组中
                words[num_words] = strdup(word);
                counts[num_words] = 1;
                num_words++;
            }
            total_count++;
            word = strtok(NULL, " \t\n");//获取下一个单词
        }
        free(line);
    }
    //输出每个单词的计数
    printf("\nWord Counts:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: ", words[i]);//输出单词名称
        //遍历每一行，统计每行中单词的出现次数
        for (int j = 0; j < num_lines; j++) {
            char *line = strdup(lines[j]);
            int count = 0;
            char *ptr = strstr(line, words[i]);
            while (ptr != NULL) {
            	//如果找到，增加计数
                count++;
                ptr = strstr(ptr + 1, words[i]);//继续查找
            }
            //输出每行的单词数
            printf("%d ", count);
            //释放复制的行
            free(line);
        }
        //输出单词的总数
        printf("(Total: %d)\n", counts[i]);
    }
    printf("\nTotal words: %d\n", total_count);
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
}

