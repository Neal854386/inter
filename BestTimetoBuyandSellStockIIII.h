/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 28, 2013
 Update:     Aug 22, 2013
 Problem:    https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
 Difficulty: HARD
 Notes:
 Say you have an array for which the ith element is the price of a given stock on day i.

 Design an algorithm to find the maximum profit. You may complete at most k transactions.

 You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 
 */



class Solution {
 public:
  int maxProfit(vector<int> prices, int k) {
        // write your solution here.
        int len = prices.size();
        if (len < 2) return 0;
        if (k > len / 2){ // simple case, means you can sell and buy int everyday
            int res = 0;
            for (int i = 1; i< len; ++i){
                res += max(prices[i] - prices[i - 1],0);
            }
            return res;
        }
        
        int hold[k + 1];
        int rele[k + 1];
        for (int i = 0;i <= k; i++){
            hold[i] = INT_MIN; rele[i] = 0;
        }
        
        int cur;
        for (int i = 0; i < len; i++){
            cur = prices[i];
            for(int j = k; j > 0; j--){
                rele[j] = max(rele[j], hold[j] + cur);
                hold[j] = max(hold[j], rele[j - 1] - cur);
            }
        }
        return rele[k];
  }
};