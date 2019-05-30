#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define MAXSIZE 100

int k = 0;
typedef char ElemType;

typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

BiTree CreateBiTree(BiTree &T) {
	char ch;
	scanf("%c", &ch);
	if (ch == ' ') T = NULL;
	else {
		if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) return ERROR;
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return T;
} // CreateBiTree

void INORDER(BiTree tree)
{
	if (tree)
	{
		INORDER(tree->lchild);
		printf("%c  ", tree->data);
		INORDER(tree->rchild);
	}
}

void inorder1(BiTree head)
{
	struct BiTNode *p;
	struct BiTNode *stack[20];
	int top = NULL;
	p = head;
	while (p || top != NULL)
	{
		while (p)
		{
			stack[top++] = p;
			p = p->lchild;
		}
		p = stack[--top];
		printf("%c ", p->data);
		p = p->rchild;
	}
}

//二叉树的层次遍历
void LevelOrder(BiTree b)		
{
	BiTree p;
	BiTree qu[MAXSIZE];
	int front, rear;
	front = rear = -1;
	rear++;
	qu[rear] = b;
	while (front != rear)
	{
		front = (front + 1) % MAXSIZE;
		p = qu[front];
		printf("%c ", p->data);
		if (p->lchild != NULL)
		{
			rear = (rear + 1) % MAXSIZE;
			qu[rear] = p->lchild;
		}
		if (p->rchild != NULL)
		{
			rear = (rear + 1) % MAXSIZE;
			qu[rear] = p->rchild;
		}
	}
}

//比较两个数的大小
int max(int m, int n)		
{
	if (m > n)
		return m;
	else
		return n;
}

//求二叉树的高度
int TreeHeight(BiTree root)			
{
	if (root == NULL)
		return 0;
	else
		return 1 + max(TreeHeight(root->lchild), TreeHeight(root->rchild));
}

//求二叉树的结点个数
void inorder(BiTree T)		
{
	if (T != NULL){
		k++;
		inorder(T->lchild);
		inorder(T->rchild);
	}
}

//求二叉树的叶子个数
int leaf(BiTree T)		
{
	int n;
	if (!T) n = 0;
	else
	if (!T->lchild&&!T->rchild) n = 1;
	else n = leaf(T->lchild) + leaf(T->rchild);
	return (n);
}

void ExchangeLR(BiTree t)
{
	if (t == NULL)
		return;
	else {
		BiTree tmp = t->lchild;
		t->lchild = t->rchild;
		t->rchild = tmp;
		ExchangeLR(t->lchild);
		ExchangeLR(t->rchild);
	}
}

int main()
{
	BiTNode T;
	BiTree t;
	int n, j;
	t = &T;
	printf("1.建立二叉树\n");
	printf("2.二叉树的中序递归遍历\n");
	printf("3.二叉树的中序非递归遍历\n");
	printf("4.二叉树的层次遍历\n");
	printf("5.求二叉树的高度\n");
	printf("6.求二叉树的结点个数\n");
	printf("7.求二叉树的叶子个数\n");
	printf("8.交换二叉树每个结点的左子树和右子树\n");
	while (1){
		printf("请选择:");
		scanf("%d", &j);
		switch (j){
		case 1:CreateBiTree(t); break;
		case 2:INORDER(t); printf("\n"); break;
		case 3:inorder1(t); printf("\n"); break;
		case 4:LevelOrder(t); printf("\n"); break;
		case 5:n = TreeHeight(t);
			printf("该二叉树的高度为:%d\n", n - 1); break;
		case 6:inorder(t);
			printf("该二叉树的节点个数是:%d\n", k - 1); break;
		case 7:printf("该二叉树的叶子个数是:%d\n", leaf(t)); break;
		case 8:ExchangeLR(t);
			printf("交换完成!\n"); break;
		default:printf("输入有误,请重新选择!\n");
		}
	}
	system("pause");
	return 0;
}
