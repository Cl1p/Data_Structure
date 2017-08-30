#pragma once
typedef struct snode// 结构体定义
{
	DataType data;
	struct snode *next;
}LSNode;

void StackInitiate(LSNode **head)//初始化
{
	*head = NULL;
}

int StackNotEmpty(LSNode *head)//检查非空否
{
	if (head == NULL) return 0;
	else return 1;
}

void StackPush(LSNode **head, DataType x)//入栈
{
	LSNode *p;
	p = (LSNode *)malloc(sizeof(LSNode));
	p->data = x;
	p->next = *head;      //新节点链入栈顶
	*head = p;                          //新的栈顶
}

int StackPop(LSNode **head, DataType *d)//出栈
{
	LSNode *p = *head;
	if (p == NULL)
	{
		printf("堆栈已空出错！");
		return 0;
	}
	*head = p->next;//删除原栈顶结点
	*d = p->data;        //原栈顶结点元素赋予d
	free(p);                                //释放原栈顶内存空间
	return 0;
}

int StackTop(LSNode *head, DataType *d)//栈顶取值
{
	LSNode *p = head;
	if (p == NULL)
	{
		printf("栈顶已空出错！");
		return 0;
	}
	*d = p->data;
	return 1;
}

void Destory(LSNode **head)//撤销堆栈
{
	LSNode *p, *p1;
	p = *head;
	while (p != NULL)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
}