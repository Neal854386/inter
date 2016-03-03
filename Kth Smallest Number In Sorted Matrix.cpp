#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <set>
using namespace std;

class cmp {
public:
    // tulpe<value, x, y>
    // index 0    , 1, 2
    bool operator()(tuple<int, int, int> t1, tuple<int, int, int> t2) {
        return get<0>(t1) > get<0>(t2);
    }
};


class Solution {
public:
    
    int kthSmallest(vector<vector<int>> matrix, int k) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, cmp> pq;
        const size_t N = matrix.size();
        const size_t M = matrix[0].size();
        bool visited [N][M];
        memset(visited,false, N * M * sizeof(bool));


        int row = 0, col = 0;
        pq.push(make_tuple(matrix[row][col], row, col));
        visited[0][0] = true; 
        int res = 0;
        for (int i = 0; i < k; i++) {
            auto element = pq.top();
            row = get<1>(element);
            col = get<2>(element);
            pq.pop();
            // Found the kth element, return its value.
            res = get<0>(element);
            
            // Only push element to heap if it hasn’t been pushed before.
            if (row < N - 1 && !visited[row + 1][col]) {
                visited[row + 1][col] = true;
                pq.push(make_tuple(matrix[row + 1][col], row + 1, col));
            }
            if (col < M - 1 && !visited[row][col + 1]) {
                visited[row][col + 1] = true;
                pq.push(make_tuple(matrix[row][col + 1], row, col + 1));
            }
        }
        return res;
    }
}; 


int main(int argc, char *argv[]) {
    
    
    
}