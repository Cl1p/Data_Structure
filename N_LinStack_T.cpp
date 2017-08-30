#include <stdio.h>
#include<malloc.h>
typedef int DataType;
#include "N_LinStack.h"

void main(void)
{
	LSNode *head;
	int x;

	StackInitiate(&head);
	for (int i = 0; i < 10; i++)
		StackPush(&head, i + 1);
	StackTop(head, &x);
	printf("当前栈顶元素为：%d\n", x);
	printf("依次出栈的元素，顺序如下");
	while (StackNotEmpty(head))
	{
		StackPop(&head, &x);
		printf("%d ", x);
	}
	getchar();
}