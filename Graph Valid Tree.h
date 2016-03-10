/*
261. Graph Valid Tree
Difficulty: Medium
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

Show Hint 
Note: you can assume that no duplicate edges will appear in edges. 
Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/

// dfs

// undirected graph
class Solution {
private:
    unordered_set<int> visited;
    unordered_map<int, vector<int>> graph;

public:
        bool dfs(int cur, int parent) {
            if(visited.count(cur)) {
                return false;
            }
            visited.insert(cur);
            for (auto neighbor : graph[cur]) {
                if (!dfs(neighbor, cur) && neighbor != parent) {
                    return false;
                }
            }
            return true;
        }

        bool validTree(int n, vector<pair<int, int>>& edges) {
            // tree should have n nodes with n-1 edges
            if (n - 1 != edges.size()) {
                return false;
            }

            for (auto p : edges) {
                graph[p.first].push_back(p.second);
                graph[p.second].push_back(p.first);
            }

            if (!dfs(0, -1)) {
                return false;
            }
            
            // check if the clique contains every node.
            for (int i = 0; i < n; i++) {
                if(!visited.count(i)) {
                    return false;
                }
            }
            return true;
        }
};

class Solution {
public:
    bool dfs(vector<vector<int>> & edges, int n, int parent) {
        if(path.count(n)) {
            return false;
        }
        path.insert(n);
        visited.insert(n);
        for (int i = 0; i < edges[n].size(); i++) {        
            if (parent != edges[n][i] && !dfs(edges, edges[n][i], n)) {
                return false;
            }
        }
        path.erase(n);
        return true;
    }

    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> neighbors(n);
        for (auto p : edges) {
            neighbors[p.first].push_back(p.second);
            neighbors[p.second].push_back(p.first);
        }
    
        if(!dfs(neighbors, 0, -1)) {
            return false;
        }
    
        for (int i = 0; i < n; i++) {
            if(!visited.count(i)) {
                return false;
            }
        }
        
        return true;    
}
private:
    unordered_set<int> visited;
    unordered_set<int> path;
};

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
        // tree should have n nodes with n-1 edges
        if (n - 1 != edges.size()) {
            return false;
        }
        
        // union-find is a data structure that can union two sets and check 
        // whether two element in the same set.
        for (int i = 0; i < n; i++) {
            father.push_back(i);
        }
        
        for (auto p : edges) {
            int x = p.first, y = p.second;
            if (find(x) == find(y)) {
                return false;
            }
            setUnion(x, y);
        }
        return true;
    }
    
    int find(int node) {
        if (father[node] == node) {
            return node;
        }
        father[node] = find(father[node]);
        return father[node];
    }
    
    void setUnion(int node1, int node2) {
        father[find(node1)] = find(node2);
    }

private:
    vector<int> father;
};