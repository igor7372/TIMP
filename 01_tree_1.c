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

//очередь
typedef struct node_o4er
{	node *s_node_tree;
	struct node_o4er *next;	
}node_o4er;
typedef struct o4er
{	node_o4er *head;
	node_o4er *tail;
}o4er;
void init_o4er(o4er *o)
{	o->head=NULL;
	o->tail=NULL;}
void push(o4er *o, node *n)
{	node_o4er *new_node_o4er = malloc(sizeof(node_o4er));
	new_node_o4er->s_node_tree = n;
	if (o->head) 
	{	o->tail->next = new_node_o4er;
		new_node_o4er->next=NULL;
		o->tail=new_node_o4er;}
	else 
	{	o->head = new_node_o4er;
		o->tail = new_node_o4er;
		new_node_o4er=NULL;}
}
node *p(o4er *o)
{	if (o->head)
	{	node_o4er *node_o4er_p;
		node *l = NULL;
		l = o->head->s_node_tree;
		node_o4er_p = o->head;
		o->head = o->head->next;
		if (o->head == NULL)
		o->tail = NULL;
		free(node_o4er_p);
		return l;}
	else return NULL;}
void clear_o4er(o4er *o)
{	node_o4er *l, *ln;
	l = o->head;
	do
	{	ln = l;
		l = l->next;
		free(ln);}
	while(l);
	o->head = NULL;
	o->tail = NULL;}
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
	{	o4er o;
		init_o4er(&o);
		push(&o, n);
		while (o.head)
		{	node *s=p(&o);
			if (s->lef) push(&o, s->lef);
			if (s->right) push(&o, s->right);
			if (o.head==NULL) printf("%d", s->value);
			else printf("%d ",s->value);
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



