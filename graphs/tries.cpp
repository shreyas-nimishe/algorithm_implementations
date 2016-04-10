#include<bits/stdc++.h>
using namespace std;
#define LETTERS 26

struct trie_node {
	bool isend;
	struct trie_node *next[LETTERS];
};

struct trie {
	struct trie_node *root;
	int total_words;	// 0 words initially
};

struct trie_node *create_trie_node() {
	struct trie_node *t = (struct trie_node *)malloc(sizeof(trie_node));
	t->isend = false;

	for(int i = 0 ; i < LETTERS ; i++) {
		t->next[i] = NULL;
	}
	printf("Prob\n");
	return t;
}

void initialize(struct trie *dict) {
	dict->root = create_trie_node();
	printf("No prob\n");
	dict->total_words = 0;
}

void insert(struct trie *dict, char word[]) {
	int len = strlen(word);
	struct trie_node *temp = dict->root;

	for(int i = 0 ; i < len ; i++) {
		if(temp->next[word[i] - 'a'] == NULL) {
			temp = create_trie_node();
		}
		temp = temp->next[word[i] - 'a'];
	}
	temp->isend = true;
	dict->total_words += 1;
}

bool search(struct trie *dict, char word[]) {
	int len = strlen(word);
	struct trie_node *temp = dict->root;

	for(int i = 0 ; i < len ; i++) {
		if(temp->next[word[i] - 'a'] == NULL) {
			return false;
		}
		temp = temp->next[word[i] - 'a'];
	}
	return temp->isend;
}	

int main() {
	struct trie *mydict = NULL;
	initialize(mydict);

	char entry[][8] = {"google", "reus", "reuse", "reality", "go", "real", "reality"};

	for(int i = 0 ; i < 7; i++) {
		insert(mydict, entry[i]);
	}
	
	char query[][8] = {"goog", "go", "reali", "reality", "real", "reus", "reuse"};
	
	for(int i = 0 ; i < 7 ; i++){
		printf("%s ",query[i] );
		if(search(mydict, query[i])) {
			printf("Exists\n");
		}else{
			printf("Not Found\n");
		}
	}
	return 0;
}