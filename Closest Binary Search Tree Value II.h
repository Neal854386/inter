/*272. Closest Binary Search Tree Value II
Difficulty: Hard
Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Note:
Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    priority_queue<pair<double, int>> pq;
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        traverse(root, target, k);
        while (pq.size() != 0){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }

    void traverse(TreeNode* root, double target, int k){
        if(root == NULL) {return;}
        double diff = abs(root->val - target);
        if (pq.size() < k){
            pq.push({diff, root->val});
        } else {
            pq.push({diff, root->val});
            pq.pop();
        }
        traverse(root->left, target, k);
        traverse(root->right, target, k);
    }
};