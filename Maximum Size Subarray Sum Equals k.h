/*
325. Maximum Size Subarray Sum Equals k
Difficulty: Easy
Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Example 1:
Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

Example 2:
Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)
*/

class Solution {
public:
    // O(n) complexity.
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int sum = 0, maxLen = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum == k) {
                maxLen = i + 1;
            } else if (m.count(sum - k)) {
                maxLen = max(maxLen, i - m[sum - k]);
            }
            
            if (!m.count(sum)) {
                m[sum] = i;
            }
        }
        return maxLen;
    }
};