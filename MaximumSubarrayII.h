/*
Maximum Subarray II
Given an array of integers, find two non-overlapping subarrays which have the largest sum.

The number in each subarray should be contiguous.

Return the largest sum.

Note
The subarray should contain at least one number

Example
For given [1, 3, -1, 2, -1, 2], the two subarrays are [1, 3] and [2, -1, 2] or [1, 3, -1, 2] and [2], they both have the largest sum 7.

The idea is similar to sell stock III
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        int n = nums.size();
        vector<int> maxLR(n, nums[0]);
        vector<int> maxRL(n, nums[n - 1]);
        
        int local = nums[0];
        for (int i = 1; i < n; i++) {
            local = max(nums[i], local + nums[i]);
            maxLR[i] = max(local,  maxLR[i - 1]);
        }
        
        local = nums[n - 1];
        
        for (int i = n - 2; i >= 0; i--) {
            local = max(nums[i], local + nums[i]);
            maxRL[i] = max(local,  maxRL[i + 1]);
        }
        
        int max_sum = INT_MIN;
        for (int i = 0; i < n - 1; i++) {
            max_sum = max(max_sum, maxLR[i] + maxRL[i + 1]);
        }
        return max_sum;
    }
};
