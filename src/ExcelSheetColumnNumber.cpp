// Source : https://leetcode.com/problems/excel-sheet-column-number/
// Author : wind4869
// Date   : 2015-04-19

/********************************************************************************** 
 * 
 * Related to question Excel Sheet Column Title
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 * 
 * For example:
 *     A -> 1
 *     B -> 2
 *     C -> 3
 *     ...
 *     Z -> 26
 *     AA -> 27
 *     AB -> 28 
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
       	if (s.empty()) return 0;
       	int size = s.size();
       	long long result = 0;
       	for (int i = 0; i < size; ++i) {
       		result = 26 * result + (s[i] - 'A' + 1);
       		if (result > INT_MAX) return INT_MAX;
       	}
       	return result;
    }
};

int main()
{
	cout << Solution().titleToNumber("AB") << endl;
}