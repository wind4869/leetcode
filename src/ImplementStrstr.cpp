// Source : https://leetcode.com/problems/implement-strstr/
// Author : wind4869
// Date   : 2015-07-09

/********************************************************************************** 
 * 
 * Implement strStr().
 * 
 * Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 * 
 * Update (2014-11-02):
 * The signature of the function had been updated to return the index instead of the pointer. If you still see your function signature returns a char * or String, please click the reload button  to reset your code definition.
 * 
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
    	int size1 = haystack.size(), size2 = needle.size();
    	if (size2 == 0)
    		return 0;
    	if (size1 == 0)
    		return -1;

    	int i = 0, j = 0;
    	while (i < size1 && j < size2) {
    		if (haystack[i] == needle[j]) {
    			++i;
    			++j;
    		} else {
    			i -= j - 1;
    			j = 0;
    		}
    	}

    	return j == size2 ? i - j : -1;
    }
};

int main()
{

}