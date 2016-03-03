/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Oct 5, 2013
 Problem:    Single Number II
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/single-number-ii/
 Notes:
 Given an array of integers, every element appears three times except for one. 
 Find that single one.
 Your algorithm should have a linear runtime complexity. Could you implement it 
 without using extra memory?

 Solution: Count the number of each bit.
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int c = 0;
            for (int x : nums) 
                if ((x >> i) & 1) {c++;}
            if (c % 3) {ans |= 1 << i;}
        }
        return ans;
    }
};

class Solution {
public:
    int singleNumber(int A[], int n) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int count = 0, bit = 1 << i;
            for (int j = 0; j < n; ++j)
                if (A[j] & bit)
                    count++;
            if (count % 3 != 0)
                res |= bit;
        }
        return res;
    }
};

class Solution {
public:
    int singleNumber(int A[], int n) {
        int res = 0;
        int bits[32] = {0};
        for (int i = 0; i < 32; i++) {
            for(int j = 0; j < n; j++) {
                bits[i] += A[j] >> i & 1;
                bits[i] %= 3;
            }
            res |= (bits[i] << i);
        }
        return res;
    }
};