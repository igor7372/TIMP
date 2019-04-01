#include <stdio.h>
#include <stdlib.h>
typedef struct node
{ 	int value;
	struct node *next;
	struct node *prev;
}node;
typedef struct
{	node *head;
	node *tail;
}list;

void init(list *l)
{	l->head=NULL;
	l->tail=NULL;}

void clear(list *l)
{	node *t1=l->head;
	node *t2;
	while (t1)
	{t2=t1->next;
	 free(t1);
	 t1=t2;}
	l->head=NULL;
	l->tail=NULL;
}

int isEmpty(list *l)
{	return((l->head==NULL)&&(l->tail==NULL));}

node* find(list *l, int x)
{	node *t=l->head;
	while(t)
	{	if(t->value==x) return t;
		t=t->next;
	}
	return NULL;}

int push_back(list* l, int x)
{	node *t=malloc(sizeof(node));
	t->value=x;
	if (isEmpty(l))
	{ t->next=NULL;
	  t->prev=NULL;
	  l->head=t;
	  l->tail=t;}
	else {  l->tail->next=t;
		t->next=NULL;
		t->prev=l->tail;
		l->tail=t;}
	return 0;}
  
int push_front(list *l, int x)
{	node *t;
	t=malloc(sizeof(node));
	t->value=x;
	l->head->prev=t;
	t->next=l->head;
	l->head=t;
	t->prev=NULL;
	return 0;}


int insertAfter(list *l,int x,int n)
{	node *s=l->head;
	node *p;
	int r;
	for(r=0;r<n;r++)
	{ p=s;
	  s=s->next;}
	node *t=malloc(sizeof(node));
	t->value=x;
	p->next=t;
	t->prev=p;
	if (s) {t->next=s; s->prev=t;}
	else {t->next=NULL; l->tail=t;}
	return 0;}

int insertBefore(list *l,int x,int n)
{	node *s=l->head;
	node *p;
	int r;
	for(r=0;r<n-1;r++)
	{ p=s;
	  s=s->next;}
	node *t=malloc(sizeof(node));
	t->value=x;
	p->next=t;
	t->prev=p;
	if (p) {t->next=s; s->prev=t;p->next=t; t->prev=p;}
	else {t->prev=NULL;t->next=s; s->prev=t; l->head=t;}
	return 0;}

int removeFirst(list *l, int x)
{	node *t=l->head;
	node *p;
	while((t!=NULL)&&(t->value!=x))
	{ p=t;
	  t=t->next;}
	if (t)
	{if(t==l->head) {l->head=l->head->next; l->head->prev=NULL;}
	 else if (t==l->tail) {l->tail=l->tail->prev; l->tail->next=NULL;}
		else {p->next=t->next; t->next->prev=p;}
	 free(t);}
	return 0;}

int removeLast(list *l, int x)
{	node *t=l->tail;
	node *p;
	while((t!=NULL)&&(t->value!=x))
	{ p=t;
	  t=t->prev;}
	if (t)
	{if(t==l->head) {l->head=l->head->next; l->head->prev=NULL;}
	 else if (t==l->tail) {l->tail=l->tail->prev; l->tail->next=NULL;}
		else {p->next=t->next; t->next->prev=p;}
	 free(t);}
	return 0;}

void print(list *l)
{	node *t=l->head;
	while (t)
	{ printf("%d ",t->value);
	  t=t->next;}
	printf("\n");}

void print_invers(list *l)
{	node *t=l->tail;
	while (t)
	{ printf("%d ",t->value);
	  t=t->prev;}
	printf("\n");}

int main()
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
	print_invers(&l);

	scanf("%d", &k);
	push_front(&l,k);
	print(&l);

	scanf("%d %d", &k,&n);
	insertAfter(&l,k,n);
	print_invers(&l);

	scanf("%d %d", &k,&n);
	insertBefore(&l,k,n);
	print(&l);

	scanf("%d", &k);
	removeFirst(&l,k);
	print_invers(&l);

	scanf("%d", &k);
	removeLast(&l,k);
	print(&l);

	clear(&l);
	return 0;}
