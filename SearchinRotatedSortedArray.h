/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 8, 2013
 Update:     Aug 7, 2013
 Problem:    Search in Rotated Sorted Array
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_33
 Notes:
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 You are given a target value to search. If found in the array return its index, otherwise return -1.
 You may assume no duplicate exists in the array.

 Solution: Binary search. O(lgn) eg. [4 5 6] -7- 8 1 2, 5 6 0 -1- [2 3 4]
 */

class Solution {
public:
    int search(int A[], int n, int target) {
        int i = 0, j = n - 1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (A[mid] == target)
                return mid;
            if (A[i] <= A[mid])
            {
                if (A[i] <= target && target < A[mid])
                    j = mid - 1;
                else
                    i = mid + 1;
            }
            else
            {
                if (A[mid] < target && target <= A[j])
                    i = mid + 1;
                else
                    j = mid - 1;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int search(int A[], int n, int target) {
        int start = 0, end = n - 1, mid;
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (A[mid] == target) {
                return mid;
            }
            if (A[start] < A[mid]) {
                // in higher part
                if (A[start] <= target && target < A[mid]) {
                    end = mid;
                }
                else {
                    start = mid;
                }
            }
            else {
                // in lower part
                if (A[mid] < target && target <= A[end]) {
                    start = mid;
                }
                else {
                    end = mid;
                }
            }
        }
        if (A[start] == target) {return start;}
        if (A[end] == target) {return end;}
        return -1;
    }
};

class Solution {
    /** 
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        // write your code here
        if (A.empty()) {return -1;}
        int start = 0, end = A.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] == target) {
                return mid;
            } else if (A[mid] > A[start]) {
                // in higher part
                if (A[start] <= target && target < A[mid]) {
                    end = mid;
                } else {
                    start = mid;
                }    
            } else {
                // in lower part
                if (A[mid] < target && target <= A[end]) {
                    start = mid;
                } else {
                    end = mid;
                }
            }
        }
        
        if (A[start] == target) {return start;}
        if (A[end] == target) {return end;}
        return -1;
    }
};
