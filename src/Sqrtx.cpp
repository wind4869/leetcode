// Source : https://leetcode.com/problems/sqrtx/
// Author : wind4869
// Date   : 2015-04-10

/********************************************************************************** 
 * 
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x.
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    int sqrt(int x) {
    	int i = 0;
    	int j = (x >> 1) + 1;
    	while (i <= j) {
    		int mid = i + ((j - i) >> 1);
    		long long square = mid * mid;
    		if (square == x) return mid;
    		else if (square > x) j = mid - 1;
    		else i = mid + 1;
    	}
    	return j;
   	}
};

int main()
{
	cout << Solution().sqrt(3) << endl;
}
