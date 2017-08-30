
typedef struct Node//节点结构体定义
{
	DataType data;
	struct Node *leftChild;
	struct Node*rightChild;
}BiTreeNode;

void Initiate(BiTreeNode **root)//初始化头节点
{
	*root = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	(*root)->leftChild = NULL;
	(*root)->rightChild = NULL;
}

BiTreeNode *InsertLeftNode(BiTreeNode *curr, DataType x)//左插入结点
{
	BiTreeNode * s, *t;
	if (curr == NULL)
		return NULL;
	t = curr->leftChild;                          //保存原curr所指结点的左子树
	s = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	s->data = x;
	s->leftChild = t;                            //新插入的结点的左子树为原curr的
	s->rightChild = NULL;
	curr->leftChild = s;                         //新结点成为curr的左子树

	return curr->leftChild;
}

BiTreeNode *InsertRightNode(BiTreeNode *curr, DataType x)
{
	BiTreeNode * s, *t;
	if (curr == NULL)
		return NULL;
	t = curr->rightChild;
	s = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	s->data = x;
	s->rightChild = t;
	s->leftChild = NULL;
	curr->rightChild = s;

	return curr->rightChild;
}

void Destroy(BiTreeNode **root)//撤销结点二叉树
{
	if ((*root) != NULL && (*root)->leftChild != NULL)
		Destroy(&(*root)->leftChild);
	if ((*root) != NULL && (*root)->rightChild != NULL)
		Destroy(&(*root)->rightChild);
	free(*root);
}

BiTreeNode *DeleteLeftTree(BiTreeNode *curr)//左删除子树
{
	if (curr == NULL || curr->leftChild == NULL)
		return NULL;                            //若curr为空，删除失败，返回空指针
	Destroy(&curr->leftChild);                  //非空，则删除curr所指结点的左子树
	curr->leftChild = NULL;

	return curr;                                //若删除成功，则返回删除结点的双亲结点指针
}

BiTreeNode *DeleteRightTree(BiTreeNode *curr)
{
	if (curr == NULL || curr->rightChild == NULL)
		return NULL;
	Destroy(&curr->rightChild);
	curr->rightChild = NULL;

	return curr;
}

void PrintBiTree(BiTreeNode *root, int n)//逆时针90度打印二叉树root，n为缩进层数，初始值为0
{
	int i;
	if (root == NULL)
		return;                                 //递归出口
	PrintBiTree(root->rightChild, n + 1);          //访问根结点
	for (i = 0; i <n - 1; i++) printf("\t");
	if (n >0)
	{
		printf("---");
		printf("%c\n", root->data);
	}

	PrintBiTree(root->leftChild, n + 1);           //
}

BiTreeNode *Search(BiTreeNode *root, DataType x)//检查数据元素x是否存在，是则返回该结点指针
{
	BiTreeNode *find = NULL;
	if (root != NULL)
	{
		if (root->data == x)
			find = root;                         //标记查找成功
		else
		{
			find = Search(root->leftChild, x);    //在左子树中找
			if (find == NULL)
				find = Search(root->rightChild, x); //在右子树中找
		}
	}
	return find;
}
