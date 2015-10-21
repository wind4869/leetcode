// Source : https://leetcode.com/problems/climbing-stairs/
// Author : wind4869
// Date   : 2015-04-01

/********************************************************************************** 
 * 
 * You are climbing a stair case. It takes n steps to reach to the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 * 
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
    	int a = 1, b = 2;
    	if (n == 1) return a;
    	if (n == 2) return b;

    	int c;
    	for (int i = 2; i < n; ++i) {
    		c = a + b;
    		a = b;
    		b = c;
    	}
    	return c;
    }
};

int main()
{
	cout << Solution().climbStairs(10) << endl;
}
