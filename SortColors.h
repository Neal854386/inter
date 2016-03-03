a/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 8, 2013
 Update:     Jul 24, 2013
 Problem:    Sort Colors
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_75
 Notes:
 Given an array with n objects colored red, white or blue, sort them so that objects of the same color
 are adjacent, with the colors in the order red, white and blue.
 Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 Note:
 You are not suppose to use the library's sort function for this problem.
 Follow up:
 A rather straight forward solution is a two-pass algorithm using counting sort.
 First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with 
 total number of 0's, then 1's and followed by 2's.
 Could you come up with an one-pass algorithm using only constant space?

 Solution: 0 0 0 1 1 1 1 ...... 2 2 2 2
               |         |      |
             zero        i     two
              ->        ->     <-  
 */

class Solution {
public:
    void sortColors(int A[], int n) {
        int zero = -1, two = n;
        int i = 0;
        while (i < two)
        {
            switch(A[i])
            {
            case 0:
                swap(A[i++], A[++zero]);
                break;
            case 1:
                i++;
                break;
            case 2:
                swap(A[i], A[--two]);
            }
        }
    }
};

class Solution {
public:
    void sortColors(int A[], int n) {
        int first_index = 0, last_index = n - 1;
        // if just has 0, or 2, skip
        while (A[first_index] == 0) {first_index++;}
        while (A[last_index] == 2) {last_index--;}
        
        int cur = first_index; 
        while (cur <= last_index) {
            if (A[cur] == 0 && cur > first_index) {
                swap(A[cur], A[first_index]); first_index++; continue;
            }
            if (A[cur] == 2) {
                swap(A[cur], A[last_index]); last_index--; continue;
            }
            cur++; 
        }
    }
};

class Solution {
public:
    vector<int> rainbowSort(vector<int> a) {
        if (a.empty()) {return a;}
        // the idx is the start of sorted part
        // 0 , 1,  2
        int idx = partition(a, 0, a.size() - 1, 0);
        partition(a, idx, a.size() - 1, 1);
        return a;
    }
    
    int partition(vector<int> &a, int first_idx, int last_idx, int target) {
        while (first_idx <= last_idx) {
            while (first_idx <= last_idx && a[first_idx] == target) {
                first_idx++;
            }
            while (first_idx <= last_idx && a[last_idx] != target) {
                last_idx--;
            }
            
            if (first_idx <= last_idx) {
                swap(a[first_idx++], a[last_idx--]);
            }
        }
        return first_idx;
    }
};
