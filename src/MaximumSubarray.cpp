// Source : https://leetcode.com/problems/maximum-subarray/
// Author : wind4869
// Date   : 2015-04-09

/********************************************************************************** 
 * 
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 * 
 * For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 * the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 * 
 * click to show more practice.
 * 
 * More practice:
 * 
 * If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 * 
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int max = A[0], cur = A[0];
        for (int i = 1; i < n; ++i) {
        	if (cur >= 0) cur += A[i];
        	else cur = A[i];

        	if (cur > max) max = cur;
        }
        return max;
    }
};

int main()
{
	int A[] = {-2, 1};
	cout << Solution().maxSubArray(A, 3) << endl;
}
