// Source : https://leetcode.com/problems/surrounded-regions/
// Author : wind4869
// Date   : 2015-08-22

/********************************************************************************** 
 * 
 * Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 * 
 * A region is captured by flipping all 'O's into 'X's in that surrounded region.
 * 
 * For example,
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * After running your function, the board should be:
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 *               
 *               
 * 
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public: 
	struct Point {
		int x, y;
		Point(int i, int j) : x(i), y(j) { }
	};

	void mark(vector<vector<char>>& board, int i, int j) {
		queue<Point*> q;
		q.push(new Point(i, j));
		board[i][j] = 'M';

		while (!q.empty()) {
			Point* p = q.front();
			q.pop();

			if (p->x - 1 >= 0 && board[p->x - 1][p->y] == 'O') {
				q.push(new Point(p->x - 1, p->y));
				board[p->x - 1][p->y] = 'M';
			}

			if (p->x + 1 < board.size() && board[p->x + 1][p->y] == 'O') {
				q.push(new Point(p->x + 1, p->y));
				board[p->x + 1][p->y] = 'M';
			}
				
			if (p->y - 1 < board.size() && board[p->x][p->y - 1] == 'O') {
				q.push(new Point(p->x, p->y - 1));
				board[p->x][p->y - 1] = 'M';
			}
				
			if (p->y + 1 < board[j].size() && board[p->x][p->y + 1] == 'O') {
				q.push(new Point(p->x, p->y + 1));
				board[p->x][p->y + 1] = 'M';
			}

			delete p;
		}
	}

    void solve(vector<vector<char>>& board) {
    	int rows = board.size();
    	if (rows < 2)
    		return;
    	int columns = board[0].size();
    	if (columns < 2)
    		return;

    	for (int i = 0; i < columns; ++i)
    		if (board[0][i] == 'O')
    			mark(board, 0, i);

    	for (int i = 0; i < columns; ++i)
    		if (board[rows - 1][i] == 'O')
    			mark(board, rows - 1, i);

    	for (int i = 1; i < rows - 1; ++i)
    		if (board[i][0] == 'O')
    			mark(board, i, 0);

    	for (int i = 1; i < rows - 1; ++i)
    		if (board[i][columns - 1] == 'O')
    			mark(board, i, columns - 1);

    	for (int i = 0; i < rows; ++i)
    		for (int j = 0; j < columns; ++j)
    			if (board[i][j] == 'M')
    				board[i][j] = 'O';
    			else if (board[i][j] == 'O')
    				board[i][j] = 'X';
    }
};

int main()
{
	vector<vector<char>> board = {
		{'O', 'O', 'O'},
		{'O', 'O', 'O'},
		{'O', 'O', 'O'}
	};
	Solution().solve(board);
}
