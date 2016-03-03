/*
Smallest Rectangle Enclosing Black Pixels My Submissions Question
An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

For example, given the following image:

[
  "0010",
  "0110",
  "0100"
]
and x = 0, y = 2,
Return 6.
*/

class Solution {
public:
    void dfs(vector<vector<char>>& image, int x, int y) {
        if (x < 0 || x >= image.size() || y < 0 || y >= image[0].size() || image[x][y] == '0') return;
        image[x][y] = '0';
        minX = min(minX, x);maxX = max(maxX, x);
        minY = min(minY, y);maxY = max(maxY, y);
        for (auto d : dir) {
            dfs(image, x + d.first, y + d.second);
        }
    }
    
    int minArea(vector<vector<char>>& image, int x, int y) {
        minX = image.size(), maxX = -1, minY = image[0].size(), maxY = -1;
        dfs(image, x, y);
        return (maxX - minX + 1) * (maxY - minY + 1);
    }
private:
    int minX = 0, maxX = 0, minY = 0, maxY = 0;
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};
