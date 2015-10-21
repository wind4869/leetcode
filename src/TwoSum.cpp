// Source : https://leetcode.com/problems/two-sum/
// Author : wind4869
// Date   : 2015-03-22

/********************************************************************************** 
 * 
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 * 
 * The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 * 
 * You may assume that each input would have exactly one solution.
 * 
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 * 
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
    	vector<int> temp = numbers, result;

		sort(temp.begin(), temp.end());
    	vector<int>::iterator it1 = temp.begin(), it2 = temp.end() - 1;
    	while (it1 != it2) {
    		int sum = *it1 + *it2;
    		if (sum == target) {
    			vector<int>::iterator it = numbers.begin();
    			for (; it != numbers.end(); ++it) {
    				if (*it == *it1 || *it == *it2)
    					result.push_back(it - numbers.begin() + 1);
    				if (result.size() == 2)
    					break;
    			}
    			return result;
    		} else if (sum > target)
    			--it2;
    		else
    			++it1;
    	}
    	return result;
    }
};

int main()
{
	vector<int> v;
	v.push_back(0);
	v.push_back(11);
	v.push_back(7);
	v.push_back(0);
	Solution s;
	for (auto i : s.twoSum(v, 0))
		cout << i << endl;
}

