/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 9, 2013
 Problem:    Maximum Depth of Binary Tree
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_104
 Notes:
 Given a binary tree, find its maximum depth.
 The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 Solution: Recursion.
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};


/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    // this method can get the max depth node for this tree
    int maxDepth(TreeNode *root) {
        // write your code here
        if (root == nullptr) {
            return 0;
        }
        helper(root);
        return max_level;
    }
    
    void helper(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        
        if (level > max_level) {
            max_level = level;
        }
        
        level++;
        helper(root->right);
        helper(root->left);
        level--;
    }
private:
    int max_level = 1;
    int level = 1;
};