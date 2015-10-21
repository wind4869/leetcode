// Source : https://leetcode.com/problems/reverse-integer/
// Author : wind4869
// Date   : 2015-03-23

/********************************************************************************** 
 * 
 * Reverse digits of an integer.
 * 
 * Example1: x =  123, return  321
 * Example2: x = -123, return -321
 * 
 * click to show spoilers.
 * 
 * Have you thought about this?
 * 
 * Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
 * 
 * If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
 * 
 * Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
 * 
 * For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 * 
 * Update (2014-11-10):
 * Test cases had been added to test the overflow behavior.
 * 
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
    	bool flag = false;
        int MAX = 0x7FFFFFFF;
        int MIN = 0x80000000;

        long long result = 0;
        int count = 0;

        if (x < 0) {
			x = -x;
			flag = true;
        }

        while (x) {
        	result = 10 * result + x % 10;
        	x /= 10;
        }

        if (flag) result = -result;
        if (result > MAX || result < MIN)
        	result = 0;

        return result;
    }
};

int main()
{
	Solution s;
	cout << s.reverse(201) << endl;
}


