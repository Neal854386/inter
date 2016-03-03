/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 13, 2013
 Problem:    Integer to Roman
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_12
 Notes:
 Given an integer, convert it to a roman numeral.
 Input is guaranteed to be within the range from 1 to 3999.

 Solution: Buffer the roman numbers.
 */

class Solution {
public:
    const string rom[4][10] = {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                               {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                               {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                               {"", "M", "MM", "MMM"}};
    string intToRoman(int num) {
        string res;
        int i = 3;
        while (num > 0)
        {
            int divisor = (int)pow(10, i);
            res += rom[i][num / divisor];
            num %= divisor;
            i--;
        }
        return res;
    }
};


class Solution {
public:
    const int nums[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const string symbols[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    string intToRoman(int num) {
        if(num <= 0) {return "";}
        string res;
        int digit = 0;
        while (num > 0) {
            int times = num / nums[digit];
            num -= nums[digit] * times;
            while (times > 0) {
                res += symbols[digit]; times--;
            }
            digit++;
        }
        return res;
    }
};

