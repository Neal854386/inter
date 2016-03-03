/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 16, 2013
 Problem:    Pascal's Triangle
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_118
 Notes:
 Given numRows, generate the first numRows of Pascal's triangle.
 For example, given numRows = 5,
 Return
 [
      [1],
     [1,1],
    [1,2,1],
   [1,3,3,1],
  [1,4,6,4,1]
 ]

 Solution: .....
 */

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res(numRows);
        if (numRows < 1) return res;
        res[0].push_back(1);
        for (int i = 1; i < numRows; ++i)
        {
            res[i].push_back(1);
            for (int j = 1; j < i; ++j)
                res[i].push_back(res[i-1][j-1] + res[i-1][j]);
            res[i].push_back(1);
        }
        return res;
    }
};

class solution_pascal : public solution {
private:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        vector<int> prev = {1};
        while (n--) {
            ans.push_back(prev);
            vector<int> cur = {1};
            for (int i = 1; i < prev.size(); i++)
                cur.push_back(prev[i] + prev[i-1]);
            cur.push_back(1);
            prev = cur;
        }
        return ans;
    }
public:
    void test() {
        for (int i = 1; i <= 5; i++) {
            auto ans = generate(i);
            for (auto &row : ans) {
                for (int x : row)
                    printf("%d ", x);
                puts("");
            }
            puts("");
        }
    }
};