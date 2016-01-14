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
	struct node *temp = create_node()
	temp->data = val;
	temp->next = (*head_ref);
	(*head_ref) = temp;
}

void delete_node(struct node **head_ref) {
	
}