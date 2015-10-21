// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Author : wind4869
// Date   : 2015-04-10

/********************************************************************************** 
 * 
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * 
 * If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
    	if (prices.empty()) return 0;
    	
    	int size = prices.size();
        if (size == 0) return 0;

        int res = 0, minPrice = prices[0];
        for (int i = 1; i < size; ++i) {
        	minPrice = min(prices[i], minPrice);
        	int temp = prices[i] - minPrice;
        	if (res < temp) res = temp;
        }

        if (res < 0) return 0;
        return res;
    }
};

int main()
{
	vector<int> prices = {3, 2, 1};
	cout << Solution().maxProfit(prices) << endl;
}


