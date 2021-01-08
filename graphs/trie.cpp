#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
	bool isEnd;
	TrieNode *child[26]; 
};

TrieNode *createTrieNode() {
	TrieNode *new_node = new TrieNode();
	new_node->isEnd = false;
	for(int i = 0 ; i < 26 ; i++) {
		new_node->child[i] = NULL;
	}

	return new_node;
}
struct Trie{
	TrieNode *root;
};

Trie *createTrie() {
	Trie *new_trie = new Trie();
	new_trie->root = createTrieNode();
	return new_trie;
}

void insertIntoTrie(Trie *trie, string word) {
	TrieNode *cur = trie->root;
	int idx = 0;
	cout << "Inserting " << word << "\n";

	while(idx < word.size()) {
		if(cur->child[word[idx]-'A'] == NULL) {
			cur->child[word[idx]-'A'] = createTrieNode();
		}
		cur = cur->child[word[idx]-'A'];
		idx += 1;
	}
	cur->isEnd = true;
}

bool searchTrie(Trie *trie, string word) {
	TrieNode *cur = trie->root;
	int idx = 0;
	while(idx < word.size()) {
		cur = cur->child[word[idx] - 'A'];
		if(cur == NULL)		return false;
		idx += 1;
	}
	return cur->isEnd == true;
}

int main() {
	Trie *dict = createTrie();
	insertIntoTrie(dict, "HEELO");
	insertIntoTrie(dict, "HELLO");
	insertIntoTrie(dict, "HOLY");
	insertIntoTrie(dict, "BOOL");
	insertIntoTrie(dict, "BOON");

	printf("Present in trie BOON = %d\n",searchTrie(dict, "BOON") );
	printf("Present in trie BOOM = %d\n",searchTrie(dict, "BOOM") );

	printf("Present in trie HEELO = %d\n",searchTrie(dict, "HEELO") );
	printf("Present in trie HELLO = %d\n",searchTrie(dict, "HELLO") );
	printf("Present in trie BOO = %d\n",searchTrie(dict, "BOO") );
	printf("Present in trie B = %d\n",searchTrie(dict, "B") );

	return 0;


}