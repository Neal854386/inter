/*
Diameter of a Binary Tree
The diameter of a tree (sometimes called the width) is the number of nodes on the longest path 
between two leaves in the tree.
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
    int diameter(TreeNode *root) {
        int start = 0;
        return helper(root, start);
    }

    int helper(TreeNode *root, int &height) {
        int lh = 0, rh = 0;
        if (root == nullptr) {
            height = 0;
            return 0;
        }

        // l and r store maximum path sum going through left and
        // right child of root respectively
        int ldiameter = helper(root->left, lh);
        int rdiameter = helper(root->right, rh);

        // Max path for parent call of root. This path must
        // include at-most one child of root
        height = max(lh, rh) + 1;

        // compare the left and right, and the max of go tho
        return max(lh + rh + 1, max(ldiameter, rdiameter));
    }
};
