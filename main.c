#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct t_node{
	int value;
	struct t_node *next;
}Node;

typedef struct t_linkList{
	Node *head;
}LinkList;

void listInit(LinkList *list);
void listAddValue(LinkList *list, int v);
void listAddToTail(LinkList *list, Node *addNode);
void showListData(LinkList *list);

void listInit(LinkList *list)
{
	if(NULL == list)
		return;

	memset(list, 0, sizeof(LinkList));
}

void listAddValue(LinkList *list, int v)
{
	if(list == NULL)
		return;

	Node *node = NULL;
	node = (Node *) malloc(sizeof(Node));
	assert(node);

	node->value = v;

	listAddToTail(list, node);
	//listAddToHead(list, node);

}

void listAddToTail(LinkList *list, Node *addNode)
{
	if(NULL == list || NULL == addNode)
		return;

	Node *node = NULL;

	if(list->head == NULL)
	{
		list->head = addNode;
		list->head->next = NULL;	
		return;
	}

	for(node = list->head; node; node = node->next)
	{
		if(node->next == NULL)
		{
			node->next = addNode;
			addNode->next = NULL;	
			break;
		}
	}
}

void listAddToHead(LinkList *list, Node *addNode)
{
	if(NULL == list || NULL == addNode)
		return;

	if(list->head == NULL)
	{
		list->head = addNode;
		list->head->next = NULL;	
		return;
	}

	addNode->next = list->head->next;
	list->head->next = addNode;
}


void showListData(LinkList *list)
{
	if(NULL == list)
		return;

	Node *node = NULL;
	for(node = list->head; node; node = node->next)	
	{
		printf("%d\n", node->value);
	}
}

/**
 * 反转链表
 */
void reverseList(LinkList *list)
{
	if(NULL == list)
		return;

	Node *node = NULL;
	Node *last = NULL;
	Node *next = NULL;

	node = list->head->next;
	last = list->head;
	next = node->next;
	
	while(node->next)
	{
		node->next = last;

		last = node;
		node = next;
		next = node->next;
	}

	node->next = last;
	list->head->next = NULL;
	list->head = node;
}

int main()
{

	LinkList list;

	listInit(&list);

	listAddValue(&list, 1);
	listAddValue(&list, 3);
	listAddValue(&list, 5);
	listAddValue(&list, 7);
	listAddValue(&list, 9);

	showListData(&list);

	reverseList(&list);
	
	showListData(&list);
}
