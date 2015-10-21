// Source : https://leetcode.com/problems/valid-parentheses/
// Author : wind4869
// Date   : 2015-03-27

/********************************************************************************** 
 * 
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * 
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 * 
 *               
 **********************************************************************************/
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string str) {
    	if (str.empty()) return true;
    	stack<char> s;

    	for (int i = 0; i < str.size(); ++i) {
    		char cur = str[i];
    		if (cur == '(' || cur == '{' || cur == '[')
    			s.push(cur);
    		if (cur == ')' || cur == '}' || cur == ']') {
    			if (s.empty()) return false;
    			if (s.top() == cur - 1 || s.top() == cur - 2)
    				s.pop();
    			else return false;
    		}
    	}
    	if (s.empty()) return true;
    	return false;
    }
};

int main()
{
	string str = "(])";
	Solution s;
	cout << s.isValid(str) << endl;
}


