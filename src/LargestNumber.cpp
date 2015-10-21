// Source : https://leetcode.com/problems/largest-number/
// Author : wind4869
// Date   : 2015-04-01

/********************************************************************************** 
 * 
 * Given a list of non negative integers, arrange them such that they form the largest number.
 * 
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 * 
 * Note: The result may be very large, so you need to return a string instead of an integer.
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

bool compare(string s1, string s2) {
    string t = s1;
    s1.append(s2);
    s2.append(t);
    return s1 > s2;
}

class Solution {
public:
    string largestNumber(vector<int> &num) {
        int size = num.size();
        if (size == 0) return "";

        vector<string> v;
        ostringstream oss;
        for (int i = 0; i < size; ++i) {
        	oss << num[i];
        	v.push_back(oss.str());
        	oss.str("");
        }

        string result;
        sort(v.begin(), v.end(), compare);
        for (int i = 0; i < size; ++i)
        	result.append(v[i]);

        int i = 0;
        for (; i < size; ++i)
        	if (result[i] != '0')
        		break;
        if (i >= size) return "0";
        return result;
    }
};

int main()
{
	vector<int> v{0};
	Solution s;
	cout << s.largestNumber(v) << endl;
}
