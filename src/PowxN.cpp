// Source : https://leetcode.com/problems/powx-n/
// Author : wind4869
// Date   : 2015-04-09

/********************************************************************************** 
 * 
 * Implement pow(x, n).
 * 
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    double pow(double x, int n) {
    	if (n == 0) return 1;
    	if (n == 1) return x;

    	double half = pow(x, abs(n) >> 1);
    	double res = half * half;

    	if (n > 0) {
    		if (n & 1) return res * x;
    		else return res;
    	} else {
    		if (n & 1) return 1.0 / (res * x);
    		else return 1.0 / res;
    	}
    }
};

int main()
{
	cout << Solution().pow(2, -1) << endl;
}
