/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 29, 2013
 Update:     Jul 19, 2013
 Problem:    Permutations
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_46
 Notes:
 Given a collection of numbers, return all possible permutations.
 For example,
 [1,2,3] have the following permutations:
 [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

 Solution: dfs...
 */

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int> &num) {
        res.clear();
        vector<bool> avail(num.size(), true);
        vector<int> pum;
        permuteRe(num, avail, pum);
        return res;
    }

    void permuteRe(const vector<int> &num, vector<bool> &avail, vector<int> &pum)
    {
        if (pum.size() == num.size())
        {
            res.push_back(pum);
            return;
        }
        for (int i = 0; i < num.size(); ++i)
        {
            if (avail[i])
            {
                avail[i] = false;
                pum.push_back(num[i]);
                permuteRe(num, avail, pum);
                pum.pop_back();
                avail[i] = true;
            }
        }
    }
};

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int>> permute(vector<int> nums) {
        // write your code here
        if (nums.empty()) {return res;}
        dfs(nums);
        return res;
    }

    void dfs(const vector<int> &nums) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (find(path.begin(), path.end(), nums[i]) != path.end()) {
                continue;
            }
            path.push_back(nums[i]);
            dfs(nums);
            path.pop_back();
        }
    }
    
private:
    vector<vector<int>> res;
    vector<int> path; 
};

