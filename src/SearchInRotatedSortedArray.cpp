// Source : https://leetcode.com/problems/search-in-rotated-sorted-array/
// Author : wind4869
// Date   : 2015-04-16

/********************************************************************************** 
 * 
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * 
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * 
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
    	int low = 0, high = n - 1;
    	while (low <= high) {
    		int mid = low + ((high - low) >> 1);

    		if (A[mid] == target) return mid;

    		if (A[mid] < A[high]) {
    			if (target > A[mid] && target <= A[high])
    				low = mid + 1;
    			else
    				high = mid - 1;
    		} else {
    			if (target < A[mid] && target >= A[low])
    				high = mid - 1;
    			else
    				low = mid + 1;
    		}
    	}

    	return -1;
    }
};

int main()
{
	int A[] = {4, 5, 6, 7, 0, 1, 2};
	cout << Solution().search(A, 7, 1) << endl;
}
