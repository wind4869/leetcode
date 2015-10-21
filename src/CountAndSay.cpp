// Source : https://leetcode.com/problems/count-and-say/
// Author : wind4869
// Date   : 2015-04-19

/********************************************************************************** 
 * 
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n, generate the nth sequence.
 * 
 * Note: The sequence of integers will be represented as a string.
 * 
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
    	string result = "1";
    	char current;
    	int count;

    	for (int i = 1; i < n; ++i) {
    		count = 1;
    		current = result[0];
    		string temp;

    		for (int j = 1; j < result.size(); ++j) {
    			if (result[j] == current) ++count;
    			else {
    				temp.push_back(count + '0');
    				temp.push_back(current);
    				current = result[j];
    				count = 1;
    			}
    		}

    		temp.push_back(count + '0');
    		temp.push_back(current);
    		result = temp;
    	}
    	return result;
    }
};

int main()
{
	cout << Solution().countAndSay(4) << endl;
}