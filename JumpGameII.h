/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 21, 2013
 Update:     Aug 22, 2013
 Problem:    Jump Game II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_45
 Notes:
 Given an array of non-negative integers, you are initially positioned at the first index of the array.
 Each element in the array represents your maximum jump length at that position.
 Your goal is to reach the last index in the minimum number of jumps.
 For example:
 Given array A = [2,3,1,1,4]
 The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

 Solution: Jump to the position where we can jump farthest (index + A[index]) next time.
 */

// dp
class Solution {
 public:
  int minJump(vector<int> input) {
    // write your solution here.
    int dp[input.size()];
    int step = 0;
    dp[0] = 0;
    for (int i = 1; i < input.size(); i++) {
          if (input[i - 1] > dp[i - 1]) {step++;}
          dp[i] = max(input[i - 1], dp[i - 1]) - 1;
          if (dp[i] < 0) {return -1;}
    }
    return step;
  }
};

class Solution {
public:
    int jump(int A[], int n) {
        int start = 0;
        int res = 0;
        while (start < n-1)
        {
            res++;
            if (start + A[start] >= n-1)
                return res;
            int mx = start;
            for (int i = start + 1; i <= start + A[start]; ++i)
                if (i + A[i] >= mx + A[mx])
                    mx = i;
            start = mx;
        }
    }
};

class Solution {
public:
    int jump(int A[], int n) {
        int steps = 0, max_index = 0, curr = 0;

        for(int i = 0; i < n; i++) {
            if (i > max_index) {
                //  if not last one and can't go further
                if (curr == max_index && max_index < n - 1) {return -1;} // never reach the last one
                max_index = curr; steps++;
            }
            curr = max(curr, i + A[i]);
        }

        return steps;
    }
};