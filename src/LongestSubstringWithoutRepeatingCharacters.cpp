// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author : wind4869
// Date   : 2015-03-30

/********************************************************************************** 
 * 
 * Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if (size == 0) return 0;

        int cur = 1;
        int max = 1;
        int lastStart = 0;

        int hash[256];
        memset(hash, -1, sizeof hash);
        hash[s[0]] = 0;

        for (int i = 1; i < size; ++i) {
        	if (hash[s[i]] == -1) {
        		++cur;
        		hash[s[i]] = i;
        	} else if (lastStart <= hash[s[i]]) {
        		cur = i - hash[s[i]];
        		lastStart = hash[s[i]] + 1;
        		hash[s[i]] = i;
        	} else {
        		++cur;
        		hash[s[i]] = i;
        	}
        	if (cur > max) max = cur;
        }
        return max;
    }
};

int main()
{
	Solution s;
	cout << s.lengthOfLongestSubstring("abacv") << endl;
}
