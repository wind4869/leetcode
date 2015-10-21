// Source : https://leetcode.com/problems/merge-sorted-array/
// Author : wind4869
// Date   : 2015-03-22

/********************************************************************************** 
 * 
 * Given two sorted integer arrays A and B, merge B into A as one sorted array.
 * 
 * Note:
 * You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
    	int i = 0, j = 0, k = 0;
    	int *t = new int[m + n];

    	while (i < m && j < n) {
    		if (A[i] <= B[j]) t[k++] = A[i++];
    		else t[k++] = B[j++];
    	}

    	while (i < m) t[k++] = A[i++];
    	while (j < n) t[k++] = B[j++];

    	for (int i = 0; i < k; ++i)
    		A[i] = t[i];

    	delete [] t;
    }
};