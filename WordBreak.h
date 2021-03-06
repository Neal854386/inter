/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Oct 6, 2013
 Problem:    Word Break
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/word-break/
 Notes:
 Given a string s and a dictionary of words dict, determine if s can be segmented into 
 a space-separated sequence of one or more dictionary words.
 For example, given
 s = "leetcode",
 dict = ["leet", "code"].
 Return true because "leetcode" can be segmented as "leet code".

 Solution: dp.
*/

class Solution {
public:
    /*
    dp[i]：S[0:i-1]是否能被break。例如dp[1]表示s[0]是否能被break。
    dp[0] = true
    dp[i] = true if and only if:
    1. 存在一个i - 1 >= k >= 0，使s[k : i - 1]存在于dict中。
    2. s[0: k - 1]可以被break，即dp[k] = true。
    */
    bool wordBreak(string s, unordered_set<string> &dict) {
        bool canBreak[s.size() + 1];
        memset(canBreak, false, sizeof(canBreak));
        canBreak[0] = true;
        for (int i = 1; i < s.size() + 1; i++) {
            for (int j = 0; j < i; j++) {
                if (canBreak[j] && dict.count(s.substr(j, i - j))) {
                    canBreak[i] = true;
                    break;
                }
            }
        }
        return canBreak[s.size()];
    }
};

//Time: O(string length * dict size)
class Solution {
    bool wordBreak(string s, unordered_set<string> &dict) {
        bool dp[s.size() + 1];
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        
        for(int i = 0; i < s.size(); i++){
            //should continue from match position
            if(!dp[i]) {continue;}
            
            for(auto word: dict){
                int len = word.size();
                int end = i + len;
                if(end > s.size()) continue;
                
                if(dp[end]) continue;
                
                if(s.substr(i, end) == word) {
                    dp[end] = true;
                }
            }
        }
        
        return dp[s.size()];
    }
};
