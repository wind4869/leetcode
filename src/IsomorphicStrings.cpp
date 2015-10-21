// Source : https://leetcode.com/problems/isomorphic-strings/
// Author : wind4869
// Date   : 2015-04-29

/********************************************************************************** 
 * 
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
 * 
 * For example,
 * Given "egg", "add", return true.
 * 
 * Given "foo", "bar", return false.
 * 
 * Given "paper", "title", return true.
 * 
 * Note:
 * You may assume both s and t have the same length.
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        char map[128] = {0};
        bool used[128] = {0};
        for (int i = 0; i < s.size(); ++i) {
        	if (map[s[i]] == 0) {
        		if (used[t[i]]) return false;
        		used[t[i]] = true;
        		map[s[i]] = t[i];
        	}
        	else if (map[s[i]] != t[i]) 
        		return false;
        }

        return true;
    }
};

int main()
{
	cout << Solution().isIsomorphic("14", "32") << endl;
}