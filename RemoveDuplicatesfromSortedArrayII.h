/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 10, 2013
 Update:     Jul 16, 2013 [Two pointers ('last' and 'lastlast').]
 Problem:    Remove Duplicates from Sorted Array II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_80
 Notes:
 Follow up for "Remove Duplicates":
 What if duplicates are allowed at most twice?
 For example,
 Given sorted array A = [1,1,1,2,2,3],
 Your function should return length = 5, and A is now [1,1,2,2,3].

 Solution: ...
 */

class Solution {
public:
    int removeDuplicates(vector<int>& s) {
        if (s.size() <= 2) {
            return s.size();
        }
        int j = 2;
        for (int i = 2; i < s.size(); i++) {
            if (s[i] != s[j - 1] || s[i] != s[j - 2]) {
			    s[j++] = s[i];
		    }		
        }
        return j;
    }
};