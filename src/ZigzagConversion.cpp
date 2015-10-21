// Source : https://leetcode.com/problems/zigzag-conversion/
// Author : wind4869
// Date   : 2015-03-31

/********************************************************************************** 
 * 
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a number of rows:
 * 
 * string convert(string text, int nRows);
 * 
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 * 
 *               
 **********************************************************************************/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
    	int size = s.size();
        if (size <= 1 || nRows <= 1) return s;

        int step = 2 * nRows - 2;
        for (int i = 0; i < nRows; ++i) {
        	for (int j = i; j < size; j += step) {
        		s.push_back(s[j]);
        		if (i > 0 && i < nRows - 1 && j + step - 2 * i < size)
        			s.push_back(s[j + step - 2 * i]);
        	}
        }
        return s.substr(size, size);
    }
};

int main()
{
	Solution s;
	cout << s.convert("PAYPALISHIRING", 1) << endl;
}