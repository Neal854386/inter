#include <bits/stdc++.h>
using namespace std;


// undirected graph
class Solution {
private:
    unordered_set<char> visited;
    unordered_map<char, vector<char>> graph;

public:
        bool dfs(char cur, char parent) {
            bool ret = false;
            visited.insert(cur);
            for (auto neighbor : graph[cur]) {
                if (visited.count(neighbor) && neighbor != parent) {
                    return true;
                }
                res |= dfs(neighbor, cur);
            }
            return res;
        }
    
        void hasCycle() {
            for (auto kv : graph) {
                if (!visited.count(kv.first)) {
                    if (dfs(kv.first, '0')) {
                        cout << "true";
                    }
                }
            }
            cout << "false";
        }
};


// Directed graph
class Solution {
private:
    unordered_set<char> visited, reback;
    unordered_map<char, vector<char>> graph;

public:
        bool dfs(char cur) {
            visited.insert(cur);
            reback.insert(cur);
            for (auto neighbor : graph[cur]) {
                if (visited.count(neighbor) && dfs(neighbor)) {
                    return true;
                } else if (reback.count(neighbor)) {
                    return true;
                }
            }
            reback.erase(cur);
            return false;
        }
    
        void hasCycle() {
            for (auto kv : graph) {
                if (!visited.count(kv.first)) {
                    if (dfs(kv.first)) {
                        cout << "true";
                    }
                }
            }
            cout << "false";
        }
};

// input format is:
// A:B,D
// B:C,F
// C:
int main() {
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
            Solution director;
            string line;
            while (cin >> line) {
                auto k = line[0];
                for (int i = 2; i < line.length(); i += 2) {
                    director.graph[k].push_back(line[i]);
                }
            }
            director.getRes();
            return 0;
}