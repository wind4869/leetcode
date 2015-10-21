// Source : https://leetcode.com/problems/edit-distance/
// Author : wind4869
// Date   : 2015-04-11

/********************************************************************************** 
 * 
 * Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
 * 
 * You have the following 3 operations permitted on a word:
 * 
 * a) Insert a character
 * b) Delete a character
 * c) Replace a character
 * 
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
    	int size1 = word1.size(), size2 = word2.size();
    	if (size1 == 0) return size2;
    	if (size2 == 0) return size1;

    	vector<int> pre(size2 + 1);
    	vector<int> cur(size2 + 1);

    	for (int i = 0; i <= size2; ++i)
    		pre[i] = i;

        for (int i = 1; i <= size1; ++i) {
        	cur[0] = i;
        	for (int j = 1; j <= size2; ++j) {
        		if (word1[i - 1] == word2[j - 1])
        			cur[j] = pre[j - 1];
        		else
        			cur[j] = min(min(pre[j - 1], pre[j]), cur[j - 1]) + 1;
        	}
        	pre = cur;
        }
        return cur[size2];
    }
};

int main()
{
	cout << Solution().minDistance("a", "a") << endl;
}
