/*
 Author:     Annie Kim, anniekim.pku@gmail.com : King, higuige@gmail.com
 Date:       Apr 8, 2013
 Update:     Nov 18, 2014
 Problem:    Search in Rotated Sorted Array II
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_81
 Notes:
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 What if duplicates are allowed?
 Would this affect the run-time complexity? How and why?
 Write a function to determine if a given target is in the array.

 Solution: Sequence search. O(n)
           Since there are duplicates, it's hard to decide which branch to go if binary-search is deployed.
 */

class Solution {
public:
    bool search(int A[], int n, int target) {
        for (int i = 0; i < n; i++)
            if (A[i] == target)
                return true;
        return false;
    }
    bool search_2(int A[], int n, int target) {
        if (A == NULL) return -1;
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) /2;
            if (A[mid] == target) return true;
            if (A[left] < A[mid]) {
                if (A[left] <= target && target < A[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (A[left] > A[mid]) {
               if (A[mid] < target && target <= A[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                } 
            } else {
                if (A[mid] == A[right]) {
                    ++left, --right;
                } else {
                    left = mid + 1;
                }
            }
        }
        return false;
    }
};



class Solution {
    /** 
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean 
     */
public:
    bool search(vector<int> &A, int target) {
        // write your code here
        if (A.empty()) {return false;}
        int start = 0, end = A.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] == target) {
                return true;
            } else if (A[mid] == A[start] || A[start] == A[end]) {
                start++;
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
        
        if (A[start] == target || A[end] == target) {return true;}
        return false;
    }
};