/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 18, 2013
 Problem:    Search Insert Position
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_35
 Notes:
 Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 You may assume no duplicates in the array.
 Here are few examples.
 [1,3,5,6], 5 -> 2
 [1,3,5,6], 2 -> 1
 [1,3,5,6], 7 -> 4
 [1,3,5,6], 0 -> 0

 Solution: Binary search.
 */

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int i = 0, j = n - 1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (A[mid] == target)
                return mid;
            if (A[mid] < target)
                i = mid + 1;
            else
                j = mid - 1;
        }
        return i;
    }
};

class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        if (A.empty()) {return -1;};
        
        int start = 0, end = A.size() - 1;
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] == target) {
                return mid;
            } else if (A[mid] > target) {
                end = mid;
            } else {
                start = mid;
            }
        }
        
        if (A[end] < target) {
            return end + 1;
        } else if (A[start] < target && target <= A[end]) {
            return end;  
        } else if (target <= A[start]) {
            return start;
        }
        return -1;
    }
};
