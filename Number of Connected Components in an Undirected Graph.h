/*
323. Number of Connected Components in an Undirected Graph
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), 
write a function to find the number of connected components in an undirected graph.

Example 1:
     0          3
     |          |
     1 --- 2    4
Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

Example 2:
     0           4
     |           |
     1 --- 2 --- 3
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

Note:
You can assume that no duplicate edges will appear in edges. 
Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/

class Solution {
private:
     vector<bool> visited;
     vector<vector<int>> graph;
public:
    int countComponents (int n, vector<pair<int, int>>& edges) {
        if (n == 0) return 0;
        graph = vector<vector<int>> (n, vector<int>(0));
        visited = vector<bool>(n, false);
        int size = edges.size(), first, second;
        for (auto edge : edges) {
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                dfs(i);
                count++;
            }
        }

        return count;
    }
    
    void dfs(int i) {
        if (visited[i]) { 
            return;
        }
        visited[i] = true;
        for(auto ch : graph[i]) {
            dfs(ch);
        }
    }
};