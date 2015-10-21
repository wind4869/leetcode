// Source : https://leetcode.com/problems/largest-rectangle-in-histogram/
// Author : wind4869
// Date   : 2015-07-07

/********************************************************************************** 
 * 
 * Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
 * 
 * Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10 unit.
 * 
 * For example,
 * Given height = [2,1,5,6,2,3],
 * return 10.
 * 
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
		int size = height.size(), result = 0;
		stack<int> s;
		for (int i = 0; i < size; ++i) {
			while (!s.empty() && height[s.top()] >= height[i]) {
				int h = height[s.top()];
				s.pop();
				result = max(result, (i - 1 - (s.empty() ? -1 : s.top())) * h);
			}
			s.push(i);
		}

		while (!s.empty()) {
			int h = height[s.top()];
			s.pop();
			result = max(result, (size - 1 - (s.empty() ? -1 : s.top())) * h);
		}

		return result;
    }
};

int main()
{
	vector<int> height = {2, 1, 5, 6, 2, 3};
	cout << Solution().largestRectangleArea(height) << endl;
}
