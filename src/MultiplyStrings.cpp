// Source : https://leetcode.com/problems/multiply-strings/
// Author : wind4869
// Date   : 2015-07-27

/********************************************************************************** 
 * 
 * Given two numbers represented as strings, return multiplication of the numbers as a string.
 * 
 * Note: The numbers can be arbitrarily large and are non-negative.
 *               
 *               
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
    	int n1 = num1.size(), n2 = num2.size(), n = n1 + n2;
    	string result(n, '0');
    	for (int i = n1 - 1; i >= 0; --i) {
    		int a = num1[i] - '0';
    		int c = 0;
    		for (int j = n2 - 1; j >= 0; --j) {
    			int k = i + j + 1;
    			int b = num2[j] - '0';
    			int sum = result[k] - '0' + a * b + c;
    			result[k] = sum % 10 + '0';
    			c = sum / 10;
    		}
    		if (c > 0) result[i] = c + '0';
    		
    	}
		
    	int i;
    	for (i = 0; i < n && result[i] == '0'; ++i)
    	;

   		if (i == n) return "0";
    	return result.substr(i, n - i);
    }
};

int main()
{
	cout << Solution().multiply("0", "0") << endl;
}