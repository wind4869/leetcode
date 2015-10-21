// Source : https://leetcode.com/problems/basic-calculator/
// Author : wind4869
// Date   : 2015-07-09

/********************************************************************************** 
 * 
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces  .
 * 
 * You may assume that the given expression is always valid.
 * 
 * Some examples:
 * 
 * "1 + 1" = 2
 * " 2-1 + 2 " = 3
 * "(1+(4+5+2)-3)+(6+8)" = 23
 * 
 * Note: Do not use the eval built-in library function.
 * 
 *               
 **********************************************************************************/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        vector<string> post;
        stack<char> charStack;
        string num;

        for (int i = 0; i < s.size(); ++i) {
        	if (s[i] >= '0' && s[i] <= '9') {
        		num.push_back(s[i]);
        		if (i == s.size() - 1)
        			post.push_back(num);
        	} else {
        		if (!num.empty()) {
        			post.push_back(num);
        			num.clear();
        		}

	        	if (s[i] == '(')
	        		charStack.push(s[i]);
	        	else if (s[i] == '*' || s[i] == '/') {
                    if (charStack.empty())
                        charStack.push(s[i]);
                    else {
                        char t = charStack.top();
                        while (t == '*' || t == '/') {
                            string temp;
                            temp.push_back(t);
                            post.push_back(temp);
                            charStack.pop();

                            if (charStack.empty())
                                break;
                            else
                                t = charStack.top();
                        }
                        charStack.push(s[i]);
                    }
                } else if (s[i] == '+' || s[i] == '-') {
	        		if (charStack.empty())
	        			charStack.push(s[i]);
	        		else {
	        			char t = charStack.top();
	        			while (true) {
	        				string temp;
	        				temp.push_back(t);
	        				post.push_back(temp);
	        				charStack.pop();

	        				if (charStack.empty())
	        					break;
	        				else
	        					t = charStack.top();
	        			}
                        charStack.push(s[i]);
	        		}                        
	        	} else if (s[i] == ')') {
	        		char t = charStack.top();
	        		while (t != '(') {
	        			string temp;
	        			temp.push_back(t);
        				post.push_back(temp);

	        			charStack.pop();
	        			t = charStack.top();
	        		}
	        		charStack.pop();
	        	}
        	}
        }

        while (!charStack.empty()) {
        	string temp;
        	temp.push_back(charStack.top());
        	post.push_back(temp);
        	charStack.pop();
        }

        for (auto a : post)
            cout << a;

        int result = 0;
        stack<int> intStack;
        for (int i = 0; i < post.size(); i++) {
        	if (post[i][0] == '+' || post[i][0] == '-' || post[i][0] == '*' || post[i][0] == '/') {
        		int num2 = intStack.top();
        		intStack.pop();
        		int num1 = intStack.top();
        		intStack.pop();

                switch(post[i][0]) {
                case '+' :
                    intStack.push(num1 + num2);
                    break;
                case '-' :
                    intStack.push(num1 - num2);
                    break;
                case '*':
                    intStack.push(num1 * num2);
                    break;
                case '/':
                    intStack.push(num1 / num2);
                    break;
                }
 
        	} else
        		intStack.push(atoi(post[i].c_str()));
        }

        return intStack.top();
    }
};

int main()
{
    string in;
    while (cin >> in)
	   cout << Solution().calculate("15-16/7+10*3/15") << endl;
}

