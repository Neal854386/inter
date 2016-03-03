/*
 Author:     King, higuige@gmail.com
 Date:       Oct 22, 2014
 Problem:    Find Minimum in Rotated Sorted ArrayII
 Difficulty: Hard
 Source:     https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
 Notes:
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

 Find the minimum element.

 The array may contain duplicates.
*/
class Solution {
public:
    int findMin(vector<int> &num) {
        if(num.empty()) return 0;
        int size = num.size();
        int left = 0;
        int right = size - 1;
        while (left < right && num[left] >= num[right]) {
            int mid = (left + right) / 2;
            if (num[mid] > num[right]) {
                left = mid + 1;
            } else if (num[mid] < num[left]) {
                right = mid;
            } else {
                ++left;
            }
        }
        return num[left];
    }
};


class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        if (num.empty()) {return -1;}
        int start = 0, end = num.size() - 1;
        
        while(start + 1 < end && num[start] >= num[end]) {
            int mid = start + (end - start) / 2;
            if (num[mid] > num[end]) {
                start = mid;
            } else if (num[mid] < num[start]) {
                end = mid;
            } else {
                start++;
            }
        }
        return min(num[start], num[end]);
    }
};
