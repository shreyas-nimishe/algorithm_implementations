#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node *next;
};

struct node *create_node() {
	struct node *temp = (struct node *) malloc (sizeof(node));
	temp->next = NULL;

	return temp;
}

void push(struct node **head_ref, int val) {
	struct node *temp = create_node();
	temp->data = val;
	temp->next = (*head_ref);
	(*head_ref) = temp;
}


void delete_node(struct node **head_ref, int key) {
	struct node *cur_node = *head_ref, *prev = *head_ref;

	if(cur_node != NULL && cur_node->data == key) {
		*head_ref = (*head_ref)->next;
		free(cur_node);
		return;
	}

	while(cur_node != NULL) {
		if(cur_node->data == key) {
			prev->next = cur_node->next;
			free(cur_node);
			return;
		}
		prev = cur_node;
		cur_node = cur_node->next;
	}
}

void printlist(struct node *cur_node) {
	printf("List => ");
	while(cur_node != NULL) {
		printf("%d ",cur_node->data );
		cur_node = cur_node->next;
	}
	printf("\n");
}

int main() {
	 /* Start with the empty list */
    struct node* head = NULL;
 
    push(&head, 34);
    push(&head, 56);
    push(&head, 345);
    push(&head, 245);
	push(&head, 43);
	push(&head, 22);

    printlist(head);

    delete_node(&head, 245);
    printf("deleted node with value 245\n");
    printlist(head);
    return 0;
}