/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 20, 2013
 Problem:    Decode Ways
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_91
 Notes:
 A message containing letters from A-Z is being encoded to numbers using the following mapping:
 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
 Given an encoded message containing digits, determine the total number of ways to decode it.
 For example,
 Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 The number of ways decoding "12" is 2.

 Solution: 1. dp. Note that '0' must be decoded in together with the number in front of it.
           2. dp. Time : O(n); Space : O(1).
 */

/*
维护一个一维数组，dp[length]。dp[i]表示字符串 i ~ length的decode ways。
初始状态：dp[length] = 0; dp[length - 1] = dp[length - 1] = s.charAt(length - 1) == '0' ? 0 : 1;
每次读取num = s.substring(i, i + 2)
如果大于26，则dp[i] = dp[i + 1];
如果小于等于26，则dp[i] = dp[i + 1] + dp[i + 2];
*/

class Solution {
public:
    int numDecodings_1(string s) {
        if (s.empty() || s[0] == '0') 
            return 0;
        int N = s.size();
        int dp[N + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1; i < N; ++i)
        {
            if (s[i] == '0')
            {
                if (s[i-1] != '1' && s[i-1] != '2')
                    return 0;
                dp[i+1] = dp[i-1];
            }
            else
            {
                int num = s[i] - '0' + (s[i-1] - '0') * 10;
                if (num >= 11 && num <= 26)
                    dp[i+1] = dp[i] + dp[i-1];
                else
                    dp[i+1] = dp[i];
            }
        }
        return dp[N];
    }
    int numDecodings_2(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int N = s.size();
        int f0 = 1, f1 = 1;
        for (int i = 1; i < N; ++i) {
            if (s[i] == '0') f1 = 0;
            int num = s[i] - '0' + (s[i-1] - '0') * 10;
            if (num < 10 || num > 26) {
                f0 = 0;
            }
            int tmp = f1;
            f1 = f1 + f0;
            f0 = tmp;
        }
        return f1;
    }
};



class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        int dp[len + 1];
        memset(dp, 0, sizeof(dp));
        if (len == 0 || s[0] == '0')  return 0;  
        if (len == 1)  return 1;
        dp[0] = 1; dp[1] = 1;
        for(int i = 2; i <= len; i++) {         
            if (is_valid(s.substr(i - 1, 1))) {
                dp[i] = dp[i - 1];
            } 
            
            if (is_valid(s.substr(i - 2, 2))){
                dp[i] = dp[i] + dp[i - 2];
            }
        }
        return dp[len];
    }
    
    bool is_valid(string input) {
        if (input[0] == '0') return false;
        int num = stoi(input);
        return 1 <= num && num <= 26;
    }
};