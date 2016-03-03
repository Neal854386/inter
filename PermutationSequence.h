/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 8, 2013
 Update:     Aug 12, 2013
 Problem:    Permutation Sequence
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_60
 Notes:
 The set [1,2,3,...,n] contains a total of n! unique permutations.
 By listing and labeling all of the permutations in order,
 We get the following sequence (ie, for n = 3):
 "123"
 "132"
 "213"
 "231"
 "312"
 "321"
 Given n and k, return the kth permutation sequence.
 Note: Given n will be between 1 and 9 inclusive.

 Solution: ...
 */

class Solution {
public:
    string getPermutation(long long n, long long k) {
        string num, res;
        int total = 1;
        for (int i = 1; i <= n; ++i) {
            num.push_back(i + '0');
            total *= i;
        }
        k--;
        while (n) {
            total /= n;
            int i = k / total;
            k %= total;
            res.push_back(num[i]);
            num.erase(i, 1);
            n--;
        }
        return res;
    }
};


vector<int> getPermutation(long long n, long long k) {  
    if (n <= 0) {   
        return vector<int>();
    }  
    long long factorial = 1;  
    vector<int> res;  
    vector<int> nums;  
    for (int i = 2; i < n; i++) {  
        factorial *= i;  
    }
  
    for(int i = 1; i <= n; i++) {  
        nums.push_back(i);  
    } 
 
    long long round = n - 1;  

    while(round >= 0) {  
        long long index = k / factorial;  
        k %= factorial;  
        res.push_back(nums[index]);  
        nums.erase(nums.begin() + index);  
        if (round > 0) {
              factorial /= round;  
        }     
        round--;  
    } 
    return res;  
}  

