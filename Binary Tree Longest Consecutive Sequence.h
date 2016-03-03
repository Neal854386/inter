/*
Binary Tree Longest Consecutive Sequence

Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

For example,
   1
    \
     3
    / \
   2   4
        \
         5
Longest consecutive sequence path is 3-4-5, so return 3.
   2
    \
     3
    / 
   2    
  / 
 1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
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
    int longestConsecutive(TreeNode* root) {
        return helper(root, nullptr, 0);
    }

    int helper(TreeNode *node, TreeNode *parent, int len) {
        if (!node) return len;
        if (parent && node->val == parent->val + 1) {
          len = len + 1;
        } else {
          len = 1;
        }
        return max(len, max(helper(node->left, node, len), helper(node->right, node, len)));
    }
};


class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if (!root) {return 0;}
        return helper(root, 0);
    }

    int helper(TreeNode *node, int len) {
        int left = 0, right = 0, current = 0;
        current = len + 1;
        if (node->left) {
            left = node->left->val == node->val + 1 ? 
            helper(node->left, current) : helper(node->left, 0);
        }
        
        if (node->right) {
            right = node->right->val == node->val + 1 ? 
            helper(node->right, current) : helper(node->right, 0);
        }
        return max(current, max(left, right));
    }
};