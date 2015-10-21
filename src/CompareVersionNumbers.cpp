// Source : https://leetcode.com/problems/compare-version-numbers/
// Author : wind4869
// Date   : 2015-04-01

/********************************************************************************** 
 * 
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 * 
 * You may assume that the version strings are non-empty and contain only digits and the . character.
 * The . character does not represent a decimal point and is used to separate number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
 * 
 * Here is an example of version numbers ordering:
 * 0.1 < 1.1 < 1.2 < 13.37
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int result1 = 0, result2 = 0;
        int size1 = version1.size(), size2 = version2.size();

        while (i < size1 && j < size2) {
        	string cur1, cur2;
        	for (; i < size1; ++i)
        		if (version1[i] != '.')
        			cur1.push_back(version1[i]);
        		else break;
        	for (; j < size2; ++j)
        		if (version2[j] != '.')
        			cur2.push_back(version2[j]);
        		else break;

        	result1 = stoi(cur1);
        	result2 = stoi(cur2);

        	if (result1 > result2) return 1;
        	else if (result1 < result2) return -1;

        	++i, ++j;
        }

        for (; i < size1; ++i)
        	if (!(version1[i] == '.' || version1[i] == '0'))
        		break;
        if (i < size1) return 1;

		for (; j < size2; ++j)
        	if (!(version2[j] == '.' || version2[j] == '0'))
        		break;
        if (j < size2) return -1;

        return 0;
    }
};

int main()
{
	Solution s;
	cout << s.compareVersion("1.2", "1.10") << endl;
}

