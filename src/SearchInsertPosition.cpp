// Source : https://leetcode.com/problems/search-insert-position/
// Author : wind4869
// Date   : 2015-04-16

/********************************************************************************** 
 * 
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 * 
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
    	int low = 0, high = n - 1;
    	while (low <= high) {
    		int mid = low + ((high - low) >> 1);
    		if (A[mid] == target) return mid;
    		else if (A[mid] < target) low = mid + 1;
    		else high = mid - 1;
    	}
    	return low;
    }
};

int main()
{
	int A[] = {1, 3, 5, 6};
	cout << Solution().searchInsert(A, 4, 7) << endl;
}
