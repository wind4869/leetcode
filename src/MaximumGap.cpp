// Source : https://leetcode.com/problems/maximum-gap/
// Author : wind4869
// Date   : 2015-09-09

/********************************************************************************** 
 * 
 * Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
 * 
 * Try to solve it in linear time/space.
 * 
 * Return 0 if the array contains less than 2 elements.
 * 
 * You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
 * 
 * Credits:Special thanks to @porker2008 for adding this problem and creating all test cases.
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        
        int maxNum, minNum;
        maxNum = minNum = nums[0];
        for (int i = 1; i < n; ++i) {
           	maxNum = max(maxNum, nums[i]);
            minNum = min(minNum, nums[i]);
        }
        
        vector<int> maxBucket(n + 1, -1);
        vector<int> minBucket(n + 1, INT_MAX);
        
        for (int i = 0; i < n; ++i) {
            int index = long(nums[i] - minNum) * long(n + 1) / (maxNum - minNum);
            if (nums[i] == maxNum) index = n;
            
            maxBucket[index] = max(maxBucket[index], nums[i]);
            minBucket[index] = min(minBucket[index], nums[i]);
        }
        
        int result = 0, start = 0;
        while (start < n) {
        	int end = start + 1;
            while (maxBucket[end] == -1) ++end;
            result = max(result, minBucket[end] - maxBucket[start]);
            start = end;
        }
        
        return result;
    }
};

int main()
{
	vector<int> nums = {3, 6, 9, 1};
	cout << Solution().maximumGap(nums) << endl;
}


