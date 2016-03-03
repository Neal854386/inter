/*
Shortest Palindrome
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".
*/

class Solution {
 public:
    string getPali(string &s, int mid, bool odd) {
        string prepend = "";
        int left, right;
        if (odd) {
            left = mid - 2; right = mid;
        } else {
            left = mid - 1; right = mid;
        }
         
        while (right < s.length()) {
            if (left < 0) {
                prepend.push_back(s[right++]);
            } else {
                if (s[left] != s[right]) {
                    return "";
                } else {
                    left--; right++;
                }
            }
        }
         
        return prepend + s;  
    }
    
    string shortestPalindrome(string s) {
        if (s.length() == 1) {return s;}
        int mid = s.length() / 2;
        for (int i = mid; i >= 0; i--) {
            string res = getPali(s, i, false);
            if (!res.empty()) {return res;}
            
            res = getPali(s, i, true);
            if (!res.empty()) {return res;}
        }
        return "";
    }
};