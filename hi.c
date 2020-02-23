#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node* next;
};

void printList(struct Node* node){
	while(node != NULL)
	{
		printf(" %d ", node->data);
		node = node->next;
	}
}

void deleteNode(struct Node** node, int target)
{
	struct Node* temp = *node, *previousNode;
	if(temp != NULL && temp->data == target)
	{
		*node = temp->next;
		free(temp);
		return;
	}
	while(temp != NULL && temp->data != target)
	{
		previousNode = temp;
		temp = temp->next;
	}
	
	if(temp == NULL)
	{
		return;
	}
	
	previousNode->next = temp->next;
	free(temp);
}

int main()
{
	
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;
	
	head	= (struct Node*)malloc(sizeof(struct Node));
	second	= (struct Node*)malloc(sizeof(struct Node));
	third	= (struct Node*)malloc(sizeof(struct Node));
	
	head->data = 1;
	head->next = second;
	second->data = 2;
	second->next = third;
	third->data = 3;
	third->next = NULL; 
	
	printList(head);

	
	return 0;
}
