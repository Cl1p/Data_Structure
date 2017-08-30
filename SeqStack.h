#pragma once
typedef struct //结构体定义
{
	DataType stack[MaxStackSize];
	int top;
}SeqStack;

void StackInitiate(SeqStack *S)//初始化
{
	S->top = 0;
}

int StackNotEmpty(SeqStack S)//检查非空否
{
	if (S.top <= 0)  return 0;
	else return 1;
}

int StackPush(SeqStack *S, DataType x)//入栈
{
	if (S->top >= MaxStackSize)//把数据元素值x存入堆栈S中，入栈成功返回 1，否则返回 0
	{
		printf("堆栈已满无法插入！\n");
		return 0;
	}
	else
	{
		S->stack[S->top] = x;
		S->top++;
		return 1;
	}
}

int StackPop(SeqStack *S, DataType *d)//出栈
{
	if (S->top <= 0)//取出堆栈S栈顶值,并由参数d带回，出栈成功返回1，否则返回0
	{
		printf("堆栈已空无数据出栈！\n");
		return 0;
	}
	else
	{
		S->top--;
		*d = S->stack[S->top];
		return 1;
	}
}

int StackTop(SeqStack S, DataType *d)
{
	if (S.top <= 0)//取得 堆栈S栈顶值，并由参数d带回，成功返回1，否则返回0
	{
		printf("堆栈已空！\n");
		return 0;
	}
	else
	{
		*d = S.stack[S.top-1];
		return 1;
	}
}