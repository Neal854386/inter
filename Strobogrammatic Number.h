/*
Strobogrammatic Number

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

For example, the numbers "69", "88", and "818" are all strobogrammatic.
*/


class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> ref({
            {'0','0'}, {'1','1'}, {'6','9'},
            {'8','8'}, {'9','6'}
        });
        int l = 0;
        int r = num.length()-1;
        while (l <= r) {
            if (!ref.count(num[l]) || num[r] != ref[num[l]])
                return false;
            l++, r--;
        }
        return true;
    }
};