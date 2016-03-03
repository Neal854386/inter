/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 21, 2013
 Problem:    Maximum Product Subarray
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_53
 Notes:
 Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 For example, given the array [2,3,-2,4],
 the contiguous subarray [2,3] has the largest product = 6.
 Solution: dp.
 */

class Solution {
public:
    int maxProduct(int A[], int n) {
        int max_local = A[0], min_local = A[0], global = A[0];  
        for(int i = 1; i < n;i++)  {  
            int max_copy = max_local;  
            max_local = max(max(A[i] * max_local, A[i]), A[i] * min_local);  
            min_local = min(min(A[i] * max_copy, A[i]), A[i] * min_local);  
            global = max(global, max_local);  
        }  
        return global;  
    }
};