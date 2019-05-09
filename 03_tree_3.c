#include <stdio.h>
#include <stdlib.h>
typedef struct node
{	int value;
	struct node *lef,*right, *pred;
}node;
typedef struct
{	struct node *root;
	int kol;
}tree;

void init(tree *t)
{	t->root=NULL;
	t->kol=0;}
int insert(tree *t, int x)
{	node *s=malloc(sizeof(node));
	if (s==NULL) return 2;
	node *z=t->root;
	node *c=NULL;
if(z)
{	while(z)
	{	if (x>z->value)
		{ c=z; z=z->right;}
		else if (x<z->value)
		{ c=z; z=z->lef; }
		else return 1;
	}
	s->value=x;
	s->lef=NULL;
	s->right=NULL;
	s->pred=c;
	if (s->value>c->value) c->right=s;
	else c->lef=s;
	t->kol++;
	return 0;}
else
{	t->root=s;
	t->root->value=x;
	t->root->pred=NULL;
	t->root->lef=NULL;
	t->root->right=NULL;
	t->kol++;
	return 0;}
}
void print(node *n)
{	if(n)
	{	
		print(n->lef);
		print(n->right);
		if (n->pred) printf("%d ",n->value);
		else printf("%d",n->value);
	}
}
int main()
{	int x,i;
	tree t;
	init(&t);
	for (i=0;i<7;i++)
	{	scanf("%d", &x);
		insert(&t, x);}
	print(t.root);
	printf("\n");
return 0;}
