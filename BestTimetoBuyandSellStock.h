/*
 Author:     Annie Kim, anniekim.pku@gmail.com : King, higuige@gmail.com
 Date:       Apr 28, 2013
 Update:     Oct 07, 2014
 Problem:    Best Time to Buy and Sell Stock
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_121
 Notes:
 Say you have an array for which the ith element is the price of a given stock on day i.
 If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
 design an algorithm to find the maximum profit.

 Solution: For each element, calculate the max difference with the former elements.
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty() || prices.size() < 2) {
            return 0;
        }
        int cur_min = prices[0], profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            profit = max(profit, prices[i] - cur_min);
            cur_min = min(cur_min, prices[i]);
        }
        return profit;
    }
};


class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int low = INT_MAX, ret = 0;
    
        for (auto i : prices) {
            low = min(low, i);
            ret = max(ret, i - low);
        }    
        return ret;
    }
};

/*

1) find maximal profit
input>> 4,3,6,2,4,8,1,3
output>> 2,8,6
*/

int maxProfit(vector<int> &prices) {
    if (prices.empty() || prices.size() < 2) {
        return 0;
    }
    int cur_min = prices[0], profit = 0, buy_var = 0, sell_var = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] - cur_min > profit) {
                profit = prices[i] - cur_min;
                buy_var = cur_min;
                sell_var = prices[i];
            }
            cur_min = min(cur_min, prices[i]);
    }
    return profit;
}
