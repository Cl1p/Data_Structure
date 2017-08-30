#include<stdlib.h>
#include<stdio.h>
typedef char DataType;
#include"BiTree.h"
int main(void)
{
	BiTreeNode * root, *p;
	Initiate(&root);

	p = InsertLeftNode(root, '1');
	p = InsertLeftNode(p, '2');
	p = InsertRightNode(root->leftChild, '3');
	InsertRightNode(p,'5');
	p = InsertLeftNode(p, '4');
	InsertLeftNode(p, '6');

	PrintBiTree(root, 0);getchar();

	return 0;
}