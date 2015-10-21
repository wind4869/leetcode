// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Author : wind4869
// Date   : 2015-04-27

/********************************************************************************** 
 * 
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int minPrice = INT_MAX, profit = 0;

        for (int i = 0; i < size; ++i) {
        	if (prices[i] < minPrice) {
        		minPrice = prices[i];
        	} else if (i == size - 1 || prices[i] > prices[i + 1]) {
        		profit += prices[i] - minPrice;
        		minPrice = prices[i];
        	}
        }

        return profit;
    }
};

int main()
{
	vector<int> prices = {3, 4, 1};
	cout << Solution().maxProfit(prices) << endl;
}
