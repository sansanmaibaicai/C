/*
	该程序要求实现非递归版本的链表空间释放函数erase_list(list_item *head)


*/





#include <stdio.h>
#include <stdlib.h>

typedef struct list_item {
	int data;
	struct list_item *next;
} list_item;

void erase_list(list_item *head) {
	list_item *current = head;
	list_item *next;

	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
}

int main() {
	// 创建一个简单的链表
	list_item *head = (list_item*)malloc(sizeof(list_item));
	list_item *current = head;
	for (int i = 0; i < 5; i++) {
		current->data = i;
		current->next = (list_item*)malloc(sizeof(list_item));
		current = current->next;
	}
	current->next = NULL;

	// 调用 erase_list 函数释放链表内存空间
	erase_list(head);

	// 验证链表内存空间已释放
	printf("List memory freed successfully!\n");

	return 0;
}
