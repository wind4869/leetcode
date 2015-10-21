// Source : https://leetcode.com/problems/valid-palindrome/
// Author : wind4869
// Date   : 2015-03-30

/********************************************************************************** 
 * 
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 * 
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 * 
 * Note:
 * Have you consider that the string might be empty? This is a good question to ask during an interview.
 * 
 * For the purpose of this problem, we define empty string as valid palindrome.
 * 
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
    	if (s.empty()) return true;

    	int begin = 0;
    	int end = s.size() - 1;

    	while (begin < end) {
    		if (isalnum(s[begin]) && isalnum(s[end])) {
    			if (tolower(s[begin++]) != tolower(s[end--]))
    				return false;
    		} else if (isalnum(s[begin])) end--;
    		else begin++;
    	}
    	return true;
    }
};

int main()
{
	Solution s;
	cout << s.isPalindrome("8V8K;G;K;V;") << endl;
}
