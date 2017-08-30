using  DataType = int;
#include "Linlist.h"
#include<stdlib.h>

void Trans_Bits(int d)
{
	if (d == 0)
	{
		cout << d;
		return;
	}
		
	LSNode * stac;
	StackInitiate(&stac);//初始化
	while (d != 0)
	{
		StackPush(stac, d % 2);
		d /= 2;
	}
	int t;
	while (StackNotEmpty(stac))
	{
		StackPop(stac, &t);
		cout << t;
	}
}