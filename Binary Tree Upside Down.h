/*

Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.

For example:
Given a binary tree {1,2,3,4,5},
    1
   / \
  2   3
 / \
4   5
return the root of the binary tree [4,5,2,#,#,3,1].
   4
  / \
 5   2
    / \
   3   1  


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
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        TreeNode *p = root, *parent = nullptr, *parentRight = nullptr;
        while (p != nullptr) {
            TreeNode* left = p->left;
            p->left = parentRight;   //ori parent->right become left node  
            parentRight = p->right;
            p->right = parent; // ori parent node become right node   
            parent = p;
            p = left;
        }
        return parent;
    }
};
