// Source : https://leetcode.com/problems/container-with-most-water/
// Author : wind4869
// Date   : 2015-07-10

/********************************************************************************** 
 * 
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 * 
 * Note: You may not slant the container.
 * 
 *               
 **********************************************************************************/
class Solution {
public:
    int maxArea(vector<int>& height) {
    	int n = height.size();
    	int low = 0, high = n - 1;

    	int result = 0;
    	while (low < high) {
    		result = max(result, min(height[low], height[high]) * (high - low));
    		if (height[low] < height[high]) ++low;
    		else --high;
    	}
    	return result;
    }
};