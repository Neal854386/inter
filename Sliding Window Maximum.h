/*
239. Sliding Window Maximum My Submissions Question
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note: 
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?
*/

/*
The index of maximum value is always saved in the queue.front()
the data in the queue is descending order
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (!n)
            return vector<int>({});
        vector<int> res(n - k + 1, 0);
        deque<int> q;
        for (int i = 0; i < k; i++) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        for (int i = k; i < n; i++) {
            res[i - k] = nums[q.front()];
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            while (!q.empty() && q.front() <= i - k) {
                q.pop_front();
            }
            q.push_back(i);
        }

        res[n - k] = nums[q.front()];
        return res;
    }
};