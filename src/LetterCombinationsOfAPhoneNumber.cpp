// Source : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Author : wind4869
// Date   : 2015-05-03

/********************************************************************************** 
 * 
 * Given a digit string, return all possible letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 * 
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * Note:
 * Although the above answer is in lexicographical order, your answer could be in any order you want.
 * 
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
    	if (digits.empty()) return result;
    	letterCombinations(digits, 0);
    	return result;
    }

    void letterCombinations(string digits, int index) {
    	if (index >= digits.size()) {
    		if (!temp.empty()) result.push_back(temp);
    		return;
    	}

    	string letters = map[digits[index] - '0'];
    	if (letters.empty()) letterCombinations(digits, index + 1);
    	for (int i = 0; i < letters.size(); ++i) {
    		temp.push_back(letters[i]);
    		letterCombinations(digits, index + 1);
    		temp.pop_back();
    	}
    }

    string temp;
    vector<string> result;
    string map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};

int main()
{
	for (auto s: Solution().letterCombinations("0"))
		cout << s << endl;
}
