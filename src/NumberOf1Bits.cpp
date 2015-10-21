// Source : https://leetcode.com/problems/number-of-1-bits/
// Author : wind4869
// Date   : 2015-03-22

/********************************************************************************** 
 * 
 * Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
 * 
 * For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
 		int count = 0;
 		while (n) {
 			count++;
 			n = n & (n - 1);
 		}       
 		return count;
    }
};

int main()
{
	Solution s;
	cout << s.hammingWeight(15) << endl;
}