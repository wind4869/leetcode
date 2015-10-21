// Source : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
// Author : wind4869
// Date   : 2015-07-07

/********************************************************************************** 
 * 
 * Follow up for "Find Minimum in Rotated Sorted Array":
 * What if duplicates are allowed?
 * 
 * Would this affect the run-time complexity? How and why?
 * 
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * 
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * 
 * Find the minimum element.
 * 
 * The array may contain duplicates.
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        int low = 0, high = size - 1;

        if (nums[low] < nums[high])
        	return nums[low];

        while (low < high - 1) {
        	int mid = low + ((high - low) >> 1);

        	if (nums[low] == nums[high] && nums[low] == nums[mid]) {
        		int minVal = nums[low];
        		for (int i = low + 1; i <= high; ++i)
        			if (nums[i] < minVal) minVal = nums[i];
        		return minVal;
        	}

        	if (nums[mid] >= nums[low]) low = mid;
        	else high = mid;
        }

        return nums[high];
    }
};

int main()
{

}
