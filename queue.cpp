#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node *next;
};

struct queue_node {
	struct node *front, *rear;
};

struct node *createnode() {
	struct node *temp = (struct node *)malloc(sizeof(node));
	temp->next = NULL;
	return temp;
}

struct queue_node *createqueue() {
	struct queue_node *temp = (struct queue_node *)malloc(sizeof(queue_node));
	temp->front = temp->rear = NULL;
	return temp;
}

void push(struct queue_node **q, int key) {
	struct node *new_node = createnode();
	new_node->data = key;

	if((*q)->front == NULL) {
		(*q)->front = (*q)->rear = new_node;
		return;
	}

	new_node->next = (*q)->front;
	(*q)->front = new_node;
}

int top(struct queue_node **q) {
	return (*q)->front == NULL ? 0 : (*q)->front->data;
}

void pop(struct queue_node **q) {
	if((*q)->front == NULL)			return;		// Empty queue

	struct node *temp = (*q)->front;


	(*q)->front = (*q)->front->next;
	free(temp);

	if((*q)->front == NULL)			(*q)->rear = NULL;
}

int main() {
	struct queue_node *que = createqueue();
	printf("Created an Queue\nPoping from an Empty Queue\n");
	pop(&que);

	printf("Pushing elements 34, 12, 45 in Queue\n");
	push(&que, 34);
	push(&que, 12);
	push(&que, 45);
	printf("Topmost element = %d\n",top(&que));
	printf("Poping three elements and then pushing 8 to the Queue\n");
	pop(&que);
	pop(&que);
	pop(&que);
	pop(&que);
	push(&que, 8);
	printf("Topmost element = %d\n",top(&que) );

	return 0;	
}