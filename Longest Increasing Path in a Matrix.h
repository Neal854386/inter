/*
329. Longest Increasing Path in a Matrix

Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int isVaild(int x, int y) {
        return x >=0 && x < m && y >= 0 && y < n;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 0;
        if (matrix.empty() || matrix[0].empty()) { return 0; }
        m = matrix.size();
        n = matrix[0].size();
        dp = vector<vector<int>> (m, vector<int>(n, 1));
        visited = vector<vector<bool>> (m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, dfs(matrix, i, j));
            }
        }
        return res;
    }
    
    int dfs(vector<vector<int>>& matrix, int x, int y) {
        // already has result
        if (dp[x][y] > 1) {
            return dp[x][y];
        }
     
        for (auto dir : dirs) {
            int nx = x + dir.first;
            int ny = y + dir.second;
            if (isVaild(nx, ny) && matrix[nx][ny] > matrix[x][y] && !visited[nx][ny]) {
               visited[nx][ny] = true;
               dp[x][y] = max(dp[x][y], dfs(matrix, nx, ny) + 1);
               visited[nx][ny] = false;
            }
        }
        return dp[x][y];
    }

private:
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> dp;
    vector<vector<bool>> visited;
    int m = 0, n = 0;
};