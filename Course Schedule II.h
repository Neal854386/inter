/*
210. Course Schedule II
Difficulty: Medium
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].
*/

/*
Topological Sort
*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses == 0) { return vector<int>(); }
        vector<int> ans;
        
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
        
        while (!que.empty()) {
            int node = que.front(); que.pop();
            ans.push_back(node);
            
            for (auto &child :graph[node]) {
                inDegree[child]--;
                if (inDegree[child] == 0) {
                    que.push(child);
                }
            }
        } 
        return ans.size() == numCourses ? ans : vector<int>();
    }
private:
    vector<vector<int>> graph;
    queue<int> que;
    unordered_set<int> visited;
};