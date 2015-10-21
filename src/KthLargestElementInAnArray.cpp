// Source : https://leetcode.com/problems/kth-largest-element-in-an-array/
// Author : wind4869
// Date   : 2015-07-09

/********************************************************************************** 
 * 
 * Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * 
 * For example,
 * Given [3,2,1,5,6,4] and k = 2, return 5.
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    	int size = nums.size();
       	int low = 0, high = size - 1;
       	int index = partition(nums, low, high);

       	while (index != size - k) { 
       		if (index > size - k)
       			high = index - 1;
       		else
       			low = index + 1;

       		index = partition(nums, low, high);
       	}

       	return nums[index];
    }
private:
	int partition(vector<int>& nums, int low, int high) {
		int mid = low - 1;
		for (int i = low; i <= high; ++i)
			if (nums[i] <= nums[high])
				swap(nums[i], nums[++mid]);
		return mid;
	}
};

int main()
{
	vector<int> nums = {3,2,1,5,6,4,2};
	cout << Solution().findKthLargest(nums, 3) << endl;
}
