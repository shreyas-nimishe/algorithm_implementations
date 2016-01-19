#include<bits/stdc++.h>
using namespace std;
/*
	This Program creates a double ended queue i.e a doubly linked list having both forward and backward pointers.
	Deque can serve as both a queue and stack. It however takes a little more memory since it has an extra pointer.
*/
struct node {
	int data;
	struct node *next, *prev;
};

struct deque_node {
	struct node *front, *rear;
};

struct node *createnode() {
	struct node *temp = (struct node *)malloc(sizeof(node));
	temp->data = 0;
	temp->next = temp->prev = NULL;
	return temp;
}

struct deque_node *createdeque() {
	struct deque_node *temp = (struct deque_node*)malloc(sizeof(deque_node));
	temp->front = temp->rear = NULL;
	return temp;
}

void push_front(struct deque_node **deq, int key) {
	struct node *temp = createnode();
	temp->data = key;

	if((*deq)->front == NULL){
		(*deq)->front = (*deq)->rear = temp;
		return;
	}

	temp->next = (*deq)->front;
	(*deq)->front->prev = temp;

	(*deq)->front = temp;
}

void push_rear(struct deque_node **deq, int key) {
	struct node *temp = createnode();
	temp->data = key;

	if((*deq)->rear == NULL) {
		(*deq)->front = (*deq)->rear = NULL;
		return;
	}

	temp->prev = (*deq)->rear;
	(*deq)->rear->next = temp;

	(*deq)->rear = temp;
}

bool isempty(struct deque_node **deq) {
	return (*deq)->front == NULL;
}

int top_front(struct deque_node **deq) {
	return (*deq)->front == NULL ? 0 : (*deq)->front->data;
}

int top_rear(struct deque_node **deq) {
	return (*deq)->rear == NULL ? 0 : (*deq)->rear->data;
}

void pop_front(struct deque_node **deq) {
	if((*deq)->front == NULL)		return;			// Empty Deque

	struct node *temp = (*deq)->front;

	if((*deq)->front == (*deq)->rear) {
		// Contains only one element
		(*deq)->front = (*deq)->rear = NULL;
		free(temp);
		return;
	}

	temp->next->prev = NULL;
	(*deq)->front = (*deq)->front->next;
	free(temp);
}

void pop_rear(struct deque_node **deq) {
	if((*deq)->rear == NULL)		return; 		// Empty Deque

	struct node *temp = (*deq)->rear;

	if((*deq)->front == (*deq)->rear) {
		(*deq)->front = (*deq)->rear = NULL;
		free(temp);
		return;
	}

	temp->prev->next = NULL;
	(*deq)->rear = (*deq)->rear->prev;
	free(temp);
}

void printdeque(struct deque_node **deq) {
	struct node *temp = (*deq)->front;
	printf("Deque => ");
	while(temp != NULL) {
		printf("%d ",temp->data );
		temp = temp->next;
	}
	printf("\n");
}
int main() {
	struct deque_node *mydeq = createdeque();
	printf("This Program Creates a double ended queue\n");
	printf("isempty = %d\n",isempty(&mydeq));
	printdeque(&mydeq);
	pop_rear(&mydeq);
	pop_front(&mydeq);
	push_front(&mydeq, 78);
	printf("Inserted 78 in deque from front\nPoping rear\n");
	pop_rear(&mydeq);
	push_front(&mydeq, 56);
	push_front(&mydeq, 12);
	push_front(&mydeq, 33);
	push_front(& mydeq, 4);

	printf("Pushed 56, 12, 33 & 4 from front\nfrontmost element = %d\nlast element = %d\n", top_front(&mydeq), top_rear(&mydeq) );
	printdeque(&mydeq);
	pop_rear(&mydeq);
	printf("Poping rear element\n");
	printf("\nfrontmost element = %d, last element = %d\n", top_front(&mydeq), top_rear(&mydeq) );
	printdeque(&mydeq);
	printf("isempty = %d\n",isempty(&mydeq) );

	return 0;
}
