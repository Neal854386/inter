/*
Contains Duplicate III
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long, int> m;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i - j > k && m[nums[j]] == j) m.erase(nums[j++]);
            auto a = m.lower_bound(nums[i] - t);
            if (a != m.end() && abs(a->first - nums[i]) <= t) return true;
            m[nums[i]] = i;
        }
        return false;
    }
};


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long long> bst;
        for (int i = 0; i < nums.size(); ++i) {
            if (bst.size() == k + 1) bst.erase(bst.find(nums[i - k - 1]));
            
            auto lb = bst.lower_bound(nums[i]);
            if (lb != bst.end() && abs(*lb - nums[i]) <= t) return true;
            
            auto ub = bst.upper_bound(nums[i]);
            // here --ub is the key
            if (ub != bst.begin() && abs(*(--ub) - nums[i]) <= t) return true;
            bst.insert(nums[i]);
        }
        return false;
    }
};