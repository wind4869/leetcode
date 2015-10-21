// Source : https://leetcode.com/problems/majority-element-ii/
// Author : wind4869
// Date   : 2015-07-09

/********************************************************************************** 
 * 
 * Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
 * 
 *   How many majority elements could it possibly have?
 *   Do you have a better hint? Suggest it!
 * 
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int num1, num2;
        int cnt1 = 0, cnt2 = 0;

        for (auto &num : nums) {
        	if (cnt1 == 0 || num == num1) {
        		++cnt1;
        		num1 = num;
        	} else if (cnt2 == 0 || num == num1) {
        		++cnt2;
        		num2 = num;
        	} else {
        		--cnt1;
        		--cnt2;
        	}
        }

        cnt1 = 0;
        cnt2 = 0;
        for (auto &num : nums) {
        	if (num == num1)
        		++cnt1;
        	else if (num == num2)
        		++cnt2;
        }

        if (cnt1 > nums.size() / 3)
        	result.push_back(num1);
        if (cnt2 > nums.size() / 3)
        	result.push_back(num2);

        return result;
    }
};

int main()
{
	
}
