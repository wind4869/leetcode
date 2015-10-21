// Source : https://leetcode.com/problems/min-stack/
// Author : wind4869
// Date   : 2015-03-22

/********************************************************************************** 
 * 
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * 
 * push(x) -- Push element x onto stack.
 * 
 * pop() -- Removes the element on top of the stack.
 * 
 * top() -- Get the top element.
 * 
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 *               
 **********************************************************************************/
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    void push(int x) {
    	m_data.push(x);
    	if (m_min.empty())
    		m_min.push(x);
    	else if (x < m_min.top())
    		m_min.push(x);
    	else
    		m_min.push(m_min.top());
    }

    void pop() {
    	if (!m_data.empty() && !m_min.empty()) {
    		m_data.pop();
    		m_min.pop();
    	}
    }

    int top() {
    	return m_data.top(); 
    }

    int getMin() {
    	return m_min.top();
    }
private:
	stack<int> m_data;
	stack<int> m_min;
};

int main()
{
	MinStack ms;
	for (int i = 1; i <= 5; ++i)
		ms.push(i);
	cout << ms.getMin() << endl;
}
