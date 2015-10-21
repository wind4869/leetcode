// Source : https://leetcode.com/problems/3sum/
// Author : wind4869
// Date   : 2015-07-06

/********************************************************************************** 
 * 
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 * 
 * Note:
 * 
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 * 
 *     For example, given array S = {-1 0 1 2 -1 -4},
 * 
 *     A solution set is:
 *     (-1, 0, 1)
 *     (-1, -1, 2)
 * 
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3)
        	return result;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
        	if (i > 0 && nums[i] == nums[i - 1])
        		continue;

        	int low = i + 1, high = nums.size() - 1;
        	while (low < high) {
        		if (low > i + 1 && nums[low] == nums[low - 1]) {
        			++low;
        			continue;
        		}
        		if (high < nums.size() - 1 && nums[high] == nums[high + 1]) {
        			--high;
        			continue;
        		}

        		int sum = nums[i] + nums[low] + nums[high];
        		if (sum > 0)
        			--high;
        		else if (sum < 0)
        			++low;
        		else {
        			vector<int> temp;
        			temp.push_back(nums[i]);
        			temp.push_back(nums[low]);
        			temp.push_back(nums[high]);
        			result.push_back(temp);
        			++low;
        		}
        	}
        }

        return result;
    }
};

int main()
{
	vector<int> nums = {0, 0, 0, 0};
	for (auto &i : Solution().threeSum(nums)) {
		for (auto &j : i)
			cout << j << " ";
		cout << endl;
	}
	return 0;
}
