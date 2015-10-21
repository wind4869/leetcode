// Source : https://leetcode.com/problems/longest-palindromic-substring/
// Author : wind4869
// Date   : 2015-03-30

/********************************************************************************** 
 * 
 * Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int max = 0;
        int cur = 0;
      	int left, right;
      	int size = s.size();

      	for(int i = 0; i < size; ++i) {
      		int j;
      		for (j = 0; (i - j) >= 0 && (i + j) < size; ++j) {
      			if (s[i - j] != s[i + j])
      				break;
      			cur = 2 * j + 1;
      		}
      		--j;
      		if (cur > max) {
      			max = cur;
      			left = i - j;
      			right = i + j;
      		}
      		for (j = 0; (i - j) >= 0 && (i + j + 1) < size; ++j) {
      			if (s[i - j] != s[i + j + 1])
      				break;
      			cur = 2 * j + 2;
      		}
      		--j;
      		if (cur > max) {
      			max = cur;
      			left = i - j;
      			right = i + j + 1;
      		}
      		
      	}
      	return s.substr(left, max);
    }
};

int main()
{
	Solution s;
	cout << s.longestPalindrome("abcba") << endl;
}
