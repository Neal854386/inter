/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 10, 2013
 Update:     Aug 7, 2013
 Problem:    Merge Sorted Array
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_88
 Notes:
 Given two sorted integer arrays A and B, merge B into A as one sorted array.
 Note:
 You may assume that A has enough space to hold additional elements from B. 
 The number of elements initialized in A and B are m and n respectively.

 Solution: From back to forth.
 */

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int a_i = m - 1;
        int b_i = n - 1;
        int res_i = m + n - 1;
        while (a_i >= 0) {
            if (A[a_i] >= B[b_i]) {
                A[res_i--] = A[a_i--];
            } else {
                A[res_i--] = B[b_i--];
            }
        }
        
        while (b_i >= 0) {
            A[res_i--] = B[b_i--];
        }
        return;
    }
};
