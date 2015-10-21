// Source : https://leetcode.com/problems/word-break/
// Author : wind4869
// Date   : 2015-04-11

/********************************************************************************** 
 * 
 * Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 * 
 * For example, given
 * s = "leetcode",
 * dict = ["leet", "code"].
 * 
 * Return true because "leetcode" can be segmented as "leet code".
 * 
 *               
 **********************************************************************************/
#include <iostream>
#include <unordered_set> 
using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
    	if (dict.empty()) return false;
    	if (s.empty()) return contains(s, dict);

        int size = s.size();
        bool *dp = new bool[size + 1];
        memset(dp, false, (size + 1) * sizeof(bool));
        dp[0] = true;

        for (int i = 1; i <= size; ++i) {
        	for (int j = 0; j < i; ++j) {
        		if (dp[j] && contains(s.substr(j, i - j), dict)) {
        			dp[i] = true;
        			break;
        		}
        	}
        }
        return dp[size];
    }

    bool contains(string s, unordered_set<string> &dict) {
    	return dict.find(s) != dict.end();
    }
};

int main()
{
	unordered_set<string> dict;
	cout << Solution().wordBreak("leetcode", dict) << endl;
}
