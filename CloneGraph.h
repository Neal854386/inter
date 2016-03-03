/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Sep 26, 2013
 Problem:    Clone Graph
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/clone-graph/
 Notes:
 Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 
 OJ's undirected graph serialization:
 Nodes are labeled from 0 to N - 1, where N is the total nodes in the graph.
 We use # as a separator for each node, and , as a separator for each neighbor of the node.
 As an example, consider the serialized graph {1,2#2#2}.
 The graph has a total of three nodes, and therefore contains three parts as separated by #.
 Connect node 0 to both nodes 1 and 2.
 Connect node 1 to node 2.
 Connect node 2 to node 2 (itself), thus forming a self-cycle.
 Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/

 Solution: 1. DFS. 2. BFS.
 */

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    typedef UndirectedGraphNode GraphNode;
    typedef unordered_map<GraphNode *, GraphNode *> MAP;
    
    GraphNode *cloneGraph(GraphNode *node) {
        return cloneGraph_1(node);
    }
    
    // DFS
    GraphNode *cloneGraph_1(GraphNode *node) {
        MAP map;
        return cloneGraphRe(node, map);
    }
    
    GraphNode *cloneGraphRe(GraphNode *node, MAP &map) {
        if (!node) return NULL;
        if (map.find(node) != map.end())
            return map[node];
        GraphNode *newNode = new GraphNode(node->label);
        map[node] = newNode;
        for (int i = 0; i < node->neighbors.size(); ++i)
            newNode->neighbors.push_back(cloneGraphRe(node->neighbors[i], map));
        return newNode;
    }
    
    // BFS
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr) {
            return nullptr;
        }
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nodesMap;
        nodesMap[node] = new UndirectedGraphNode(node->label);
        queue<UndirectedGraphNode*> q;
        q.push(node);
        while (!q.empty()) {
            UndirectedGraphNode* tmp = q.front();
            q.pop();
            for (int i = 0; i < tmp->neighbors.size(); ++i) {
                UndirectedGraphNode* neighbor = tmp->neighbors[i];
                if (nodesMap.find(neighbor) == nodesMap.end()) {
                    UndirectedGraphNode* newNode = new UndirectedGraphNode(neighbor->label);
                    nodesMap[neighbor] = newNode;
                    q.push(neighbor);
                }
                nodesMap[tmp]->neighbors.push_back(nodesMap[neighbor]);
            }
        }
        return nodesMap[node];
    }
};


/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    using Node = UndirectedGraphNode;
    
    unordered_map<Node*, Node*> copied;
    auto nd = node;
    
    function<Node*(Node*)> clone = [&](Node* nd) {
        if(!nd) return nd;
    
        if(!copied.count(nd)) {
            copied[nd] = new Node(nd->label);
        } else {
            return copied[nd];
        }
        
        Node* new_nd = copied[nd];
        for (int i = 0; i < nd->neighbors.size(); i++) {
            new_nd->neighbors.push_back(clone(nd->neighbors[i]));
        }
        return new_nd;
    };
    
    return clone(node);
}


class Solution {
public:
    using Node = UndirectedGraphNode;
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // write your code here
        if (node == nullptr) {
            return node;
        }
        
        // init clone first node
        node_map[node] = new Node(node->label);
        node_que.push(node);
        while (!node_que.empty()) {
            auto ori_node = node_que.front(); node_que.pop();
            auto new_node = node_map[ori_node];
            for (int i = 0; i < ori_node->neighbors.size(); i++) {
                auto ori_neighbor = ori_node->neighbors[i];
                // clone node
                if (!node_map.count(ori_neighbor)) {
                    auto new_neighbor = new Node(ori_neighbor->label);
                    node_map[ori_neighbor] = new_neighbor;
                    node_que.push(ori_neighbor);
                }
                // clone neighbor
                new_node->neighbors.push_back(node_map[ori_neighbor]);
            }
        }
        return node_map[node];
    }

private:
    unordered_map<Node*, Node*> node_map;
    queue<Node*> node_que;
};