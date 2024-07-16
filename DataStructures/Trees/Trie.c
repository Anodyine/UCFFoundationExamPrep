#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct _TrieNode {
    struct _TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

TrieNode* new_TrieNode() {
    TrieNode* node = malloc(sizeof(TrieNode));

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }

    node->isEndOfWord = false;

    return node;
}

void Trie_Insert(TrieNode* currentNode, const char* word) {
    int index = word[0] - 'a';
    
    if (!currentNode->children[index]) {
        currentNode->children[index] = new_TrieNode();
    }

    if (word[1] == '\0') {
        currentNode->children[index]->isEndOfWord = true;
        return;
    }

    Trie_Insert(currentNode->children[index], (word + 1));
}

bool Trie_Search(TrieNode* currentNode, const char* word) {
    if (currentNode == NULL) {
        return false;
    }

    if (currentNode->isEndOfWord == true) {
        return true;
    }

    int index = word[0] - 'a';
    return Trie_Search(currentNode->children[index], (word + 1));
}

// Main function to test the Trie implementation
int main() {
    // Array of words to be inserted
    char* words[] = {"hello", "world", "trie", "algorithm"};
    int n = sizeof(words) / sizeof(words[0]);

    TrieNode* root = new_TrieNode();

    // Insert words into the Trie
    for (int i = 0; i < n; i++) {
        Trie_Insert(root, words[i]);
    }

    // Search for words in the Trie and print the result
    char* queries[] = {"hello", "world", "trie", "data", "algo", "algorithm"};
    int q = sizeof(queries) / sizeof(queries[0]);

    for (int i = 0; i < q; i++) {
        printf("Search for \"%s\": %s\n", queries[i], Trie_Search(root, queries[i]) ? "Found" : "Not Found");
    }

    return 0;
}