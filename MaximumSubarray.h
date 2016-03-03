/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 21, 2013
 Problem:    Maximum Subarray
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_53
 Notes:
 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 For example, given the array [-2,1,-3,4,-1,2,1,-5,4], the contiguous subarray [4,-1,2,1] has the largest sum = 6.

 Solution: dp.
 */

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int res = A[0];
        int dp = A[0];
        for (int i = 1; i < n; ++i) {
            dp = max(A[i], dp + A[i]);
            res = max(dp, res);
        }
        return res;
    }
};


class Solution {
public:
    int maxSubArray(int A[], int n) {
        int local = A[0];
        int global = A[0];
        for (int i = 1; i < n; i++) {
            local = max(A[i], local + A[i]);
            global = max(local, global);
        }      
        return global;
    }
};

//return the index for subarray
class Solution{
public:
    vector<int> maxSubArray(int A[], int n) {
        int lastMax = A[0], global_max = A[0];
        int start = 0, end = 0;
        vector<int> res(2, 0); 
        for(int i = 1; i < n; i++){
            if (lastMax < 0) {  
                start = i;  
                lastMax = A[i];  
            }  
            else {
                lastMax = lastMax + A[i]; 
            } 
            end = i;  
            if(lastMax > global_max) {  
                global_max = lastMax;  
                res[0] = start;  
                res[1] = end;  
            }  
        }  
        return res;
    }
};
