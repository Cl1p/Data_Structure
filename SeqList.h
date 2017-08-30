typedef struct//创建结构体
{
	DataType list[MaxSize];
	int size;
}SeqList;

void ListInitiate(SeqList *L)//初始化
{
	L->size =0;
}

int ListLength(SeqList L)//返回当前元素个数
{
	return L.size;
}

int ListInsert(SeqList *L, int i, DataType x)//在第i位向前插入x
{
	int j;
	if(L->size >= MaxSize)
	{
		printf("顺序表当前已满无法插入！");
		return 0;//失败
	}
	else if(i <0 || i > L->size)
	{
		printf("参数i不合法！");
		return 0;//
	}
	else
	{
		for(j =L->size;j >i;j--) L->list[j] = L->list[j-1];
		L->list[i] =x;
		L->size++;
		return 1;//成功
	}
}

int ListDelete(SeqList *L, int i, DataType *x)//删除第i位元素
{
	int j;
	if(L->size <=0)
	{
		printf("顺序表已无空数据元素可删！\n");
		return 0;
	}
	else if(i <0 || i >L->size-1)
	{
		printf("参数i不合法");
		return 0;
	}
	else
	{
		*x = L->list[i];
		for(j =i+ 1;j <=L->size-1;j++) L->list[j-1] =L->list[j];
		L->size--;//数据元素个数减1
		return 1;
	}
}

int ListGet(SeqList L,int i,DataType *x)
{
	if(i <0 || i >L.size-1)
	{
		printf("参数i不合法！\n");
		return 0;
	}
	else
	{
		*x =L.list[i];
		return 1;
	}
}