//Summary Ranges
/*
Difficulty: Easy
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        for (int cur = 0; cur < nums.size(); ) {
            int next = cur + 1;
            while (next < nums.size() && nums[next] == nums[next - 1] + 1)
                next++;
            // A new range
            if (next == cur + 1) {
                ans.push_back(to_string(nums[cur]));
            } else {
                ans.push_back(to_string(nums[cur]) + "->" + to_string(nums[next - 1]));
            }
            cur = next;
        }
        return ans;
    }
};