#include<bits/stdc++.h>
using namespace std;
#define CHAR_SIZE 26

struct trie_node {
	bool isend;
	struct trie_node *next[CHAR_SIZE];
};

struct trie {
	struct trie_node *root;
	int total_words;
};

struct trie_node *createTrieNode() {
	struct trie_node *t = (struct trie_node *)malloc(sizeof(struct trie_node));

	for(int i = 0 ; i < CHAR_SIZE ; ++i) {
		t->next[i] = 0;
	}
	return t;
}

struct trie *createTrie() {
	struct trie *dict = (struct trie*)malloc(sizeof(trie));
	struct trie_node *head_ref = createTrieNode();


	dict->root = head_ref;
	dict->total_words = 0;
	return dict;
}

void insert(struct trie *dict, char word[]) {
	int len = strlen(word);
	struct trie_node *cur = (dict)->root;

	for(int i = 0 ; i < len ; i++) {
		if(!cur->next[word[i] - 'a'])
			cur->next[word[i] - 'a'] = createTrieNode();
		cur = cur->next[word[i] - 'a'];
	}
	cur->isend = true;
	dict->total_words += 1;
}

bool search(struct trie *dict, char word[]) {
	int len = strlen(word);
	struct trie_node *cur = (dict)->root;

	for(int i = 0 ; i < len ; i++) {
		if(!cur->next[word[i] - 'a'])
			return false;

		cur = cur->next[word[i] - 'a'];
	}

	return (cur != NULL && cur->isend);
}

bool isleaf(struct trie_node *t) {
	for(int i = 0 ; i < CHAR_SIZE ; i++) {
		if(t->next[i] != NULL){
			return false;
		}
	}
	return true;
}

bool delete_recursive(struct trie_node *cur, int idx, int len, char word[]){
	struct trie_node *next = cur->next[word[idx] - 'a'];
	bool result;
	if(idx == len-1) {
		if(isleaf(next) && next->isend){
			free(next);
			return true;
		}else{
			return false;
		}
	}else{
		if(!isleaf(next) ) {
			result = next->isend;
			free(next);
			return result;
		}else{
			return false;
		}
	}
}

void delete_word(struct trie *dict, char word[]) {
	if(search(dict, word)) {
		delete_recursive(dict->root, 0, strlen(word), word);
	}
}

int main() {
    char keys[][8] = {"she", "shells", "shea", "xhprw", "x", "bye", "byeee"};
    struct trie *dict = createTrie();
 
    createTrie(&trie);
 
    for(int i = 0; i < 8; i++) {
        insert(&dict, keys[i]);
    }
 
    delete_word(&dict, keys[0]);
 
	//printf("%s %s\n", "shel", search(&dict, "shel") ? "Present in trie" : "Not present in trie");
 
    return 0;
}