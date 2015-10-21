// Source : https://leetcode.com/problems/add-binary/
// Author : wind4869
// Date   : 2015-03-23

/********************************************************************************** 
 * 
 * Given two binary strings, return their sum (also a binary string).
 * 
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 * 
 *               
 **********************************************************************************/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
    	string result = "";
    	int i = a.size() - 1, j = b.size() - 1;
    	int cur = 0, carry = 0;
    	int ai = 0, bj = 0;

    	while (i >= 0 && j >= 0) {   
            ai = a[i--] - '0';
            bj = b[j--] - '0';
            cur = ai + bj + carry; 		
            carry = cur / 2;
    		result += cur % 2 + '0';
    	}
        while (i >= 0) {
            ai = a[i--] - '0';
            cur = ai + carry;
            carry = cur / 2;
            result += cur % 2 + '0';
        }
        while (j >= 0) {
            bj = b[j--] - '0';
            cur = bj + carry;
            carry = cur / 2;
            result += cur % 2 + '0';
        }
    	if (carry) result += carry + '0';

        int size = result.size();
        for (int k = 0; k < size / 2; ++k) {
            char temp = result[k];
            result[k] = result[size - k - 1];
            result[size - k - 1] = temp;
        }
    	return result;
    }
};

int main()
{
	string a = "110010";
	string b = "10111";
	Solution s;
	cout << s.addBinary(a, b) << endl;
}


