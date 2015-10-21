// Source : https://leetcode.com/problems/median-of-two-sorted-arrays/
// Author : wind4869
// Date   : 2015-07-07

/********************************************************************************** 
 * 
 * There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int m = nums1.size(), n = nums2.size();

    	int *A = NULL, *B = NULL;
    	if (m > 0) A = &nums1[0];
    	if (n > 0) B = &nums2[0];

    	int k = m + n;
    	if (k & 0x1)
    		return findKth(A, m, B, n, k / 2 + 1);
    	else 
    		return (findKth(A, m, B, n, k / 2) +
    			findKth(A, m, B, n, k / 2 + 1)) / 2;
    }
private:
	double findKth(int A[], int m, int B[], int n, int k) {
		// m is equal or smaller than n
		if (m > n)
			return findKth(B, n, A, m, k);
		if (m == 0)
			return B[k - 1];
		if (k == 1)
			return min(A[0], B[0]);

		int pa = min(k / 2, m), pb = k - pa;
		if (A[pa - 1] < B[pb - 1])
			return findKth(A + pa, m - pa, B, n, k - pa);
		else if (A[pa - 1] > B[pb - 1])
			return findKth(A, m, B + pb, n - pb, k - pb);
		else 
			return A[pa - 1];
	}
};

int main()
{
	vector<int> nums1 = {1, 1, 3, 3}, nums2 = {1, 1, 3, 3};
	cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
}
