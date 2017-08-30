typedef struct Node //结构体定义
{
	DataType data;
	struct Node *next;
}SLNode;

void ListInitiate(SLNode **head)//初始化
{
	*head = (SLNode *)malloc(sizeof(SLNode));
	(*head)->next = NULL;
}

int ListLength(SLNode *head)//求当前元素个数
{
	SLNode *p = head;
	int size = 0;

	while (p->next != NULL)
	{
		p = p->next;
		size++;
	}
	return size;
}

int ListInsert(SLNode *head, int i,DataType x)//在第i位插入新结点
{
	SLNode *p, *q;
	int j;
	
	p = head;
	j = -1;
	while (p->next != NULL && j < i - 1)//让指针P指向第i-1个结点
	{
		p = p->next;
		j++;
	}

	if (j != i - 1)
	{
		printf("插入元素位置参数错！");
		return 0;
	}

	q = (SLNode *)malloc(sizeof(SLNode));//生成新结点
	q->data = x;//新结点赋值
    
	q->next = p->next;//插入步骤1
	p->next = q;//插入步骤2
	return 1;
}

int ListDelete(SLNode *head, int i, DataType *x)//删除i结点，并存入指针x
{
	SLNode *p, *s;
	int j;
	p = head;
	j = -1;
	while (p->next != NULL && p->next->next != NULL && j < i - 1)
		//循环结束时指针p指向第i-1个结点
	{
		p = p->next;
		j++;
	}

	if (j != i - 1)
	{
		printf("删除元素位置参数错！");
		return 0;
	}

	s = p->next;//指针s指向i结点
	*x = s->data;//把指针s所指结点的数据域值赋予x
	p->next = p->next->next;//删除
	free(s);//释放指针s所指结点的内存空间
	return 1;
}

int ListGet(SLNode *head, int i, DataType *x)//获取i结点的数据元素
{
	SLNode *p;
	int j;
	p = head;
	j = -1;
	while (p->next != NULL && j < i)
	{
		p = p->next;
		j++;
	}

	if (j != i)
	{
		printf("取元素位置参数错！");
		return 0;
	}

	*x = p->data;
	return 1;
}

void Destroy(SLNode **head)//释放单链表SLNode
{
	SLNode *p, *p1;

	p = *head;
	while (p != NULL)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
	*head = NULL;
}
