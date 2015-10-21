// Source : https://leetcode.com/problems/valid-sudoku/
// Author : wind4869
// Date   : 2015-04-19

/********************************************************************************** 
 * 
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 * 
 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 * 
 * A partially filled sudoku which is valid.
 * 
 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
 * 
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool row[10], column[10], sub[10];
        for (int i = 0; i < 9; ++i) {
        	memset(row, 0, sizeof(row));
        	memset(column, 0, sizeof(column));
        	memset(sub, 0, sizeof(sub));

        	for (int j = 0; j < 9; ++j) {
        		if (!isValidSudoku(row, board[i][j] - '0') ||
        			!isValidSudoku(column, board[j][i] - '0') ||
        			!isValidSudoku(sub, board[3 * (i / 3) + j / 3][3 * (i % 3) + j % 3] - '0'))
        			return false;
        	}
        }
        return true;
    }

    bool isValidSudoku(bool table[], int index) {
    	if (index == '.' - '0') return true;
    	if (table[index]) return false;
    	table[index] = true;
    	return true;
    }
};