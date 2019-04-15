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
int push(o4er *o, node *n)
{	node_o4er *new_node_o4er = malloc(sizeof(node_o4er));
	new_node_o4er->s_node_tree = n;
	new_node_o4er->next = NULL;
	if (o->head) o->tail->next = new_node_o4er;
	else o->head = new_node_o4er;
	o->tail = new_node_o4er;
	return 0;}
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
int removeMin(tree *t,node *r)
{	while(r->lef!=NULL) r=r->lef;
	if (r->right)
	{	r->right->pred=r->pred;
		if (r!=t->root) r->pred->lef=r->right;
		else t->root=r->right;
	}
	else if (t->kol > 1)
	{	r->pred->lef=NULL;}
	else
	{	t->root = NULL;
		free(t->root);
		t->kol--;
		return 0;}
	int k=r->value;
	free(r);
	t->kol--;
	return k;}
void clear(tree *t)
{	while (t->root) removeMin(t,t->root);}

int removeT(tree *t, int x)
{	node *s = t->root;
    	while (s->value != x)
    	{	if (x < s->value)
		s = s->lef;
		else if (x > s->value)
    		s = s->right;}
    	if (s == NULL) return 1;
    	if (s->lef == NULL && s->right == NULL)
    	{	if (s->pred->value > x)
    		s->pred->lef = NULL;
    		else s->pred->right = NULL;
    		free(s);}
   	else if (s->lef != NULL && s->right == NULL)
    	{	s->lef->pred = s->pred;
    		if (s->pred->value > x) s->pred->lef = s->lef;
    		else s->pred->right = s->lef;
    		free(s);}
    	else if (s->lef == NULL && s->right != NULL)
    	{	s->right->pred = s->pred;
    		if (s->pred->value > x) s->pred->lef = s->right;
    		else s->pred->right = s->right;
    		free(s);}
    	else if (s->lef != NULL && s->right != NULL)
    	{	node *p = s->right;
    		if (p->lef == NULL)
    		{	s->value = p->value;
    			if (p->right == NULL)
    			{	s->right = NULL;
   				free(s->right);}
 			else
    			{	s->right = s->right->right;
				p->right->pred = s;
    				free(p);}
    		}
    		else
   		{	while(p->lef) p = p->lef;
    			s->value = p->value;
    			if (p->right)
    			{	s->value = p->value;
   				p->value = p->right->value;
    				s->right = NULL;
    				free(p->right);}
   			else
   			{	s->value = p->value;
    				p->pred->lef = NULL;
    				free(p);}
    		}
    	}
t->kol--;
return 0;}

int find(tree *t, int x, node **r)
{	node *s=t->root;
	while(s)
	{	if (x<s->value) s=s->lef;
		else if (x>s->value) s=s->right;
		     else { *r=s; return 0;}
	}
	*r=s;
	return 1;
}

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
{	if (n)
	{
	o4er o1,o2;
	o4er *l_o1 = &o1;
	o4er *l_o2 = &o2;
	init_o4er(l_o1);
	init_o4er(l_o2);
	node *c = NULL;
	node_o4er *o = NULL;
	int q = 0, x = n->value, w = 0;
	node *e = n->lef;
	node *r = n->right;
	push(l_o1, n);
	while(1)
	{
	while(l_o1->head)
	{c = p(l_o1);
	if(l_o1->head == NULL)
		{ if ((c->value == x) && (q == 1)) printf("_\n");
		else printf("%d\n", c->value);}
	else {if((c->value == x) && (q == 1)) printf("_ ");
		else printf("%d ", c->value);}
	if (c->lef) push(l_o2, c->lef);
	else push(l_o2, n);
	if (c->right) push(l_o2,c->right);
	else push(l_o2, n);}
	n->lef =NULL;
	n->right = NULL;
	q = 1;
	o = l_o2->head;
	while(l_o2->head->s_node_tree->value == x)
		{ l_o2->head = l_o2->head->next;
		if(l_o2->head->next == NULL)
		if(l_o2->head->s_node_tree->value == x)
		{ 	w = 1;
			n->lef = e;
			n->right = r;
			clear_o4er(l_o2);
			break;}
	}
		l_o2->head = o;
		if(w == 1) break;
		l_o1->head = l_o2->head;
		l_o1->tail = l_o2->tail;
		l_o2->head = NULL;
		l_o2->tail = NULL;}}
	else printf("-\n");
}
int printTree(tree *t)
{	print(t->root);}

int rotRight(node **n)
{	node *s=(*n)->lef;
	if (s==NULL) return 1;
	(*n)->lef=s->right;
	s->right=*n;
	s->pred=(*n)->pred;
	(*n)->pred=s;
	*n=s;
	return 0;}

int rotLef(node **n)
{	node *s=(*n)->right;
	if (s==NULL) return 1;
	(*n)->right=s->lef;
	s->lef=*n;
	s->pred=(*n)->pred;
	(*n)->pred=s;
	*n=s;
	return 0;}	

int main()
{	int i,a,j;
	tree t;
	init(&t);
	for (i=0;i<4;i++)
	{	scanf("%d",&a);
		insert(&t,a);}
	printTree(&t);
	
	for (i=0;i<3;i++)
	{	scanf("%d",&a);
		insert(&t,a);}
	printTree(&t);
	
	for (i=0;i<2;i++)
	{	scanf("%d",&a);
		node *n=NULL;
		j=find(&t,a,&n);
		if (j==0)
		{if (n->pred) printf("%d ",n->pred->value);
		 else printf("_ ");
		 if (n->lef) printf("%d ",n->lef->value);
		 else printf("_ ");
		 if (n->right) printf("%d\n",n->right->value);
		 else printf("_\n");
		}
		else printf("_\n");
	}

	scanf("%d",&a);
	removeT(&t,a);
	printTree(&t);

	while (rotLef(&t.root)==0){;}
	printTree(&t);
	while (rotRight(&t.root)==0){;}
	printTree(&t);
	printf("%d\n",(t.kol));
	clear(&t);
	printTree(&t);
return 0;}
