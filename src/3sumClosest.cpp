// Source : https://leetcode.com/problems/3sum-closest/
// Author : wind4869
// Date   : 2015-07-07

/********************************************************************************** 
 * 
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 * 
 *     For example, given array S = {-1 2 1 -4}, and target = 1.
 * 
 *     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 *               
 **********************************************************************************/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    	if (nums.size() < 3)
    		return -1;

    	sort(nums.begin(), nums.end());
    	int minGap = nums[0] + nums[1] + nums[2] - target;
    	
    	for (int i = 0; i < nums.size() - 2; ++i) {
    		int low = i + 1, high = nums.size() - 1;
    		while (low < high) {
    			int curGap = nums[i] + nums[low] + nums[high] - target;

    			if (curGap == 0) return target;
    			else if (curGap < 0) ++low;
    			else --high;

    			if (abs(curGap) < abs(minGap)) minGap = curGap;
    		}
    	}

    	return minGap + target;
    }
};


