/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 13, 2013
 Update:     Sep 22, 2013
 Problem:    Roman to Integer
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_13
 Notes:
 Given a roman numeral, convert it to an integer.
 Input is guaranteed to be within the range from 1 to 3999.

 Solution: use <map> or <unordered_map> (clean)
 */

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman;
        roman['M'] = 1000;
        roman['D'] = 500;
        roman['C'] = 100;
        roman['L'] = 50;
        roman['X'] = 10;
        roman['V'] = 5;
        roman['I'] = 1;

        int res = 0, N = s.size();
        for (int i = 0; i < N; ++i) {
            if (i < N-1 && roman[s[i]] < roman[s[i+1]])
                res -= roman[s[i]];
            else
                res += roman[s[i]];
        }
        return res;
    }
};

class Solution {
public:
	int romanToInt(string s) {
	    map<char, int> tb = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
	    
	    int value = 0;
	    int last = 0;
	    for(int i = s.size() - 1; i >= 0; --i) {
	        auto cur = tb[s[i]];
	        if(cur >= last) {
	            value += cur;
	        } else {
	            value -= cur;
	        }
	        last = cur;
	    }
	    
	    return value;
	}
};
