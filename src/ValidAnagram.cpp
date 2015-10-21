// Source : https://leetcode.com/problems/valid-anagram/
// Author : wind4869
// Date   : 2015-08-06

/********************************************************************************** 
 * 
 * Given two strings s and t, write a function to determine if t is an anagram of s. 
 * 
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
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
    bool isAnagram(string s, string t) {
        vector<int> count(26, 0);
        for(int i = 0; i < s.size(); i++)
            count[s[i]-'a']++;
        for(int i = 0; i < t.size(); i++)
            count[t[i]-'a']--;
        for(int i = 0; i < 26; i++)
            if(count[i] != 0)
                return false;
        return true;
    }
};

int main()
{
	cout << Solution().isAnagram("ltjupwrxip", "uprtjlixwp") << endl;
}