// Source : https://leetcode.com/problems/permutations/
// Author : wind4869
// Date   : 2015-04-19

/********************************************************************************** 
 * 
 * Given a collection of numbers, return all possible permutations.
 * 
 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 * 
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        if (num.empty()) return result;
        permute(num, 0, result);
        return result;
    }

    void permute(vector<int> &num, int start, vector<vector<int> > &result) {
    	if (start == num.size())
    		result.push_back(num);
    	else {
    		for (int i = start; i < num.size(); ++i) {
    			swap(num[start], num[i]);
    			permute(num, start + 1, result);
    			swap(num[start], num[i]);
    		}
    	}
    }
};

int main()
{
	vector<int> num = {1, 2, 3};
	Solution().permute(num);
}