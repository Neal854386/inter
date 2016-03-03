/*Number of Islands

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
*/

class Solution {
public:
    bool isVaild(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < M;
    }
    
    void search(int x, int y, vector<vector<char>>& grid) {
		int count = 0;
        visisted[x][y] = 1;
        for (auto dir : direction) {
            int nx = x + dir.first;
            int ny = y + dir.second;
            if (isVaild(nx, ny) && !visisted[nx][ny] && grid[x][y] == '1') {
                search(nx, ny, grid);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        N = grid.size(), M = grid[0].size();
        int count = 0;
        visisted = vector<vector<int>>(N, vector<int>(M, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == '1' && !visisted[i][j]) {
                    count++;
                    search(i, j, grid);
                }
            }
        } 
        return count;
    }

private:
    vector<vector<int>> visisted;
    vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int N; int M;
};