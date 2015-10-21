// Source : https://leetcode.com/problems/implement-trie-prefix-tree/
// Author : wind4869
// Date   : 2015-09-10

/********************************************************************************** 
 * 
 * Implement a trie with insert, search, and startsWith methods.
 * 
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 * 
 *               
 *               
 * 
 *               
 **********************************************************************************/
#include <iostream>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : isWord(false), next() { }

	bool isWord;
	unordered_map<char, TrieNode *> next;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *node = root;
        for (auto c : word) {
        	if (node->next.find(c) == node->next.end())
        		node->next[c] = new TrieNode();
        	node = node->next[c];
        }
        node->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *node = root;
        for (auto c : word) {
        	if (node->next.find(c) == node->next.end())
        		return false;
        	node = node->next[c];
        }
        return node->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for (auto c : prefix) {
        	if (node->next.find(c) == node->next.end())
        		return false;
        	node = node->next[c];
        }
        return true;
    }
private:
    TrieNode *root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main()
{
	Trie t;
	t.insert("abcd");
	cout << t.startsWith("abc") << endl;
}