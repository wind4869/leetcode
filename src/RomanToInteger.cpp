// Source : https://leetcode.com/problems/roman-to-integer/
// Author : wind4869
// Date   : 2015-07-27

/********************************************************************************** 
 * 
 * Given a roman numeral, convert it to an integer.
 * 
 * Input is guaranteed to be within the range from 1 to 3999.
 *               
 *               
 *               
 **********************************************************************************/
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
        	if (i < s.size() - 1 && m[s[i]] < m[s[i + 1]]) {
        		result += m[s[i + 1]] - m[s[i]];
        		++i;
        	} else
        		result += m[s[i]];
        }
        return result;
    }

	map<char, int> m = {
		{'I', 1},
		{'V', 5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000}
	};
};

int main()
{
	cout << Solution().romanToInt("MDCCCXCIX") << endl;
}