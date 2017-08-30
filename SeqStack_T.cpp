#include<stdio.h>
#define MaxStackSize 100
typedef int DataType;
#include "SeqStack.h"

void main(void)
{
	SeqStack myStack;
	int x;

	StackInitiate(&myStack);
	for (int i = 0; i < 10; i++)
		StackPush(&myStack, i + 1);
	StackTop(myStack, &x);
	printf("当前栈顶元素为：%d\n", x);
	printf("依次出栈的元素，顺序如下");
	while (StackNotEmpty(myStack))
	{
		StackPop(&myStack, &x);
		printf("%d ", x);
	}
	getchar();
}