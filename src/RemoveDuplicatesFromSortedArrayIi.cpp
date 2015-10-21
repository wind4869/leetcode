// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Author : wind4869
// Date   : 2015-04-09

/********************************************************************************** 
 * 
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 * 
 * For example,
 * Given sorted array A = [1,1,1,2,2,3],
 * 
 * Your function should return length = 5, and A is now [1,1,2,2,3].
 * 
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
    	bool isTwice = false;
       	int count = 0, current = A[0];
       	for (int i = 1; i < n; ++i) {
       		if (A[i] == current) {
       			if (isTwice) ++count;
       			else {
       				isTwice = true;
       				A[i - count] = A[i];
       			}
       		} else {
       			isTwice = false;
       			current = A[i];
       			A[i - count] = A[i];
       		}
       	} 
       	return n - count;
    }
};

int main()
{
	int A[] = {1,1,1,1,3,3};
	cout << Solution().removeDuplicates(A, 6) << endl;
	for (int i = 0; i < 4; ++i) cout << A[i] << endl;
}


