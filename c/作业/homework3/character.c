/*
 *
 *该程序要求输入为不确定个数的字符（字符数少于5个），输出为这些字符的图案表示
 *
 */



#include<stdio.h>

#define MAX_CHARACTERS 5 
#define MAX_ROWS 7 

const char *char_patterns[128][MAX_ROWS]= {
	['E'] = {
		"******",
		"*     ",
		"*     ",
		"******",
		"*     ",
		"*     ",
		"******"
	},
	['T'] = {
		"*******",
		"   *   ",
		"   *   ",
		"   *   ",
		"   *   ",
		"   *   ",
		"   *   "
	},
	['A'] = {
		" ***** ",
		"*     *",
		"*     *",
		"*******",
		"*     *",
		"*     *",
		"*     *"
	},
	['I'] = {
		" ***** ",
		"   *   ",
		"   *   ",
		"   *   ",
		"   *   ",
		"   *   ",
		" ***** "
	},
	['S'] = {
		" *****",
		"*     ",
		"*     ",
		" **** ",
		"     *",
		"     *",
		"*****"
	}
};


void print_pattern(const char *input) {
	int i, j;
	int length = 0;

	while (input[length] != '\0' && length < MAX_CHARACTERS) {
		length++;
	}


	for (j = 0; j < MAX_ROWS; j++) {
		for (i = 0; i < length; i++) {
			char c = input[i];
			if (char_patterns[(int)c][j] != NULL) {
			printf("%s", char_patterns[(int)c][j]);
			} else {
				printf("       "); 
			}
			if (i < length - 1) {
				printf("   ");
			}
		}

		printf("\n");
	}
}

int main() {
	char input[MAX_CHARACTERS + 1];
    
	printf("请输入字符（字符数少于5个）：");
	scanf("%s", input);

	print_pattern(input);
    
	return 0;
}
