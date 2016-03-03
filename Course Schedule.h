/*
207. Course Schedule
Difficulty: Medium
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

*/

/*
Topological Sort
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses == 0) { return true; }
        
        // init graph
        graph = vector<vector<int>>(numCourses,vector<int>());
        vector<int> inDegree(numCourses, 0);
        for (auto p: prerequisites) {
            graph[p.second].push_back(p.first);
            inDegree[p.first]++;
        }
        
        // push the index of zero in-degree node to que
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                que.push(i);
            }
        }
        
        int num = 0;
        while (!que.empty()) {
            int node = que.front(); que.pop();
            num++;
            
            for (auto &child :graph[node]) {
                inDegree[child]--;
                if (inDegree[child] == 0) {
                    que.push(child);
                }
            }
        } 
        return num == numCourses;
    }
private:
    vector<vector<int>> graph;
    queue<int> que;
    unordered_set<int> visited;
};