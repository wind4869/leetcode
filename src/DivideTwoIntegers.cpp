// Source : https://leetcode.com/problems/divide-two-integers/
// Author : wind4869
// Date   : 2015-04-10

/********************************************************************************** 
 * 
 * Divide two integers without using multiplication, division and mod operator.
 * 
 * If it is overflow, return MAX_INT.
 * 
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
    	if (divisor == 0) return INT_MAX;

        long long a = dividend;
        long long b = divisor;
        a = abs(a), b = abs(b);

        long long res = 0;
        while (a >= b) {
        	for (long long i = 1, t = b; a >= t; i <<= 1, t <<= 1) {
        		a -= t;
        		res += i;
        	}
        }

        if ((dividend < 0) ^ (divisor < 0)) res = -res;
        if (res > INT_MAX) res = INT_MAX;
        return res;
    }
};

int main()
{
	cout << Solution().divide(-2147483648, 1) << endl;
}
