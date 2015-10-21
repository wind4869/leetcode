// Source : https://leetcode.com/problems/length-of-last-word/
// Author : wind4869
// Date   : 2015-04-01

/********************************************************************************** 
 * 
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space characters only.
 * 
 * For example, 
 * Given s = "Hello World",
 * return 5.
 * 
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (s == NULL) return 0;
        int cur = 0, prev = 0;
        for (; *s != '\0'; ++s) {
        	if (*s != ' ') ++cur;
        	else {
        		if (cur) prev = cur;
        		cur = 0;
        	}
        }
        if (cur) return cur;
        return prev;
    }
};

int main()
{
	cout << Solution().lengthOfLastWord("1  ") << endl;
}
