/*
 Author:     Min
 Date:       Jan 13, 2015
 Problem:    Compare Version Numbers
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/compare-version-numbers/
 Notes:
 Compare two version numbers version1 and version1.
 If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

 You may assume that the version strings are non-empty and contain only digits and the . character.
 The . character does not represent a decimal point and is used to separate number sequences.
 For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

 Here is an example of version numbers ordering:

 0.1 < 1.1 < 1.2 < 13.37
*/

 class Solution {
public:
    int compareVersion(string version1, string version2) {
        size_t i = 0, j = 0;
        string str_1 = "0", str_2 = "0";
        while (i < version1.size() || j < version2.size()) {
            while (str_1.back() != '.' && i < version1.size()) {str_1 += version1[i++];}
            while (str_2.back() != '.' && j < version2.size()) {str_2 += version2[j++];}
            if (stoi(str_1) > stoi(str_2)) {
                return 1;
            } else if (stoi(str_1) < stoi(str_2)) {
                return -1;
            }
            str_1 = "0";
            str_2 = "0";
        }
        return 0;
    }
};