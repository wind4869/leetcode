// Source : https://leetcode.com/problems/generate-parentheses/
// Author : wind4869
// Date   : 2015-07-26

/********************************************************************************** 
 * 
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * 
 * For example, given n = 3, a solution set is:
 * 
 * "((()))", "(()())", "(())()", "()(())", "()()()"
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
	void generateParenthesis(int left, int right, vector<string> &result, string temp) {
		if (left == 0 && right == 0)
			result.push_back(temp);
		else {
			if (left != 0) 
				generateParenthesis(left - 1, right, result, temp + '(');
			if (left < right && right != 0)
				generateParenthesis(left, right - 1, result, temp + ')');
		}
	}

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n > 0)
        	generateParenthesis(n, n, result, string());
        return result;
    }
};

int main()
{
	
}