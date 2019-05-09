#include <stdio.h>
#include <stdlib.h>
typedef struct node
{	int value;
	struct node *lef,*right, *pred;
}node;
typedef struct
{	node *root;
	int kol;
}tree;

//стек
typedef struct stack_node
{	node *s_node_tree;
	struct stack_node *next;	
}stack_node;
typedef struct 
{	stack_node *top;
}stack;
void init_stack(stack *s)
{	s->top=NULL;}
void push(stack *s, node *n)
{	stack_node *new_stack_node = malloc(sizeof(stack_node));
	new_stack_node->s_node_tree = n;
	if (s->top) 
	{	new_stack_node->next=s->top;
		s->top=new_stack_node;}
	else 
	{	s->top=new_stack_node;
		new_stack_node->next=NULL;}
}
node *p(stack *s)
{	if (s->top)
	{	stack_node *stack_node_p;
		node *l = NULL;
		stack_node_p = s->top;
		l = s->top->s_node_tree;
		s->top = s->top->next;
		free(stack_node_p);
		return l;}
	else return NULL;}

//дерево
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
	{	stack s;
		init_stack(&s);
		push(&s, n);
		while (s.top)
		{	node *o=p(&s);
			if (o->right) push(&s, o->right);
			if (o->lef) push(&s, o->lef);
			if (s.top==NULL) printf("%d", o->value);
			else printf("%d ",o->value);
			}
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
