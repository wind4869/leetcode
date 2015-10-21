// Source : https://leetcode.com/problems/number-of-digit-one/
// Author : wind4869
// Date   : 2015-07-09

/********************************************************************************** 
 * 
 * Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
 * 
 * For example: 
 * Given n = 13,
 * Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 * 
 *   Beware of overflow.
 * 
 *               
 **********************************************************************************/
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0)
        	return 0;

        char str[50];
        sprintf(str, "%d", n);
        return numberOf1(str);
    }
private:
	int numberOf1(char *str) {
		if (str == NULL || *str > '9' || *str < '0' || *str == '\0')
			return 0;

		int first = *str - '0';
		int length = strlen(str);

		if (length == 1 && first > 0)
			return 1;
		if (length == 1 && first == 0)
			return 0;

		int numFirstDigit = 0;
		if (first > 1)
			numFirstDigit = pow(10.0, length - 1);
		else if (first == 1)
			numFirstDigit = atoi(str + 1) + 1;

		int numOtherDigits = first * (length - 1) * pow(10.0, length - 2);
		int numRecursive = numberOf1(str + 1);

		long long result = numFirstDigit + numOtherDigits + numRecursive;
		if (result > INT_MAX)
			return 0;
		return result;
	}
};

int main()
{
	cout << Solution().countDigitOne(100) << endl;
}