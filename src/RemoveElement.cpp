// Source : https://leetcode.com/problems/remove-element/
// Author : wind4869
// Date   : 2015-03-31

/********************************************************************************** 
 * 
 * Given an array and a value, remove all instances of that value in place and return the new length.
 * 
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 * 
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int count = 0;
       	for (int i = 0; i < n; ++i) {
       		if (A[i] == elem) count++;
       		else A[i - count] = A[i];
       	}
       	return n - count;
    }
};

int main()
{
	Solution s;
	int A[] = {1, 2, 3, 2, 4, 5};
	int n = s.removeElement(A, 6, 2);
	for (int i = 0; i < n; ++i)
		cout << A[i] << endl;
}


