// Source : https://leetcode.com/problems/excel-sheet-column-title/
// Author : wind4869
// Date   : 2015-04-19

/********************************************************************************** 
 * 
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 * 
 * For example:
 * 
 *     1 -> A
 *     2 -> B
 *     3 -> C
 *     ...
 *     26 -> Z
 *     27 -> AA
 *     28 -> AB 
 * 
 * Credits:Special thanks to @ifanchu for adding this problem and creating all test cases.
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
    	char c;
    	string result;
    	while (n) {
    		if (n % 26) c = n % 26 + 'A' - 1;
    		else { c = 'Z'; --n; }
    		result.push_back(c);
    		n /= 26;
    	}

    	reverse(result.begin(), result.end());
    	return result;
    }
};

int main()
{
	cout << Solution().convertToTitle(78) << endl;
}