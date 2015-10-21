// Source : https://leetcode.com/problems/pascals-triangle-ii/
// Author : wind4869
// Date   : 2015-03-31

/********************************************************************************** 
 * 
 * Given an index k, return the kth row of the Pascal's triangle.
 * 
 * For example, given k = 3,
 * Return [1,3,3,1].
 * 
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return vector<int>(1, 1);
        if (rowIndex == 1) return vector<int>(2, 1);

        vector<int> cur = vector<int>(2, 1);
        for (int i = 1; i < rowIndex; ++i) {
        	cur.push_back(1);
        	for (int j = i; j > 0; --j)
        		cur[j] = cur[j] + cur[j - 1];
        }
        return cur;
    }
};

int main()
{
	Solution s;
	for (auto i : s.getRow(2))
		cout << i << endl;
}

