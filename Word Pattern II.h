/*
Word Pattern II
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.

Examples:
pattern = "abab", str = "redblueredblue" should return true.
pattern = "aaaa", str = "asdasdasdasd" should return true.
pattern = "aabb", str = "xyzabcxzyabc" should return false.
Notes:
You may assume both pattern and str contains only lowercase letters.
*/

class Solution {
public:
    unordered_set<string> used;
    unordered_map<char, string> dict;

    bool wordPatternMatch(string pattern, string str) {
        return helper(pattern, 0, str, 0);
    }

    bool helper(string& pattern, int i, string& str, int j) {
        int p_end = pattern.length(), s_end = str.length();
        if (i == p_end && j == s_end) return true;
        if (i == p_end || j == s_end) return false;
        char c = pattern[i];
        
        if (dict.count(c)) {
            string s = dict[c];
            int l = s.length();
            if (s != str.substr(j, l)) return false;
            return helper(pattern, i + 1, str, j + l);
        } 

        for (int k = j; k < s_end; k++) {
            string s = str.substr(j, k - j + 1);
            if (used.count(s)) continue;
            dict[c] = s;
            used.insert(s);
            if (helper(pattern, i + 1, str, k + 1)) {
            	return true;
            }
            used.erase(s);
            dict.erase(c);
        }
        return false;
    }
};