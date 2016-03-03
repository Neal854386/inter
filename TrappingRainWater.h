/*
 Author:     Annie Kim, anniekim.pku@gmail.com : King, higuige@gmail.com
 Date:       May 25, 2013
 Update:     Oct 07, 2014
 Problem:    Trapping Rain Water
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_42
 Notes:
 Given n non-negative integers representing an elevation map where the width of 
 each bar is 1, compute how much water it is able to trap after raining.
 For example, 
 Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

 Solution: 1. Find left bound and right bound for each element. O(n).
           2. more space efficiency. Time: O(n), Space: O(1);
*/



class Solution {
public:
    int trap(int A[], int n) {
        if (n == 0) return 0;
        vector<int> maxLeft(n,0);
        vector<int> maxRight(n,0);
        maxLeft[0] = A[0];
        maxRight[n - 1] = A[n - 1];
        for (int i = 1; i < n; ++i) {
            maxLeft[i] = max(maxLeft[i - 1], A[i]);
            maxRight[n - 1 - i] = max(maxRight[n - i], A[n - 1 - i]);
        }
        
        int res = 0;
        for (int i = 1; i < n; ++i) {
            res += min(maxLeft[i], maxRight[i]) - A[i];
        }
        return res;
    }
    int trap_2(int A[], int n) {
        if (A == NULL || n <= 2) return 0;
        int left= 1;
        int right = n - 2;
        int maxLeft = A[0];
        int maxRight = A[n - 1];
        int res = 0;
        while (left <= right) {
            if (maxLeft <= maxRight) {
                res += max(0, maxLeft - A[left]);
                maxLeft = max(maxLeft, A[left]);
                ++left;
            } else {
                res += max(0, maxRight - A[right]);
                maxRight = max(maxRight, A[right]);
                --right;
            }
        }
        return res;
    }

    class Solution {
public:
    int trap(vector<int>& heights) {
        int left = 0, right = heights.size() - 1;
        int res = 0;
        if (heights.empty()) {return res;}
        int leftHeight = heights[left], rightHeight = heights[right];
        while (left < right - 1) {
            if (leftHeight < rightHeight) {
                left++;
                if (leftHeight > heights[left]) {
                    res += leftHeight - heights[left];
                } else {
                    leftHeight = heights[left];
                }
            } else {
                right--;
                if (rightHeight > heights[right]) {
                    res += rightHeight - heights[right];
                } else {
                    rightHeight = heights[right];
                }
            }
        }
        return res;
    }
};

};
