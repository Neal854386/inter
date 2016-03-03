/*
Strobogrammatic Number II

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Find all strobogrammatic numbers that are of length = n.

For example,
Given n = 2, return ["11","69","88","96"].
*/

class Solution {
private:
    unordered_map<char, char> ref;
    vector<char> str;
    void generate(int index, int n, string &num, vector<string> &ans) {
        // base case, set the last char in the mid
        if (index == n >> 1) {
            if (n & 1) {    
                for (int x : {'0','1','8'})
                    num[index] = x, ans.push_back(num);
            } else {
                ans.push_back(num);
            }
            return;
        }
		// set left side and right side, the first elemt can't be zero
		// so if the index == 0, the index for string should start in 1
        for (int i = (index ? 0 : 1); i < 5; i++) {
            num[index] = str[i];
            num[n - index - 1] = ref[str[i]];
            generate(index + 1, n, num, ans);
        }
    }
public:
    vector<string> findStrobogrammatic(int n) {
        str = {'0','1','6','8','9'};
        ref = {
            {'0','0'}, {'1','1'}, {'6','9'},
            {'8','8'}, {'9','6'}
        };
        vector<string> ans;
        string num(n, '0');
        generate(0, n, num, ans);
        return ans;
    }
};