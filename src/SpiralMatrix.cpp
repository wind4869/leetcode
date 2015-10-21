// Source : https://leetcode.com/problems/spiral-matrix/
// Author : wind4869
// Date   : 2015-07-27

/********************************************************************************** 
 * 
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 * 
 * For example,
 * Given the following matrix:
 * 
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 * 
 * You should return [1,2,3,6,9,8,7,4,5].
 * 
 *               
 *               
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void spiralOrder(vector<vector<int>>& matrix, int rows, int columns, int start, vector<int> & res) {
		int rowEnd = rows - start - 1;
		int columnEnd = columns - start - 1;

		for (int i = start; i <= columnEnd; ++i)
			res.push_back(matrix[start][i]);

		if (start < rowEnd)
			for (int i = start + 1; i <= rowEnd; ++i)
				res.push_back(matrix[i][columnEnd]);

		if (start < rowEnd && start < columnEnd)
			for (int i = columnEnd - 1; i >= start; --i)
				res.push_back(matrix[rowEnd][i]);

		if (start < rowEnd - 1 && start < columnEnd)
			for (int i = rowEnd - 1; i >= start + 1; --i)
				res.push_back(matrix[i][start]);
	}

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    	vector<int> res;

        int rows = matrix.size();
        if (rows == 0) return res;
        int columns = matrix[0].size();
        if (columns == 0) return res;

        int start = 0;
        while (rows > 2 * start && columns > 2 * start) {
        	spiralOrder(matrix, rows, columns, start, res);
        	++start;
        }

        return res;
    }
};

int main()
{
	vector<vector<int>> matrix = {
 		{1},
 		{2},
 		{3}
	};

	for (auto i : Solution().spiralOrder(matrix))
		cout << i;
}