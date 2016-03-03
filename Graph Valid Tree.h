// Graph Valid Tree
/*
Difficulty: Medium
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
*/

// Quick-Find
/*
The function returns true if and only if:
There should be exactly n-1 edges.
Edges should connect all nodes together.
In order to check the second statement, we adapt the union-find set to connect two different connected components 
(See https://en.wikipedia.org/wiki/Disjoint-setdatastructure for explanation.)

Details of the union-find approach:
For each connected components, we use an arbitrary node within the component to represent it. 
And we use a vector parents to record which component each node belongs to, 
and use an integer component_num to record the number of component.
In the beginning, there are n components. So we initialize parents to 0, 1, ... , n-1.
For each edge, we try to determine whether the two nodes of the edge are in the same connected components. 
If the answer is yes, we find a loop, since the edge is connecting nodes within the same component. 
Otherwise, we connect the two components into one.

Complexities:
Let alpha(n) denote the inverse function of Ackermann function A(x,x)=n, which grows extremely slow, can be viewed as constant. 
(https://en.wikipedia.org/wiki/Ackermann_function)
Time complexity: O(n*alpha(n))
Space complexity: O(alpha(n)),
*/

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        // Step 1: Check the number of edges
        if (edges.size() != n - 1) {
            return false;
        }

        // Step 2: Union-find set
        vector<int> parents(n, 0);
        for (pair<int, int> edge : edges) {
            int root1 = find(parents, edge.first);
            int root2 = find(parents, edge.second);
            if (root1 == root2) {
                return false;
            } else {
                parents[root1] = root2;
            }
        }
        return true;
    }
private:
    // standard function of union-find set
    int find(vector<int> &parents, int c) {
        if (parents[c] != c) {
            parents[c] = find(parents, parents[c]);
        }
        return parents[c];
    }
};


class Solution {
public:
    int findFather(vector<int> &father, int x) {
        while (x != father[x]) {
            x = father[x];
        }
        return x;
    }
    bool dfs(vector<vector<int>> &graph, vector<bool> &visit, int u, int f) {
        visit[u] = true;
        for (auto v : graph[u]) {
            if (v != f) {
                if (visit[v]) {
                    return false;
                }
            } else if (!dfs(graph, visit, v, u)) {
                return false;
            }
        }
        return true;
    }
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> father(n);
        for (int i = 0; i < n; ++i) father[i] = i;
        for (auto edge : edges) {
            int fa = findFather(father, edge.first);
            int fb = findFather(father, edge.second);
            if (fa < fb) {
                father[fb] = fa;
            } else {
                father[fa] = fb;
            }
        };
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (i == father[i]) {
                ++cnt;
            }
            if (cnt > 1) {
                return false;
            }
        }
        vector<vector<int>> graph(n);
        vector<bool> visit(n, false);
        for (auto edge : edges) {
            int u = edge.first, v = edge.second;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return dfs(graph, visit, 0, -1);
    }
};