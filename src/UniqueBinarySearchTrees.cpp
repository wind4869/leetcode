// Source : https://leetcode.com/problems/unique-binary-search-trees/
// Author : wind4869
// Date   : 2015-04-19

/********************************************************************************** 
 * 
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 * 
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.
 * 
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 * 
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
    	vector<int> dp(n + 1, 0);
    	dp[0] = 1, dp[1] = 1;

    	if (n <= 1) return dp[n];
    	for (int i = 2; i <= n; ++i)
    		for (int j = 0; j <= i - 1; ++j)
    			dp[i] += dp[j] * dp[i - j - 1];

    	return dp[n];
    }
};

int main()
{
	cout << Solution().numTrees(3) << endl;
}