//Inorder Successor in BST
/*
Difficulty: Medium
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

Note: If the given node has no in-order successor in the tree, return null.
*/

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
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root || !p) return nullptr;
        TreeNode *curr = root, *succ = nullptr;
        while (curr) {
            if (curr->val == p->val) {
                curr = curr->right;
            } else if (curr->val > p->val) {
                succ = curr;
                curr = curr->left;
            } else if (curr->val < p->val) {
                curr = curr->right;
            }
        }
        return succ;
    }
};