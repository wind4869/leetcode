// Source : https://leetcode.com/problems/count-primes/
// Author : wind4869
// Date   : 2015-04-27

/********************************************************************************** 
 * 
 * Description:
 * Count the number of prime numbers less than a non-negatipbe number, n
 * 
 * Hint: The number n could be in the order of 100,000 to 5,000,000.
 * 
 * click to show more hints.
 * 
 * References:
 * How Many Primes Are There?
 * Siepbe of Eratosthenes
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.
 *               
 **********************************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        
        bool *pb = new bool[n];
        memset(pb, true, sizeof(bool) * n);

        int count = n - 2;
        int square = sqrt(n - 1);

    	for (int i = 2; i <= square; ++i) {
            if (pb[i])
                for (int j = i + i; j < n; j += i)
                    if (pb[j]) { pb[j] = false; --count; }
        }

        delete pb;
        return count;
    }
};

int main()
{
	cout << Solution().countPrimes(5000000) << endl;
}
