// Source : https://leetcode.com/problems/happy-number/
// Author : wind4869
// Date   : 2015-04-27

/********************************************************************************** 
 * 
 * Write an algorithm to determine if a number is "happy".
 * 
 * A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
 * 
 * Example: 19 is a happy number
 * 
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 * 
 * Credits:Special thanks to @mithmatt and @ts for adding this problem and creating all test cases.
 *               
 **********************************************************************************/
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
    	set<int> hs;
       	while (n != 1) {
       		if (hs.insert(n).second == false) return false;

    		int temp = 0;
    		while (n) {
    			int digit = n % 10;
    			temp += digit * digit;
    			n /= 10;
    		}
    		n = temp;
       	}
       	return true;
    }
};

int main()
{
	cout << Solution().isHappy(19) << endl;
}
