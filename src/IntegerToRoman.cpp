// Source : https://leetcode.com/problems/integer-to-roman/
// Author : wind4869
// Date   : 2015-07-27

/********************************************************************************** 
 * 
 * Given an integer, convert it to a roman numeral.
 * 
 * Input is guaranteed to be within the range from 1 to 3999.
 *               
 *               
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
    	string result;
        int m = num / 1000;
        result.append(m, 'M');
        num -= m * 1000;

        if (num >= 900) {
        	result.append("CM");
        	num -= 900;
        } 

        int d = num / 500;
        result.append(d, 'D');
        num -= d * 500;

        if (num >= 400) {
        	result.append("CD");
        	num -= 400;
        }

        int c = num / 100;
        result.append(c, 'C'); 
        num -= c * 100;

        if (num >= 90) {
        	result.append("XC");
        	num -= 90;
        }

        int l = num / 50;
        result.append(l, 'L');
        num -= l * 50;

        if (num >= 40) {
        	result.append("XL");
        	num -= 40;
        }

        int x = num / 10;
        result.append(x, 'X');
        num -= x * 10;

        if (num == 9)
        	result.append("IX");
        else if (num == 4)
        	result.append("IV");
        else {
        	int v = num / 5;
        	result.append(v, 'V');
        	num -= v * 5;

        	result.append(num, 'I');
        }

        return result;
    }
};

int main()
{
	cout << Solution().intToRoman(90) << endl;
}
