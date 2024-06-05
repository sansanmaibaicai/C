#include <stdio.h>

#define DAYS_IN_WEEK 7

// 判断闰年
int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 获取月份的天数
int get_days_in_month(int year, int month) {
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && is_leap_year(year)) {
        return 29;
    }
    return days_in_month[month - 1];
}

// 计算给定年份和月份的第一天是星期几
int calculate_first_day_of_month(int year, int month) {
    // 使用 Zeller's Congruence 算法
    int adjusted_month = month - 2;
    int adjusted_year = year;
    
    if (adjusted_month <= 0) {
        adjusted_month += 12;
        adjusted_year -= 1;
    }

    int K = adjusted_year % 100;
    int J = adjusted_year / 100;

    int day_of_week = (1 + (13 * adjusted_month - 1) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;

    // 将结果调整为周一开始
    day_of_week = (day_of_week + 5) % 7;

    return day_of_week;
}

// 输出某个月的日历
void print_single_month(int year, int month, int start_day) {
    // 获取该月的天数和第一天是星期几
    int days_in_month = get_days_in_month(year, month);
    int first_day_of_month = calculate_first_day_of_month(year, month);
    
    // 输出月份标题
    printf("    %4d年 %2d月\n", year, month);
    // 输出星期标题
    printf("一 二 三 四 五 六 日\n");
    printf("--------------------\n");

    // 在第一天之前添加空格
    for (int i = 0; i < first_day_of_month; i++) {
        printf("   ");
    }

    // 输出日期
    for (int day = 1; day <= days_in_month; day++) {
        printf("%2d ", day);

        // 在周日结束时换行
        if ((day + first_day_of_month) % DAYS_IN_WEEK == 0) {
            printf("\n");
        }
    }

    // 确保在月历结束时输出空行
    if ((days_in_month + first_day_of_month) % DAYS_IN_WEEK != 0) {
        printf("\n");
    }

    // 输出间隔空格
    for (int i = 0; i < (start_day - (days_in_month + first_day_of_month) % DAYS_IN_WEEK) % DAYS_IN_WEEK; i++) {
        printf("\n");
    }
}

// 输出三个月为一行的万年历
void print_row_of_months(int year, int start_month) {
    for (int i = 0; i < 3; i++) {
        // 输出当前月份的日历
        print_single_month(year, start_month + i, 0);
        // 添加间隔
        if (i < 2) {
            printf("        ");
        }
    }
}

// 主函数
int main() {
    int year;
    printf("请输入年份：");
    scanf("%d", &year);

    // 按照三个月为一行的格式输出
    for (int row = 0; row < 4; row++) {
        print_row_of_months(year, row * 3 + 1);
        printf("\n");
    }

    return 0;
}
