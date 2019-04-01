#include <stdio.h>
#include <stdlib.h>
typedef struct node
{	int value;
	struct node *next;}node;
typedef struct
{node *head;}list;

void init(list *l)
{	l->head=NULL;}

void clear(list *l)
{	node *t=l->head;
	node *c;
	while (t)
	{	c=t->next;
		free(t);
		t=c;
	}
	l->head=NULL;}

int isEmpty(list *l)
{	return (l->head==NULL);}

node* find(list *l, int x)
{	node *t=l->head;
	while(t)
	{	if(t->value==x) return t;
		t=t->next;
	}
	return NULL;}

int push_back(list *l, int x)
{	node *t=l->head;
	if (t==NULL)
	{	t=malloc(sizeof(node));
		t->value=x;
		t->next=NULL;
		l->head=t;
		return 0;}
	while (t->next) {t=t->next;}
	t->next=malloc(sizeof(node));
	t->next->value=x;
	t->next->next=NULL;
	return 0;}

int push_front(list *l, int x)
{	node *t;
	t=malloc(sizeof(node));
	t->value=x;
	t->next=l->head;
	l->head=t;
	return 0;}

int insertAfter(list* l, int x,int n)
{	node *s=l->head;
	node *p;
	int r;
	for(r=0;r<n;r++)
	{ p=s;
	  s=s->next;}
	node *t=malloc(sizeof(node));
	t->value=x;
	p->next=t;
	if (s) t->next=s;
	else t->next=NULL;
	return 0;}

int removee(list *l, int x)
{	node *t=l->head;
	node *p;
	while((t!=NULL)&&(t->value!=x))
	{ p=t;
	  t=t->next;}
	if (t)
	{if(t==l->head) l->head=l->head->next;
	 else p->next=t->next;
	 free(t);}
	return 0;}

void print(list *l)
{	node *t=l->head;
	while (t)
	{	printf("%d ",t->value);
		t=t->next;
	}
	printf("\n");}

int main ()
{	int i,k,n;
	list l;
	init(&l);
	scanf("%d", &n);
	for (i=0;i<n;i++)
	{	scanf("%d", &k);
		push_back(&l,k);}
	print(&l);
	int a[3];
	for(i=0;i<3;i++) scanf("%d",&a[i]);
	for(i=0;i<3;i++)
	{ if(find(&l,a[i])) printf("1");
	  else printf("0");}
	printf("\n");
	scanf("%d", &k);
	push_back(&l,k);
	print(&l);
	scanf("%d", &k);
	push_front(&l,k);
	print(&l);
	scanf("%d %d", &k,&n);
	insertAfter(&l,k,n);
	print(&l);
	scanf("%d", &k);
	removee(&l,k);
	print(&l);
	clear(&l);
	return 0;}
