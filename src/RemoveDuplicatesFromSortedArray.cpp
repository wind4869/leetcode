// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Author : wind4869
// Date   : 2015-03-31

/********************************************************************************** 
 * 
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * 
 * For example,
 * Given input array A = [1,1,2],
 * 
 * Your function should return length = 2, and A is now [1,2].
 * 
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int count = 0;
        int current = A[0];
        for (int i = 1; i < n; ++i) {
        	if (A[i] == current) ++count;
        	else {
        		current = A[i];
        		A[i - count] = A[i];
        	}
        }
        return n - count;
    }
};

int main()
{
	Solution s;
	int A[] = {1, 1, 2, 3, 3, 4, 5};
	int n = s.removeDuplicates(A, 7);
	for (int i = 0; i < n; ++i)
		cout << A[i] << endl;
}

