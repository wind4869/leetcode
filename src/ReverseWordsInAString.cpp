// Source : https://leetcode.com/problems/reverse-words-in-a-string/
// Author : wind4869
// Date   : 2015-03-22

/********************************************************************************** 
 * 
 * Given an input string, reverse the string word by word.
 * 
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 * 
 * Update (2015-02-12):
 * For C programmers: Try to solve it in-place in O(1) space.
 * 
 * click to show clarification.
 * 
 * Clarification:
 * 
 * What constitutes a word?
 * A sequence of non-space characters constitutes a word.
 * Could the input string contain leading or trailing spaces?
 * Yes. However, your reversed string should not contain leading or trailing spaces.
 * How about multiple spaces between two words?
 * Reduce them to a single space in the reversed string.
 * 
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
    	int length = s.size();
    	if (length == 0) return;

		int left = 0, right = length - 1;
		while (left < length && s[left] == ' ') left++;
		if (left == length) {
			s = "";
			return;
		}
		while (right < length && s[right] == ' ') right--;
		if (left > 0 || right < length - 1)
			s = s.substr(left, right - left + 1);

		length = s.size();
		left = right = 0;
		while (left < length && s[left] != ' ') left++;

		right = left;
		while (right < length) {
			if (s[right] == ' ' && s[right + 1] != ' ') {
				do {
					s[left++] = s[right++];
				} while (s[right] != ' ' && right < length);
			}
			else
				right++;
		}

		if (left < length)
			s = s.substr(0, left);

		left = right = 0;
		length = s.size();
		reverse(s, 0, length - 1);

		while (left < length) {
			if (right < length && s[right] != ' ') right++;
			else {
				reverse(s, left, right - 1);
				left = ++right;
			}
		}
    }

    void reverse(string &s, int left, int right) {
		while (left < right) {
			char temp = s[left];
			s[left] = s[right];
			s[right] = temp;

			left++;
			right--;
		}
    }
};

int main()
{
	string s = "a";
	Solution solution;
	solution.reverseWords(s);

	cout << s << endl;
}