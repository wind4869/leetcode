// Source : https://leetcode.com/problems/simplify-path/
// Author : wind4869
// Date   : 2015-09-09

/********************************************************************************** 
 * 
 * Given an absolute path for a file (Unix-style), simplify it.
 * 
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 * 
 * click to show corner cases.
 * 
 * Corner Cases:
 * 
 * Did you consider the case where path = "/../"?
 * In this case, you should return "/".
 * Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
 * In this case, you should ignore redundant slashes and return "/home/foo".
 * 
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        if (path.empty()) return string();

        for (int i = 0; i < path.size(); ++i) {
        	for (; i < path.size() && path[i] == '/'; ++i)
        		;

        	string temp;
        	while (i < path.size() && path[i] != '/')
        		temp.push_back(path[i++]);

        	if (temp == "..") {
        		if (!v.empty()) v.pop_back();
        	} else if (temp != "." && !temp.empty())
        		v.push_back(temp);
        }

        string result = "/";
        for (int i = 0; i < v.size(); ++i) {
        	result.append(v[i]);
        	if (i < v.size() - 1) result.push_back('/');
        }

        return result;
    }
};

int main()
{
	cout << Solution().simplifyPath("/a/./b///../c/../././../d/..//../e/./f/./g/././//.//h///././/..///") << endl;
}