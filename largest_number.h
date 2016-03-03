/*
 Author:     Xingmin Han
 Date:       Apr 10, 2013
 Update:     Aug 17, 2013
 Problem:    Largest Number 
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/largest-number/
 Notes:
 Given a list of non negative integers, arrange them such that they form the largest number.For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 Note: The result may be very large, so you need to return a string instead of an integer.
*/

class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> arr;
        for(auto i : num) {
            arr.push_back(to_string(i));
        }

        // sort the string 
        sort(begin(arr), end(arr), [](string &s1, string &s2){ return s1 + s2 > s2 + s1; });
        string res;
        for(auto s : arr) {
            res += s;
        }

        // avoid case like: [00]
        while(res[0] == '0' && res.length() > 1) {
            res.erase(0, 1);
        }
        return res;
    }
};