// Source : https://leetcode.com/problems/plus-one/
// Author : wind4869
// Date   : 2015-04-01

/********************************************************************************** 
 * 
 * Given a non-negative number represented as an array of digits, plus one to the number.
 * 
 * The digits are stored such that the most significant digit is at the head of the list.
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        reverse(digits.begin(), digits.end());

        int carry = 1;
        for (int i = 0; i < digits.size(); ++i) {
        	if (carry == 0) break;
        	int sum = digits[i] + carry;
        	digits[i] = sum % 10;
        	carry = sum / 10;
        }

        if (carry == 1) digits.push_back(1);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};

int main()
{
	vector<int> v{8};
	for (auto i : Solution().plusOne(v))
		cout << i;
	cout << endl;
}