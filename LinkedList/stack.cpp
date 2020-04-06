#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node *next;
};

struct node *createnode() {
	struct node *temp = (struct node*)malloc(sizeof(node));
	temp->next = NULL;
	temp->data = 0;
	return temp;
}

void push(struct node **head_ref, int key) {
	struct node *new_node = createnode();
	new_node->data = key;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

int top(struct node **head_ref) {
	// double pointer not nessecery but used for the sake of consistency
	if((*head_ref) == NULL)		return 0;	
	else						return (*head_ref)->data;
}

bool isempty(struct node **head_ref) {
	return (*head_ref) == NULL;
}

void pop(struct node **head_ref) {
	struct node *new_node = *head_ref;

	if(*head_ref == NULL)	return;

	(*head_ref) = (*head_ref)->next;
	free(new_node);
}

void printstack(struct node **head_ref) {
	struct node *new_node = *head_ref;
	printf("Stack => ");
	while(new_node != NULL) {
		printf("%d ",new_node->data);
		new_node = new_node->next;
	}
	printf("\n");
}
int main() {
	struct node *stack = NULL;
	int i;
	printf("isempty = %d\npushing value 90 to the stack\n",isempty(&stack) );
	push(&stack, 90);
	printstack(&stack);
	printf("isempty = %d\nPoping from stack\n",isempty(&stack) );
	pop(&stack);

	printf("isempty = %d\nPoping from empty stack\n",isempty(&stack) );
	pop(&stack);
	printf("Top of the stack = %d\n",top(&stack));
	printstack(&stack);
	printf("isempty = %d\nPushing Value 89, 78 & 39 to the stack (in order)\n",isempty(&stack) );
	push(&stack, 89);
	push(&stack, 78);
	push(&stack, 39);
	printstack(&stack);
	printf("Top of the stack = %d\n",top(&stack));
	return 0;

}