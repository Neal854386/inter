/*
Longest Increasing Subsequence

Given a sequence of integers, find the longest increasing subsequence (LIS).

You code should return the length of the LIS.

Example
For [5, 4, 1, 2, 3], the LIS  is [1, 2, 3], return 3

For [4, 2, 4, 5, 3, 7], the LIS is [4, 4, 5, 7], return 4

Challenge
Time complexity O(n^2) or O(nlogn)

Clarification
What's the definition of longest increasing subsequence?

    * The longest increasing subsequence problem is to find a subsequence of a given sequence in which the subsequence's elements are in sorted order, lowest to highest, and in which the subsequence is as long as possible. This subsequence is not necessarily contiguous, or unique.  

    * https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
*/

class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        int dp[nums.size()];
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
             dp[i] = 1;
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {   // MAX(dp[j] + 1, j < i && nums[j] <= nums[i])
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[j] + 1, dp[i]);   
                }
            }
            res = max(dp[i], res);
        }
        return res;
    }
};