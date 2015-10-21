// Source : https://leetcode.com/problems/house-robber/
// Author : wind4869
// Date   : 2015-04-09

/********************************************************************************** 
 * 
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 * 
 * Credits:Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int> &num) {
        if (num.empty()) return 0;
        int size = num.size();

        int ppre = num[0];
        if (size == 1) return ppre;

        int pre = max(num[0], num[1]);
        if (size == 2) return pre;

        int maxSum = 0, cur = 0;
        for (int i = 2; i < size; ++i) {
        	cur = max(pre, ppre + num[i]);
        	ppre = pre;
        	pre = cur;

        	if (cur > maxSum) maxSum = cur;
        }
        return maxSum;
    }
};

int main()
{
	vector<int> num = {4,3,1,3,2}; 
	cout << Solution().rob(num) << endl;
}
