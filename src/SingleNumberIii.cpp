// Source : https://leetcode.com/problems/single-number-iii/
// Author : wind4869
// Date   : 2015-08-22

/********************************************************************************** 
 * 
 * Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
 * 
 * For example:
 * 
 * Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
 * 
 * Note:
 * 
 * The order of the result is not important. So in the above example, [5, 3] is also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 *               
 *               
 * 
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int temp = 0;
        for (auto i : nums)
        	temp ^= i;

        unsigned int mask = 1;
        while ((mask & temp) == 0)
        	mask <<= 1;

        int num1 = 0, num2 = 0;
        for (auto i : nums)
        	if (mask & i)
        		num1 ^= i;
        	else
        		num2 ^= i;

        return {num1, num2};
    }
};

int main()
{
	vector<int> nums = {1, 2, 1, 3, 2, 5};
	for (auto i : Solution().singleNumber(nums))
		cout << i << endl;
}

