// Source : https://leetcode.com/problems/longest-common-prefix/
// Author : wind4869
// Date   : 2015-04-09

/********************************************************************************** 
 * 
 * Write a function to find the longest common prefix string amongst an array of strings.
 * 
 *               
 **********************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
    	if (strs.empty()) return "";

    	int size = strs.size();
        int i = size, j = 0;
    	while (1) {
    		if (strs[0] == "") return "";
    		if (j >= strs[0].size()) break; 
        	for (i = 1; i < size; ++i) {
        		if (strs[i] == "") return "";
        		if (j >= strs[i].size() || strs[i][j] != strs[i - 1][j])
        			break;
        	}
        	if (i < size) break;
        	else ++j;
    	}
    	return strs[0].substr(0, j);
    }
};

int main()
{
	vector<string> strs = {"a", "b"};
	cout << Solution().longestCommonPrefix(strs) << endl;
}

