// Source : https://leetcode.com/problems/string-to-integer-atoi/
// Author : wind4869
// Date   : 2015-03-23

/********************************************************************************** 
 * 
 * Implement atoi to convert a string to an integer.
 * 
 * Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 * 
 * Notes: 
 * It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front. 
 * 
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
 * 
 * spoilers alert... click to show requirements for atoi.
 * 
 * Requirements for atoi:
 * 
 * The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
 * 
 * The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
 * 
 * If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
 * 
 * If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
 * 
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    int atoi(string str) {
        if (str.empty())
        	return 0;
 
        long long result = 0;
        bool flag = false;

        for (int i = 0; i < str.length(); ++i) {
        	if (str[i] == ' ')
        		continue;
        	if (str[i] == '-' || str[i] == '+' || (str[i] >= '0' && str[i] <= '9')) {
        		if (str[i] == '-') { ++i; flag = true; }
        		else if (str[i] == '+') ++i;

        		if (i >= str.length() || str[i] < '0' || str[i] > '9') return 0;
        		while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
                    result = 10 * result + str[i++] - '0';
                    if (result > INT_MAX) break;
        		}

        		if (flag) result = -result;
                if (result > INT_MAX) return INT_MAX;
        		if (result < INT_MIN) return INT_MIN;
        		return result;
        	} else return 0;
        }
        return 0;
    }
};

int main()
{
	string str = "-2147483648";
	Solution s;
	cout << s.atoi(str) << endl;
}


