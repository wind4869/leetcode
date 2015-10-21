// Source : https://leetcode.com/problems/majority-element/
// Author : wind4869
// Date   : 2015-03-28

/********************************************************************************** 
 * 
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always exist in the array.
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int count = 1;
        int current = num[0];
        for (int i = 1; i < num.size(); ++i) {
        	if (num[i] == current)
        		count++;
        	else 
        		count--;
        	if (count == 0) {
        		current = num[i];
        		count = 1;
        	}
        }
        return current;
    }
};

int main()
{
	vector<int> v = {4, 5, 4};
	Solution s;
	cout << s.majorityElement(v) << endl;
}

