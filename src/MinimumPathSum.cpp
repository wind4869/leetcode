// Source : https://leetcode.com/problems/minimum-path-sum/
// Author : wind4869
// Date   : 2015-04-18

/********************************************************************************** 
 * 
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
    	int row = grid.size(), column =  grid[0].size();
    	vector<int> dp(column);

    	dp[0] = grid[0][0];
    	for (int j = 1; j < column; ++j)
    		dp[j] = dp[j - 1] + grid[0][j];

    	for (int i = 1; i < row; ++i) {
    		dp[0] += grid[i][0];
    		for (int j = 1; j < column; ++j) {
    			if (dp[j - 1] < dp[j])
    				dp[j] = dp[j - 1] + grid[i][j];
    			else
    				dp[j] += grid[i][j];
    		}
    	}
    	return dp[column - 1];
    }
};

int main()
{
	vector<vector<int>> grid = {
		{1, 2, 3},
		{1, 3, 4},
		{4, 1, 1}
	};
	cout << Solution().minPathSum(grid) << endl;
}