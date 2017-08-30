#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
#include "LinList.h"
int scan(void);
int getL(SLNode *head, int n);
void show(SLNode *head,int S);
void ListMerge(SLNode *L1,SLNode *L2,SLNode *L3);
void main()
{
	SLNode *L1;SLNode *L2;SLNode *L3;

	ListInitiate(&L1);ListInitiate(&L2);ListInitiate(&L3);

	int t;
	printf("\n请输入L1所含元素个数：");
	int S1 =scan();
	printf("\n请输入L1：");

	for(int i =0;i <S1;i++)
	{
		t =scan();
		ListInsert(L1,i,t);
	}

	printf("\n\n\n\n请输入L2所含元素个数：");
	int S2 =scan();
	
	printf("\n请输入L2：");
	for(i =0;i <S2;i++)
	{
		t =scan();
		ListInsert(L2,i,t);
	}
	ListMerge(L1,L2,L3);
	show(L3,ListLength(L1)+ListLength(L2));
}
void show(SLNode *head,int S)
{
	int x;
	for(int i=0;i <S;i++)
	{
		ListGet(head,i,&x);
		printf("%d\t",x);
	}
	putchar('\n');
}
int scan(void)
{
	int n;
	while(scanf("%d",&n) !=1)
	{
		printf("\n格式错误！再试一次");
		while(getchar() !='\n')
			continue;
	}

	return n;
}
int getL(SLNode *head, int n)
{
	int x;

	ListGet(head,n,&x);	
	return x;
}
void ListMerge(SLNode *L1,SLNode *L2,SLNode *L3)
{
	SLNode * Le, *Mo;
	Le =L1; Mo =L2;
	int x,M =ListLength(L2),L =ListLength(L1),i =0,j =0,k =0;
	if(ListLength(L2) <L)
	{
		L =ListLength(L2);
		M =ListLength(L1);
		Le =L2;
		Mo =L1;
	}

	if(getL(Le,ListLength(Le)-1) <=getL(Mo,ListLength(Mo)-1))
	{
		while((i <L) && (j <L))
		{
			if(getL(L1,i) == getL(L2,j))
			{
				ListInsert(L3,k++,getL(L1,i++));
				ListInsert(L3,k++,getL(L2,j++));
			}
			else if(getL(L1,i) < getL(L2,j))
				ListInsert(L3,k++,getL(L1,i++));
			else if(getL(L1,i) > getL(L2,j))
				ListInsert(L3,k++,getL(L2,j++));
		}
		if(i == L)
			for(j =j;j <ListLength(L2);j++)
				ListInsert(L3,k++,getL(L2,j));
		else
			for(i =i;i <ListLength(L1);i++)
				ListInsert(L3,k++,getL(L1,i));
	}

	else if(getL(Le,ListLength(Le)-1) >getL(Mo,ListLength(Mo)-1))
	{
		while((i <M) && (j <M))
		{
			if(getL(L1,i) == getL(L2,j))
			{
				ListInsert(L3,k++,getL(L1,i++));
				ListInsert(L3,k++,getL(L2,j++));
			}
			else if(getL(L1,i) < getL(L2,j))
				ListInsert(L3,k++,getL(L1,i++));
			else if(getL(L1,i) > getL(L2,j))
				ListInsert(L3,k++,getL(L2,j++));
		}
		if(i == M)
			for(j =j;j <ListLength(L2);j++)
				ListInsert(L3,k++,getL(L2,j));
		else
			for(i =i;i <ListLength(L1);i++)
				ListInsert(L3,k++,getL(L1,i));
	}

	getchar();
}