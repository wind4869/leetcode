// Source : https://leetcode.com/problems/4sum/
// Author : wind4869
// Date   : 2015-07-07

/********************************************************************************** 
 * 
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 * The solution set must not contain duplicate quadruplets.
 * 
 *     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 * 
 *     A solution set is:
 *     (-1,  0, 0, 1)
 *     (-2, -1, 1, 2)
 *     (-2,  0, 0, 2)
 * 
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	vector<vector<int>> result;
    	int size = nums.size();
    	if (size < 4) return result;

    	sort(nums.begin(), nums.end());
    	for (int i = 0; i < size - 3; ++i) {
    		if (i > 0 && nums[i] == nums[i - 1])
    			continue;

    		for (int j = i + 1; j < size - 2; ++j) {
    			if (j > i + 1 && nums[j] == nums[j - 1])
    				continue;

    			int k = j + 1, l = size - 1;
    			while (k < l) {
    				if (k > j + 1 && nums[k] == nums[k - 1]) {
                        ++k;
                        continue;
                    }
    				if (l < size - 1 && nums[l] == nums[l + 1]) {
                        --l;
                        continue;
                    }

    				int sum = nums[i] + nums[j] + nums[k] + nums[l];
    				if (sum == target) {
    					vector<int> temp;
    					temp.push_back(nums[i]);
    					temp.push_back(nums[j]);
    					temp.push_back(nums[k]);
    					temp.push_back(nums[l]);
    					result.push_back(temp);
    					++k;
    				} else if (sum > target) --l;
    				else ++k;
    			}
    		}
    	} 

    	return result;
    }
};

int main()
{
	vector<int> nums = {-1, -2, 0, 0, 1, 2};
	for (auto &i : Solution().fourSum(nums, 0)) {
		for (auto &j : i)
			cout << j << " ";
		cout << endl;
	}
	return 0;
}
