// Source : https://leetcode.com/problems/reverse-bits/
// Author : wind4869
// Date   : 2015-03-23

/********************************************************************************** 
 * 
 * Reverse bits of a given 32 bits unsigned integer.
 * 
 * For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
 * 
 * Follow up:
 * If this function is called many times, how would you optimize it?
 * 
 * Related problem: Reverse Integer
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (uint32_t i = 0; i < 32; ++i) {
        	if (n & ((uint32_t)1 << (31 - i)))
        		result += (uint32_t)1 << i;

        }
        return result;
    }
};

int main()
{
	Solution s;
	cout << s.reverseBits(43261596) << endl;
}


