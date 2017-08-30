#include <stdio.h>
#include<malloc.h>
typedef int DataType;
#include "N_LinList.h"

void main(void)
{
	SLNode * head;
	int i, x;

	ListInitiate(&head);
	printf("\n初始化后\t%d\n",(int)head);

	for (i = 0; i < 10; i++)
		ListInsert(&head, i, i + 1);
	for (i = 0; i < ListLength(head); i++)
	{
		ListGet(head, i, &x);
		printf("%d\t", x);
	}
	printf("\n1次插入后\t%d\n", (int)head);
	ListDelete(&head, 0, &x);
	for (i = 0; i < ListLength(head); i++)
	{
		ListGet(head, i, &x);
		printf("%d\t", x);
	}
	printf("\n第1删除后\t%d\n", (int)head);
	ListInsert(&head, 0, 112);
	for (i = 0; i < ListLength(head); i++)
	{
		ListGet(head, i, &x);
		printf("%d\t", x);
	}
	printf("\n第1插入112后\t%d\n", (int)head);

	Destroy(&head);
	getchar();
}
