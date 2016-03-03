/*
 Author:     King, wangjingui@outlook.com
 Date:       Dec 06, 2014
 Problem:    Find Peak Element
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/find-peak-element/
 Notes:
 A peak element is an element that is greater than its neighbors.
 Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
 You may imagine that num[-1] = num[n] = -∞.
 For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

 Find the peak element.
*/

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int n = num.size();
        int left = 0, right = n - 1,mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if ((mid == 0 || num[mid-1] <= num[mid]) && (mid == n -1 || num[mid+1] <= num[mid]))
                return mid;
            if (mid > 0 && num[mid - 1] > num[mid]) {
                right = mid - 1;
            } else if (num[mid + 1] > num[mid]) {
                left = mid + 1;
            }
        }
        return mid;
    }
};

class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> num) {
        // write your code here
        if (num.empty()) {
            return INT_MIN;
        }
        
        int start = 0, end = num.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (num[mid] > num[mid - 1] && num[mid] > num[mid + 1]) {
                return mid;
            } else {
                if (num[mid] < num[mid + 1]) {
                    start = mid;
                } else {
                    end = mid;
                }
            }
        }
        return num[start] > num[end] ? start : end;
    }
};

