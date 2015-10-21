// Source : https://leetcode.com/problems/different-ways-to-add-parentheses/
// Author : wind4869
// Date   : 2015-08-22

/********************************************************************************** 
 * 
 * Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.
 * 
 * Example 1
 * Input: "2-1-1". 
 * ((2-1)-1) = 0
 * (2-(1-1)) = 2
 * Output: [0, 2]
 * 
 * Example 2
 * Input: "2*3-4*5" 
 * (2*(3-(4*5))) = -34
 * ((2*3)-(4*5)) = -14
 * ((2*(3-4))*5) = -10
 * (2*((3-4)*5)) = -10
 * (((2*3)-4)*5) = 10
 * Output: [-34, -14, -10, -10, 10] 
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.
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
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        for (int i = 0; i < input.size(); ++i) {
        	char c = input[i];
        	if (c == '+' || c == '-' || c == '*') {
        		vector<int> left = diffWaysToCompute(input.substr(0, i));
        		vector<int> right = diffWaysToCompute(input.substr(i + 1));

        		for (int j = 0; j < left.size(); ++j) {
        			for (int k = 0; k < right.size(); ++k) {
        				switch (c) {
        				case '+':
        					result.push_back(left[j] + right[k]);
        					break;
        				case '-':
        					result.push_back(left[j] - right[k]);
        					break;
        				case '*':
        					result.push_back(left[j] * right[k]);
        					break;
        				default:
        					break;
        				}
        			}
        		}
        	}
        }

        if (result.empty())
        	result.push_back(stoi(input));

        return result;
    }
};

int main()
{
	for (auto i : Solution().diffWaysToCompute("2*3-4*5"))
		cout << i << endl;
}
