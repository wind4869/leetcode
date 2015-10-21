// Source : https://leetcode.com/problems/word-ladder/
// Author : wind4869
// Date   : 2015-08-06

/********************************************************************************** 
 * 
 * Given two words (beginWord and endWord), and a dictionary, find the length of shortest transformation sequence from beginWord to endWord, such that:
 * 
 * Only one letter can be changed at a time
 * Each intermediate word must exist in the dictionary
 * 
 * For example,
 * 
 * Given:
 * start = "hit"
 * end = "cog"
 * dict = ["hot","dot","dog","lot","log"]
 * 
 * As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * return its length 5.
 * 
 * Note:
 * 
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 **********************************************************************************/
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        if (beginWord == endWord) return 1;

        unordered_map<string, int> d;
        queue<string> q;
        d[beginWord] = 1;
        q.push(beginWord);

        for (q.push(beginWord); !q.empty(); q.pop()) {
        	string word = q.front();
        	int step = d[word] + 1;
        	for (int i = 0; i < word.size(); ++i) {
        		for (int c = 'a'; c <= 'z'; ++c) {
        			if (word[i] != c) {
        				char temp = word[i];
        				word[i] = c;

        				if (word == endWord) return step;
        				if (wordDict.find(word) != wordDict.end() && d.find(word) == d.end()) {
        					q.push(word);
        					d.insert(make_pair(word, step));
        				}

        				word[i] = temp;
        			}
        		}
        	}
        }

        return 0;
    }
};

int main()
{

}
