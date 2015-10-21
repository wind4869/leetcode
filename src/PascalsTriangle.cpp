// Source : https://leetcode.com/problems/pascals-triangle/
// Author : wind4869
// Date   : 2015-03-31

/********************************************************************************** 
 * 
 * Given numRows, generate the first numRows of Pascal's triangle.
 * 
 * For example, given numRows = 5,
 * Return
 * 
 * [
 *      [1],
 *     [1,1],
 *    [1,2,1],
 *   [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 * 
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        if (numRows == 0) return result;
        result.push_back(vector<int>(1, 1));
        if (numRows == 1) return result;
        result.push_back(vector<int>(2, 1));
        if (numRows == 2) return result;

        for (int i = 2; i < numRows; ++i) {
        	vector<int> prev = result[i - 1];
        	vector<int> cur = vector<int>(1, 1);
        	for (int j = 0; j < i - 1; ++j)
        		cur.push_back(prev[j] + prev[j + 1]);
        	cur.push_back(1);
        	result.push_back(cur);
        }
        return result;
    }
};

int main()
{
	Solution s;
	for (auto v : s.generate(5)) {
		for (auto i : v)
			cout << i << ' ';
		cout << endl;
	}
}


