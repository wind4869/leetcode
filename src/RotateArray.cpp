// Source : https://leetcode.com/problems/rotate-array/
// Author : wind4869
// Date   : 2015-03-22

/********************************************************************************** 
 * 
 * Rotate an array of n elements to the right by k steps.
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4]. 
 * 
 * Note:
 * Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
 * 
 * [show hint]
 * Hint:
 * Could you do it in-place with O(1) extra space?
 * 
 * Related problem: Reverse Words in a String II
 * 
 * Credits:Special thanks to @Freezen for adding this problem and creating all test cases.
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(int nums[], int n, int k) {
    	if (n <= 0 || k <= 0) return;
    	k = k % n;
    	reverse(nums, 0, n - 1);
    	reverse(nums, 0, k - 1);
    	reverse(nums, k, n - 1);
    }

    void reverse(int nums[], int left, int right) {
    	while (left < right) {
    		int temp = nums[left];
    		nums[left] = nums[right];
    		nums[right] = temp;

    		left++;
    		right--;
    	}
    }
};

int main()
{
	int nums[] = {1,2,3,4,5,6,7};
	Solution s;
	s.rotate(nums, 7, 0);
	for (int i = 0; i < 7; ++i)
		cout << nums[i];
}
