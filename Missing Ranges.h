// Missing Ranges
/*
Difficulty: Medium
Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.

For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
*/

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        int s = lower - 1;
        for (int x : nums) {
            if (x - 1 != s) {
                if (x - 2 == s) {
                    ans.push_back(to_string(x - 1));
                } else {
                    ans.push_back(to_string(s + 1) +"->" + to_string(x - 1));
                }
            }
            s = x;
        }
        
        if (s != upper) {
            if (upper - 1 == s) {
                ans.push_back(to_string(upper));
            } else {
                ans.push_back(to_string(s + 1) + "->" + to_string(upper));
            }
        }

        return ans;
    }
};