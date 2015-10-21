// Source : https://leetcode.com/problems/summary-ranges/
// Author : wind4869
// Date   : 2015-07-09

/********************************************************************************** 
 * 
 * Given a sorted integer array without duplicates, return the summary of its ranges.
 * 
 * For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int size = nums.size();
        if (size == 0)
        	return result;

        int start = nums[0], end = nums[0];
        for (int i = 1; i < size; ++i) {
        	if (nums[i] == end + 1)
        		end = nums[i];
        	else {
        		result.push_back(getEach(start, end));
        		start = end = nums[i];
        	}
        }

        result.push_back(getEach(start, end));

        return result;
    }
private:
	string getEach(int start, int end) {
		stringstream ss;
        ss << start;
        string temp = ss.str();
        ss.str("");
        if (end > start) {
        	ss << end;
        	temp += "->" + ss.str();
        }
        return temp;
	}
};

int main()
{
	vector<int> nums = {0,1,2,3,4,5};
	for (auto &s : Solution().summaryRanges(nums))
		cout << s << endl;
}
