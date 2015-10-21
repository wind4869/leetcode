// Source : https://leetcode.com/problems/permutation-sequence/
// Author : wind4869
// Date   : 2015-03-31

/********************************************************************************** 
 * 
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * Given n and k, return the kth permutation sequence.
 * 
 * Note: Given n will be between 1 and 9 inclusive.
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
    	string s = string("123456789").substr(0, n);
    	string res;
    	for (int i = 0; i < n; ++i)
    		res.push_back(get_each(s, k));
    	return res;
    }

    char get_each(string &s, int &k) {
    	int div = factorial(s.size() - 1), factor = (k - 1) / div;
    	char res = s[factor];
    	s.erase(factor, 1);
    	k -= factor * div;
    	return res;
    }

    int factorial(int n) {
    	int res = 1;
    	for (int i = 2; i <= n; ++i)
    		res *= i;
    	return res;
    }
};

int main()
{
	Solution s;
	cout << s.getPermutation(3, 1) << endl;
}
