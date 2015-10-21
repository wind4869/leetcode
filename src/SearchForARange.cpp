// Source : https://leetcode.com/problems/search-for-a-range/
// Author : wind4869
// Date   : 2015-04-16

/********************************************************************************** 
 * 
 * Given a sorted array of integers, find the starting and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 * 
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
    	vector<int> result;
    	result.push_back(-1);
    	result.push_back(-1);

    	int low = -1, high = n;
    	while (low + 1 != high) {
    		int mid = low + ((high - low) >> 1);
    		if (A[mid] < target) low = mid;
    		else high = mid;
    	}

    	if (high >= n || A[high] != target)
    		return result;

    	result[0] = high;
    	low = -1, high = n;
    	while (low + 1 != high) {
    		int mid = low + ((high - low) >> 1);
    		if (A[mid] > target) high = mid;
    		else low = mid;
    	}

    	result[1] = low;
    	return result;
    }
};

int main()
{
	int A[] = {5, 7, 7, 8, 8, 10};
	for (auto i : Solution().searchRange(A, 6, 4))
		cout << i << endl;
}