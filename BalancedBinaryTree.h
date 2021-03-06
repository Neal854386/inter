/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 10, 2013
 Update:     Aug 4, 2013
 Problem:    Balanced Binary Tree
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_110
 Notes:
 Given a binary tree, determine if it is height-balanced.
 For this problem, a height-balanced binary tree is defined as a binary tree in which 
 the depth of the two subtrees of every node never differ by more than 1.

 Solution: DFS.
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
    bool isBalanced(TreeNode *root) {
        int height = 0;
        return isBalancedRe(root, height);
    }
    
    bool isBalancedRe(TreeNode *root, int &height){
        if (!root) return true;
        
        int leftHeight = 0, rightHeight = 0;
        if (!isBalancedRe(root->left, leftHeight)) return false;
        if (!isBalancedRe(root->right, rightHeight)) return false;
        if (abs(leftHeight-rightHeight) > 1) return false;
        
        height = 1 + max(leftHeight, rightHeight);
        return true;
    }
};


class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    int maxDepth (TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int left = maxDepth(node->left);
        int right = maxDepth(node->right);
        if (left == -1 || right == -1 || abs(left - right) > 1) {
            return -1;
        }
        
        return 1 + max(left, right);
    } 
    bool isBalanced(TreeNode *root) {
        // write your code here
        return maxDepth(root) != -1;
    }
};