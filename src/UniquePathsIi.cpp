// Source : https://leetcode.com/problems/unique-paths-ii/
// Author : wind4869
// Date   : 2015-04-13

/********************************************************************************** 
 * 
 * Follow up for "Unique Paths":
 * 
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 * 
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * 
 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 * 
 * [
 *   [0,0,0],
 *   [0,1,0],
 *   [0,0,0]
 * ]
 * 
 * The total number of unique paths is 2.
 * 
 * Note: m and n will be at most 100.
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> dp(n, 0);
        for (int j = 0; j < n; ++j) {
        	if (obstacleGrid[0][j] == 1) break;
        	else dp[j] = 1;
        }

        for (int i = 1; i < m; ++i) {
        	if (obstacleGrid[i][0] == 1) dp[0] = 0;
        	for (int j = 1; j < n; ++j) {
        		if (obstacleGrid[i][j] == 1)
        			dp[j] = 0;
        		else
        			dp[j] += dp[j - 1];
        	}
        }

        return dp[n - 1];
    }
};

int main()
{
	vector<vector<int> > obstacleGrid = 
	{
		{1, 1, 0},
		{0, 1, 0},
		{0, 0, 0}
	};

	cout << Solution().uniquePathsWithObstacles(obstacleGrid) << endl;
}

