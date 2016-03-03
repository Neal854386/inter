/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 21, 2013
 Update:     Jul 12, 2013
 Problem:    Jump Game
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_55
 Notes:
 Given an array of non-negative integers, you are initially positioned at the first index of the array.
 Each element in the array represents your maximum jump length at that position.
 Determine if you are able to reach the last index.
 For example:
 A = [2,3,1,1,4], return true.
 A = [3,2,1,0,4], return false.

 Solution: Updated solution: try every reachable index. 
           Thank to Wenxin Xing for kindly feedback and pointing out my big mistake:)
 */

// greedy
class Solution {
public:
    bool canJump(int A[], int n) {
        int start = 0, end = 0;
        while (start <= end && end < n-1)
        {
            end = max(end, start + A[start]);
            start++;
        }
        return end >= (n-1);
    }
};

class Solution {
public:
    bool canJump(int A[], int n) {
        int max_index = 0;
        for (int i = 0; i < n; i++) {
            if (i <= max_index) {
                max_index = max(max_index, i + A[i]);
            }
        }
        return max_index >= n - 1;  
    }
};

// dp
class Solution {
public:
    bool canJump(int A[], int n) {
        int dp[n];  
        dp[0] = 0;  
        for(int i = 1; i < n; i++) {  
            dp[i] = max(dp[i - 1], A[i - 1]) - 1;  
            if(dp[i] < 0) {   
                return false;
            }
        }  
        return dp[n - 1] >=0;  
    }
};