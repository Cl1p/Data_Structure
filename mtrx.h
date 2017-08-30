//矩阵计算的头文件（行规范/行阶梯 转化与乘法(二元)运算）

//分配内存
int ** cvra(int R,int L)
{
	if(R >L)
	{
		int temp =L;
		L = R;R = temp;
	}
	int ** era = (int **)malloc(L *sizeof(int*)); 
    for(int n =0;n <L;n++)
    *(era+n) =  (int *)malloc(R *sizeof (int));

	for (int i = 0; i < R; i++)
		for (int j = 0; j < L; j++)
			era[i][j] = 0;

	return era;
}

//容错输入
int scan(void)
{
	int n;
	while(scanf("%d",&n) !=1)
	{
		printf("\n格式不对，再试一次\t");
		while(getchar() !='\n')
			continue;
	}

	return n;
}

//获取矩阵
int ** lsin(int R,int L)
{
    
    int **st = cvra(R,L); 
	
    for (int i =0;i <R;i++)
    {
        for (int j =0;j <L;j++)
        st[i][j] = scan();
    }
    return st;
}

//输出矩阵
void rint(int i)
{
    if (i >=0)
    printf(" %d\t",i);
    else
    printf("%d\t",i);
}

void lsot(int R,int L,int **st)
{
          printf("\n");
    for(int i =0;i <R;i++)
    {
        for(int j =0;j <L;j++)
        rint(st[i][j]);
        puts("\n");
    }
}

//指定排序
void sort(int S,int E,int l,int ** mtrx,int K)//大小方向K
{
	int * temp;
	for(int i =S-1;i <E;i++)
	for(int j =i+1;j <E;j++)
	{
                int L =l-1;
		while (mtrx[i][L] == mtrx[j][L])
		L++;
		if((K ==0)? abs(mtrx[i][L]) <abs(mtrx[j][L]):abs(mtrx[i][L]) >abs(mtrx[j][L]))
		{
			temp = mtrx[i];
			mtrx[i] =mtrx[j];
			mtrx[j] =temp;
		}
	}

}

//整行加减
void dsa(int ** mtrx,int r,int r2,int n,int  L)
{
    for(int i =0;i <L;i ++)
    mtrx[r][i] += n*mtrx[r2][i];
}

//加乘化简
void cvos(int S,int E,int l,int ** mtrx,int L)
{
	for(int i =S-1;i >E-1;i--)
	{
		if(mtrx[i][l-1] %mtrx[E-1][l-1] ==0)
			dsa(mtrx,i,E-1,-mtrx[i][l-1]/mtrx[E-1][l-1],L);
		else
		{
			dsa(mtrx,i,i,mtrx[E-1][l-1]-1,L);
			dsa(mtrx,i,E-1,-(mtrx[i][l-1]/mtrx[E-1][l-1]),L);
		}
	}
}
void cvos_n(int S,int E,int l,int ** mtrx,int L)
{
	for(int i =E-1;i <S-1;i++)
	{
		if(mtrx[i][l] !=0)
		{
			if(mtrx[S-1][l-1] %mtrx[i][l-1] ==0)
			{
				dsa(mtrx,i,i,mtrx[S-1][l-1]/mtrx[i][l-1]-1,L);
				dsa(mtrx,i,S-1,-1,L);
			}
			else
			{
				dsa(mtrx,i,i,mtrx[S-1][l-1]-1,L);
				dsa(mtrx,i,S-1,-mtrx[i][l-1]/mtrx[S-1][l-1],L);
			}
		}
	}
}

//阶梯列序
int esort(int R,int S,int ** mtrx,int l)
{
	int i;
		sort(S,R,l,mtrx,0);
		for(i =R-1;i >=0;i--)
			if(mtrx[i][l-1] !=0)
				break;
              //printf("\t0有%d个",R-i-1);
		sort(S,i+1,l,mtrx,1);
		sort(S+i+1,R,l,mtrx,1);
		return i+1;
}






//二元乘法
int ** caur(int **st2, int R2, int L2, int **st, int R, int L)
{
	int **rsut = cvra(R,L2);

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < L2; j++)
			for(int k =0;k < L;k++)
			rsut[i][j] += st[i][k] * st2[k][j];
	}
	return rsut;
}

//行阶梯化
void uain(int ** mtrx,int R,int L)
{
	int N,E =1;
	for(int l =1;l <=L;l++)
	{
		N =esort(R,E,mtrx,l);
		//lsot(R,L,mtrx);
		cvos(N,E,l,mtrx,L);
		//lsot(R,L,mtrx);
		E =esort(R,E,mtrx,l)+1;
	}
}

//行规范化
void usin(int ** mtrx,int R,int L)
{
	uain(mtrx,R,L);
	for(int i =R-1;i >0;i--)
		for(int j =0;j <L;j++)
			if(mtrx[i][j] !=0)
			{
				cvos_n(i+1,1,j+1,mtrx,L);
				break;
			}
}

//bug
/* 行规范化时
   1)预设为下层的数大于上层，条件为否时，会出现商为〇的情况   
   2)忽略了cvos_n函数，上层被除数为〇的情况
   
   行最简化时，商无法表示为分数
   1)设一个主元各行被%，能否全〇的计算入口条件
   2)使用可以用分数表示的，数据格式  

    乘法运算（二元）时，列为1*数据错误
	没有完成释放矩阵的步骤（#include <stdlib.h>/*用到molloc函数*/）
*/